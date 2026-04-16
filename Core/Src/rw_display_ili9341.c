#include "rw_display_ili9341.h"

#include "ili9341.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define COLOR_BLACK 0x0000U
#define COLOR_WHITE 0xFFFFU
#define COLOR_CYAN  0x07FFU
#define COLOR_YELLOW 0xFFE0U
#define COLOR_RED   0xF800U

static bool g_lcd_ready = false;
static char g_line_cache[3][27];
static bool g_line_cache_valid[3] = {false, false, false};

static uint16_t text_pixel_width(const char *text, uint8_t scale)
{
  if (text == NULL)
  {
    return 0U;
  }

  size_t len = strlen(text);
  uint32_t w = (uint32_t)len * 6U * scale;
  return (w > 65535U) ? 65535U : (uint16_t)w;
}

int RW_LCD_Backend_Init(void)
{
  g_lcd_ready = ili9341_init();
  return g_lcd_ready ? 0 : -1;
}

void RW_LCD_Backend_Clear(void)
{
  if (!g_lcd_ready)
  {
    return;
  }

  g_line_cache_valid[0] = false;
  g_line_cache_valid[1] = false;
  g_line_cache_valid[2] = false;
  ili9341_fill_screen(COLOR_BLACK);
}

void RW_LCD_Backend_PrintLine(uint8_t line, const char *text)
{
  if (!g_lcd_ready || text == NULL || line >= 3U)
  {
    return;
  }

  ili9341_info_t info = ili9341_get_info();
  const uint8_t scale = 2U;
  const uint16_t line_h = (uint16_t)(8U * scale);
  const uint16_t gap = 10U;
  const uint16_t block_h = (uint16_t)(3U * line_h + 2U * gap);

  uint16_t y0 = (info.height > block_h) ? (uint16_t)((info.height - block_h) / 2U) : 0U;
  uint16_t y = (uint16_t)(y0 + line * (line_h + gap));

  char render[27];
  memset(render, ' ', sizeof(render) - 1U);
  render[sizeof(render) - 1U] = '\0';
  size_t text_len = strlen(text);
  if (text_len > 26U)
  {
    text_len = 26U;
  }
  memcpy(render, text, text_len);

  if (g_line_cache_valid[line] && strcmp(g_line_cache[line], render) == 0)
  {
    return;
  }
  strcpy(g_line_cache[line], render);
  g_line_cache_valid[line] = true;

  uint16_t clear_w = (uint16_t)(26U * 6U * scale);
  uint16_t clear_x = (info.width > clear_w) ? (uint16_t)((info.width - clear_w) / 2U) : 0U;
  char clear_buf[27];
  memset(clear_buf, ' ', sizeof(clear_buf) - 1U);
  clear_buf[sizeof(clear_buf) - 1U] = '\0';
  ili9341_draw_string(clear_x, y, clear_buf, COLOR_BLACK, COLOR_BLACK, scale);

  uint16_t text_w = text_pixel_width(render, scale);
  uint16_t x = (info.width > text_w) ? (uint16_t)((info.width - text_w) / 2U) : clear_x;

  uint16_t fg = COLOR_WHITE;
  if (line == 0U)
  {
    fg = COLOR_CYAN;
  }
  else if (strstr(render, "FAIL") != NULL)
  {
    fg = COLOR_RED;
  }
  else if (strstr(render, "SpO2") != NULL || strstr(render, "SPO2") != NULL)
  {
    fg = COLOR_YELLOW;
  }

  ili9341_draw_string(x, y, render, fg, COLOR_BLACK, scale);
}
