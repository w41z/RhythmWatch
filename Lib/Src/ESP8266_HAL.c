/*
 * ESP8266_HAL.c
 *
 *  Created on: Apr 14, 2020
 *      Author: Controllerstech
 *  Modified on : Nov 26, 2025
 *  Modified by : WU, Chi Hang
 */


#include "UartRingbuffer_multi.h"
#include "ESP8266_HAL.h"
#include "stdio.h"
#include "string.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

#define wifi_uart &huart3
#define pc_uart &huart1

char buffer[40];
uint8_t RLEDStatus = 0, GLEDStatus = 0, BLEDStatus = 0, BUZZStatus = 0;


/*****************************************************************************************************************************************/

void ESP_Init ()
{
	char data[80];

	Ringbuf_init();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET); //Chip Enable
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET); //Chip Reset
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); //Chip Reset

	Uart_sendstring("AT+RST\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+RST\r\n", pc_uart);
	Uart_sendstring("RESETTING.", pc_uart);
	for (int i=0; i<5; i++)
	{
		Uart_sendstring(".", pc_uart);
		HAL_Delay(1000);
	}

	/********* AT **********/
	Uart_sendstring("AT\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT\r\n", pc_uart);
	while(!(Wait_for("AT\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("STM_Rx : AT\r\r\n\r\nOK\r\n", pc_uart);
	HAL_Delay(1000);

	/********* AT+CWMODE=2 **********/
	Uart_sendstring("AT+CWMODE=2\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+CWMODE=2\r\n", pc_uart);
	while (!(Wait_for("AT+CWMODE=2\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("STM_Rx : AT+CWMODE=2\r\r\n\r\nOK\r\n", pc_uart);
	HAL_Delay(1000);

	/********* AT+CIPAP="192.168.123.168" **********/
	Uart_sendstring("AT+CIPAP=\"192.168.123.168\"\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+CIPAP=\"192.168.123.168\"\r\n", pc_uart);
	while (!(Wait_for("AT+CIPAP=\"192.168.123.168\"\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("STM_Rx : AT+CIPAP=\"192.168.123.168\"\r\r\n\r\nOK\r\n",pc_uart);
	HAL_Delay(1000);

	/********* AT+CWSAP="ELEC3300WIFI","3300",1,0 **********/
	Uart_sendstring("AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\n", pc_uart);
	while (!(Wait_for("AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("STM_Rx : AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\r\n\r\nOK\r\n",pc_uart);
	HAL_Delay(1000);

	/********* AT+CIPMUX=1 **********/
	Uart_sendstring("AT+CIPMUX=1\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+CIPMUX=1\r\n", pc_uart);
	while (!(Wait_for("AT+CIPMUX=1\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("STM_Rx : AT+CIPMUX=1\r\r\n\r\nOK\r\n",pc_uart);
	HAL_Delay(1000);

	/********* AT+CIPSERVER=1,8080 **********/
	Uart_sendstring("AT+CIPSERVER=1,8080\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+CIPSERVER=1,8080\r\n", pc_uart);
	while (!(Wait_for("AT+CIPSERVER=1,8080\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("STM_Rx : AT+CIPSERVER=1,8080\r\r\n\r\nOK\r\n",pc_uart);
	HAL_Delay(1000);

	/********* AT+CIPSTO=1800 **********/
	Uart_sendstring("AT+CIPSTO=1800\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+CIPSTO=1800\r\n", pc_uart);
	while (!(Wait_for("AT+CIPSTO=1800\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("STM_Rx : AT+CIPSTO=1800\r\r\n\r\nOK\r\n",pc_uart);
	HAL_Delay(1000);

	/********* AT+CIFSR **********/
	Uart_sendstring("AT+CIFSR\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+CIFSR\r\n", pc_uart);
	while (!(Wait_for("CIFSR:APIP,\"", wifi_uart)));
	while (!(Copy_upto("\"",buffer, wifi_uart)));
	int len = strlen (buffer);
	buffer[len-1] = '\0';
	sprintf (data, "+CIFSR:APIP,\"%s\"\r\n", buffer);
	Uart_sendstring(data, pc_uart);
	while (!(Wait_for("CIFSR:APMAC,\"", wifi_uart)));
	while (!(Copy_upto("\"",buffer, wifi_uart)));
	while (!(Wait_for("OK\r\n", wifi_uart)));
	len = strlen (buffer);
	buffer[len-1] = '\0';
	sprintf (data, "+CIFSR:APMAC,\"%s\"\r\n", buffer);
	Uart_sendstring(data, pc_uart);
	HAL_Delay(1000);
}




int Server_Send (char *str, int Link_ID)
{
	int len = strlen (str);
	char data[80];
	sprintf (data, "AT+CIPSEND=%d,%d\r\n", Link_ID, len);
	Uart_sendstring(data, wifi_uart);
	Uart_sendstring(data, pc_uart);
	while (!(Wait_for(">", wifi_uart)));
	Uart_sendstring (str, wifi_uart);
	while (!(Wait_for("SEND OK", wifi_uart)));
	Uart_sendstring (str, pc_uart);
	return 1;
}

void Server_Program ()
{
  char cStr [100] = { 0 };
  int  LinkID;
  while (!(Wait_for("+IPD,",wifi_uart)));
  while(!(Copy_upto("\n",buffer,wifi_uart)));
  Uart_sendstring (buffer, pc_uart);
  LinkID = buffer[0] - '0';
  if (Look_for("LED_",buffer)==1) {
	  if (buffer[13]=='1') {
		  if (buffer[15]=='0') {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);  // 100 = R OFF
			  RLEDStatus = 0;
		  }
		  else if (buffer[15]=='1') {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET); // 101 = R ON
			  RLEDStatus = 1;
		  }
	  }
	  else if (buffer[13]=='2') {
		  if (buffer[15]=='0') {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);	// 200 = G OFF
			  GLEDStatus = 0;
		  }
		  else if (buffer[15]=='1') {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); // 201 = G ON
			  GLEDStatus = 1;
		  }
	  }
	  else if (buffer[13]=='3') {
		  if (buffer[15]=='0') {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);	  // 300 = B OFF
			  BLEDStatus = 0;
		  }
		  else if (buffer[15]=='1') {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);   // 301 = B ON
			  BLEDStatus = 1;
		  }
	  }
	  for (int i=0; i<40;i++) {
		  buffer[i]='\0';
	  }
	  sprintf(cStr,"CMD_LED_%d_%d_%d_END\r\n", RLEDStatus, GLEDStatus, BLEDStatus);
	  Server_Send(cStr,LinkID);
  }
  else if (Look_for("BUZZER_",buffer)==1) {
	  if (buffer[16]=='0') {
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);   // BUZZER OFF
		  BUZZStatus = 0;
	  }
	  else if (buffer[16]=='1') {
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);     // BUZZER ON
		  BUZZStatus = 1;
	  }
	  for (int i=0; i<40;i++) {
		  buffer[i]='\0';
	 }
	 sprintf(cStr,"CMD_BUZZER_%d_END\r\n", BUZZStatus);
	 Server_Send(cStr,LinkID);
  }
}

