#include "max30102.h"

#include "rw_soft_i2c.h"
#include "stm32f1xx_hal.h"

#define REG_INTR_STATUS_1      0x00U
#define REG_INTR_STATUS_2      0x01U
#define REG_INTR_ENABLE_1      0x02U
#define REG_INTR_ENABLE_2      0x03U
#define REG_FIFO_WR_PTR        0x04U
#define REG_OVF_COUNTER        0x05U
#define REG_FIFO_RD_PTR        0x06U
#define REG_FIFO_DATA          0x07U
#define REG_FIFO_CONFIG        0x08U
#define REG_MODE_CONFIG        0x09U
#define REG_SPO2_CONFIG        0x0AU
#define REG_LED1_PA            0x0CU
#define REG_LED2_PA            0x0DU
#define REG_MULTI_LED_CTRL1    0x11U
#define REG_MULTI_LED_CTRL2    0x12U
#define REG_PART_ID            0xFFU

static max30102_init_status_t g_last_init_status = MAX30102_INIT_OK;
static uint8_t g_last_part_id = 0x00U;

static bool write_reg(uint8_t reg, uint8_t value)
{
  return rw_soft_i2c_write_reg(MAX30102_I2C_ADDR, reg, value);
}

static bool read_reg(uint8_t reg, uint8_t *value)
{
  return rw_soft_i2c_read_reg(MAX30102_I2C_ADDR, reg, value);
}

static bool read_regs(uint8_t reg, uint8_t *buf, uint8_t len)
{
  return rw_soft_i2c_read_regs(MAX30102_I2C_ADDR, reg, buf, len);
}

static bool write_reg_retry(uint8_t reg, uint8_t value, uint8_t retries)
{
  while (retries-- > 0U)
  {
    if (write_reg(reg, value))
    {
      return true;
    }
    HAL_Delay(2U);
  }
  return false;
}

static bool read_reg_retry(uint8_t reg, uint8_t *value, uint8_t retries)
{
  while (retries-- > 0U)
  {
    if (read_reg(reg, value))
    {
      return true;
    }
    HAL_Delay(2U);
  }
  return false;
}

bool max30102_init(void)
{
  g_last_init_status = MAX30102_INIT_OK;
  g_last_part_id = 0x00U;

  rw_soft_i2c_init();

  if (!write_reg_retry(REG_MODE_CONFIG, 0x40U, 5U))
  {
    g_last_init_status = MAX30102_INIT_I2C_FAIL;
    return false;
  }
  HAL_Delay(50U);

  uint8_t part_id = 0U;
  if (read_reg_retry(REG_PART_ID, &part_id, 5U))
  {
    g_last_part_id = part_id;
    if ((part_id != 0x15U) && (part_id != 0x11U))
    {
      g_last_init_status = MAX30102_INIT_PART_ID_WARN;
    }
  }

  if (!write_reg_retry(REG_INTR_ENABLE_1, 0x00U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }
  if (!write_reg_retry(REG_INTR_ENABLE_2, 0x00U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }

  if (!write_reg_retry(REG_FIFO_WR_PTR, 0x00U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }
  if (!write_reg_retry(REG_OVF_COUNTER, 0x00U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }
  if (!write_reg_retry(REG_FIFO_RD_PTR, 0x00U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }

  /* Enable FIFO rollover so sensor keeps producing samples continuously. */
  if (!write_reg_retry(REG_FIFO_CONFIG, 0x1FU, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }

  if (!write_reg_retry(REG_MODE_CONFIG, 0x03U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }

  if (!write_reg_retry(REG_SPO2_CONFIG, 0x27U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }

  /* LED1 = RED, LED2 = IR on MAX30102 boards. */
  if (!write_reg_retry(REG_LED1_PA, 0x6FU, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }
  if (!write_reg_retry(REG_LED2_PA, 0x4FU, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }

  if (!write_reg_retry(REG_MULTI_LED_CTRL1, 0x00U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }
  if (!write_reg_retry(REG_MULTI_LED_CTRL2, 0x00U, 3U))
  {
    g_last_init_status = MAX30102_INIT_CONFIG_FAIL;
    return false;
  }

  uint8_t dummy = 0U;
  (void)read_reg(REG_INTR_STATUS_1, &dummy);
  (void)read_reg(REG_INTR_STATUS_2, &dummy);

  return true;
}

max30102_init_status_t max30102_get_last_init_status(void)
{
  return g_last_init_status;
}

uint8_t max30102_get_last_part_id(void)
{
  return g_last_part_id;
}

uint8_t max30102_get_sample_count(void)
{
  uint8_t wr = 0U;
  uint8_t rd = 0U;

  if (!read_reg(REG_FIFO_WR_PTR, &wr))
  {
    return 0U;
  }
  if (!read_reg(REG_FIFO_RD_PTR, &rd))
  {
    return 0U;
  }

  uint8_t count = (uint8_t)((wr - rd) & 0x1FU);

  if (count == 0U)
  {
    uint8_t st1 = 0U;
    if (read_reg(REG_INTR_STATUS_1, &st1) && ((st1 & 0x40U) != 0U))
    {
      /* PPG_RDY is set but pointers are momentarily equal; allow one read. */
      count = 1U;
    }
  }

  return count;
}

bool max30102_read_sample(max30102_sample_t *sample)
{
  if (sample == 0)
  {
    return false;
  }

  uint8_t raw[6] = {0};
  if (!read_regs(REG_FIFO_DATA, raw, 6U))
  {
    return false;
  }

  sample->red = (uint32_t)(((uint32_t)raw[0] << 16U) | ((uint32_t)raw[1] << 8U) | raw[2]) & 0x3FFFFU;
  sample->ir = (uint32_t)(((uint32_t)raw[3] << 16U) | ((uint32_t)raw[4] << 8U) | raw[5]) & 0x3FFFFU;
  return true;
}
