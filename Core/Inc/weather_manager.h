#ifndef WEATHER_MANAGER_H
#define WEATHER_MANAGER_H

#include "main.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "ESP8266_HAL.h"
#include "UartRingbuffer_multi.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define wifi_uart &huart3
#define pc_uart   &huart1

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

void Weather_Manager_SetCredentials(const char *ssid, const char *passwd);
void Weather_Manager_SetLocation(const char *location);
void Weather_Manager_RequestFetch(void);
void Weather_Manager_Task(lv_ui *ui);

#endif // WEATHER_MANAGER_H