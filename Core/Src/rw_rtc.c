#include "rw_rtc.h"
#include "stm32f1xx_hal_rtc_ex.h"

static char message[50] = "";
static struct tm *now;

/**
  * @brief  Enters the RTC Initialization mode.
  * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
  *                the configuration information for RTC.
  * @retval HAL status
  */
static HAL_StatusTypeDef RTC_EnterInitMode(RTC_HandleTypeDef *hrtc)
{
  uint32_t tickstart = 0U;

  tickstart = HAL_GetTick();
  /* Wait till RTC is in INIT state and if Time out is reached exit */
  while ((hrtc->Instance->CRL & RTC_CRL_RTOFF) == (uint32_t)RESET)
  {
    if ((HAL_GetTick() - tickstart) >  RTC_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Disable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_DISABLE(hrtc);


  return HAL_OK;
}

/**
  * @brief  Exit the RTC Initialization mode.
  * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
  *                the configuration information for RTC.
  * @retval HAL status
  */
static HAL_StatusTypeDef RTC_ExitInitMode(RTC_HandleTypeDef *hrtc)
{
  uint32_t tickstart = 0U;

  /* Disable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_ENABLE(hrtc);

  tickstart = HAL_GetTick();
  /* Wait till RTC is in INIT state and if Time out is reached exit */
  while ((hrtc->Instance->CRL & RTC_CRL_RTOFF) == (uint32_t)RESET)
  {
    if ((HAL_GetTick() - tickstart) >  RTC_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  return HAL_OK;
}

/**
  * @brief  Read the time counter available in RTC_CNT registers.
  * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
  *                the configuration information for RTC.
  * @retval Time counter
  */
static uint32_t RTC_ReadTimeCounter(RTC_HandleTypeDef *hrtc)
{
  uint16_t high1 = 0U, high2 = 0U, low = 0U;
  uint32_t timecounter = 0U;

  high1 = READ_REG(hrtc->Instance->CNTH & RTC_CNTH_RTC_CNT);
  low   = READ_REG(hrtc->Instance->CNTL & RTC_CNTL_RTC_CNT);
  high2 = READ_REG(hrtc->Instance->CNTH & RTC_CNTH_RTC_CNT);

  if (high1 != high2)
  {
    /* In this case the counter roll over during reading of CNTL and CNTH registers,
       read again CNTL register then return the counter value */
    timecounter = (((uint32_t) high2 << 16U) | READ_REG(hrtc->Instance->CNTL & RTC_CNTL_RTC_CNT));
  }
  else
  {
    /* No counter roll over during reading of CNTL and CNTH registers, counter
       value is equal to first value of CNTL and CNTH */
    timecounter = (((uint32_t) high1 << 16U) | low);
  }

  return timecounter;
}

/**
  * @brief  Write the time counter in RTC_CNT registers.
  * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
  *                the configuration information for RTC.
  * @param  TimeCounter: Counter to write in RTC_CNT registers
  * @retval HAL status
  */
static HAL_StatusTypeDef RTC_WriteTimeCounter(RTC_HandleTypeDef *hrtc, uint32_t TimeCounter)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Set Initialization mode */
  if (RTC_EnterInitMode(hrtc) != HAL_OK)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Set RTC COUNTER MSB word */
    WRITE_REG(hrtc->Instance->CNTH, (TimeCounter >> 16U));
    /* Set RTC COUNTER LSB word */
    WRITE_REG(hrtc->Instance->CNTL, (TimeCounter & RTC_CNTL_RTC_CNT));

    /* Wait for synchro */
    if (RTC_ExitInitMode(hrtc) != HAL_OK)
    {
      status = HAL_ERROR;
    }
  }

  return status;
}

// self-deined RTC_SetTime function, which takes in a struct tm and sets the RTC time accordingly based on the unix timestamp
HAL_StatusTypeDef RW_RTC_SetTime(struct tm *time)
{
    uint32_t unix_time = mktime(time);
    return RTC_WriteTimeCounter(&hrtc, unix_time);
}

// self-defined RTC_GetTime function, which reads the current time from the RTC and returns it as a struct tm based on the unix timestamp
struct tm* RW_RTC_GetTime()
{
    time_t unix_time = RTC_ReadTimeCounter(&hrtc);
    return gmtime(&unix_time);
}

// self-defined RTC_Init function, which initializes the RTC with a default time if it has not been initialized before, and sets a backup register to indicate that the RTC has been initialized
void RW_RTC_Init()
{
    uint32_t init_Flag = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1);
    if (init_Flag == RTC_INIT_FLAG)
    {
        // RTC has been initialized before, no need to set the time again
        return;
    }
    
    if (HAL_RTC_Init(&hrtc) != HAL_OK)
    {
        Error_Handler();
    }

    struct tm time = {
        .tm_year = 2026 - 1900, // tm_year is years since 1900
        .tm_mon = 1 - 1, // tm_mon is 0-11 for Jan-Dec
        .tm_mday = 1,
        .tm_hour = 23,
        .tm_min = 59,
        .tm_sec = 59,
    };

    RW_RTC_SetTime(&time);
    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, RTC_INIT_FLAG); // Set backup register to indicate RTC has been initialized
}

// self-defined function to display the current time on the LCD, which will be called in the main loop
void RW_RTC_DisplayTime()
{
    now = RW_RTC_GetTime();
    // Format the time as "YYYY-MM-DD HH:MM:SS" and display it on the LCD
    sprintf(message, "%d-%d-%d %02d:%02d:%02d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
    LCD_DrawString(10, 10, message);
    HAL_Delay(1000); // Update every second
}