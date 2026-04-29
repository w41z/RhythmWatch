// /*
//  * ESP8266_HAL.c
//  *
//  *  Created on: Apr 14, 2020
//  *      Author: Controllerstech
//  *  Modified on : Nov 26, 2025
//  *  Modified by : WU, Chi Hang
//  */


// #include "UartRingbuffer_multi.h"
// #include "ESP8266_HAL.h"
// #include "stdio.h"
// #include "string.h"

// extern UART_HandleTypeDef huart1;
// extern UART_HandleTypeDef huart3;

// #define wifi_uart &huart3
// #define pc_uart &huart1

// char buffer[40];
// uint8_t RLEDStatus = 0, GLEDStatus = 0, BLEDStatus = 0, BUZZStatus = 0;


// /*****************************************************************************************************************************************/

// void ESP_Init ()
// {
// 	char data[80];

// 	Ringbuf_init();
// 	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET); //Chip Enable
// 	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET); //Chip Reset
// 	HAL_Delay(500);
// 	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET); //Chip Reset

// 	Uart_sendstring("AT+RST\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+RST\r\n", pc_uart);
// 	Uart_sendstring("RESETTING.", pc_uart);
// 	for (int i=0; i<5; i++)
// 	{
// 		Uart_sendstring(".", pc_uart);
// 		HAL_Delay(1000);
// 	}

// 	/********* AT **********/
// 	Uart_sendstring("AT\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT\r\n", pc_uart);
// 	while(!(Wait_for("AT\r\r\n\r\nOK\r\n", wifi_uart)));
// 	Uart_sendstring("STM_Rx : AT\r\r\n\r\nOK\r\n", pc_uart);
// 	HAL_Delay(1000);

// 	/********* AT+CWMODE=2 **********/
// 	Uart_sendstring("AT+CWMODE=2\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+CWMODE=2\r\n", pc_uart);
// 	while (!(Wait_for("AT+CWMODE=2\r\r\n\r\nOK\r\n", wifi_uart)));
// 	Uart_sendstring("STM_Rx : AT+CWMODE=2\r\r\n\r\nOK\r\n", pc_uart);
// 	HAL_Delay(1000);

// 	/********* AT+CIPAP="192.168.123.168" **********/
// 	Uart_sendstring("AT+CIPAP=\"192.168.123.168\"\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+CIPAP=\"192.168.123.168\"\r\n", pc_uart);
// 	while (!(Wait_for("AT+CIPAP=\"192.168.123.168\"\r\r\n\r\nOK\r\n", wifi_uart)));
// 	Uart_sendstring("STM_Rx : AT+CIPAP=\"192.168.123.168\"\r\r\n\r\nOK\r\n",pc_uart);
// 	HAL_Delay(1000);

// 	/********* AT+CWSAP="ELEC3300WIFI","3300",1,0 **********/
// 	Uart_sendstring("AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\n", pc_uart);
// 	while (!(Wait_for("AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\r\n\r\nOK\r\n", wifi_uart)));
// 	Uart_sendstring("STM_Rx : AT+CWSAP=\"ELEC3300WIFI\",\"3300\",1,0\r\r\n\r\nOK\r\n",pc_uart);
// 	HAL_Delay(1000);

// 	/********* AT+CIPMUX=1 **********/
// 	Uart_sendstring("AT+CIPMUX=1\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+CIPMUX=1\r\n", pc_uart);
// 	while (!(Wait_for("AT+CIPMUX=1\r\r\n\r\nOK\r\n", wifi_uart)));
// 	Uart_sendstring("STM_Rx : AT+CIPMUX=1\r\r\n\r\nOK\r\n",pc_uart);
// 	HAL_Delay(1000);

// 	/********* AT+CIPSERVER=1,8080 **********/
// 	Uart_sendstring("AT+CIPSERVER=1,8080\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+CIPSERVER=1,8080\r\n", pc_uart);
// 	while (!(Wait_for("AT+CIPSERVER=1,8080\r\r\n\r\nOK\r\n", wifi_uart)));
// 	Uart_sendstring("STM_Rx : AT+CIPSERVER=1,8080\r\r\n\r\nOK\r\n",pc_uart);
// 	HAL_Delay(1000);

// 	/********* AT+CIPSTO=1800 **********/
// 	Uart_sendstring("AT+CIPSTO=1800\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+CIPSTO=1800\r\n", pc_uart);
// 	while (!(Wait_for("AT+CIPSTO=1800\r\r\n\r\nOK\r\n", wifi_uart)));
// 	Uart_sendstring("STM_Rx : AT+CIPSTO=1800\r\r\n\r\nOK\r\n",pc_uart);
// 	HAL_Delay(1000);

// 	/********* AT+CIFSR **********/
// 	Uart_sendstring("AT+CIFSR\r\n", wifi_uart);
// 	Uart_sendstring("STM_Tx : AT+CIFSR\r\n", pc_uart);
// 	while (!(Wait_for("CIFSR:APIP,\"", wifi_uart)));
// 	while (!(Copy_upto("\"",buffer, wifi_uart)));
// 	int len = strlen (buffer);
// 	buffer[len-1] = '\0';
// 	sprintf (data, "+CIFSR:APIP,\"%s\"\r\n", buffer);
// 	Uart_sendstring(data, pc_uart);
// 	while (!(Wait_for("CIFSR:APMAC,\"", wifi_uart)));
// 	while (!(Copy_upto("\"",buffer, wifi_uart)));
// 	while (!(Wait_for("OK\r\n", wifi_uart)));
// 	len = strlen (buffer);
// 	buffer[len-1] = '\0';
// 	sprintf (data, "+CIFSR:APMAC,\"%s\"\r\n", buffer);
// 	Uart_sendstring(data, pc_uart);
// 	HAL_Delay(1000);
// }




// int Server_Send (char *str, int Link_ID)
// {
// 	int len = strlen (str);
// 	char data[80];
// 	sprintf (data, "AT+CIPSEND=%d,%d\r\n", Link_ID, len);
// 	Uart_sendstring(data, wifi_uart);
// 	Uart_sendstring(data, pc_uart);
// 	while (!(Wait_for(">", wifi_uart)));
// 	Uart_sendstring (str, wifi_uart);
// 	while (!(Wait_for("SEND OK", wifi_uart)));
// 	Uart_sendstring (str, pc_uart);
// 	return 1;
// }

// void Server_Program ()
// {
//   char cStr [100] = { 0 };
//   int  LinkID;
//   while (!(Wait_for("+IPD,",wifi_uart)));
//   while(!(Copy_upto("\n",buffer,wifi_uart)));
//   Uart_sendstring (buffer, pc_uart);
//   LinkID = buffer[0] - '0';
//   if (Look_for("LED_",buffer)==1) {
// 	  if (buffer[13]=='1') {
// 		  if (buffer[15]=='0') {
// 			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);  // 100 = R OFF
// 			  RLEDStatus = 0;
// 		  }
// 		  else if (buffer[15]=='1') {
// 			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET); // 101 = R ON
// 			  RLEDStatus = 1;
// 		  }
// 	  }
// 	  else if (buffer[13]=='2') {
// 		  if (buffer[15]=='0') {
// 			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);	// 200 = G OFF
// 			  GLEDStatus = 0;
// 		  }
// 		  else if (buffer[15]=='1') {
// 			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); // 201 = G ON
// 			  GLEDStatus = 1;
// 		  }
// 	  }
// 	  else if (buffer[13]=='3') {
// 		  if (buffer[15]=='0') {
// 			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);	  // 300 = B OFF
// 			  BLEDStatus = 0;
// 		  }
// 		  else if (buffer[15]=='1') {
// 			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);   // 301 = B ON
// 			  BLEDStatus = 1;
// 		  }
// 	  }
// 	  for (int i=0; i<40;i++) {
// 		  buffer[i]='\0';
// 	  }
// 	  sprintf(cStr,"CMD_LED_%d_%d_%d_END\r\n", RLEDStatus, GLEDStatus, BLEDStatus);
// 	  Server_Send(cStr,LinkID);
//   }
//   else if (Look_for("BUZZER_",buffer)==1) {
// 	  if (buffer[16]=='0') {
// 		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);   // BUZZER OFF
// 		  BUZZStatus = 0;
// 	  }
// 	  else if (buffer[16]=='1') {
// 		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);     // BUZZER ON
// 		  BUZZStatus = 1;
// 	  }
// 	  for (int i=0; i<40;i++) {
// 		  buffer[i]='\0';
// 	 }
// 	 sprintf(cStr,"CMD_BUZZER_%d_END\r\n", BUZZStatus);
// 	 Server_Send(cStr,LinkID);
//   }
// }

#include "UartRingbuffer_multi.h"
#include "ESP8266_HAL.h"
#include "stdio.h"
#include "string.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

#define wifi_uart &huart3
#define pc_uart &huart1


char buffer[20];



// 		content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n\
// 		<title>LED CONTROL</title>\n<style>html { font-family: Helvetica; \
// 		display: inline-block; margin: 0px auto; text-align: center;}\n\
// 		body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\
// 		h3 {color: #444444;margin-bottom: 50px;}\n.button {display: block;\
// 		width: 80px;background-color: #1abc9c;border: none;color: white;\
// 		padding: 13px 30px;text-decoration: none;font-size: 25px;\
// 		margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n\
// 		.button-on {background-color: #1abc9c;}\n.button-on:active \
// 		{background-color: #16a085;}\n.button-off {background-color: #34495e;}\n\
// 		.button-off:active {background-color: #2c3e50;}\np {font-size: 14px;color: #888;margin-bottom: 10px;}\n\
// 		</style>\n</head>\n<body>\n<h1>ESP8266 LED CONTROL</h1>\n";

// char *LED_ON = "<p>LED Status: ON</p><a class=\"button button-off\" href=\"/ledoff\">OFF</a>";
// char *LED_OFF = "<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/ledon\">ON</a>";
// char *Terminate = "</body></html>";



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
	// while (!(Wait_for("CIFSR:STAIP,\"", wifi_uart)));
	// while (!(Copy_upto("\"",buffer, wifi_uart)));
	while (!(Wait_for("OK\r\n", wifi_uart)));
	Uart_sendstring("AT+CIFSR---->OK\n\n", pc_uart);
	// int len = strlen (buffer);
	// buffer[len-1] = '\0';
	// sprintf (data, "IP ADDR: %s\n\n", buffer);
	// Uart_sendstring(data, pc_uart);


	// Uart_sendstring("AT+CIPMUX=1\r\n", wifi_uart);
	// while (!(Wait_for("AT+CIPMUX=1\r\r\n\r\nOK\r\n", wifi_uart)));
	// Uart_sendstring("CIPMUX---->OK\n\n", pc_uart);

	// Uart_sendstring("AT+CIPSERVER=1,80\r\n", wifi_uart);
	// while (!(Wait_for("OK\r\n", wifi_uart)));
	// Uart_sendstring("CIPSERVER---->OK\n\n", pc_uart);

	Uart_sendstring("Now Connect to the IP ADRESS\n\n", pc_uart);

}

int HTTP_GET_Request(char *host, int port, char *path)
{
	Uart_sendstring("Get Send\n", pc_uart);
    char cmd[128];
    char request[256];
    char response[512] = {0};

    Uart_flush(wifi_uart);

    sprintf(cmd, "AT+CIPSTART=\"TCP\",\"%s\",%d\r\n", host, port);
    Uart_sendstring(cmd, wifi_uart);
    if (!Wait_for_timeout("OK\r\n", wifi_uart, 5000)) {
            Uart_sendstring("GET: Connection failed!\n", pc_uart);
            return 0;
        }

    sprintf(request,
        "GET %s HTTP/1.0\r\n"
        "Host: %s\r\n"
        "Connection: close\r\n"
        "\r\n",
        path, host);

    int len = strlen(request);
    sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
    Uart_sendstring(cmd, wifi_uart);
    if (!Wait_for_timeout(">", wifi_uart ,5000)) {
        Uart_sendstring("GET: Send prompt timeout!\n", pc_uart);
        return 0;
    }
    Uart_sendstring(request, wifi_uart);
    if (!Wait_for_timeout("SEND OK", wifi_uart , 5000)) {
        Uart_sendstring("GET: Send failed!\n", pc_uart);
        return 0;
    }

    if (Wait_for_timeout("+IPD,", wifi_uart, 5000)) {
        while (IsDataAvailable(wifi_uart)) {
            char c = Uart_read(wifi_uart);
            if (c == ':') break;
        }

        int i = 0;
        uint32_t last_rx = HAL_GetTick();
        while (i < 511) {
            if (IsDataAvailable(wifi_uart)) {
                response[i++] = Uart_read(wifi_uart);
                last_rx = HAL_GetTick();
            }
            if ((HAL_GetTick() - last_rx) > 100) break;
            HAL_Delay(1);
        }
        response[i] = '\0';

        Uart_sendstring("GET Response:\n", pc_uart);
        Uart_sendstring(response, pc_uart);
        Uart_sendstring("\n", pc_uart);
    } else {
        Uart_sendstring("GET: No response received (timeout).\n", pc_uart);
    }

    HAL_Delay(100);
    Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
    Wait_for_timeout("OK\r\n", wifi_uart ,5000);
    return 1;
}
/**
 * ارسال درخواست HTTP POST با بدنه JSON
 * مثال: HTTP_POST_Request("192.168.1.3", 8000, "/api/receive", "{...}");
 */
/*
int HTTP_POST_Request(char *host, int port, char *path)
{
	Uart_sendstring("PostSend\n", pc_uart);
    char cmd[128];
    char request[512];
    char response[512] = {0};

    Uart_flush(wifi_uart); // پاک‌سازی بافر

    // اتصال TCP
    sprintf(cmd, "AT+CIPSTART=\"TCP\",\"%s\",%d\r\n", host, port);
    Uart_sendstring(cmd, wifi_uart);
    if (!Wait_for("OK\r\n", wifi_uart)) {
        Uart_sendstring("POST: Connection failed!\n", pc_uart);
        return 0;
    }


    int json_len = strlen(json_data);
    sprintf(request,
        "POST %s HTTP/1.0\r\n"
        "Host: %s\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s",
        path, host, port, json_len, json_data);

    sprintf(request,
        "POST %s HTTP/1.1\r\n"
        "Host: %s:%d\r\n"
        "Connection: close\r\n"
        "\r\n",
        path, host, port);

    int len = strlen(request);
    sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
    Uart_sendstring(cmd, wifi_uart);
    if (!Wait_for_timeout(">", wifi_uart,5000)) {
        Uart_sendstring("POST: Send prompt timeout!\n", pc_uart);
        return 0;
    }

    Uart_sendstring(request, wifi_uart);
    if (!Wait_for_timeout("SEND OK", wifi_uart,5000)) {
        Uart_sendstring("POST: Send failed!\n", pc_uart);
        return 0;
    }

    // خواندن پاسخ سرور
    if (Wait_for_timeout("+IPD,", wifi_uart, 5000)) {
        // عبور از +IPD,0,123: تا ":"
        while (IsDataAvailable(wifi_uart)) {
            char c = Uart_read(wifi_uart);
            if (c == ':') break;
        }

        // خواندن بدنه HTTP
        int i = 0;
        while (i < 511 && IsDataAvailable(wifi_uart)) {
            response[i++] = Uart_read(wifi_uart);
            HAL_Delay(1);
        }
        response[i] = '\0';

        Uart_sendstring("POST Response:\n", pc_uart);
        Uart_sendstring(response, pc_uart);
        Uart_sendstring("\n", pc_uart);
    } else {
        Uart_sendstring("POST: No response received (timeout).\n", pc_uart);
    }

    Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
    if (!Wait_for_timeout("OK", wifi_uart, 2000)) {
        Uart_sendstring("Warning: CIPCLOSE not confirmed\n", pc_uart);
    }
    HAL_Delay(500);
}
*/
int HTTP_POST_Request(char *host, int port, char *path)
{
    Uart_sendstring("PostSend\n", pc_uart);
    char cmd[128];
    char request[256];
    char response[512] = {0};

    Uart_flush(wifi_uart);

    sprintf(cmd, "AT+CIPSTART=\"TCP\",\"%s\",%d\r\n", host, port);
    Uart_sendstring(cmd, wifi_uart);
    if (!Wait_for_timeout("OK\r\n", wifi_uart, 5000)) {
        Uart_sendstring("POST: Connection failed!\n", pc_uart);
        return 0;
    }

    sprintf(request,
        "POST %s HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Connection: close\r\n"
        "\r\n",
        path, host);

    int len = strlen(request);
    sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
    Uart_sendstring(cmd, wifi_uart);
    if (!Wait_for_timeout(">", wifi_uart, 5000)) {
        Uart_sendstring("POST: Send prompt timeout!\n", pc_uart);
        return 0;
    }

    Uart_sendstring(request, wifi_uart);
    if (!Wait_for_timeout("SEND OK", wifi_uart, 5000)) {
        Uart_sendstring("POST: Send failed!\n", pc_uart);
        return 0;
    }

    if (Wait_for_timeout("+IPD,", wifi_uart, 5000)) {
        while (IsDataAvailable(wifi_uart)) {
            char c = Uart_read(wifi_uart);
            if (c == ':') break;
        }
        int i = 0;
        while (i < 511 && IsDataAvailable(wifi_uart)) {
            response[i++] = Uart_read(wifi_uart);
            HAL_Delay(1);
        }
        response[i] = '\0';
        Uart_sendstring("POST Response:\n", pc_uart);
        Uart_sendstring(response, pc_uart);
        Uart_sendstring("\n", pc_uart);
    } else {
        Uart_sendstring("POST: No response received (timeout).\n", pc_uart);
    }

    Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
    Wait_for_timeout("OK", wifi_uart, 2000);
    HAL_Delay(500);
    return 1;
}

int Wttr_Get_Weather(void)
{
    Uart_sendstring("=== wttr.in Hong Kong Weather ===\r\n", pc_uart);

    char cmd[120];
    char request[250];
    char raw[1024] = {0};
    char *start;

    // ====================== 1. Condition ======================
    Uart_sendstring("Condition : ", pc_uart);
    Uart_flush(wifi_uart);
    Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
    HAL_Delay(1500);

    sprintf(cmd, "AT+CIPSTART=\"TCP\",\"wttr.in\",80\r\n");
    Uart_sendstring(cmd, wifi_uart);
    Wait_for_timeout("OK\r\n", wifi_uart, 20000);
    HAL_Delay(1200);

    sprintf(request, "GET /Hong+Kong?format=%%C HTTP/1.1\r\nHost: wttr.in\r\nConnection: close\r\n\r\n");
    int len = strlen(request);
    sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
    Uart_sendstring(cmd, wifi_uart);

    if (Wait_for_timeout(">", wifi_uart, 15000))
    {
        Uart_sendstring(request, wifi_uart);
        Wait_for_timeout("SEND OK", wifi_uart, 10000);

        int i = 0;
        uint32_t timeout = HAL_GetTick() + 15000;
        while (i < 1023 && HAL_GetTick() < timeout)
        {
            if (IsDataAvailable(wifi_uart))
                raw[i++] = Uart_read(wifi_uart);
            else
                HAL_Delay(8);
        }
        raw[i] = '\0';

        start = strstr(raw, "+IPD,"); if (start) { start = strchr(start, ':'); if (start) strcpy(raw, start + 1); }
        start = strstr(raw, "\r\n\r\n"); if (start) strcpy(raw, start + 4);
        start = strstr(raw, "CLOSED"); if (start) *start = '\0';

        start = raw;
        while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t') start++;
        strcpy(raw, start);

        for (int j = strlen(raw)-1; j >= 0; j--) {
            if (raw[j] == ' ' || raw[j] == '\r' || raw[j] == '\n' || raw[j] == '\t') raw[j] = '\0';
            else break;
        }
        Uart_sendstring(raw, pc_uart);
    }
    Uart_sendstring("\r\n", pc_uart);

    // ====================== 2. Temperature ======================
    Uart_sendstring("Temperature: ", pc_uart);
    Uart_flush(wifi_uart);
    Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
    HAL_Delay(1500);

    sprintf(cmd, "AT+CIPSTART=\"TCP\",\"wttr.in\",80\r\n");
    Uart_sendstring(cmd, wifi_uart);
    Wait_for_timeout("OK\r\n", wifi_uart, 20000);
    HAL_Delay(1200);

    sprintf(request, "GET /Hong+Kong?format=%%t HTTP/1.1\r\nHost: wttr.in\r\nConnection: close\r\n\r\n");
    len = strlen(request);
    sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
    Uart_sendstring(cmd, wifi_uart);

    if (Wait_for_timeout(">", wifi_uart, 15000))
    {
        Uart_sendstring(request, wifi_uart);
        Wait_for_timeout("SEND OK", wifi_uart, 10000);

        int i = 0;
        uint32_t timeout = HAL_GetTick() + 15000;
        while (i < 1023 && HAL_GetTick() < timeout)
        {
            if (IsDataAvailable(wifi_uart))
                raw[i++] = Uart_read(wifi_uart);
            else
                HAL_Delay(8);
        }
        raw[i] = '\0';

        start = strstr(raw, "+IPD,"); if (start) { start = strchr(start, ':'); if (start) strcpy(raw, start + 1); }
        start = strstr(raw, "\r\n\r\n"); if (start) strcpy(raw, start + 4);
        // === 移除亂碼「掳C」並加上空格+C ===
        start = strstr(raw, "°C"); if (start) strcpy(start, " degree Celsius");
        start = strstr(raw, "CLOSED"); if (start) *start = '\0';

        start = raw;
        while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t') start++;
        strcpy(raw, start);

        for (int j = strlen(raw)-1; j >= 0; j--) {
            if (raw[j] == ' ' || raw[j] == '\r' || raw[j] == '\n' || raw[j] == '\t') raw[j] = '\0';
            else break;
        }
        Uart_sendstring(raw, pc_uart);
    }
    Uart_sendstring("\r\n", pc_uart);

    // ====================== 3. Feels Like ======================
    Uart_sendstring("Feels Like : ", pc_uart);
    Uart_flush(wifi_uart);
    Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
    HAL_Delay(1500);

    sprintf(cmd, "AT+CIPSTART=\"TCP\",\"wttr.in\",80\r\n");
    Uart_sendstring(cmd, wifi_uart);
    Wait_for_timeout("OK\r\n", wifi_uart, 20000);
    HAL_Delay(1200);

    sprintf(request, "GET /Hong+Kong?format=%%f HTTP/1.1\r\nHost: wttr.in\r\nConnection: close\r\n\r\n");
    len = strlen(request);
    sprintf(cmd, "AT+CIPSEND=%d\r\n", len);
    Uart_sendstring(cmd, wifi_uart);

    if (Wait_for_timeout(">", wifi_uart, 15000))
    {
        Uart_sendstring(request, wifi_uart);
        Wait_for_timeout("SEND OK", wifi_uart, 10000);

        int i = 0;
        uint32_t timeout = HAL_GetTick() + 15000;
        while (i < 1023 && HAL_GetTick() < timeout)
        {
            if (IsDataAvailable(wifi_uart))
                raw[i++] = Uart_read(wifi_uart);
            else
                HAL_Delay(8);
        }
        raw[i] = '\0';

        start = strstr(raw, "+IPD,"); if (start) { start = strchr(start, ':'); if (start) strcpy(raw, start + 1); }
        start = strstr(raw, "\r\n\r\n"); if (start) strcpy(raw, start + 4);
        // === 移除亂碼「掳C」並加上空格+C ===
        start = strstr(raw, "°C"); if (start) strcpy(start, " degree Celsius");
        start = strstr(raw, "CLOSED"); if (start) *start = '\0';

        start = raw;
        while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t') start++;
        strcpy(raw, start);

        for (int j = strlen(raw)-1; j >= 0; j--) {
            if (raw[j] == ' ' || raw[j] == '\r' || raw[j] == '\n' || raw[j] == '\t') raw[j] = '\0';
            else break;
        }
        Uart_sendstring(raw, pc_uart);
    }
    Uart_sendstring("\r\n", pc_uart);

    Uart_sendstring("=== All Done ===\r\n\r\n", pc_uart);
    return 1;
}

// int Server_Send (char *str, int Link_ID)
// {
// 	int len = strlen (str);
// 	char data[80];
// 	sprintf (data, "AT+CIPSEND=%d,%d\r\n", Link_ID, len);
// 	Uart_sendstring(data, wifi_uart);
// 	while (!(Wait_for(">", wifi_uart)));
// 	Uart_sendstring (str, wifi_uart);
// 	while (!(Wait_for("SEND OK", wifi_uart)));
// 	sprintf (data, "AT+CIPCLOSE=5\r\n");
// 	Uart_sendstring(data, wifi_uart);
// 	while (!(Wait_for("OK\r\n", wifi_uart)));
// 	return 1;
// }

// void Server_Handle (char *str, int Link_ID)
// {
// 	char datatosend[1024] = {0};
// 	if (!(strcmp (str, "/ledon")))
// 	{
// 		sprintf (datatosend, Basic_inclusion);
// 		strcat(datatosend, LED_ON);
// 		strcat(datatosend, Terminate);
// 		Server_Send(datatosend, Link_ID);
// 	}

// 	else if (!(strcmp (str, "/ledoff")))
// 	{
// 		sprintf (datatosend, Basic_inclusion);
// 		strcat(datatosend, LED_OFF);
// 		strcat(datatosend, Terminate);
// 		Server_Send(datatosend, Link_ID);
// 	}

// 	else
// 	{
// 		sprintf (datatosend, Basic_inclusion);
// 		strcat(datatosend, LED_OFF);
// 		strcat(datatosend, Terminate);
// 		Server_Send(datatosend, Link_ID);
// 	}

// }
/**
 * ارسال درخواست HTTP GET و بازگرداندن پاسخ (تا 512 بایت)
 * مثال: HTTP_GET_Request("192.168.1.3", 8000, "/api/receive?input=5");
 */




// void Server_Start (void)
// {
// 	char buftocopyinto[64] = {0};
// 	char Link_ID;
// 	while (!(Get_after("+IPD,", 1, &Link_ID, wifi_uart)));
// 	Link_ID -= 48;
// 	while (!(Copy_upto(" HTTP/1.1", buftocopyinto, wifi_uart)));
// 	if (Look_for("/ledon", buftocopyinto) == 1)
// 	{
// 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
// 		Server_Handle("/ledon",Link_ID);
// 	}

// 	else if (Look_for("/ledoff", buftocopyinto) == 1)
// 	{
// 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
// 		Server_Handle("/ledoff",Link_ID);
// 	}

// 	else if (Look_for("/favicon.ico", buftocopyinto) == 1);

// 	else
// 	{
// 		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
// 		Server_Handle("/ ", Link_ID);
// 	}
// }
