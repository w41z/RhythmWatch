#ifndef RTC_MANAGER_H
#define RTC_MANAGER_H

#include "lvgl.h"
#include "gui_guider.h"
#include "main.h"
#include <stdio.h>
#include "stm32f1xx_hal.h"
#include "time.h"
#include "string.h"

#define RTC_INIT_FLAG 0xFEED

extern RTC_HandleTypeDef hrtc;

HAL_StatusTypeDef RW_RTC_SetTime(struct tm *time);
struct tm* RW_RTC_GetTime(void);
void RW_RTC_Init(void);
void RTC_Manager_Task(lv_ui *ui);

#endif
