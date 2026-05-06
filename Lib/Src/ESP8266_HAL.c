#include "ESP8266_HAL.h"


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

#define wifi_uart &huart3
#define pc_uart &huart1

char buffer[20];

/*****************************************************************************************************************************************/

void ESP_Init (char *SSID, char *PASSWD)
{
	char data[80];
	//HAL_UART_Transmit(&huart2, "Check\r\n",7, HAL_MAX_DELAY);

	Ringbuf_init();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET); //Chip Enable
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET); //Chip Reset
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); //Chip Reset
	Uart_sendstring("RESETTING.\r\n", pc_uart);

	Uart_sendstring("AT+RST\r\n", wifi_uart);
	Uart_sendstring("STM_Tx : AT+RST\r\n", pc_uart);

	for (int i=0; i<5; i++)
	{
		Uart_sendstring(".", pc_uart);
		HAL_Delay(1000);
	}

	/********* AT **********/
	Uart_sendstring("AT\r\n", wifi_uart);
	Uart_sendstring("Wait for AT response\r\n", pc_uart);
	while(!(Wait_for("AT\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("AT---->OK\n\n", pc_uart);


	/********* AT+CWMODE=1 **********/
	Uart_sendstring("AT+CWMODE=1\r\n", wifi_uart);
	Uart_sendstring("Wait for CWMODE response\r\n", pc_uart);
	while (!(Wait_for("AT+CWMODE=1\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("CW MODE---->1\n\n", pc_uart);


	/********* AT+CWJAP="SSID","PASSWD" **********/
	Uart_sendstring("connecting... to the provided AP\n", pc_uart);
	Uart_sendstring("Wait for CWJAP response\r\n", pc_uart);
	sprintf (data, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, PASSWD);
	Uart_sendstring(data, wifi_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));
	sprintf (data, "Connected to,\"%s\"\n\n", SSID);
	Uart_sendstring(data,pc_uart);


	/********* AT+CIFSR **********/
	Uart_sendstring("AT+CIFSR\r\n", wifi_uart);
	Uart_sendstring("Wait for CIFSR response\r\n", pc_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));
	Uart_sendstring("AT+CIFSR---->OK\n\n", pc_uart);

	Uart_sendstring("Now Connect to the IP ADDRESS\n\n", pc_uart);
}
