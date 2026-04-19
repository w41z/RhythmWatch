#include "rgb.h"

static uint8_t color_state = 0;

void RGB_Init() {
    // Initial every pin to high -> LED goes off
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
}

void Led_toggle_RGB() {    
    // the reading from pa0 = low -> button has been press, perform the color-switching
    if (HAL_GPIO_ReadPin(GPIOA, K1_Pin) == 1)
    {
      color_state++;
      if (color_state > 3) color_state = 1;

      switch (color_state)
      {
        case 1://R
          HAL_GPIO_WritePin(GPIOB, R_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOB, G_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOB, B_Pin, GPIO_PIN_SET);
          break;
        case 2://G
          HAL_GPIO_WritePin(GPIOB, R_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOB, G_Pin, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOB, B_Pin, GPIO_PIN_SET);
          break;
        case 3://B
          HAL_GPIO_WritePin(GPIOB, R_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOB, G_Pin, GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOB, B_Pin, GPIO_PIN_RESET);
          break;

      }
    }
    // wait for user to release the button
    while (HAL_GPIO_ReadPin(GPIOA, K1_Pin) == 1)
    {
      HAL_Delay(10);
    }
    // extra delay for stability
    HAL_Delay(10);
}