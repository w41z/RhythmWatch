/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *home;
	bool home_del;
	lv_obj_t *home_cont_1;
	lv_obj_t *home_WEATHER;
	lv_obj_t *home_WEATHER_label;
	lv_obj_t *home_DHT11;
	lv_obj_t *home_DHT11_label;
	lv_obj_t *home_RTC;
	lv_obj_t *home_RTC_label;
	lv_obj_t *home_label_1;
	lv_obj_t *home_MUSIC;
	lv_obj_t *home_MUSIC_label;
	lv_obj_t *rtc_screen;
	bool rtc_screen_del;
	lv_obj_t *rtc_screen_RTC;
	lv_obj_t *rtc_screen_label_rtc_date;
	lv_obj_t *rtc_screen_label_rtc_time;
	lv_obj_t *rtc_screen_label_rtc_day;
	lv_obj_t *rtc_screen_btn_1;
	lv_obj_t *rtc_screen_btn_1_label;
	lv_obj_t *rtc_screen_modebtn;
	lv_obj_t *rtc_screen_modebtn_label;
	lv_obj_t *rtc_screen_mode_label;
	lv_obj_t *rtc_screen_nextbtn;
	lv_obj_t *rtc_screen_nextbtn_label;
	lv_obj_t *rtc_screen_minusbtn;
	lv_obj_t *rtc_screen_minusbtn_label;
	lv_obj_t *rtc_screen_addbtn;
	lv_obj_t *rtc_screen_addbtn_label;
	lv_obj_t *dht11_screen;
	bool dht11_screen_del;
	lv_obj_t *dht11_screen_temp_chart;
	lv_obj_t *dht11_screen_humi_chart;
	lv_obj_t *dht11_screen_DHT11_Title;
	lv_obj_t *dht11_screen_Timer;
	lv_obj_t *dht11_screen_TempHumiDisplay;
	lv_obj_t *dht11_screen_temp_num;
	lv_obj_t *dht11_screen_humi_num;
	lv_obj_t *dht11_screen_btn_1;
	lv_obj_t *dht11_screen_btn_1_label;
	lv_obj_t *dht11_screen_label_1;
	lv_obj_t *dht11_screen_label_2;
	lv_obj_t *dht11_screen_label_3;
	lv_obj_t *music_screen;
	bool music_screen_del;
	lv_obj_t *music_screen_song_name;
	lv_obj_t *music_screen_status;
	lv_obj_t *music_screen_btn_1;
	lv_obj_t *music_screen_btn_1_label;
	lv_obj_t *music_screen_ddlist_1;
	lv_obj_t *music_screen_label_1;
	lv_obj_t *music_screen_playpulsebtn;
	lv_obj_t *music_screen_playpulsebtn_label;
	lv_obj_t *music_screen_prevbtn;
	lv_obj_t *music_screen_prevbtn_label;
	lv_obj_t *music_screen_nextbtn;
	lv_obj_t *music_screen_nextbtn_label;
	lv_obj_t *music_screen_minusbtn;
	lv_obj_t *music_screen_minusbtn_label;
	lv_obj_t *music_screen_plusbtn;
	lv_obj_t *music_screen_plusbtn_label;
	lv_obj_t *music_screen_volume;
	lv_obj_t *music_screen_randombtn;
	lv_obj_t *music_screen_randombtn_label;
	lv_obj_t *weather_screen;
	bool weather_screen_del;
	lv_obj_t *weather_screen_Weather_Title;
	lv_obj_t *weather_screen_btn_1;
	lv_obj_t *weather_screen_btn_1_label;
	lv_obj_t *weather_screen_condition;
	lv_obj_t *weather_screen_real_t;
	lv_obj_t *weather_screen_apparent_t;
	lv_obj_t *weather_screen_fetch;
	lv_obj_t *weather_screen_fetch_label;
	lv_obj_t *weather_screen_location;
	lv_obj_t *weather_screen_w_loc;
	lv_obj_t *weather_screen_w_con;
	lv_obj_t *weather_screen_w_rt;
	lv_obj_t *weather_screen_w_at;
	lv_obj_t *weather_screen_wifi_name;
	lv_obj_t *weather_screen_stat;
	lv_obj_t *weather_screen_s_sta;
	lv_obj_t *weather_screen_s_stat;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_home(lv_ui *ui);
void setup_scr_rtc_screen(lv_ui *ui);
void setup_scr_dht11_screen(lv_ui *ui);
void setup_scr_music_screen(lv_ui *ui);
void setup_scr_weather_screen(lv_ui *ui);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_30)


#ifdef __cplusplus
}
#endif
#endif
