#ifndef __BSP_ESP8266_H
#define __BSP_ESP8266_H

#include "main.h"
#include "string.h"
#include "stdio.h"

/******* UART 和 DMA 外部句柄声明 *******/  
extern UART_HandleTypeDef huart1;               // 调试串口 UART1 句柄
extern UART_HandleTypeDef huart3;               // ESP8266 串口 UART3 句柄
extern DMA_HandleTypeDef hdma_usart3_rx;        // USART3 RX DMA 句柄

/******* DEBUG 调试串口引脚用户宏定义 *******/
#define DEBUG_TX_Pin         GPIO_PIN_9
#define DEBUG_TX_GPIO_Port   GPIOA
#define DEBUG_RX_Pin         GPIO_PIN_10
#define DEBUG_RX_GPIO_Port   GPIOA

/******* ESP8266 引脚用户宏定义 *******/
#define ESP8266_TX_Pin       GPIO_PIN_10
#define ESP8266_TX_GPIO_Port GPIOB
#define ESP8266_RX_Pin       GPIO_PIN_11
#define ESP8266_RX_GPIO_Port GPIOB

/******* ESP8266 控制引脚用户宏定义 *******/
#define ESP8266_IO_Pin       	GPIO_PIN_8
#define ESP8266_IO_GPIO_Port 	GPIOB
#define ESP8266_RST_Pin      	GPIO_PIN_9
#define ESP8266_RST_GPIO_Port GPIOB

/* 定义缓冲区长度 */
#define UART_RX_BUFF_LEN 512

/************ 函数声明 ************/
void ESP8266_GPIO_Init(void);
void ESP8266_Reset(void);
void UART_StartReceive(void);
void ESP8266_Init(void);

#endif /* __BSP_ESP8266_H  */