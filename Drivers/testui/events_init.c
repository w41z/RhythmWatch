/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "weather_manager.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void home_WEATHER_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.weather_screen, guider_ui.weather_screen_del, &guider_ui.home_del, setup_scr_weather_screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void home_DHT11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.dht11_screen, guider_ui.dht11_screen_del, &guider_ui.home_del, setup_scr_dht11_screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void home_RTC_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.rtc_screen, guider_ui.rtc_screen_del, &guider_ui.home_del, setup_scr_rtc_screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void home_MUSIC_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.music_screen, guider_ui.music_screen_del, &guider_ui.home_del, setup_scr_music_screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_WEATHER, home_WEATHER_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_DHT11, home_DHT11_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_RTC, home_RTC_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_MUSIC, home_MUSIC_event_handler, LV_EVENT_ALL, ui);
}

static void rtc_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.rtc_screen_del, setup_scr_home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_rtc_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->rtc_screen_btn_1, rtc_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void dht11_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.dht11_screen_del, setup_scr_home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_dht11_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->dht11_screen_btn_1, dht11_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void music_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.music_screen_del, setup_scr_home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_music_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->music_screen_btn_1, music_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void weather_screen_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.weather_screen_del, setup_scr_home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void weather_screen_fetch_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        // Only set the flag; actual fetch happens in Weather_Manager_Task
        Weather_Manager_RequestFetch();
        
        // Update UI labels to show fetching status
        lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
        if (ui) {
            lv_label_set_text(ui->weather_screen_s_stat, "Starting...");
            lv_label_set_text(ui->weather_screen_w_con, "connecting...");
            lv_label_set_text(ui->weather_screen_w_rt, "connecting...");
            lv_label_set_text(ui->weather_screen_w_at, "connecting...");
        }
        break;
    }
    default:
        break;
    }
}

void events_init_weather_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->weather_screen_btn_1, weather_screen_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->weather_screen_fetch, weather_screen_fetch_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
