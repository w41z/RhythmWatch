#ifndef MAX30102_H
#define MAX30102_H

#include <stdbool.h>
#include <stdint.h>

#define MAX30102_I2C_ADDR 0x57U

typedef struct
{
  uint32_t red;
  uint32_t ir;
} max30102_sample_t;

typedef enum
{
  MAX30102_INIT_OK = 0,
  MAX30102_INIT_I2C_FAIL,
  MAX30102_INIT_CONFIG_FAIL,
  MAX30102_INIT_PART_ID_WARN
} max30102_init_status_t;

bool max30102_init(void);
bool max30102_read_sample(max30102_sample_t *sample);
uint8_t max30102_get_sample_count(void);
max30102_init_status_t max30102_get_last_init_status(void);
uint8_t max30102_get_last_part_id(void);

#endif
