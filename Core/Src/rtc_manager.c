#include "rtc_manager.h"
#include "stm32f1xx_hal.h"

// global variable for RTC handle, which is used in the RTC read/write functions
char message[50] = "";   // buffer for sprintf
struct tm *now;    // global variable to hold the current time read from RTC
char weekday[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  // array to convert tm_wday (0-6) to weekday string

// type and variable for Edit mode/Mode switching and field editing
// enum of system mode (display or edit) and the field being edited (year, month, day, hour, min, sec, wday)
typedef enum {
    MODE_DISPLAY,
    MODE_EDIT
} SystemMode;

typedef enum {
    FIELD_YEAR,
    FIELD_MONTH,
    FIELD_MDAY,
    FIELD_HOUR,
    FIELD_MIN,
    FIELD_SEC,
    NUM_FIELDS
} EditField;

// initialization of system mode and edit field
SystemMode sys_mode = MODE_DISPLAY;
EditField curr_field = FIELD_YEAR;
// edit mode tm struct
struct tm edit_tm;


// This remembers the last screen pointer so we know when GUI Guider makes a new one
static lv_obj_t * last_known_rtc_screen = NULL;

// =========================================================
// THE BUTTON LOGIC (Pure C)
// =========================================================
static bool long_press_flag = false;

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
        .tm_mon = 5 - 1, // tm_mon is 0-11 for Jan-Dec
        .tm_mday = 4,
        .tm_hour = 9,
        .tm_min = 0,
        .tm_sec = 0,
    };

    RW_RTC_SetTime(&time);
    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, RTC_INIT_FLAG); // Set backup register to indicate RTC has been initialized
}

void Next_Edit_Field() {
    curr_field = (curr_field + 1) % NUM_FIELDS;
}

void Increment_Field(struct tm *tm, EditField field)
{
    switch (field) {
        case FIELD_YEAR:
            tm->tm_year = (tm->tm_year >= 206) ? 0 : tm->tm_year + 1;   // 1900~2106
            break;
        case FIELD_MONTH:
            tm->tm_mon = (tm->tm_mon + 1) % 12;
            break;
        case FIELD_MDAY:
            tm->tm_mday++;
            if (tm->tm_mday > 31) tm->tm_mday = 1;
            break;
        case FIELD_HOUR:
            tm->tm_hour = (tm->tm_hour + 1) % 24;
            break;
        case FIELD_MIN:
            tm->tm_min = (tm->tm_min + 1) % 60;
            break;
        case FIELD_SEC:
            tm->tm_sec = (tm->tm_sec + 1) % 60;
            break;
        default:
            break;
    }
}

void Decrement_Field(struct tm *tm, EditField field)
{
    switch (field) {
        case FIELD_YEAR:
            tm->tm_year = (tm->tm_year <= 0) ? 206 : tm->tm_year - 1;
            break;
        case FIELD_MONTH:
            tm->tm_mon = (tm->tm_mon + 11) % 12;
            break;
        case FIELD_MDAY:
            tm->tm_mday--;
            if (tm->tm_mday < 1) tm->tm_mday = 31;
            break;
        case FIELD_HOUR:
            tm->tm_hour = (tm->tm_hour + 23) % 24;
            break;
        case FIELD_MIN:
            tm->tm_min = (tm->tm_min + 59) % 60;
            break;
        case FIELD_SEC:
            tm->tm_sec = (tm->tm_sec + 59) % 60;
            break;
        default:
            break;
    }
}

static void rtc_button_handler(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);
    lv_ui * ui = (lv_ui *)lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    // 1. MODE BUTTON
    if (btn == ui->rtc_screen_modebtn) {
        if (code == LV_EVENT_LONG_PRESSED && sys_mode == MODE_EDIT) {
        	long_press_flag = true;
            // Save and Exit Edit Mode
            RW_RTC_SetTime(&edit_tm);
            sys_mode = MODE_DISPLAY;
            lv_label_set_text(ui->rtc_screen_mode_label, "Display");
        }
        else if (code == LV_EVENT_RELEASED){

        }
        else if (code == LV_EVENT_CLICKED) {
        	if(long_press_flag) {
        		long_press_flag = false;
        		return;
        	}
        	if (sys_mode != MODE_EDIT) {
				// Switch from Display -> Edit
				sys_mode = MODE_EDIT;
				curr_field = FIELD_YEAR;
				edit_tm = *RW_RTC_GetTime();  // copy current time to edit_tm for editing
				lv_label_set_text(ui->rtc_screen_mode_label, "Edit: Year");
			}
        }
    }

    if (sys_mode != MODE_EDIT) return; // Ignore other buttons if not editing

    // 2. NEXT BUTTON
    if (btn == ui->rtc_screen_nextbtn && code == LV_EVENT_CLICKED) {
        Next_Edit_Field();
        const char* f[] = {"Year", "Month", "Day", "Hour", "Min", "Sec"};
        snprintf(message, sizeof(message), "Edit: %s", f[curr_field]);
        lv_label_set_text(ui->rtc_screen_mode_label, message);
    }

    // 3. ADD BUTTON
    if (btn == ui->rtc_screen_addbtn && code == LV_EVENT_CLICKED) {
        Increment_Field(&edit_tm, curr_field);
    }

    // 4. MINUS BUTTON
    if (btn == ui->rtc_screen_minusbtn && code == LV_EVENT_CLICKED) {
        Decrement_Field(&edit_tm, curr_field);
    }
}

static void rtc_screen_delete_handler(lv_event_t * e)
{
    if(lv_event_get_code(e) != LV_EVENT_DELETE) return;

    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

    if(ui) {
        ui->rtc_screen = NULL;
        ui->rtc_screen_modebtn = NULL;
        ui->rtc_screen_nextbtn = NULL;
        ui->rtc_screen_addbtn = NULL;
        ui->rtc_screen_minusbtn = NULL;
    }

    last_known_rtc_screen = NULL;
    sys_mode = MODE_DISPLAY;
    long_press_flag = false;
}

static void RW_RTC_Showtime(struct tm *time, lv_ui *ui)
{
    snprintf(message, sizeof(message), "%04d-%02d-%02d", time->tm_year + 1900, time->tm_mon + 1, time->tm_mday);
    lv_label_set_text(ui->rtc_screen_label_rtc_date, message);

    snprintf(message, sizeof(message), "%02d:%02d:%02d", time->tm_hour, time->tm_min, time->tm_sec);
    lv_label_set_text(ui->rtc_screen_label_rtc_time, message);
    
    char* week = weekday[time->tm_wday];
    lv_label_set_text(ui->rtc_screen_label_rtc_day, week);

}


// =========================================================
// THE WATCHDOG & UI UPDATER
// =========================================================
void RTC_Manager_Task(lv_ui *ui) {
    // 1. DETECT SCREEN CHANGES (The Bulletproof Linker)
    // If GUI Guider made a new screen pointer, it means we just entered the page!
    if (ui->rtc_screen != NULL && ui->rtc_screen != last_known_rtc_screen) {

        // Link the buttons to our C logic IMMEDIATELY
        lv_obj_add_event_cb(ui->rtc_screen_modebtn, rtc_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->rtc_screen_nextbtn, rtc_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->rtc_screen_addbtn, rtc_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->rtc_screen_minusbtn, rtc_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->rtc_screen, rtc_screen_delete_handler, LV_EVENT_DELETE, ui);
        // Save this pointer so we don't link them twice
        last_known_rtc_screen = ui->rtc_screen;
    }

    // 2. UPDATE THE LABELS
    // Only update if the RTC screen is the one actually being looked at
    if (ui->rtc_screen == NULL || lv_scr_act() != ui->rtc_screen) {
        return;
    }

    if (sys_mode == MODE_EDIT) {
        RW_RTC_Showtime(&edit_tm, ui);
    } else {
        now = RW_RTC_GetTime();
        RW_RTC_Showtime(now, ui);
    }
}
