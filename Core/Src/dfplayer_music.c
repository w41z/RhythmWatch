#include "dfplayer_music.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart2;

// DFPlayer state variables
static int is_playing = 0;
static int is_paused = 0;
static int current_track = 1;
static int current_volume = 5;
static int max_track = 4;  // Change this the number of MP3 files

// Screen pointer for tracking
static lv_obj_t *last_known_music_screen = NULL;

// Command sending
static void dfplayer_send_command(uint8_t cmd, uint8_t param1, uint8_t param2)
{
    uint8_t buffer[10];
    uint16_t checksum = 0;

    buffer[0] = 0x7E;  // Start
    buffer[1] = 0xFF;  // Version
    buffer[2] = 0x06;  // Length
    buffer[3] = cmd;   // Command
    buffer[4] = 0x00;  // No ACK
    buffer[5] = param1;
    buffer[6] = param2;

    // Calculate checksum (two's complement)
    for (int i = 1; i <= 6; i++) {
        checksum += buffer[i];
    }
    checksum = -checksum;

    buffer[7] = (checksum >> 8) & 0xFF;
    buffer[8] = checksum & 0xFF;
    buffer[9] = 0xEF;

    HAL_UART_Transmit(&huart2, buffer, 10, 100);
    HAL_Delay(50);
}

// =========================================================
// BUTTON EVENT HANDLERS (Same style as rtc_manager)
// =========================================================
static void dfplayer_button_handler(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if (code != LV_EVENT_CLICKED) return;

    // Play/Pause button
    if (btn == ui->music_screen_playpulsebtn) {
        if (!is_playing) {
            // Start playing first track
            dfplayer_send_command(0x03, 0x01, current_track);
            is_playing = 1;
            is_paused = 0;
        } else if (is_paused) {
            // Resume
            dfplayer_send_command(0x0D, 0x00, 0x00);
            is_paused = 0;
        } else {
            // Pause
            dfplayer_send_command(0x0E, 0x00, 0x00);
            is_paused = 1;
        }
    }

    // Next button
    else if (btn == ui->music_screen_nextbtn) {
    	if (current_track < max_track) current_track++;
		else current_track = 1;
		dfplayer_send_command(0x03, 0x00, current_track);
        dfplayer_send_command(0x01, 0x00, 0x00);
        is_playing = 1;
        is_paused = 0;
    }

    // Previous button
    else if (btn == ui->music_screen_prevbtn) {
    	if (current_track > 1) current_track--;
		else current_track = max_track;
    	dfplayer_send_command(0x03, 0x00, current_track);
        is_playing = 1;
        is_paused = 0;
    }

    // Volume Up button
    else if (btn == ui->music_screen_plusbtn) {
        if (current_volume < 30) {
            current_volume += 5;
            if (current_volume > 30) current_volume = 30;
            dfplayer_send_command(0x06, 0x00, current_volume);
        }
    }

    // Volume Down button
    else if (btn == ui->music_screen_minusbtn) {
        if (current_volume > 0) {
            current_volume -= 5;
            if (current_volume < 0) current_volume = 0;
            dfplayer_send_command(0x06, 0x00, current_volume);
        }
    }
}

// =========================================================
// HARDWARE INITIALIZATION
// =========================================================
void DFPlayer_Init(void)
{
    HAL_Delay(3000);  // Wait for DFPlayer to boot

    // Set initial volume
    dfplayer_send_command(0x06, 0x00, current_volume);
    HAL_Delay(100);

    // Stop any auto-play
    dfplayer_send_command(0x16, 0x00, 0x00);
    is_playing = 0;
    is_paused = 0;
}

// =========================================================
// MAIN TASK FUNCTION (Call this in your main loop)
// =========================================================
void DFPlayer_Manager_Task(lv_ui *ui)
{
    // 1. DETECT SCREEN CHANGES - Link buttons when entering music screen
    if (ui->music_screen != NULL && ui->music_screen != last_known_music_screen) {
        // Link all buttons to our handler
        lv_obj_add_event_cb(ui->music_screen_playpulsebtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->music_screen_nextbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->music_screen_prevbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->music_screen_plusbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
        lv_obj_add_event_cb(ui->music_screen_minusbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);

        last_known_music_screen = ui->music_screen;
    }

    // 2. UPDATE DISPLAY LABELS (Only if music screen is active)
    if (ui->music_screen == NULL || lv_scr_act() != ui->music_screen) {
        return;
    }

    char buf[32];
    if (ui->music_screen_volume) {
		snprintf(buf, sizeof(buf), "%d/30", current_volume);
		lv_label_set_text(ui->music_screen_volume, buf);
	}

    // Update button text dynamically (optional)
    if (ui->music_screen_playpulsebtn) {
        lv_obj_t *label = lv_obj_get_child(ui->music_screen_playpulsebtn, 0);
        if (label != NULL) {
            if (is_playing && !is_paused) {
                lv_label_set_text(label, "Pause");
            } else {
                lv_label_set_text(label, "Play");
            }
        }
    }
}
