#ifndef __RW_RTC_H
#define __RW_RTC_H

#include "stm32f1xx_hal.h"
#include "rtc.h"
#include "time.h"
#include "lcd.h"
#include "stdio.h"
#include "string.h"

#define RTC_INIT_FLAG 0xFEED
HAL_StatusTypeDef RW_RTC_SetTime(struct tm *time);
struct tm* RW_RTC_GetTime(void);
void RW_RTC_Init(void);
void RW_RTC_DisplayTime(void);

#endif /* __RW_RTC_H */