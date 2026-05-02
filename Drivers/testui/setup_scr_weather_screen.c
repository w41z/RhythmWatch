/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_weather_screen(lv_ui *ui)
{
    //Write codes weather_screen
    ui->weather_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->weather_screen, 240, 320);
    lv_obj_set_scrollbar_mode(ui->weather_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for weather_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->weather_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->weather_screen, lv_color_hex(0x2fcada), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->weather_screen, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->weather_screen, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->weather_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->weather_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_Weather_Title
    ui->weather_screen_Weather_Title = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_Weather_Title, 69, 5);
    lv_obj_set_size(ui->weather_screen_Weather_Title, 100, 32);
    lv_label_set_text(ui->weather_screen_Weather_Title, "Current Weather");
    lv_label_set_long_mode(ui->weather_screen_Weather_Title, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_Weather_Title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_Weather_Title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_Weather_Title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_Weather_Title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_Weather_Title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_Weather_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_btn_1
    ui->weather_screen_btn_1 = lv_button_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_btn_1, 175, 280);
    lv_obj_set_size(ui->weather_screen_btn_1, 58, 32);
    ui->weather_screen_btn_1_label = lv_label_create(ui->weather_screen_btn_1);
    lv_label_set_text(ui->weather_screen_btn_1_label, "Home");
    lv_label_set_long_mode(ui->weather_screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->weather_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->weather_screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->weather_screen_btn_1_label, LV_PCT(100));

    //Write style for weather_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->weather_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->weather_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_condition
    ui->weather_screen_condition = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_condition, 9, 70);
    lv_obj_set_size(ui->weather_screen_condition, 65, 15);
    lv_label_set_text(ui->weather_screen_condition, "Condition:");
    lv_label_set_long_mode(ui->weather_screen_condition, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_condition, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_condition, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_condition, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_condition, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_condition, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_condition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_real_t
    ui->weather_screen_real_t = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_real_t, 0, 133);
    lv_obj_set_size(ui->weather_screen_real_t, 86, 24);
    lv_label_set_text(ui->weather_screen_real_t, "Real Temperature:");
    lv_label_set_long_mode(ui->weather_screen_real_t, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_real_t, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_real_t, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_real_t, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_real_t, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_real_t, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_real_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_apparent_t
    ui->weather_screen_apparent_t = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_apparent_t, 0, 170);
    lv_obj_set_size(ui->weather_screen_apparent_t, 86, 25);
    lv_label_set_text(ui->weather_screen_apparent_t, "Apparent Temperature:");
    lv_label_set_long_mode(ui->weather_screen_apparent_t, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_apparent_t, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_apparent_t, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_apparent_t, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_apparent_t, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_apparent_t, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_apparent_t, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_fetch
    ui->weather_screen_fetch = lv_button_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_fetch, 155, 228);
    lv_obj_set_size(ui->weather_screen_fetch, 70, 27);
    ui->weather_screen_fetch_label = lv_label_create(ui->weather_screen_fetch);
    lv_label_set_text(ui->weather_screen_fetch_label, "Fetch Data");
    lv_label_set_long_mode(ui->weather_screen_fetch_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->weather_screen_fetch_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->weather_screen_fetch, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->weather_screen_fetch_label, LV_PCT(100));

    //Write style for weather_screen_fetch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->weather_screen_fetch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->weather_screen_fetch, lv_color_hex(0xff8100), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->weather_screen_fetch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->weather_screen_fetch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_fetch, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_fetch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_fetch, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_fetch, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_fetch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_fetch, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_location
    ui->weather_screen_location = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_location, 9, 44);
    lv_obj_set_size(ui->weather_screen_location, 59, 10);
    lv_label_set_text(ui->weather_screen_location, "Location:");
    lv_label_set_long_mode(ui->weather_screen_location, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_location, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_location, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_location, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_location, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_location, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_w_loc
    ui->weather_screen_w_loc = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_w_loc, 98, 44);
    lv_obj_set_size(ui->weather_screen_w_loc, 74, 15);
    lv_label_set_text(ui->weather_screen_w_loc, "waiting...");
    lv_label_set_long_mode(ui->weather_screen_w_loc, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_w_loc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_w_loc, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_w_loc, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_w_loc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_w_loc, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_w_loc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_w_con
    ui->weather_screen_w_con = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_w_con, 9, 94);
    lv_obj_set_size(ui->weather_screen_w_con, 58, 15);
    lv_label_set_text(ui->weather_screen_w_con, "waiting...");
    lv_label_set_long_mode(ui->weather_screen_w_con, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_w_con, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_w_con, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_w_con, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_w_con, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_w_con, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_w_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_w_rt
    ui->weather_screen_w_rt = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_w_rt, 98, 137);
    lv_obj_set_size(ui->weather_screen_w_rt, 74, 15);
    lv_label_set_text(ui->weather_screen_w_rt, "waiting...");
    lv_label_set_long_mode(ui->weather_screen_w_rt, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_w_rt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_w_rt, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_w_rt, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_w_rt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_w_rt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_w_rt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_w_at
    ui->weather_screen_w_at = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_w_at, 98, 173);
    lv_obj_set_size(ui->weather_screen_w_at, 74, 15);
    lv_label_set_text(ui->weather_screen_w_at, "waiting...");
    lv_label_set_long_mode(ui->weather_screen_w_at, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_w_at, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_w_at, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_w_at, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_w_at, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_w_at, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_w_at, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_wifi_name
    ui->weather_screen_wifi_name = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_wifi_name, 0, 228);
    lv_obj_set_size(ui->weather_screen_wifi_name, 74, 15);
    lv_label_set_text(ui->weather_screen_wifi_name, "Wifi Name:");
    lv_label_set_long_mode(ui->weather_screen_wifi_name, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_wifi_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_wifi_name, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_wifi_name, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_wifi_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_wifi_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_stat
    ui->weather_screen_stat = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_stat, 3, 243);
    lv_obj_set_size(ui->weather_screen_stat, 43, 15);
    lv_label_set_text(ui->weather_screen_stat, "Status:");
    lv_label_set_long_mode(ui->weather_screen_stat, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_stat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_stat, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_stat, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_stat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_stat, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_s_sta
    ui->weather_screen_s_sta = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_s_sta, 69, 228);
    lv_obj_set_size(ui->weather_screen_s_sta, 74, 15);
    lv_label_set_text(ui->weather_screen_s_sta, "---");
    lv_label_set_long_mode(ui->weather_screen_s_sta, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_s_sta, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_s_sta, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_s_sta, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_s_sta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_s_sta, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_s_sta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes weather_screen_s_stat
    ui->weather_screen_s_stat = lv_label_create(ui->weather_screen);
    lv_obj_set_pos(ui->weather_screen_s_stat, 69, 243);
    lv_obj_set_size(ui->weather_screen_s_stat, 74, 15);
    lv_label_set_text(ui->weather_screen_s_stat, "---");
    lv_label_set_long_mode(ui->weather_screen_s_stat, LV_LABEL_LONG_WRAP);

    //Write style for weather_screen_s_stat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->weather_screen_s_stat, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->weather_screen_s_stat, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->weather_screen_s_stat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->weather_screen_s_stat, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->weather_screen_s_stat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of weather_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->weather_screen);

    //Init events for screen.
    events_init_weather_screen(ui);
}
