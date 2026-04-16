#ifndef RW_SOFT_I2C_H
#define RW_SOFT_I2C_H

#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

#ifndef RW_SOFT_I2C_SCL_PORT
#define RW_SOFT_I2C_SCL_PORT GPIOB
#endif

#ifndef RW_SOFT_I2C_SCL_PIN
#define RW_SOFT_I2C_SCL_PIN GPIO_PIN_10
#endif

#ifndef RW_SOFT_I2C_SDA_PORT
#define RW_SOFT_I2C_SDA_PORT GPIOB
#endif

#ifndef RW_SOFT_I2C_SDA_PIN
#define RW_SOFT_I2C_SDA_PIN GPIO_PIN_11
#endif

void rw_soft_i2c_init(void);
bool rw_soft_i2c_write_reg(uint8_t dev_addr_7bit, uint8_t reg, uint8_t value);
bool rw_soft_i2c_read_reg(uint8_t dev_addr_7bit, uint8_t reg, uint8_t *value);
bool rw_soft_i2c_read_regs(uint8_t dev_addr_7bit, uint8_t start_reg, uint8_t *buf, uint8_t len);

#endif
