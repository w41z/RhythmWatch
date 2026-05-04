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



void setup_scr_rtc_screen(lv_ui *ui)
{
    //Write codes rtc_screen
    ui->rtc_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->rtc_screen, 240, 320);
    lv_obj_set_scrollbar_mode(ui->rtc_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for rtc_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->rtc_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->rtc_screen, lv_color_hex(0xffe2f0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->rtc_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_RTC
    ui->rtc_screen_RTC = lv_label_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_RTC, 69, 18);
    lv_obj_set_size(ui->rtc_screen_RTC, 100, 32);
    lv_label_set_text(ui->rtc_screen_RTC, "RTC");
    lv_label_set_long_mode(ui->rtc_screen_RTC, LV_LABEL_LONG_WRAP);

    //Write style for rtc_screen_RTC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_RTC, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_RTC, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_RTC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_RTC, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_RTC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_label_rtc_date
    ui->rtc_screen_label_rtc_date = lv_label_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_label_rtc_date, 18, 50);
    lv_obj_set_size(ui->rtc_screen_label_rtc_date, 100, 32);
    lv_label_set_text(ui->rtc_screen_label_rtc_date, "waiting");
    lv_label_set_long_mode(ui->rtc_screen_label_rtc_date, LV_LABEL_LONG_WRAP);

    //Write style for rtc_screen_label_rtc_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_label_rtc_date, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_label_rtc_date, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_label_rtc_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_label_rtc_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_label_rtc_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_label_rtc_time
    ui->rtc_screen_label_rtc_time = lv_label_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_label_rtc_time, 118, 50);
    lv_obj_set_size(ui->rtc_screen_label_rtc_time, 100, 32);
    lv_label_set_text(ui->rtc_screen_label_rtc_time, "waiting");
    lv_label_set_long_mode(ui->rtc_screen_label_rtc_time, LV_LABEL_LONG_WRAP);

    //Write style for rtc_screen_label_rtc_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_label_rtc_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_label_rtc_time, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_label_rtc_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_label_rtc_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_label_rtc_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_label_rtc_day
    ui->rtc_screen_label_rtc_day = lv_label_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_label_rtc_day, 66, 82);
    lv_obj_set_size(ui->rtc_screen_label_rtc_day, 100, 32);
    lv_label_set_text(ui->rtc_screen_label_rtc_day, "waiting");
    lv_label_set_long_mode(ui->rtc_screen_label_rtc_day, LV_LABEL_LONG_WRAP);

    //Write style for rtc_screen_label_rtc_day, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_label_rtc_day, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_label_rtc_day, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_label_rtc_day, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_label_rtc_day, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_label_rtc_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_modebtn
    ui->rtc_screen_modebtn = lv_button_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_modebtn, 36, 150);
    lv_obj_set_size(ui->rtc_screen_modebtn, 50, 50);
    ui->rtc_screen_modebtn_label = lv_label_create(ui->rtc_screen_modebtn);
    lv_label_set_text(ui->rtc_screen_modebtn_label, "Mode");
    lv_label_set_long_mode(ui->rtc_screen_modebtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rtc_screen_modebtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rtc_screen_modebtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->rtc_screen_modebtn_label, LV_PCT(100));

    //Write style for rtc_screen_modebtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->rtc_screen_modebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->rtc_screen_modebtn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->rtc_screen_modebtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->rtc_screen_modebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_modebtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_modebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_modebtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_modebtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_modebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_modebtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_mode_label
    ui->rtc_screen_mode_label = lv_label_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_mode_label, 13, 127);
    lv_obj_set_size(ui->rtc_screen_mode_label, 100, 32);
    lv_label_set_text(ui->rtc_screen_mode_label, "Display");
    lv_label_set_long_mode(ui->rtc_screen_mode_label, LV_LABEL_LONG_WRAP);

    //Write style for rtc_screen_mode_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_mode_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_mode_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_mode_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_mode_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_mode_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_nextbtn
    ui->rtc_screen_nextbtn = lv_button_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_nextbtn, 156, 150);
    lv_obj_set_size(ui->rtc_screen_nextbtn, 50, 50);
    ui->rtc_screen_nextbtn_label = lv_label_create(ui->rtc_screen_nextbtn);
    lv_label_set_text(ui->rtc_screen_nextbtn_label, "Next");
    lv_label_set_long_mode(ui->rtc_screen_nextbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rtc_screen_nextbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rtc_screen_nextbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->rtc_screen_nextbtn_label, LV_PCT(100));

    //Write style for rtc_screen_nextbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->rtc_screen_nextbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->rtc_screen_nextbtn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->rtc_screen_nextbtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->rtc_screen_nextbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_nextbtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_nextbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_nextbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_nextbtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_nextbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_nextbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_minusbtn
    ui->rtc_screen_minusbtn = lv_button_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_minusbtn, 69, 224);
    lv_obj_set_size(ui->rtc_screen_minusbtn, 35, 53);
    ui->rtc_screen_minusbtn_label = lv_label_create(ui->rtc_screen_minusbtn);
    lv_label_set_text(ui->rtc_screen_minusbtn_label, "<");
    lv_label_set_long_mode(ui->rtc_screen_minusbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rtc_screen_minusbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rtc_screen_minusbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->rtc_screen_minusbtn_label, LV_PCT(100));

    //Write style for rtc_screen_minusbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->rtc_screen_minusbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->rtc_screen_minusbtn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->rtc_screen_minusbtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->rtc_screen_minusbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_minusbtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_minusbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_minusbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_minusbtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_minusbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_minusbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_addbtn
    ui->rtc_screen_addbtn = lv_button_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_addbtn, 140, 224);
    lv_obj_set_size(ui->rtc_screen_addbtn, 35, 53);
    ui->rtc_screen_addbtn_label = lv_label_create(ui->rtc_screen_addbtn);
    lv_label_set_text(ui->rtc_screen_addbtn_label, ">");
    lv_label_set_long_mode(ui->rtc_screen_addbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rtc_screen_addbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rtc_screen_addbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->rtc_screen_addbtn_label, LV_PCT(100));

    //Write style for rtc_screen_addbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->rtc_screen_addbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->rtc_screen_addbtn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->rtc_screen_addbtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->rtc_screen_addbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->rtc_screen_addbtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_addbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->rtc_screen_addbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_addbtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_addbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_addbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes rtc_screen_btn_1
    ui->rtc_screen_btn_1 = lv_imagebutton_create(ui->rtc_screen);
    lv_obj_set_pos(ui->rtc_screen_btn_1, 188, 267);
    lv_obj_set_size(ui->rtc_screen_btn_1, 45, 45);
    lv_obj_add_flag(ui->rtc_screen_btn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->rtc_screen_btn_1, LV_IMAGEBUTTON_STATE_RELEASED, &_homebtn_RGB565A8_45x45, NULL, NULL);
    lv_imagebutton_set_src(ui->rtc_screen_btn_1, LV_IMAGEBUTTON_STATE_PRESSED, &_homebtn_RGB565A8_45x45, NULL, NULL);
    ui->rtc_screen_btn_1_label = lv_label_create(ui->rtc_screen_btn_1);
    lv_label_set_text(ui->rtc_screen_btn_1_label, "");
    lv_label_set_long_mode(ui->rtc_screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->rtc_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->rtc_screen_btn_1, 0, LV_STATE_DEFAULT);

    //Write style for rtc_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->rtc_screen_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->rtc_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->rtc_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->rtc_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->rtc_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for rtc_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->rtc_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->rtc_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->rtc_screen_btn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->rtc_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->rtc_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->rtc_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for rtc_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->rtc_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->rtc_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->rtc_screen_btn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->rtc_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->rtc_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->rtc_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for rtc_screen_btn_1, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->rtc_screen_btn_1, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->rtc_screen_btn_1, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //The custom code of rtc_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->rtc_screen);

    //Init events for screen.
    events_init_rtc_screen(ui);
}
