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



void setup_scr_dht11_screen(lv_ui *ui)
{
    //Write codes dht11_screen
    ui->dht11_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->dht11_screen, 240, 320);
    lv_obj_set_scrollbar_mode(ui->dht11_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for dht11_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->dht11_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->dht11_screen, lv_color_hex(0x00ff86), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->dht11_screen, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->dht11_screen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->dht11_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->dht11_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_temp_chart
    ui->dht11_screen_temp_chart = lv_chart_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_temp_chart, 20, 42);
    lv_obj_set_size(ui->dht11_screen_temp_chart, 200, 60);
    lv_obj_set_scrollbar_mode(ui->dht11_screen_temp_chart, LV_SCROLLBAR_MODE_OFF);
    lv_chart_set_type(ui->dht11_screen_temp_chart, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->dht11_screen_temp_chart, 3, 15);
    lv_chart_set_point_count(ui->dht11_screen_temp_chart, 5);
    lv_chart_set_range(ui->dht11_screen_temp_chart, LV_CHART_AXIS_PRIMARY_Y, 16, 35);
    lv_chart_set_range(ui->dht11_screen_temp_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);

    //Write style for dht11_screen_temp_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->dht11_screen_temp_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->dht11_screen_temp_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->dht11_screen_temp_chart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->dht11_screen_temp_chart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->dht11_screen_temp_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->dht11_screen_temp_chart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->dht11_screen_temp_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_temp_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->dht11_screen_temp_chart, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->dht11_screen_temp_chart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->dht11_screen_temp_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_temp_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_humi_chart
    ui->dht11_screen_humi_chart = lv_chart_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_humi_chart, 20, 123);
    lv_obj_set_size(ui->dht11_screen_humi_chart, 200, 60);
    lv_obj_set_scrollbar_mode(ui->dht11_screen_humi_chart, LV_SCROLLBAR_MODE_OFF);
    lv_chart_set_type(ui->dht11_screen_humi_chart, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->dht11_screen_humi_chart, 6, 15);
    lv_chart_set_point_count(ui->dht11_screen_humi_chart, 5);
    lv_chart_set_range(ui->dht11_screen_humi_chart, LV_CHART_AXIS_PRIMARY_Y, 30, 100);
    lv_chart_set_range(ui->dht11_screen_humi_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);

    //Write style for dht11_screen_humi_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->dht11_screen_humi_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->dht11_screen_humi_chart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->dht11_screen_humi_chart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->dht11_screen_humi_chart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->dht11_screen_humi_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->dht11_screen_humi_chart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->dht11_screen_humi_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_humi_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->dht11_screen_humi_chart, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->dht11_screen_humi_chart, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->dht11_screen_humi_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_humi_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_DHT11_Title
    ui->dht11_screen_DHT11_Title = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_DHT11_Title, 43, 9);
    lv_obj_set_size(ui->dht11_screen_DHT11_Title, 154, 28);
    lv_label_set_text(ui->dht11_screen_DHT11_Title, "DHT11 Infomation");
    lv_label_set_long_mode(ui->dht11_screen_DHT11_Title, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_DHT11_Title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_DHT11_Title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_DHT11_Title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_DHT11_Title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_DHT11_Title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_DHT11_Title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_Timer
    ui->dht11_screen_Timer = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_Timer, 13, 187);
    lv_obj_set_size(ui->dht11_screen_Timer, 210, 32);
    lv_label_set_text(ui->dht11_screen_Timer, "Time connecting");
    lv_label_set_long_mode(ui->dht11_screen_Timer, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_Timer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_Timer, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_Timer, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_Timer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_Timer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_TempHumiDisplay
    ui->dht11_screen_TempHumiDisplay = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_TempHumiDisplay, 13, 229);
    lv_obj_set_size(ui->dht11_screen_TempHumiDisplay, 91, 78);
    lv_label_set_text(ui->dht11_screen_TempHumiDisplay, "Temp :\n\nHumi :");
    lv_label_set_long_mode(ui->dht11_screen_TempHumiDisplay, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_TempHumiDisplay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_TempHumiDisplay, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_TempHumiDisplay, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_TempHumiDisplay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_TempHumiDisplay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_TempHumiDisplay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_temp_num
    ui->dht11_screen_temp_num = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_temp_num, 96, 229);
    lv_obj_set_size(ui->dht11_screen_temp_num, 100, 32);
    lv_label_set_text(ui->dht11_screen_temp_num, "connecting");
    lv_label_set_long_mode(ui->dht11_screen_temp_num, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_temp_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_temp_num, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_temp_num, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_temp_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_temp_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_temp_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_humi_num
    ui->dht11_screen_humi_num = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_humi_num, 96, 261);
    lv_obj_set_size(ui->dht11_screen_humi_num, 100, 32);
    lv_label_set_text(ui->dht11_screen_humi_num, "connecting");
    lv_label_set_long_mode(ui->dht11_screen_humi_num, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_humi_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_humi_num, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_humi_num, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_humi_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_humi_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_humi_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_btn_1
    ui->dht11_screen_btn_1 = lv_button_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_btn_1, 175, 279);
    lv_obj_set_size(ui->dht11_screen_btn_1, 58, 32);
    ui->dht11_screen_btn_1_label = lv_label_create(ui->dht11_screen_btn_1);
    lv_label_set_text(ui->dht11_screen_btn_1_label, "Home");
    lv_label_set_long_mode(ui->dht11_screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->dht11_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->dht11_screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->dht11_screen_btn_1_label, LV_PCT(100));

    //Write style for dht11_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->dht11_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->dht11_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_label_1
    ui->dht11_screen_label_1 = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_label_1, 148, 48);
    lv_obj_set_size(ui->dht11_screen_label_1, 91, 98);
    lv_label_set_text(ui->dht11_screen_label_1, "Temp -\n\n\n\n\n\nHumi -");
    lv_label_set_long_mode(ui->dht11_screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_label_1, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_label_2
    ui->dht11_screen_label_2 = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_label_2, 5, 42);
    lv_obj_set_size(ui->dht11_screen_label_2, 25, 145);
    lv_label_set_text(ui->dht11_screen_label_2, "35\n\n\n16");
    lv_label_set_long_mode(ui->dht11_screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes dht11_screen_label_3
    ui->dht11_screen_label_3 = lv_label_create(ui->dht11_screen);
    lv_obj_set_pos(ui->dht11_screen_label_3, 5, 123);
    lv_obj_set_size(ui->dht11_screen_label_3, 29, 85);
    lv_label_set_text(ui->dht11_screen_label_3, "100\n\n\n30");
    lv_label_set_long_mode(ui->dht11_screen_label_3, LV_LABEL_LONG_WRAP);

    //Write style for dht11_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->dht11_screen_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->dht11_screen_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->dht11_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->dht11_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->dht11_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of dht11_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->dht11_screen);

    //Init events for screen.
    events_init_dht11_screen(ui);
}
