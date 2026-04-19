#ifndef DEMO_K1_H
#define DEMO_K1_H

#include "stm32f1xx_hal.h"

#define K1_Pin GPIO_PIN_0
#define K1_GPIO_Port GPIOA
#define R_Pin GPIO_PIN_5
#define R_GPIO_Port GPIOB
#define G_Pin GPIO_PIN_0
#define G_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_1
#define B_GPIO_Port GPIOB

void RGB_Init(void);
void Led_toggle_RGB(void);

#endif /* DEMO_K1_H */