#ifndef OXIMETER_H
#define OXIMETER_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  float heart_rate_bpm;
  float spo2_percent;
  uint32_t ir_level;
  uint32_t red_level;
  bool heart_rate_valid;
  bool spo2_valid;
  bool finger_detected;
} oximeter_reading_t;

bool oximeter_init(void);
bool oximeter_process(oximeter_reading_t *reading);

#endif
