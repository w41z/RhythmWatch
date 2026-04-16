#include "oximeter.h"

#include "max30102.h"
#include <math.h>

#define OXI_WINDOW_SIZE          240U
#define OXI_SAMPLE_RATE_HZ       100.0f
#define OXI_MIN_PEAK_DISTANCE    30U
#define OXI_MIN_FINGER_IR        5000U
#define OXI_HR_MAX_STEP          6.0f
#define OXI_SPO2_MAX_STEP        1.0f

static uint32_t red_buf[OXI_WINDOW_SIZE];
static uint32_t ir_buf[OXI_WINDOW_SIZE];
static uint16_t buf_index = 0U;
static uint8_t buffer_filled = 0U;
static uint16_t no_data_cycles = 0U;
static float filtered_hr_bpm = 0.0f;
static float filtered_spo2_percent = 0.0f;
static bool filtered_hr_valid = false;
static bool filtered_spo2_valid = false;

static float clampf(float x, float lo, float hi)
{
  if (x < lo)
  {
    return lo;
  }
  if (x > hi)
  {
    return hi;
  }
  return x;
}

static float compute_mean_u32(const uint32_t *x, uint16_t n)
{
  uint64_t acc = 0ULL;
  for (uint16_t i = 0U; i < n; ++i)
  {
    acc += x[i];
  }
  return (float)acc / (float)n;
}

static float compute_std_u32(const uint32_t *x, uint16_t n, float mean)
{
  float sum_sq = 0.0f;
  for (uint16_t i = 0U; i < n; ++i)
  {
    float d = (float)x[i] - mean;
    sum_sq += d * d;
  }
  return sqrtf(sum_sq / (float)n);
}

static bool compute_heart_rate_autocorr(const uint32_t *ir, uint16_t n, float *bpm)
{
  float mean = compute_mean_u32(ir, n);

  uint16_t min_lag = (uint16_t)(OXI_SAMPLE_RATE_HZ * 60.0f / 220.0f);
  uint16_t max_lag = (uint16_t)(OXI_SAMPLE_RATE_HZ * 60.0f / 45.0f);
  if (max_lag >= n)
  {
    max_lag = (uint16_t)(n - 1U);
  }
  if (min_lag < 2U || min_lag >= max_lag)
  {
    return false;
  }

  float best_corr = 0.0f;
  uint16_t best_lag = 0U;
  for (uint16_t lag = min_lag; lag <= max_lag; ++lag)
  {
    float corr = 0.0f;
    for (uint16_t i = 0U; i + lag < n; ++i)
    {
      float a = (float)ir[i] - mean;
      float b = (float)ir[i + lag] - mean;
      corr += a * b;
    }

    if (corr > best_corr)
    {
      best_corr = corr;
      best_lag = lag;
    }
  }

  if (best_lag == 0U || best_corr <= 0.0f)
  {
    return false;
  }

  *bpm = 60.0f * OXI_SAMPLE_RATE_HZ / (float)best_lag;
  return true;
}

static bool compute_heart_rate(const uint32_t *ir, uint16_t n, float *bpm)
{
  float mean = compute_mean_u32(ir, n);
  float std = compute_std_u32(ir, n, mean);
  float threshold = mean + 0.10f * std;

  uint16_t peak_indices[10] = {0};
  uint8_t peak_count = 0U;
  uint16_t last_peak = 0U;

  for (uint16_t i = 2U; i + 2U < n; ++i)
  {
    bool is_peak =
      ((float)ir[i] > threshold) &&
      (ir[i] > ir[i - 1U]) &&
      (ir[i] >= ir[i + 1U]) &&
      (ir[i] > ir[i - 2U]) &&
      (ir[i] >= ir[i + 2U]);

    if (!is_peak)
    {
      continue;
    }

    if (peak_count > 0U && (uint16_t)(i - last_peak) < OXI_MIN_PEAK_DISTANCE)
    {
      continue;
    }

    if (peak_count < (uint8_t)(sizeof(peak_indices) / sizeof(peak_indices[0])))
    {
      peak_indices[peak_count++] = i;
      last_peak = i;
    }
  }

  if (peak_count < 2U)
  {
    return false;
  }

  float interval_sum = 0.0f;
  uint8_t intervals = 0U;
  for (uint8_t i = 1U; i < peak_count; ++i)
  {
    interval_sum += (float)(peak_indices[i] - peak_indices[i - 1U]);
    intervals++;
  }

  if (intervals == 0U)
  {
    return false;
  }

  float avg_interval = interval_sum / (float)intervals;
  if (avg_interval < 1.0f)
  {
    return false;
  }

  *bpm = 60.0f * OXI_SAMPLE_RATE_HZ / avg_interval;
  return true;
}

static bool compute_spo2(const uint32_t *red, const uint32_t *ir, uint16_t n, float *spo2)
{
  float red_dc = compute_mean_u32(red, n);
  float ir_dc = compute_mean_u32(ir, n);

  if (red_dc < 1.0f || ir_dc < 1.0f)
  {
    return false;
  }

  uint32_t red_min = red[0];
  uint32_t red_max = red[0];
  uint32_t ir_min = ir[0];
  uint32_t ir_max = ir[0];
  for (uint16_t i = 1U; i < n; ++i)
  {
    if (red[i] < red_min) red_min = red[i];
    if (red[i] > red_max) red_max = red[i];
    if (ir[i] < ir_min) ir_min = ir[i];
    if (ir[i] > ir_max) ir_max = ir[i];
  }

  float red_ac = ((float)red_max - (float)red_min) * 0.5f;
  float ir_ac = ((float)ir_max - (float)ir_min) * 0.5f;

  if (red_ac < 1.0f || ir_ac < 1.0f)
  {
    return false;
  }

  float r = (red_ac / red_dc) / (ir_ac / ir_dc);
  float estimate = 104.0f - 17.0f * r;
  *spo2 = clampf(estimate, 70.0f, 100.0f);
  return true;
}

bool oximeter_init(void)
{
  buf_index = 0U;
  buffer_filled = 0U;
  no_data_cycles = 0U;
  filtered_hr_bpm = 0.0f;
  filtered_spo2_percent = 0.0f;
  filtered_hr_valid = false;
  filtered_spo2_valid = false;
  return max30102_init();
}

static float smooth_limited(float previous, float raw, float max_step, float alpha)
{
  float delta = raw - previous;
  if (delta > max_step)
  {
    raw = previous + max_step;
  }
  else if (delta < -max_step)
  {
    raw = previous - max_step;
  }

  return previous + alpha * (raw - previous);
}

bool oximeter_process(oximeter_reading_t *reading)
{
  if (reading == 0)
  {
    return false;
  }

  uint8_t count = max30102_get_sample_count();
  if (count == 0U)
  {
    if (no_data_cycles < 0xFFFFU)
    {
      no_data_cycles++;
    }

    /* Recover from occasional sensor/FIFO stall without manual reset. */
    if (no_data_cycles > 200U)
    {
      (void)max30102_init();
      no_data_cycles = 0U;
    }

    return false;
  }

  no_data_cycles = 0U;

  max30102_sample_t sample;
  bool got_new = false;

  while (count-- > 0U)
  {
    if (!max30102_read_sample(&sample))
    {
      break;
    }

    red_buf[buf_index] = sample.red;
    ir_buf[buf_index] = sample.ir;
    buf_index = (uint16_t)((buf_index + 1U) % OXI_WINDOW_SIZE);
    if (buffer_filled < OXI_WINDOW_SIZE)
    {
      buffer_filled++;
    }
    got_new = true;
  }

  if (!got_new)
  {
    return false;
  }

  reading->red_level = sample.red;
  reading->ir_level = sample.ir;
  reading->finger_detected = (sample.ir > OXI_MIN_FINGER_IR);
  reading->heart_rate_valid = false;
  reading->spo2_valid = false;

  if (buffer_filled < OXI_WINDOW_SIZE || !reading->finger_detected)
  {
    if (!reading->finger_detected)
    {
      filtered_hr_valid = false;
      filtered_spo2_valid = false;
    }
    return true;
  }

  uint32_t red_tmp[OXI_WINDOW_SIZE];
  uint32_t ir_tmp[OXI_WINDOW_SIZE];

  uint16_t idx = buf_index;
  for (uint16_t i = 0U; i < OXI_WINDOW_SIZE; ++i)
  {
    red_tmp[i] = red_buf[idx];
    ir_tmp[i] = ir_buf[idx];
    idx = (uint16_t)((idx + 1U) % OXI_WINDOW_SIZE);
  }

  float bpm = 0.0f;
  float spo2 = 0.0f;

  if (compute_heart_rate(ir_tmp, OXI_WINDOW_SIZE, &bpm) ||
      compute_heart_rate_autocorr(ir_tmp, OXI_WINDOW_SIZE, &bpm))
  {
    bpm = clampf(bpm, 35.0f, 220.0f);
    if (filtered_hr_valid)
    {
      filtered_hr_bpm = smooth_limited(filtered_hr_bpm, bpm, OXI_HR_MAX_STEP, 0.30f);
    }
    else
    {
      filtered_hr_bpm = bpm;
      filtered_hr_valid = true;
    }

    reading->heart_rate_bpm = filtered_hr_bpm;
    reading->heart_rate_valid = true;
  }

  if (compute_spo2(red_tmp, ir_tmp, OXI_WINDOW_SIZE, &spo2))
  {
    spo2 = clampf(spo2, 70.0f, 100.0f);
    if (filtered_spo2_valid)
    {
      filtered_spo2_percent = smooth_limited(filtered_spo2_percent, spo2, OXI_SPO2_MAX_STEP, 0.25f);
    }
    else
    {
      filtered_spo2_percent = spo2;
      filtered_spo2_valid = true;
    }

    reading->spo2_percent = filtered_spo2_percent;
    reading->spo2_valid = true;
  }

  return true;
}
