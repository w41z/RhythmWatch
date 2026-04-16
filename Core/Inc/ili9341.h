#ifndef ILI9341_H
#define ILI9341_H

#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

#define ILI9341_LCD_RST_PORT GPIOE
#define ILI9341_LCD_RST_PIN GPIO_PIN_1

#define ILI9341_LCD_BL_PORT GPIOD
#define ILI9341_LCD_BL_PIN GPIO_PIN_12

/* Many Wildfire boards drive BL with active-low logic via transistor.
 * If your board is active-high, change to GPIO_PIN_SET.
 */
#ifndef ILI9341_LCD_BL_ACTIVE_STATE
#define ILI9341_LCD_BL_ACTIVE_STATE GPIO_PIN_RESET
#endif

/* MADCTL default set to 0x08 (BGR) for normal portrait direction.
 * If needed, tune to 0x48 / 0x88 / 0xC8 / 0x28 based on panel mounting.
 */
#ifndef ILI9341_MADCTL_VALUE
#define ILI9341_MADCTL_VALUE 0x08U
#endif

/* Tutorial mapping: FSMC NE1 with RS on A16 (PD11). */
#define ILI9341_FSMC_BANK_BASE 0x60000000UL
#define ILI9341_RS_ADDRESS_BIT 16U

typedef struct
{
  uint16_t width;
  uint16_t height;
} ili9341_info_t;

bool ili9341_init(void);
void ili9341_fill_screen(uint16_t color);
void ili9341_draw_string(uint16_t x, uint16_t y, const char *text, uint16_t fg, uint16_t bg, uint8_t scale);
ili9341_info_t ili9341_get_info(void);

#endif
