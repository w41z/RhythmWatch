#include "rtc_manager.h"
#include "main.h"
#include <stdio.h>

extern RTC_HandleTypeDef hrtc;

// Variables to remember what we are editing
static int is_edit_mode = 0;
static int current_field = 0; // 0:Year, 1:Month, 2:Day, 3:Hour, 4:Min, 5:Sec
static RTC_DateTypeDef tempDate;
static RTC_TimeTypeDef tempTime;

// This remembers the last screen pointer so we know when GUI Guider makes a new one
static lv_obj_t * last_known_rtc_screen = NULL;


uint8_t Calculate_Day_Of_Week(uint8_t y, uint8_t m, uint8_t d) {
    uint16_t year = 2000 + y;
    if (m < 3) {
        m += 12;
        year--;
    }
    int h = (d + (13 * (m + 1) / 5) + (year % 100) + ((year % 100) / 4) + ((year / 100) / 4) + (5 * (year / 100))) % 7;
    uint8_t map[] = {6,     7,     1,     2,     3,     4,     5};
    return map[h];
}
// =========================================================
// THE BUTTON LOGIC (Pure C)
// =========================================================
static bool long_press_flag = false;

static void rtc_button_handler(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);
    lv_ui * ui = (lv_ui *)lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    // 1. MODE BUTTON
    if (btn == ui->rtc_screen_modebtn) {
        if (code == LV_EVENT_LONG_PRESSED && is_edit_mode) {
        	long_press_flag = true;
            // Save and Exit Edit Mode
            is_edit_mode = 0;
            tempDate.WeekDay = Calculate_Day_Of_Week(tempDate.Year, tempDate.Month, tempDate.Date);
            HAL_RTC_SetTime(&hrtc, &tempTime, RTC_FORMAT_BIN);
            HAL_RTC_SetDate(&hrtc, &tempDate, RTC_FORMAT_BIN);
            lv_label_set_text(ui->rtc_screen_mode_label, "Display");
        }
        else if (code == LV_EVENT_RELEASED){

        }
        else if (code == LV_EVENT_CLICKED) {
        	if(long_press_flag){
        		long_press_flag = false;
        		return;
        	}
        	if (!is_edit_mode) {
				// Switch from Display -> Edit
				is_edit_mode = 1;
				current_field = 0;
				HAL_RTC_GetTime(&hrtc, &tempTime, RTC_FORMAT_BIN);
				HAL_RTC_GetDate(&hrtc, &tempDate, RTC_FORMAT_BIN);
				lv_label_set_text(ui->rtc_screen_mode_label, "Edit: Year");
			}
        }
    }

    if (!is_edit_mode) return; // Ignore other buttons if not editing

    // 2. NEXT BUTTON
    if (btn == ui->rtc_screen_nextbtn && code == LV_EVENT_CLICKED) {
        current_field = (current_field + 1) % 6;
        const char* f[] = {"Year", "Month", "Day", "Hour", "Min", "Sec"};
        char buf[32];
        snprintf(buf, sizeof(buf), "Edit: %s", f[current_field]);
        lv_label_set_text(ui->rtc_screen_mode_label, buf);
    }

    // 3. ADD BUTTON
    if (btn == ui->rtc_screen_addbtn && code == LV_EVENT_CLICKED) {
        if (current_field == 0) tempDate.Year++;
        else if (current_field == 1) tempDate.Month = (tempDate.Month % 12) + 1;
        else if (current_field == 2) tempDate.Date = (tempDate.Date % 31) + 1;
        else if (current_field == 3) tempTime.Hours = (tempTime.Hours + 1) % 24;
        else if (current_field == 4) tempTime.Minutes = (tempTime.Minutes + 1) % 60;
        else if (current_field == 5) tempTime.Seconds = (tempTime.Seconds + 1) % 60;
    }

    // 4. MINUS BUTTON
    if (btn == ui->rtc_screen_minusbtn && code == LV_EVENT_CLICKED) {
        if (current_field == 0) tempDate.Year--;
        else if (current_field == 1) tempDate.Month = (tempDate.Month == 1) ? 12 : tempDate.Month - 1;
        else if (current_field == 2) tempDate.Date = (tempDate.Date == 1) ? 31 : tempDate.Date - 1;
        else if (current_field == 3) tempTime.Hours = (tempTime.Hours == 0) ? 23 : tempTime.Hours - 1;
        else if (current_field == 4) tempTime.Minutes = (tempTime.Minutes == 0) ? 59 : tempTime.Minutes - 1;
        else if (current_field == 5) tempTime.Seconds = (tempTime.Seconds == 0) ? 59 : tempTime.Seconds - 1;
    }
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

        // Save this pointer so we don't link them twice
        last_known_rtc_screen = ui->rtc_screen;
    }

    // 2. UPDATE THE LABELS
    // Only update if the RTC screen is the one actually being looked at
    if (ui->rtc_screen == NULL || lv_scr_act() != ui->rtc_screen) {
        return;
    }

    char buf[32];
    RTC_DateTypeDef dDate;
    RTC_TimeTypeDef dTime;

    if (is_edit_mode) {
        dDate = tempDate;
        dTime = tempTime;
    } else {
        HAL_RTC_GetTime(&hrtc, &dTime, RTC_FORMAT_BIN);
        HAL_RTC_GetDate(&hrtc, &dDate, RTC_FORMAT_BIN);
    }

    snprintf(buf, sizeof(buf), "20%02d-%02d-%02d", dDate.Year, dDate.Month, dDate.Date);
    lv_label_set_text(ui->rtc_screen_label_rtc_date, buf);

    snprintf(buf, sizeof(buf), "%02d:%02d:%02d", dTime.Hours, dTime.Minutes, dTime.Seconds);
    lv_label_set_text(ui->rtc_screen_label_rtc_time, buf);

    const char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    if (dDate.WeekDay >= 1 && dDate.WeekDay <= 7) {
        lv_label_set_text(ui->rtc_screen_label_rtc_day, days[dDate.WeekDay-1]);
    } else{
    	lv_label_set_text(ui->rtc_screen_label_rtc_day, "Sunday");
    }
}
