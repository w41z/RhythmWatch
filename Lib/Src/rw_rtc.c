/* Depreciated
   New one integrated RTC function with LVGL+Touchscreen in Core/Src/rtc_manager.c */

// #include "rw_rtc.h"
// #include "lcd.h"

// // global variable for RTC handle, which is used in the RTC read/write functions
// char message[50] = "";   // buffer for sprintf
// struct tm *now;    // global variable to hold the current time read from RTC
// char weekday[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  // array to convert tm_wday (0-6) to weekday string

// // type and variable for Edit mode/Mode switching and field editing
// // enum of system mode (display or edit) and the field being edited (year, month, day, hour, min, sec, wday)
// typedef enum {
//     MODE_DISPLAY,
//     MODE_EDIT
// } SystemMode;

// typedef enum {
//     FIELD_YEAR,
//     FIELD_MONTH,
//     FIELD_MDAY,
//     FIELD_HOUR,
//     FIELD_MIN,
//     FIELD_SEC,
//     FIELD_WDAY,
//     NUM_FIELDS
// } EditField;
// // button state variables
// uint8_t edit_is_pressed = 0;
// uint8_t edit_long_handled = 0;
// uint8_t dec_is_pressed = 0;
// uint8_t dec_long_handled = 0;
// // initialization of system mode and edit field
// SystemMode sys_mode = MODE_DISPLAY;
// EditField curr_field = FIELD_YEAR;
// // edit mode tm struct
// struct tm edit_tm;

// /**
//   * @brief  Enters the RTC Initialization mode.
//   * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
//   *                the configuration information for RTC.
//   * @retval HAL status
//   */
// static HAL_StatusTypeDef RTC_EnterInitMode(RTC_HandleTypeDef *hrtc)
// {
//   uint32_t tickstart = 0U;

//   tickstart = HAL_GetTick();
//   /* Wait till RTC is in INIT state and if Time out is reached exit */
//   while ((hrtc->Instance->CRL & RTC_CRL_RTOFF) == (uint32_t)RESET)
//   {
//     if ((HAL_GetTick() - tickstart) >  RTC_TIMEOUT_VALUE)
//     {
//       return HAL_TIMEOUT;
//     }
//   }

//   /* Disable the write protection for RTC registers */
//   __HAL_RTC_WRITEPROTECTION_DISABLE(hrtc);


//   return HAL_OK;
// }

// /**
//   * @brief  Exit the RTC Initialization mode.
//   * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
//   *                the configuration information for RTC.
//   * @retval HAL status
//   */
// static HAL_StatusTypeDef RTC_ExitInitMode(RTC_HandleTypeDef *hrtc)
// {
//   uint32_t tickstart = 0U;

//   /* Disable the write protection for RTC registers */
//   __HAL_RTC_WRITEPROTECTION_ENABLE(hrtc);

//   tickstart = HAL_GetTick();
//   /* Wait till RTC is in INIT state and if Time out is reached exit */
//   while ((hrtc->Instance->CRL & RTC_CRL_RTOFF) == (uint32_t)RESET)
//   {
//     if ((HAL_GetTick() - tickstart) >  RTC_TIMEOUT_VALUE)
//     {
//       return HAL_TIMEOUT;
//     }
//   }

//   return HAL_OK;
// }

// /**
//   * @brief  Read the time counter available in RTC_CNT registers.
//   * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
//   *                the configuration information for RTC.
//   * @retval Time counter
//   */
// static uint32_t RTC_ReadTimeCounter(RTC_HandleTypeDef *hrtc)
// {
//   uint16_t high1 = 0U, high2 = 0U, low = 0U;
//   uint32_t timecounter = 0U;

//   high1 = READ_REG(hrtc->Instance->CNTH & RTC_CNTH_RTC_CNT);
//   low   = READ_REG(hrtc->Instance->CNTL & RTC_CNTL_RTC_CNT);
//   high2 = READ_REG(hrtc->Instance->CNTH & RTC_CNTH_RTC_CNT);

//   if (high1 != high2)
//   {
//     /* In this case the counter roll over during reading of CNTL and CNTH registers,
//        read again CNTL register then return the counter value */
//     timecounter = (((uint32_t) high2 << 16U) | READ_REG(hrtc->Instance->CNTL & RTC_CNTL_RTC_CNT));
//   }
//   else
//   {
//     /* No counter roll over during reading of CNTL and CNTH registers, counter
//        value is equal to first value of CNTL and CNTH */
//     timecounter = (((uint32_t) high1 << 16U) | low);
//   }

//   return timecounter;
// }

// /**
//   * @brief  Write the time counter in RTC_CNT registers.
//   * @param  hrtc   pointer to a RTC_HandleTypeDef structure that contains
//   *                the configuration information for RTC.
//   * @param  TimeCounter: Counter to write in RTC_CNT registers
//   * @retval HAL status
//   */
// static HAL_StatusTypeDef RTC_WriteTimeCounter(RTC_HandleTypeDef *hrtc, uint32_t TimeCounter)
// {
//   HAL_StatusTypeDef status = HAL_OK;

//   /* Set Initialization mode */
//   if (RTC_EnterInitMode(hrtc) != HAL_OK)
//   {
//     status = HAL_ERROR;
//   }
//   else
//   {
//     /* Set RTC COUNTER MSB word */
//     WRITE_REG(hrtc->Instance->CNTH, (TimeCounter >> 16U));
//     /* Set RTC COUNTER LSB word */
//     WRITE_REG(hrtc->Instance->CNTL, (TimeCounter & RTC_CNTL_RTC_CNT));

//     /* Wait for synchro */
//     if (RTC_ExitInitMode(hrtc) != HAL_OK)
//     {
//       status = HAL_ERROR;
//     }
//   }

//   return status;
// }

// // self-deined RTC_SetTime function, which takes in a struct tm and sets the RTC time accordingly based on the unix timestamp
// HAL_StatusTypeDef RW_RTC_SetTime(struct tm *time)
// {
//     uint32_t unix_time = mktime(time);
//     return RTC_WriteTimeCounter(&hrtc, unix_time);
// }

// // self-defined RTC_GetTime function, which reads the current time from the RTC and returns it as a struct tm based on the unix timestamp
// struct tm* RW_RTC_GetTime()
// {
//     time_t unix_time = RTC_ReadTimeCounter(&hrtc);
//     return gmtime(&unix_time);
// }

// // self-defined RTC_Init function, which initializes the RTC with a default time if it has not been initialized before, and sets a backup register to indicate that the RTC has been initialized
// void RW_RTC_Init()
// {
//     uint32_t init_Flag = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1);
//     if (init_Flag == RTC_INIT_FLAG)
//     {
//         // RTC has been initialized before, no need to set the time again
//         return;
//     }
    
//     if (HAL_RTC_Init(&hrtc) != HAL_OK)
//     {
//         Error_Handler();
//     }

//     struct tm time = {
//         .tm_year = 2026 - 1900, // tm_year is years since 1900
//         .tm_mon = 4 - 1, // tm_mon is 0-11 for Jan-Dec
//         .tm_mday = 20,
//         .tm_hour = 16,
//         .tm_min = 43,
//         .tm_sec = 59,
//     };

//     RW_RTC_SetTime(&time);
//     HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, RTC_INIT_FLAG); // Set backup register to indicate RTC has been initialized
// }

// static void RW_RTC_Showtime(struct tm *time)
// {
//     sprintf(message, "%d-%d-%d %02d:%02d:%02d", time->tm_year + 1900, time->tm_mon + 1, time->tm_mday, time->tm_hour, time->tm_min, time->tm_sec);
//     LCD_DrawString(10, 10, message);
//     char* week = weekday[time->tm_wday];
//     LCD_DrawString(10, 30, week);
// }

// // self-defined function to display the current time on the LCD, which will be called in the main loop
// void RW_RTC_DisplayTime()
// {
//   if (sys_mode == MODE_DISPLAY) {
//       now = RW_RTC_GetTime();
//       RW_RTC_Showtime(now);
//       LCD_DrawString(10, 50, "Displaying...");
//   }
//   else if (sys_mode == MODE_EDIT) {
//       RW_RTC_Showtime(&edit_tm);
//       LCD_DrawString(10, 50, "Editing...");
//   }
// }

// void Next_Edit_Field() {
//     curr_field = (curr_field + 1) % NUM_FIELDS;
// }

// void Increment_Field(struct tm *tm, EditField field)
// {
//     switch (field) {
//         case FIELD_YEAR:
//             tm->tm_year = (tm->tm_year >= 206) ? 0 : tm->tm_year + 1;   // 1900~2106
//             break;
//         case FIELD_MONTH:
//             tm->tm_mon = (tm->tm_mon + 1) % 12;
//             break;
//         case FIELD_MDAY:
//             tm->tm_mday++;
//             if (tm->tm_mday > 31) tm->tm_mday = 1;
//             break;
//         case FIELD_HOUR:
//             tm->tm_hour = (tm->tm_hour + 1) % 24;
//             break;
//         case FIELD_MIN:
//             tm->tm_min = (tm->tm_min + 1) % 60;
//             break;
//         case FIELD_SEC:
//             tm->tm_sec = (tm->tm_sec + 1) % 60;
//             break;
//         case FIELD_WDAY:
//             tm->tm_wday = (tm->tm_wday + 1) % 7;
//             break;
//         default:
//             break;
//     }
// }

// void Decrement_Field(struct tm *tm, EditField field)
// {
//     switch (field) {
//         case FIELD_YEAR:
//             tm->tm_year = (tm->tm_year <= 0) ? 206 : tm->tm_year - 1;
//             break;
//         case FIELD_MONTH:
//             tm->tm_mon = (tm->tm_mon + 11) % 12;
//             break;
//         case FIELD_MDAY:
//             tm->tm_mday--;
//             if (tm->tm_mday < 1) tm->tm_mday = 31;
//             break;
//         case FIELD_HOUR:
//             tm->tm_hour = (tm->tm_hour + 23) % 24;
//             break;
//         case FIELD_MIN:
//             tm->tm_min = (tm->tm_min + 59) % 60;
//             break;
//         case FIELD_SEC:
//             tm->tm_sec = (tm->tm_sec + 59) % 60;
//             break;
//         case FIELD_WDAY:
//             tm->tm_wday = (tm->tm_wday + 6) % 7;
//             break;
//         default:
//             break;
//     }
// }

// void RW_RTC_ButtonHandler()
// {
//   static uint32_t edit_press_start = 0;

//   uint8_t edit_pressed_now = HAL_GPIO_ReadPin(EDIT_BTN_PORT, EDIT_BTN_PIN);
//   // Debug info
//   LCD_DrawString(10, 90, edit_pressed_now ? "EDIT Pressed" : "EDIT Released");
//   if (edit_pressed_now && !edit_is_pressed) {           // just pressed
//         edit_press_start = HAL_GetTick();
//         edit_long_handled = 0;
//         edit_is_pressed = 1;
//   }
//   else if (edit_pressed_now && edit_is_pressed) {       // still pressed
//         if (!edit_long_handled && (HAL_GetTick() - edit_press_start >= 1500)) {   // long press
//             edit_long_handled = 1;
//             if (sys_mode == MODE_DISPLAY) {
//                 sys_mode = MODE_EDIT;
//                 curr_field = FIELD_YEAR;  // start editing from the year field
//                 edit_tm = *RW_RTC_GetTime();  // copy current time to edit_tm for editing
//             }
//             else {
//                 RW_RTC_SetTime(&edit_tm);  // save the edited time to RTC
//                 sys_mode = MODE_DISPLAY;
//             }
//             edit_long_handled = 1;
//         }
//   }
//   else if (!edit_pressed_now && edit_is_pressed) {     // just released
//         if (!edit_long_handled && sys_mode == MODE_EDIT) {   // short press in edit mode
//                 Increment_Field(&edit_tm, curr_field);
//             }
//         edit_is_pressed = 0;
//   }

//   // dec button variables
//   static uint32_t dec_press_start = 0;
//   uint8_t dec_pressed_now = HAL_GPIO_ReadPin(DEC_BTN_PORT, DEC_BTN_PIN);
//   // Debug info
//   LCD_DrawString(10, 70, dec_pressed_now ? "DEC Pressed" : "DEC Released");

//   if (dec_pressed_now && !dec_is_pressed) {             // just pressed
//         dec_press_start = HAL_GetTick();
//         dec_long_handled = 0;
//         dec_is_pressed = 1;
//     }
//     else if (dec_pressed_now && dec_is_pressed) {         // still pressed
//         if (!dec_long_handled && (HAL_GetTick() - dec_press_start >= 1500)) {
//             dec_long_handled = 1;

//             if (sys_mode == MODE_EDIT) {
//                 // next field
//                 Next_Edit_Field();
//             }
//         }
//     }
//     else if (!dec_pressed_now && dec_is_pressed) {        // just released → short press
//         if (!dec_long_handled && sys_mode == MODE_EDIT) {
//             // decrement the current field
//             Decrement_Field(&edit_tm, curr_field);
//         }
//         dec_is_pressed = 0;
//     }
// }


