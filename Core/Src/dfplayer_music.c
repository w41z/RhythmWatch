#include "dfplayer_music.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart2;

// DFPlayer state variables
static int is_playing = 0;
static int is_paused = 0;
static int current_track = 1;      // Track number (1 = 0001.mp3)
static int current_volume = 5;

// BUSY pin (PE3) - LOW = Playing, HIGH = Stopped/Paused
#define DFPLAYER_BUSY_PORT   GPIOC
#define DFPLAYER_BUSY_PIN    GPIO_PIN_7

// Screen pointer for tracking
static lv_obj_t *last_known_music_screen = NULL;

typedef struct {
    const char *name;
    const char *singer;
} SongInfo;

static const SongInfo playlist[] = {
    {"Yoru ni Kakeru", "Yoasobi"}, // Track 1
    {"You Belong With Me", "Taylor Swift"}, // Track 2
    {"Love You Too Much", "Hins Cheung"}, // Track 3
    {"Dummy testing song", "Sound from AI"}  // Track 4
};

#define PLAYLIST_SIZE (sizeof(playlist) / sizeof(playlist[0]))

// Command sending
static void dfplayer_send_command(uint8_t cmd, uint8_t param1, uint8_t param2)
{
    uint8_t buffer[10];
    uint16_t checksum = 0;

    buffer[0] = 0x7E;
    buffer[1] = 0xFF;
    buffer[2] = 0x06;
    buffer[3] = cmd;
    buffer[4] = 0x00;
    buffer[5] = param1;
    buffer[6] = param2;

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

// Check actual playback state from BUSY pin
static int dfplayer_is_actually_playing(void)
{
    return (HAL_GPIO_ReadPin(DFPLAYER_BUSY_PORT, DFPLAYER_BUSY_PIN) == GPIO_PIN_RESET);
}

// Play a specific track from MP3 folder (supports 0001-9999)
static void dfplayer_play_track(int track_num)
{
    uint8_t high_byte = (track_num >> 8) & 0xFF;
    uint8_t low_byte = track_num & 0xFF;

    dfplayer_send_command(0x12, high_byte, low_byte);
}

// =========================================================
// BUTTON EVENT HANDLERS
// =========================================================
static void dfplayer_button_handler(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if (code != LV_EVENT_CLICKED) return;

    // Play/Pause button
    if (btn == ui->music_screen_playpulsebtn) {
        int actually_playing = dfplayer_is_actually_playing();

        if (!actually_playing && !is_paused) {
            // Stopped - start playing current track
            dfplayer_play_track(current_track);
            is_playing = 1;
            is_paused = 0;
        } else if (actually_playing && !is_paused) {
            // Currently playing - pause
            dfplayer_send_command(0x0E, 0x00, 0x00);
            is_paused = 1;
        } else if (is_paused) {
            // Paused - resume
            dfplayer_send_command(0x0D, 0x00, 0x00);
            is_paused = 0;
        }
    }

    /*
    // Next button - Let DFPlayer manage tracks
    else if (btn == ui->music_screen_nextbtn) {
        dfplayer_send_command(0x02, 0x00, 0x00);
        is_playing = 1;
        is_paused = 0;
    }

    // Previous button
    else if (btn == ui->music_screen_prevbtn) {
        dfplayer_send_command(0x01, 0x00, 0x00);
        is_playing = 1;
        is_paused = 0;
    }
    */
    else if (btn == ui->music_screen_nextbtn) {
		current_track++;
		// PLAYLIST_SIZE 係我哋之前定義嘅 Array 長度
		if (current_track > PLAYLIST_SIZE) {
			current_track = 1; // 播到最後就跳返第一首
		}
		dfplayer_play_track(current_track); // 使用 0x12 指令播放
		is_playing = 1;
		is_paused = 0;
	}

	else if (btn == ui->music_screen_prevbtn) {
		current_track--;
		if (current_track < 1) {
			current_track = PLAYLIST_SIZE; // 第一首再退就跳去最後一首
		}
		dfplayer_play_track(current_track);
		is_playing = 1;
		is_paused = 0;
	}

    // Volume Up
    else if (btn == ui->music_screen_plusbtn) {
        if (current_volume < 30) {
            current_volume += 5;
            if (current_volume > 30) current_volume = 30;
            dfplayer_send_command(0x06, 0x00, current_volume);
        }
    }

    // Volume Down
    else if (btn == ui->music_screen_minusbtn) {
        if (current_volume > 0) {
            current_volume -= 5;
            if (current_volume < 0) current_volume = 0;
            dfplayer_send_command(0x06, 0x00, current_volume);
        }
    }

    else if (btn == ui->music_screen_randombtn) {
        // rand() % PLAYLIST_SIZE 會得到 0 到 (PLAYLIST_SIZE - 1)
        current_track = (rand() % PLAYLIST_SIZE) + 1;

        dfplayer_play_track(current_track);
        is_playing = 1;
        is_paused = 0;

        if (ui->music_screen_ddlist_1) {
            lv_dropdown_set_selected(ui->music_screen_ddlist_1, current_track - 1);
        }
    }

    if (ui->music_screen_ddlist_1) {
        lv_dropdown_set_selected(ui->music_screen_ddlist_1, current_track - 1);
    }
}

// =========================================================
// DROPDOWN HANDLER
// =========================================================
static void music_dropdown_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code != LV_EVENT_VALUE_CHANGED) return;

    lv_obj_t *dropdown = lv_event_get_target(e);
    uint16_t selected = lv_dropdown_get_selected(dropdown);
    current_track = selected + 1;  // Option 0 = Track 1

    // Play selected track
    dfplayer_play_track(current_track);
    is_playing = 1;
    is_paused = 0;
}

// =========================================================
// SCREEN DELETE HANDLER
// =========================================================
static void music_screen_delete_handler(lv_event_t *e)
{
    if(lv_event_get_code(e) != LV_EVENT_DELETE) return;
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

    if(ui) {
        ui->music_screen = NULL;
        ui->music_screen_song_name = NULL;
        ui->music_screen_status = NULL;
        ui->music_screen_btn_1 = NULL;
        ui->music_screen_btn_1_label = NULL;
        ui->music_screen_playpulsebtn = NULL;
        ui->music_screen_playpulsebtn_label = NULL;
        ui->music_screen_nextbtn = NULL;
        ui->music_screen_nextbtn_label = NULL;
        ui->music_screen_prevbtn = NULL;
        ui->music_screen_prevbtn_label = NULL;
        ui->music_screen_plusbtn = NULL;
        ui->music_screen_plusbtn_label = NULL;
        ui->music_screen_minusbtn = NULL;
        ui->music_screen_minusbtn_label = NULL;
        ui->music_screen_volume = NULL;
        ui->music_screen_randombtn = NULL;
        ui->music_screen_randombtn_label = NULL;
        ui->music_screen_ddlist_1 = NULL;
    }

    last_known_music_screen = NULL;
}

// =========================================================
// HARDWARE INITIALIZATION
// =========================================================
void DFPlayer_Init(void)
{
    // Configure BUSY pin as input with pull-up
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DFPLAYER_BUSY_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(DFPLAYER_BUSY_PORT, &GPIO_InitStruct);
    srand(HAL_GetTick());

    HAL_Delay(3000);  // Wait for DFPlayer to boot

    // Set initial volume
    dfplayer_send_command(0x06, 0x00, current_volume);

    dfplayer_send_command(0x16, 0x00, 0x00);  // Stop

    current_track = 1;
    is_playing = 0;
    is_paused = 0;
}

// =========================================================
// MAIN TASK FUNCTION
// =========================================================
void DFPlayer_Manager_Task(lv_ui *ui)
{
	if (ui->music_screen_ddlist_1 && lv_obj_is_valid(ui->music_screen_ddlist_1)) {
		lv_obj_t * list = lv_dropdown_get_list(ui->music_screen_ddlist_1);
		if (lv_obj_is_valid(list)) {
			lv_obj_set_style_pad_row(list, 40, LV_STATE_DEFAULT);
			lv_obj_set_style_pad_all(list, 10, LV_STATE_DEFAULT);
		}
	}

	// 1. Link UI elements when entering screen
	if (ui->music_screen != NULL && ui->music_screen != last_known_music_screen && lv_obj_is_valid(ui->music_screen)) {
		if (ui->music_screen_ddlist_1 && lv_obj_is_valid(ui->music_screen_ddlist_1)) {
			lv_obj_add_event_cb(ui->music_screen_ddlist_1, music_dropdown_handler, LV_EVENT_VALUE_CHANGED, ui);
		}
		if (ui->music_screen_playpulsebtn)
			lv_obj_add_event_cb(ui->music_screen_playpulsebtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
		if (ui->music_screen_nextbtn)
			lv_obj_add_event_cb(ui->music_screen_nextbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
		if (ui->music_screen_prevbtn)
			lv_obj_add_event_cb(ui->music_screen_prevbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
		if (ui->music_screen_plusbtn)
			lv_obj_add_event_cb(ui->music_screen_plusbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
		if (ui->music_screen_minusbtn)
			lv_obj_add_event_cb(ui->music_screen_minusbtn, dfplayer_button_handler, LV_EVENT_ALL, ui);
		if (ui->music_screen_randombtn)
			lv_obj_add_event_cb(ui->music_screen_randombtn, dfplayer_button_handler, LV_EVENT_ALL, ui);

		lv_obj_add_event_cb(ui->music_screen, music_screen_delete_handler, LV_EVENT_ALL, ui);
		last_known_music_screen = ui->music_screen;
	}

	// 2. Auto-detect song end using BUSY pin
	static int last_busy_state = 1;
	//int current_busy = dfplayer_is_actually_playing();
	int current_busy = HAL_GPIO_ReadPin(DFPLAYER_BUSY_PORT, DFPLAYER_BUSY_PIN);

	    // 重點：判斷「自然播完」
	    // 條件：上一刻係 0 (播緊)，呢一刻變咗 1 (停咗)，而且「唔係」User 手動撳咗暫停
	    if (last_busy_state == 0 && current_busy == 1) {
	        if (!is_paused) {
	            // 只有喺冇撳暫停嘅情況下，先至係「自然播完」
	            current_track++;
	            if (current_track > PLAYLIST_SIZE) current_track = 1;

	            dfplayer_play_track(current_track); // 指令 0x12
	            is_playing = 1;
	            is_paused = 0;

	            // 同步 Dropdown
	            if (ui->music_screen_ddlist_1) {
	                lv_dropdown_set_selected(ui->music_screen_ddlist_1, current_track - 1);
	            }
	        }
	    }
	/*
	if (last_busy_state == 0 && current_busy == 1) {
		// Song just finished
		if (!is_paused) {
			is_playing = 0;
     	}
	}*/
	last_busy_state = current_busy;

	// 3. Update display
	if (ui->music_screen == NULL || !lv_obj_is_valid(ui->music_screen) || lv_scr_act() != ui->music_screen) {
		return;
	}

	char buf[32];

	// Update volume
	if (ui->music_screen_volume && lv_obj_is_valid(ui->music_screen_volume)) {
		snprintf(buf, sizeof(buf), "%d/30", current_volume);
		lv_label_set_text(ui->music_screen_volume, buf);
	}

    // Update play/pause button text
    if (ui->music_screen_playpulsebtn && lv_obj_is_valid(ui->music_screen_playpulsebtn)) {
        lv_obj_t *label = lv_obj_get_child(ui->music_screen_playpulsebtn, 0);
        if (label && lv_obj_is_valid(label)) {
            if (current_busy) {
                lv_label_set_text(label, "Play");
            } else {
                lv_label_set_text(label, "Pause");
            }
        }
    }

    // Status Label ---
    if (ui->music_screen_status && lv_obj_is_valid(ui->music_screen_status)) {
        if (current_busy) {
            lv_label_set_text(ui->music_screen_status, "Click \"Play\" to start");
        } else if (is_paused) {
            lv_label_set_text(ui->music_screen_status, "Now Pausing");
        } else {
            lv_label_set_text(ui->music_screen_status, "Now playing");
        }
    }

    // Song Name Label (Song - Singer) ---
    if (ui->music_screen_song_name && lv_obj_is_valid(ui->music_screen_song_name)) {
		// current_track 係由 1 開始，陣列係由 0 開始，所以要 -1
		int index = current_track - 1;

		// 預防 index 出界 (Safety check)
		if (index >= 0 && index < PLAYLIST_SIZE) {
			char info_buf[64];
			snprintf(info_buf, sizeof(info_buf), "%s   \n\n%s", playlist[index].name, playlist[index].singer);
			lv_label_set_text(ui->music_screen_song_name, info_buf);
		}
	}
}
