#include "rw_soft_i2c.h"

static inline void i2c_delay(void)
{
  for (volatile uint32_t i = 0; i < 120U; ++i)
  {
    __NOP();
  }
}

static inline void scl_high(void)
{
  HAL_GPIO_WritePin(RW_SOFT_I2C_SCL_PORT, RW_SOFT_I2C_SCL_PIN, GPIO_PIN_SET);
}

static inline void scl_low(void)
{
  HAL_GPIO_WritePin(RW_SOFT_I2C_SCL_PORT, RW_SOFT_I2C_SCL_PIN, GPIO_PIN_RESET);
}

static inline void sda_high(void)
{
  HAL_GPIO_WritePin(RW_SOFT_I2C_SDA_PORT, RW_SOFT_I2C_SDA_PIN, GPIO_PIN_SET);
}

static inline void sda_low(void)
{
  HAL_GPIO_WritePin(RW_SOFT_I2C_SDA_PORT, RW_SOFT_I2C_SDA_PIN, GPIO_PIN_RESET);
}

static inline GPIO_PinState sda_read(void)
{
  return HAL_GPIO_ReadPin(RW_SOFT_I2C_SDA_PORT, RW_SOFT_I2C_SDA_PIN);
}

static void i2c_start(void)
{
  sda_high();
  scl_high();
  i2c_delay();
  sda_low();
  i2c_delay();
  scl_low();
}

static void i2c_stop(void)
{
  sda_low();
  i2c_delay();
  scl_high();
  i2c_delay();
  sda_high();
  i2c_delay();
}

static bool i2c_write_byte(uint8_t byte)
{
  for (uint8_t bit = 0; bit < 8U; ++bit)
  {
    if ((byte & 0x80U) != 0U)
    {
      sda_high();
    }
    else
    {
      sda_low();
    }

    i2c_delay();
    scl_high();
    i2c_delay();
    scl_low();
    byte <<= 1U;
  }

  sda_high();
  i2c_delay();
  scl_high();
  i2c_delay();
  bool ack = (sda_read() == GPIO_PIN_RESET);
  scl_low();
  return ack;
}

static uint8_t i2c_read_byte(bool ack)
{
  uint8_t value = 0U;
  sda_high();

  for (uint8_t bit = 0; bit < 8U; ++bit)
  {
    value <<= 1U;
    scl_high();
    i2c_delay();
    if (sda_read() == GPIO_PIN_SET)
    {
      value |= 0x01U;
    }
    scl_low();
    i2c_delay();
  }

  if (ack)
  {
    sda_low();
  }
  else
  {
    sda_high();
  }

  i2c_delay();
  scl_high();
  i2c_delay();
  scl_low();
  sda_high();

  return value;
}

void rw_soft_i2c_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  if (RW_SOFT_I2C_SCL_PORT == GPIOA || RW_SOFT_I2C_SDA_PORT == GPIOA)
  {
    __HAL_RCC_GPIOA_CLK_ENABLE();
  }
  if (RW_SOFT_I2C_SCL_PORT == GPIOB || RW_SOFT_I2C_SDA_PORT == GPIOB)
  {
    __HAL_RCC_GPIOB_CLK_ENABLE();
  }
  if (RW_SOFT_I2C_SCL_PORT == GPIOC || RW_SOFT_I2C_SDA_PORT == GPIOC)
  {
    __HAL_RCC_GPIOC_CLK_ENABLE();
  }

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  GPIO_InitStruct.Pin = RW_SOFT_I2C_SCL_PIN;
  HAL_GPIO_Init(RW_SOFT_I2C_SCL_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = RW_SOFT_I2C_SDA_PIN;
  HAL_GPIO_Init(RW_SOFT_I2C_SDA_PORT, &GPIO_InitStruct);

  /* Release possible stuck slave by toggling SCL before first START. */
  sda_high();
  for (uint8_t i = 0U; i < 9U; ++i)
  {
    scl_low();
    i2c_delay();
    scl_high();
    i2c_delay();
  }

  sda_high();
  scl_high();
}

bool rw_soft_i2c_write_reg(uint8_t dev_addr_7bit, uint8_t reg, uint8_t value)
{
  i2c_start();
  if (!i2c_write_byte((uint8_t)(dev_addr_7bit << 1U)))
  {
    i2c_stop();
    return false;
  }

  if (!i2c_write_byte(reg))
  {
    i2c_stop();
    return false;
  }

  if (!i2c_write_byte(value))
  {
    i2c_stop();
    return false;
  }

  i2c_stop();
  return true;
}

bool rw_soft_i2c_read_reg(uint8_t dev_addr_7bit, uint8_t reg, uint8_t *value)
{
  return rw_soft_i2c_read_regs(dev_addr_7bit, reg, value, 1U);
}

bool rw_soft_i2c_read_regs(uint8_t dev_addr_7bit, uint8_t start_reg, uint8_t *buf, uint8_t len)
{
  if (buf == 0 || len == 0U)
  {
    return false;
  }

  i2c_start();
  if (!i2c_write_byte((uint8_t)(dev_addr_7bit << 1U)))
  {
    i2c_stop();
    return false;
  }

  if (!i2c_write_byte(start_reg))
  {
    i2c_stop();
    return false;
  }

  i2c_start();
  if (!i2c_write_byte((uint8_t)((dev_addr_7bit << 1U) | 0x01U)))
  {
    i2c_stop();
    return false;
  }

  for (uint8_t i = 0U; i < len; ++i)
  {
    bool ack = (i < (uint8_t)(len - 1U));
    buf[i] = i2c_read_byte(ack);
  }

  i2c_stop();
  return true;
}
