#ifndef DFPLAYER_MUSIC_H
#define DFPLAYER_MUSIC_H

#include "lvgl.h"
#include "gui_guider.h"

// Call this in main loop to handle DFPlayer UI updates
void DFPlayer_Manager_Task(lv_ui *ui);

// Initialize DFPlayer hardware
void DFPlayer_Init(void);

#endif
