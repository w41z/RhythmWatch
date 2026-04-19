#include "ili9341.h"

#include <ctype.h>
#include <stddef.h>

#define ILI9341_CMD_SWRESET 0x01U
#define ILI9341_CMD_SLPOUT  0x11U
#define ILI9341_CMD_GAMMASET 0x26U
#define ILI9341_CMD_DISPOFF 0x28U
#define ILI9341_CMD_DISPON  0x29U
#define ILI9341_CMD_CASET   0x2AU
#define ILI9341_CMD_PASET   0x2BU
#define ILI9341_CMD_RAMWR   0x2CU
#define ILI9341_CMD_MADCTL  0x36U
#define ILI9341_CMD_COLMOD  0x3AU

static uint16_t g_width = 240U;
static uint16_t g_height = 320U;

#define LCD_REG_ADDR ((volatile uint16_t *)(ILI9341_FSMC_BANK_BASE))
#define LCD_RAM_ADDR ((volatile uint16_t *)(ILI9341_FSMC_BANK_BASE | (1UL << (ILI9341_RS_ADDRESS_BIT + 1U))))

static inline void lcd_backlight_on(void);
static inline void lcd_backlight_off(void);

static inline void write_cmd(uint8_t cmd)
{
  *LCD_REG_ADDR = (uint16_t)cmd;
}

static inline void write_data_u8(uint8_t data)
{
  *LCD_RAM_ADDR = (uint16_t)data;
}

static inline void write_data_u16(uint16_t data)
{
  *LCD_RAM_ADDR = data;
}

static void write_data_buf(const uint8_t *buf, uint16_t len)
{
  for (uint16_t i = 0U; i < len; ++i)
  {
    write_data_u8(buf[i]);
  }
}

static void init_fsmc_gpio(void)
{
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_FSMC_CLK_ENABLE();

  GPIO_InitTypeDef gpio = {0};

  gpio.Mode = GPIO_MODE_AF_PP;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;

  /* Mapping from pins_for_LCD.png (left=board pin, right=FSMC signal):
   * PD0->D2, PD1->D3, PD4->NOE, PD5->NWE, PD7->NE1,
   * PD8->D13, PD9->D14, PD10->D15, PD11->A16, PD14->D0, PD15->D1.
   */
  gpio.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7 |
             GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |
             GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOD, &gpio);

  /* PE7->D4, PE8->D5, PE9->D6, PE10->D7, PE11->D8, PE12->D9, PE13->D10, PE14->D11, PE15->D12. */
  gpio.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |
             GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  HAL_GPIO_Init(GPIOE, &gpio);

  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Pin = ILI9341_LCD_BL_PIN;
  HAL_GPIO_Init(ILI9341_LCD_BL_PORT, &gpio);
  lcd_backlight_off();

  gpio.Pin = ILI9341_LCD_RST_PIN;
  HAL_GPIO_Init(ILI9341_LCD_RST_PORT, &gpio);
}

static void init_fsmc_timing(void)
{
  /* 16-bit SRAM mode on NE1, separate write timing enabled. */
  FSMC_Bank1->BTCR[0] = FSMC_BCRx_MBKEN | FSMC_BCRx_MWID_0 | FSMC_BCRx_WREN | FSMC_BCRx_EXTMOD;

  /* Read timing: ADDSET=2, DATAST=5. */
  FSMC_Bank1->BTCR[1] = (2U << FSMC_BTRx_ADDSET_Pos) | (5U << FSMC_BTRx_DATAST_Pos);

  /* Write timing: ADDSET=2, DATAST=5. */
  FSMC_Bank1E->BWTR[0] = (2U << FSMC_BWTRx_ADDSET_Pos) | (5U << FSMC_BWTRx_DATAST_Pos);
}

static inline void lcd_reset_assert(void)
{
  HAL_GPIO_WritePin(ILI9341_LCD_RST_PORT, ILI9341_LCD_RST_PIN, GPIO_PIN_RESET);
}

static inline void lcd_reset_release(void)
{
  HAL_GPIO_WritePin(ILI9341_LCD_RST_PORT, ILI9341_LCD_RST_PIN, GPIO_PIN_SET);
}

static inline void lcd_backlight_on(void)
{
  HAL_GPIO_WritePin(ILI9341_LCD_BL_PORT, ILI9341_LCD_BL_PIN, ILI9341_LCD_BL_ACTIVE_STATE);
}

static inline void lcd_backlight_off(void)
{
  GPIO_PinState inactive = (ILI9341_LCD_BL_ACTIVE_STATE == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
  HAL_GPIO_WritePin(ILI9341_LCD_BL_PORT, ILI9341_LCD_BL_PIN, inactive);
}

static void set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  uint8_t data[4];

  write_cmd(ILI9341_CMD_CASET);
  data[0] = (uint8_t)(x0 >> 8U);
  data[1] = (uint8_t)(x0 & 0xFFU);
  data[2] = (uint8_t)(x1 >> 8U);
  data[3] = (uint8_t)(x1 & 0xFFU);
  write_data_buf(data, 4U);

  write_cmd(ILI9341_CMD_PASET);
  data[0] = (uint8_t)(y0 >> 8U);
  data[1] = (uint8_t)(y0 & 0xFFU);
  data[2] = (uint8_t)(y1 >> 8U);
  data[3] = (uint8_t)(y1 & 0xFFU);
  write_data_buf(data, 4U);

  write_cmd(ILI9341_CMD_RAMWR);
}

static void write_color_repeat(uint16_t color, uint32_t count)
{
  for (uint32_t i = 0U; i < count; ++i)
  {
    write_data_u16(color);
  }
}

static void draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
  if (x >= g_width || y >= g_height)
  {
    return;
  }

  set_window(x, y, x, y);
  write_color_repeat(color, 1U);
}

static void fill_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
  if (x >= g_width || y >= g_height)
  {
    return;
  }

  if ((uint32_t)x + w > g_width)
  {
    w = (uint16_t)(g_width - x);
  }
  if ((uint32_t)y + h > g_height)
  {
    h = (uint16_t)(g_height - y);
  }

  set_window(x, y, (uint16_t)(x + w - 1U), (uint16_t)(y + h - 1U));
  write_color_repeat(color, (uint32_t)w * (uint32_t)h);
}

static uint8_t font5x7_column(char c, uint8_t column)
{
  switch (c)
  {
    case 'A': { static const uint8_t g[5] = {0x7EU,0x11U,0x11U,0x11U,0x7EU}; return g[column]; }
    case 'B': { static const uint8_t g[5] = {0x7FU,0x49U,0x49U,0x49U,0x36U}; return g[column]; }
    case 'C': { static const uint8_t g[5] = {0x3EU,0x41U,0x41U,0x41U,0x22U}; return g[column]; }
    case 'D': { static const uint8_t g[5] = {0x7FU,0x41U,0x41U,0x22U,0x1CU}; return g[column]; }
    case 'E': { static const uint8_t g[5] = {0x7FU,0x49U,0x49U,0x49U,0x41U}; return g[column]; }
    case 'F': { static const uint8_t g[5] = {0x7FU,0x09U,0x09U,0x09U,0x01U}; return g[column]; }
    case 'G': { static const uint8_t g[5] = {0x3EU,0x41U,0x49U,0x49U,0x7AU}; return g[column]; }
    case 'H': { static const uint8_t g[5] = {0x7FU,0x08U,0x08U,0x08U,0x7FU}; return g[column]; }
    case 'I': { static const uint8_t g[5] = {0x00U,0x41U,0x7FU,0x41U,0x00U}; return g[column]; }
    case 'J': { static const uint8_t g[5] = {0x20U,0x40U,0x41U,0x3FU,0x01U}; return g[column]; }
    case 'K': { static const uint8_t g[5] = {0x7FU,0x08U,0x14U,0x22U,0x41U}; return g[column]; }
    case 'L': { static const uint8_t g[5] = {0x7FU,0x40U,0x40U,0x40U,0x40U}; return g[column]; }
    case 'M': { static const uint8_t g[5] = {0x7FU,0x02U,0x0CU,0x02U,0x7FU}; return g[column]; }
    case 'N': { static const uint8_t g[5] = {0x7FU,0x04U,0x08U,0x10U,0x7FU}; return g[column]; }
    case 'O': { static const uint8_t g[5] = {0x3EU,0x41U,0x41U,0x41U,0x3EU}; return g[column]; }
    case 'P': { static const uint8_t g[5] = {0x7FU,0x09U,0x09U,0x09U,0x06U}; return g[column]; }
    case 'Q': { static const uint8_t g[5] = {0x3EU,0x41U,0x51U,0x21U,0x5EU}; return g[column]; }
    case 'R': { static const uint8_t g[5] = {0x7FU,0x09U,0x19U,0x29U,0x46U}; return g[column]; }
    case 'S': { static const uint8_t g[5] = {0x46U,0x49U,0x49U,0x49U,0x31U}; return g[column]; }
    case 'T': { static const uint8_t g[5] = {0x01U,0x01U,0x7FU,0x01U,0x01U}; return g[column]; }
    case 'U': { static const uint8_t g[5] = {0x3FU,0x40U,0x40U,0x40U,0x3FU}; return g[column]; }
    lcd_backlight_off();
    case 'W': { static const uint8_t g[5] = {0x7FU,0x20U,0x18U,0x20U,0x7FU}; return g[column]; }
    case 'X': { static const uint8_t g[5] = {0x63U,0x14U,0x08U,0x14U,0x63U}; return g[column]; }
    case 'Y': { static const uint8_t g[5] = {0x03U,0x04U,0x78U,0x04U,0x03U}; return g[column]; }
    case 'Z': { static const uint8_t g[5] = {0x61U,0x51U,0x49U,0x45U,0x43U}; return g[column]; }

    case '0': { static const uint8_t g[5] = {0x3EU,0x45U,0x49U,0x51U,0x3EU}; return g[column]; }
    case '1': { static const uint8_t g[5] = {0x00U,0x21U,0x7FU,0x01U,0x00U}; return g[column]; }
    case '2': { static const uint8_t g[5] = {0x21U,0x43U,0x45U,0x49U,0x31U}; return g[column]; }
    case '3': { static const uint8_t g[5] = {0x42U,0x41U,0x51U,0x69U,0x46U}; return g[column]; }
    case '4': { static const uint8_t g[5] = {0x0CU,0x14U,0x24U,0x7FU,0x04U}; return g[column]; }
    case '5': { static const uint8_t g[5] = {0x72U,0x51U,0x51U,0x51U,0x4EU}; return g[column]; }
    case '6': { static const uint8_t g[5] = {0x1EU,0x29U,0x49U,0x49U,0x06U}; return g[column]; }
    case '7': { static const uint8_t g[5] = {0x40U,0x47U,0x48U,0x50U,0x60U}; return g[column]; }
    case '8': { static const uint8_t g[5] = {0x36U,0x49U,0x49U,0x49U,0x36U}; return g[column]; }
    case '9': { static const uint8_t g[5] = {0x30U,0x49U,0x49U,0x4AU,0x3CU}; return g[column]; }

    case ':': { static const uint8_t g[5] = {0x00U,0x36U,0x36U,0x00U,0x00U}; return g[column]; }
    case '.': { static const uint8_t g[5] = {0x00U,0x40U,0x60U,0x00U,0x00U}; return g[column]; }
    case '%': { static const uint8_t g[5] = {0x62U,0x64U,0x08U,0x13U,0x23U}; return g[column]; }
    case '-': { static const uint8_t g[5] = {0x08U,0x08U,0x08U,0x08U,0x08U}; return g[column]; }
    case '=': { static const uint8_t g[5] = {0x14U,0x14U,0x14U,0x14U,0x14U}; return g[column]; }
    case '/': { static const uint8_t g[5] = {0x20U,0x10U,0x08U,0x04U,0x02U}; return g[column]; }
    case ' ': { static const uint8_t g[5] = {0x00U,0x00U,0x00U,0x00U,0x00U}; return g[column]; }
    default:  { static const uint8_t g[5] = {0x7FU,0x41U,0x5DU,0x41U,0x7FU}; return g[column]; }
  }
}

static void draw_char5x7(uint16_t x, uint16_t y, char c, uint16_t fg, uint16_t bg, uint8_t scale)
{
  char up = (char)toupper((unsigned char)c);

  for (uint8_t col = 0U; col < 5U; ++col)
  {
    uint8_t bits = font5x7_column(up, col);
    for (uint8_t row = 0U; row < 7U; ++row)
    {
      uint16_t color = ((bits & (1U << row)) != 0U) ? fg : bg;
      for (uint8_t sx = 0U; sx < scale; ++sx)
      {
        for (uint8_t sy = 0U; sy < scale; ++sy)
        {
          draw_pixel((uint16_t)(x + col * scale + sx), (uint16_t)(y + row * scale + sy), color);
        }
      }
    }
  }

  for (uint8_t col = 5U; col < 6U; ++col)
  {
    for (uint8_t row = 0U; row < 7U; ++row)
    {
      for (uint8_t sx = 0U; sx < scale; ++sx)
      {
        for (uint8_t sy = 0U; sy < scale; ++sy)
        {
          draw_pixel((uint16_t)(x + col * scale + sx), (uint16_t)(y + row * scale + sy), bg);
        }
      }
    }
  }
}

bool ili9341_init(void)
{
  init_fsmc_gpio();
  init_fsmc_timing();

  lcd_reset_assert();
  HAL_Delay(20U);
  lcd_reset_release();
  HAL_Delay(120U);

  write_cmd(ILI9341_CMD_SWRESET);
  HAL_Delay(150U);

  write_cmd(ILI9341_CMD_DISPOFF);

  write_cmd(ILI9341_CMD_COLMOD);
  write_data_u8(0x55U);

  write_cmd(ILI9341_CMD_MADCTL);
  write_data_u8(ILI9341_MADCTL_VALUE);

  write_cmd(ILI9341_CMD_GAMMASET);
  write_data_u8(0x01U);

  write_cmd(ILI9341_CMD_SLPOUT);
  HAL_Delay(120U);

  write_cmd(ILI9341_CMD_DISPON);
  HAL_Delay(20U);

  lcd_backlight_on();

  ili9341_fill_screen(0x0000U);
  return true;
}

void ili9341_fill_screen(uint16_t color)
{
  fill_rect(0U, 0U, g_width, g_height, color);
}

void ili9341_draw_string(uint16_t x, uint16_t y, const char *text, uint16_t fg, uint16_t bg, uint8_t scale)
{
  if (text == NULL || scale == 0U)
  {
    return;
  }

  uint16_t cursor_x = x;
  while (*text != '\0')
  {
    if ((uint32_t)cursor_x + (6U * scale) >= g_width)
    {
      break;
    }

    draw_char5x7(cursor_x, y, *text, fg, bg, scale);
    cursor_x = (uint16_t)(cursor_x + 6U * scale);
    ++text;
  }
}

ili9341_info_t ili9341_get_info(void)
{
  ili9341_info_t info;
  info.width = g_width;
  info.height = g_height;
  return info;
}
