#ifndef RW_DISPLAY_H
#define RW_DISPLAY_H

#include "oximeter.h"

void rw_display_init(void);
void rw_display_show_reading(const oximeter_reading_t *reading);
void rw_display_show_error(const char *line0, const char *line1);

#endif
