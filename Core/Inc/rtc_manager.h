#ifndef RTC_MANAGER_H
#define RTC_MANAGER_H

#include "lvgl.h"
#include "gui_guider.h"

// Put this one function inside your main.c while(1) loop
void RTC_Manager_Task(lv_ui *ui);
uint8_t Calculate_Day_Of_Week(uint8_t , uint8_t , uint8_t );

#endif
