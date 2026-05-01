/*
 * ESP8266_HAL.h
 *
 *  Created on: Apr 14, 2020
 *      Author: Controllerstech
 *  Modified on : Apr 11, 2024
 *  Modified by : WU, Chi Hang
 */

#ifndef INC_ESP8266_HAL_H_
#define INC_ESP8266_HAL_H_


void ESP_Init (char *SSID, char *PASSWD);
int HTTP_GET_Request(char *host, int port, char *path);
int HTTP_POST_Request(char *host, int port, char *path);
int Wttr_Get_Weather(void);

#endif /* INC_ESP8266_HAL_H_ */
