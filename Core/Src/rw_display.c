#include "rw_display.h"

#include <stdio.h>
#include "stm32f1xx_hal.h"

static void format_fixed_1dp(char *buf, size_t buf_size, const char *prefix, float value, const char *suffix)
{
  int32_t scaled = (int32_t)(value * 10.0f + ((value >= 0.0f) ? 0.5f : -0.5f));
  int32_t abs_scaled = (scaled < 0) ? -scaled : scaled;
  int32_t ipart = abs_scaled / 10;
  int32_t dpart = abs_scaled % 10;

  if (scaled < 0)
  {
    snprintf(buf, buf_size, "%s-%ld.%ld%s", prefix, (long)ipart, (long)dpart, suffix);
  }
  else
  {
    snprintf(buf, buf_size, "%s%ld.%ld%s", prefix, (long)ipart, (long)dpart, suffix);
  }
}

__attribute__((weak)) int RW_LCD_Backend_Init(void)
{
  return 0;
}

__attribute__((weak)) void RW_LCD_Backend_Clear(void)
{
}

__attribute__((weak)) void RW_LCD_Backend_PrintLine(uint8_t line, const char *text)
{
  (void)line;
  (void)text;
}

void rw_display_init(void)
{
  if (RW_LCD_Backend_Init() == 0)
  {
    RW_LCD_Backend_Clear();
    RW_LCD_Backend_PrintLine(0U, "RhythmWatch Oximeter");
    RW_LCD_Backend_PrintLine(1U, "Sensor booting...");
  }
}

void rw_display_show_reading(const oximeter_reading_t *reading)
{
  if (reading == 0)
  {
    return;
  }

  static uint32_t last_update_ms = 0U;
  uint32_t now = HAL_GetTick();
  if ((now - last_update_ms) < 400U)
  {
    return;
  }
  last_update_ms = now;

  char line0[32];
  char line1[32];
  char line2[32];

  if (!reading->finger_detected)
  {
    snprintf(line0, sizeof(line0), "HR: --.- bpm");
    snprintf(line1, sizeof(line1), "SpO2: --.-%%");
    snprintf(line2, sizeof(line2), "No finger");
  }
  else
  {
    if (reading->heart_rate_valid)
    {
      format_fixed_1dp(line0, sizeof(line0), "HR: ", reading->heart_rate_bpm, " bpm");
    }
    else
    {
      snprintf(line0, sizeof(line0), "HR: --.- bpm");
    }

    if (reading->spo2_valid)
    {
      format_fixed_1dp(line1, sizeof(line1), "SpO2: ", reading->spo2_percent, "%%");
    }
    else
    {
      snprintf(line1, sizeof(line1), "SpO2: --.-%%");
    }

    if (reading->heart_rate_valid && reading->spo2_valid)
    {
      snprintf(line2, sizeof(line2), "Signal: Stable");
    }
    else
    {
      snprintf(line2, sizeof(line2), "Signal: Acquiring");
    }
  }

  RW_LCD_Backend_PrintLine(0U, line0);
  RW_LCD_Backend_PrintLine(1U, line1);
  RW_LCD_Backend_PrintLine(2U, line2);
}

void rw_display_show_error(const char *line0, const char *line1)
{
  RW_LCD_Backend_Clear();
  RW_LCD_Backend_PrintLine(0U, line0);
  RW_LCD_Backend_PrintLine(1U, line1);
}
