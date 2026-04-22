#include "dht11.h"

extern TIM_HandleTypeDef htim1;

// Function to set Pin as Output
void DHT11_Set_Output(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

// Function to set Pin as Input
void DHT11_Set_Input(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

// Simple microsecond delay (Adjust based on your CPU frequency)
void delay_us(uint16_t us) {
    __HAL_TIM_SET_COUNTER(&htim1, 0); // Requires a Basic Timer (TIM1/2/3) configured in .ioc
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

// Function to read data from DHT11 sensor
// Returns 1 if successful, 0 if error
uint8_t DHT11_Read(DHT11_Data *sensor_data) {
    uint8_t data[5] = {0};
    uint8_t response = 0;

    DHT11_Set_Output();
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
    HAL_Delay(18);
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
    delay_us(30);
    if(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_SET)
        response = 1;

    DHT11_Set_Input();

    if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_RESET) {
        while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_RESET);
        while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_SET);

        for (int j=0; j<5; j++) {
            for (int i=0; i<8; i++) {
                while (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)));
                delay_us(40);

                if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)) {
                    data[j] |= (1 << (7 - i));
                    while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
                }
            }
        }

        if(response == 0) {
            return 0; // Sensor error
        } else {
            sensor_data->humidity_integral = data[0];
            sensor_data->humidity_decimal = data[1];
            sensor_data->temperature_integral = data[2];
            sensor_data->temperature_decimal = data[3];
            sensor_data->checksum = data[4];
            return 1; // Success
        }
    }
    return 0; // No response from sensor
}
