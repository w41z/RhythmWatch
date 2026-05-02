#include "ESP8266_HAL.h"


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

#define wifi_uart &huart3
#define pc_uart &huart1

char buffer[20];

/*****************************************************************************************************************************************/

int ESP_Init (char *SSID, char *PASSWD)
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

	while(!(Wait_for("AT\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("AT---->OK\n\n", pc_uart);


	/********* AT+CWMODE=1 **********/
	Uart_sendstring("AT+CWMODE=1\r\n", wifi_uart);
	while (!(Wait_for("AT+CWMODE=1\r\r\n\r\nOK\r\n", wifi_uart)));
	Uart_sendstring("CW MODE---->1\n\n", pc_uart);


	/********* AT+CWJAP="SSID","PASSWD" **********/
	Uart_sendstring("connecting... to the provided AP\n", pc_uart);
	sprintf (data, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, PASSWD);
	Uart_sendstring(data, wifi_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));
	sprintf (data, "Connected to,\"%s\"\n\n", SSID);
	Uart_sendstring(data,pc_uart);


	/********* AT+CIFSR **********/
	Uart_sendstring("AT+CIFSR\r\n", wifi_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));
	Uart_sendstring("AT+CIFSR---->OK\n\n", pc_uart);

	Uart_sendstring("Now Connect to the IP ADDRESS\n\n", pc_uart);

    return 1;
}

// int Wttr_Get_Weather(void)
// {
//     Uart_sendstring("=== wttr.in Hong Kong Weather ===\r\n", pc_uart);

//     char cmd[120];
//     char request[250];
//     char raw[1024] = {0};
//     char *start;

//     // ====================== 1. Condition ======================
//     Uart_sendstring("Condition : ", pc_uart);
//     Uart_flush(wifi_uart);
//     Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
//     HAL_Delay(1500);

//     sprintf(cmd, "AT+CIPSTART=\"TCP\",\"wttr.in\",80\r\n");
//     Uart_sendstring(cmd, wifi_uart);
//     Wait_for_timeout("OK\r\n", wifi_uart, 3000);
//     HAL_Delay(1200);

//     sprintf(request, "GET /Hong+Kong?format=%%C HTTP/1.1\r\nHost: wttr.in\r\nConnection: close\r\n\r\n");
//     int len = strlen(request);
//     sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
//     Uart_sendstring(cmd, wifi_uart);

//     if (Wait_for_timeout(">", wifi_uart, 3000))
//     {
//         Uart_sendstring(request, wifi_uart);
//         Wait_for_timeout("SEND OK", wifi_uart, 3000);

//         int i = 0;
//         uint32_t timeout = HAL_GetTick() + 3000;
//         while (i < 1023 && HAL_GetTick() < timeout)
//         {
//             if (IsDataAvailable(wifi_uart))
//                 raw[i++] = Uart_read(wifi_uart);
//             else
//                 HAL_Delay(8);
//         }
//         raw[i] = '\0';

//         start = strstr(raw, "+IPD,"); if (start) { start = strchr(start, ':'); if (start) strcpy(raw, start + 1); }
//         start = strstr(raw, "\r\n\r\n"); if (start) strcpy(raw, start + 4);
//         start = strstr(raw, "CLOSED"); if (start) *start = '\0';

//         start = raw;
//         while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t') start++;
//         strcpy(raw, start);

//         for (int j = strlen(raw)-1; j >= 0; j--) {
//             if (raw[j] == ' ' || raw[j] == '\r' || raw[j] == '\n' || raw[j] == '\t') raw[j] = '\0';
//             else break;
//         }
//         Uart_sendstring(raw, pc_uart);
//     }
//     Uart_sendstring("\r\n", pc_uart);

//     // ====================== 2. Temperature ======================
//     Uart_sendstring("Temperature: ", pc_uart);
//     Uart_flush(wifi_uart);
//     Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
//     HAL_Delay(1500);

//     sprintf(cmd, "AT+CIPSTART=\"TCP\",\"wttr.in\",80\r\n");
//     Uart_sendstring(cmd, wifi_uart);
//     Wait_for_timeout("OK\r\n", wifi_uart, 3000);
//     HAL_Delay(1200);

//     sprintf(request, "GET /Hong+Kong?format=%%t HTTP/1.1\r\nHost: wttr.in\r\nConnection: close\r\n\r\n");
//     len = strlen(request);
//     sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
//     Uart_sendstring(cmd, wifi_uart);

//     if (Wait_for_timeout(">", wifi_uart, 3000))
//     {
//         Uart_sendstring(request, wifi_uart);
//         Wait_for_timeout("SEND OK", wifi_uart, 3000);

//         int i = 0;
//         uint32_t timeout = HAL_GetTick() + 3000;
//         while (i < 1023 && HAL_GetTick() < timeout)
//         {
//             if (IsDataAvailable(wifi_uart))
//                 raw[i++] = Uart_read(wifi_uart);
//             else
//                 HAL_Delay(8);
//         }
//         raw[i] = '\0';

//         start = strstr(raw, "+IPD,"); if (start) { start = strchr(start, ':'); if (start) strcpy(raw, start + 1); }
//         start = strstr(raw, "\r\n\r\n"); if (start) strcpy(raw, start + 4);
//         // === 移除亂碼「掳C」並加上空格+C ===
//         start = strstr(raw, "°C"); if (start) strcpy(start, " degree Celsius");
//         start = strstr(raw, "CLOSED"); if (start) *start = '\0';

//         start = raw;
//         while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t') start++;
//         strcpy(raw, start);

//         for (int j = strlen(raw)-1; j >= 0; j--) {
//             if (raw[j] == ' ' || raw[j] == '\r' || raw[j] == '\n' || raw[j] == '\t') raw[j] = '\0';
//             else break;
//         }
//         Uart_sendstring(raw, pc_uart);
//     }
//     Uart_sendstring("\r\n", pc_uart);

//     // ====================== 3. Feels Like ======================
//     Uart_sendstring("Feels Like : ", pc_uart);
//     Uart_flush(wifi_uart);
//     Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
//     HAL_Delay(1500);

//     sprintf(cmd, "AT+CIPSTART=\"TCP\",\"wttr.in\",80\r\n");
//     Uart_sendstring(cmd, wifi_uart);
//     Wait_for_timeout("OK\r\n", wifi_uart, 3000);
//     HAL_Delay(1200);

//     sprintf(request, "GET /Hong+Kong?format=%%f HTTP/1.1\r\nHost: wttr.in\r\nConnection: close\r\n\r\n");
//     len = strlen(request);
//     sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
//     Uart_sendstring(cmd, wifi_uart);

//     if (Wait_for_timeout(">", wifi_uart, 3000))
//     {
//         Uart_sendstring(request, wifi_uart);
//         Wait_for_timeout("SEND OK", wifi_uart, 3000);

//         int i = 0;
//         uint32_t timeout = HAL_GetTick() + 3000;
//         while (i < 1023 && HAL_GetTick() < timeout)
//         {
//             if (IsDataAvailable(wifi_uart))
//                 raw[i++] = Uart_read(wifi_uart);
//             else
//                 HAL_Delay(8);
//         }
//         raw[i] = '\0';

//         start = strstr(raw, "+IPD,"); if (start) { start = strchr(start, ':'); if (start) strcpy(raw, start + 1); }
//         start = strstr(raw, "\r\n\r\n"); if (start) strcpy(raw, start + 4);
//         // === 移除亂碼「掳C」並加上空格+C ===
//         start = strstr(raw, "°C"); if (start) strcpy(start, " degree Celsius");
//         start = strstr(raw, "CLOSED"); if (start) *start = '\0';

//         start = raw;
//         while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t') start++;
//         strcpy(raw, start);

//         for (int j = strlen(raw)-1; j >= 0; j--) {
//             if (raw[j] == ' ' || raw[j] == '\r' || raw[j] == '\n' || raw[j] == '\t') raw[j] = '\0';
//             else break;
//         }
//         Uart_sendstring(raw, pc_uart);
//     }
//     Uart_sendstring("\r\n", pc_uart);

//     Uart_sendstring("=== All Done ===\r\n\r\n", pc_uart);
//     return 1;
// }