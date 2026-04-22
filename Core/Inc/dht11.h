#ifndef DHT11_H
#define DHT11_H

#include "main.h"

#define DHT11_PORT GPIOA
#define DHT11_PIN  GPIO_PIN_2

/* DHT11 sensor data structure */
typedef struct {
    uint8_t humidity_integral;
    uint8_t humidity_decimal;
    uint8_t temperature_integral;
    uint8_t temperature_decimal;
    uint8_t checksum;
} DHT11_Data;

/* Function prototypes */
void DHT11_Set_Output(void);
void DHT11_Set_Input(void);
void delay_us(uint16_t us);
uint8_t DHT11_Read(DHT11_Data *sensor_data);

#endif /* DHT11_H */
