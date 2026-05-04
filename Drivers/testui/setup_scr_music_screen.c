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



void setup_scr_music_screen(lv_ui *ui)
{
    //Write codes music_screen
    ui->music_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->music_screen, 240, 320);
    lv_obj_set_scrollbar_mode(ui->music_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for music_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen, lv_color_hex(0xdebeff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_song_name
    ui->music_screen_song_name = lv_label_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_song_name, 21, 44);
    lv_obj_set_size(ui->music_screen_song_name, 191, 55);
    lv_label_set_text(ui->music_screen_song_name, "");
    lv_label_set_long_mode(ui->music_screen_song_name, LV_LABEL_LONG_WRAP);

    //Write style for music_screen_song_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_song_name, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_song_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_song_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_song_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_status
    ui->music_screen_status = lv_label_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_status, 13, 14);
    lv_obj_set_size(ui->music_screen_status, 217, 19);
    lv_label_set_text(ui->music_screen_status, "Click \"Play\" to play Song");
    lv_label_set_long_mode(ui->music_screen_status, LV_LABEL_LONG_WRAP);

    //Write style for music_screen_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_status, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_status, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_ddlist_1
    ui->music_screen_ddlist_1 = lv_dropdown_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_ddlist_1, 21, 111);
    lv_obj_set_size(ui->music_screen_ddlist_1, 198, 33);
    lv_dropdown_set_options(ui->music_screen_ddlist_1, "Yoru ni Kakeru \nYou Belong With Me\nLove You Too Much\nDummy testing song");

    //Write style for music_screen_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->music_screen_ddlist_1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_ddlist_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_screen_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->music_screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->music_screen_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->music_screen_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_screen_ddlist_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_screen_ddlist_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_screen_ddlist_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_ddlist_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_music_screen_ddlist_1_extra_list_selected_checked
    static lv_style_t style_music_screen_ddlist_1_extra_list_selected_checked;
    ui_init_style(&style_music_screen_ddlist_1_extra_list_selected_checked);

    lv_style_set_border_width(&style_music_screen_ddlist_1_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_music_screen_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_music_screen_ddlist_1_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_music_screen_ddlist_1_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_music_screen_ddlist_1_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_music_screen_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_music_screen_ddlist_1_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_music_screen_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->music_screen_ddlist_1), &style_music_screen_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_music_screen_ddlist_1_extra_list_main_default
    static lv_style_t style_music_screen_ddlist_1_extra_list_main_default;
    ui_init_style(&style_music_screen_ddlist_1_extra_list_main_default);

    lv_style_set_max_height(&style_music_screen_ddlist_1_extra_list_main_default, 90);
    lv_style_set_text_color(&style_music_screen_ddlist_1_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_music_screen_ddlist_1_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_music_screen_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_width(&style_music_screen_ddlist_1_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_music_screen_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_color(&style_music_screen_ddlist_1_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_music_screen_ddlist_1_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_music_screen_ddlist_1_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_music_screen_ddlist_1_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_music_screen_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_music_screen_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->music_screen_ddlist_1), &style_music_screen_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_music_screen_ddlist_1_extra_list_scrollbar_default
    static lv_style_t style_music_screen_ddlist_1_extra_list_scrollbar_default;
    ui_init_style(&style_music_screen_ddlist_1_extra_list_scrollbar_default);

    lv_style_set_radius(&style_music_screen_ddlist_1_extra_list_scrollbar_default, 10);
    lv_style_set_bg_opa(&style_music_screen_ddlist_1_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_music_screen_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_music_screen_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->music_screen_ddlist_1), &style_music_screen_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes music_screen_label_1
    ui->music_screen_label_1 = lv_label_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_label_1, 68, 147);
    lv_obj_set_size(ui->music_screen_label_1, 100, 32);
    lv_label_set_text(ui->music_screen_label_1, "Song list");
    lv_label_set_long_mode(ui->music_screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for music_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_playpulsebtn
    ui->music_screen_playpulsebtn = lv_button_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_playpulsebtn, 60, 179);
    lv_obj_set_size(ui->music_screen_playpulsebtn, 43, 50);
    ui->music_screen_playpulsebtn_label = lv_label_create(ui->music_screen_playpulsebtn);
    lv_label_set_text(ui->music_screen_playpulsebtn_label, "Play");
    lv_label_set_long_mode(ui->music_screen_playpulsebtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_screen_playpulsebtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_screen_playpulsebtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->music_screen_playpulsebtn_label, LV_PCT(100));

    //Write style for music_screen_playpulsebtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_screen_playpulsebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen_playpulsebtn, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen_playpulsebtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_screen_playpulsebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_playpulsebtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_playpulsebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_playpulsebtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_playpulsebtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_playpulsebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_playpulsebtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_prevbtn
    ui->music_screen_prevbtn = lv_button_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_prevbtn, 13, 179);
    lv_obj_set_size(ui->music_screen_prevbtn, 36, 50);
    ui->music_screen_prevbtn_label = lv_label_create(ui->music_screen_prevbtn);
    lv_label_set_text(ui->music_screen_prevbtn_label, "<");
    lv_label_set_long_mode(ui->music_screen_prevbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_screen_prevbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_screen_prevbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->music_screen_prevbtn_label, LV_PCT(100));

    //Write style for music_screen_prevbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_screen_prevbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen_prevbtn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen_prevbtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_screen_prevbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_prevbtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_prevbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_prevbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_prevbtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_prevbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_prevbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_nextbtn
    ui->music_screen_nextbtn = lv_button_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_nextbtn, 192, 179);
    lv_obj_set_size(ui->music_screen_nextbtn, 36, 50);
    ui->music_screen_nextbtn_label = lv_label_create(ui->music_screen_nextbtn);
    lv_label_set_text(ui->music_screen_nextbtn_label, ">");
    lv_label_set_long_mode(ui->music_screen_nextbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_screen_nextbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_screen_nextbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->music_screen_nextbtn_label, LV_PCT(100));

    //Write style for music_screen_nextbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_screen_nextbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen_nextbtn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen_nextbtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_screen_nextbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_nextbtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_nextbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_nextbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_nextbtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_nextbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_nextbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_minusbtn
    ui->music_screen_minusbtn = lv_button_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_minusbtn, 57, 235);
    lv_obj_set_size(ui->music_screen_minusbtn, 36, 50);
    ui->music_screen_minusbtn_label = lv_label_create(ui->music_screen_minusbtn);
    lv_label_set_text(ui->music_screen_minusbtn_label, "-");
    lv_label_set_long_mode(ui->music_screen_minusbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_screen_minusbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_screen_minusbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->music_screen_minusbtn_label, LV_PCT(100));

    //Write style for music_screen_minusbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_screen_minusbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen_minusbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen_minusbtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_screen_minusbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_minusbtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_minusbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_minusbtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_minusbtn, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_minusbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_minusbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_plusbtn
    ui->music_screen_plusbtn = lv_button_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_plusbtn, 145, 235);
    lv_obj_set_size(ui->music_screen_plusbtn, 36, 50);
    ui->music_screen_plusbtn_label = lv_label_create(ui->music_screen_plusbtn);
    lv_label_set_text(ui->music_screen_plusbtn_label, "+");
    lv_label_set_long_mode(ui->music_screen_plusbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_screen_plusbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_screen_plusbtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->music_screen_plusbtn_label, LV_PCT(100));

    //Write style for music_screen_plusbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_screen_plusbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen_plusbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen_plusbtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_screen_plusbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_plusbtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_plusbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_plusbtn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_plusbtn, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_plusbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_plusbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_volume
    ui->music_screen_volume = lv_label_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_volume, 68, 253);
    lv_obj_set_size(ui->music_screen_volume, 100, 32);
    lv_label_set_text(ui->music_screen_volume, "5/30");
    lv_label_set_long_mode(ui->music_screen_volume, LV_LABEL_LONG_WRAP);

    //Write style for music_screen_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_volume, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_volume, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_volume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_volume, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_randombtn
    ui->music_screen_randombtn = lv_button_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_randombtn, 113, 179);
    lv_obj_set_size(ui->music_screen_randombtn, 74, 50);
    ui->music_screen_randombtn_label = lv_label_create(ui->music_screen_randombtn);
    lv_label_set_text(ui->music_screen_randombtn_label, "Random\n");
    lv_label_set_long_mode(ui->music_screen_randombtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_screen_randombtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_screen_randombtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->music_screen_randombtn_label, LV_PCT(100));

    //Write style for music_screen_randombtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_screen_randombtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_screen_randombtn, lv_color_hex(0x0ba01c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_screen_randombtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_screen_randombtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_screen_randombtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_randombtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_screen_randombtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_randombtn, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_randombtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_randombtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_screen_btn_1
    ui->music_screen_btn_1 = lv_imagebutton_create(ui->music_screen);
    lv_obj_set_pos(ui->music_screen_btn_1, 188, 267);
    lv_obj_set_size(ui->music_screen_btn_1, 45, 45);
    lv_obj_add_flag(ui->music_screen_btn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->music_screen_btn_1, LV_IMAGEBUTTON_STATE_RELEASED, &_homebtn_RGB565A8_45x45, NULL, NULL);
    lv_imagebutton_set_src(ui->music_screen_btn_1, LV_IMAGEBUTTON_STATE_PRESSED, &_homebtn_RGB565A8_45x45, NULL, NULL);
    ui->music_screen_btn_1_label = lv_label_create(ui->music_screen_btn_1);
    lv_label_set_text(ui->music_screen_btn_1_label, "");
    lv_label_set_long_mode(ui->music_screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_screen_btn_1, 0, LV_STATE_DEFAULT);

    //Write style for music_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->music_screen_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for music_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->music_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->music_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->music_screen_btn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->music_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->music_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->music_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for music_screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->music_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->music_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->music_screen_btn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->music_screen_btn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->music_screen_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->music_screen_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for music_screen_btn_1, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->music_screen_btn_1, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->music_screen_btn_1, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //The custom code of music_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->music_screen);

    //Init events for screen.
    events_init_music_screen(ui);
}
