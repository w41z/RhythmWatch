#include "weather_manager.h"
#include "stm32f1xx_hal.h"

static volatile bool weather_fetch_requested = false;
static volatile bool wifi_connected = false;

static char weather_ssid[64] = "";
static char weather_passwd[64] = "";
static char weather_location[32] = "";

static void weather_set_label(lv_obj_t *obj, const char *text)
{
    if (obj != NULL && text != NULL)
    {
        lv_label_set_text(obj, text);
    }
}

static void weather_trim(char *text)
{
    char *start;
    int end;

    if (text == NULL)
        return;

    start = text;
    while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t')
    {
        start++;
    }

    if (start != text)
    {
        memmove(text, start, strlen(start) + 1);
    }

    end = (int)strlen(text) - 1;
    while (end >= 0)
    {
        if (text[end] == ' ' || text[end] == '\r' || text[end] == '\n' || text[end] == '\t')
        {
            text[end] = '\0';
        }
        else
        {
            break;
        }
        end--;
    }
}

static bool weather_fetch_wttr_value(const char *format, char *out, size_t out_size)
{
    char cmd[120];
    char request[256];
    char raw[1024] = {0};
    char *start;
    int len;
    int i;
    uint32_t timeout;

    if (format == NULL || out == NULL || out_size == 0)
        return false;

    Uart_flush(wifi_uart);
    Uart_sendstring("AT+CIPCLOSE\r\n", wifi_uart);
    HAL_Delay(800);

    sprintf(cmd, "AT+CIPSTART=\"TCP\",\"wttr.in\",80\r\n");
    Uart_sendstring(cmd, wifi_uart);

    if (!Wait_for_timeout("OK\r\n", wifi_uart, 3000))
    {
        return false;
    }

    HAL_Delay(500);

    snprintf(request, sizeof(request),
             "GET /%s?format=%s HTTP/1.1\r\nHost: wttr.in\r\nConnection: close\r\n\r\n",
             weather_location, format);

    len = (int)strlen(request);
    snprintf(cmd, sizeof(cmd), "AT+CIPSEND=%d\r\n", len);
    Uart_sendstring(cmd, wifi_uart);

    if (!Wait_for_timeout(">", wifi_uart, 3000))
    {
        return false;
    }

    Uart_sendstring(request, wifi_uart);
    Wait_for_timeout("SEND OK", wifi_uart, 3000);

    i = 0;
    timeout = HAL_GetTick() + 3000;
    while (i < (int)sizeof(raw) - 1 && HAL_GetTick() < timeout)
    {
        if (IsDataAvailable(wifi_uart))
        {
            raw[i++] = Uart_read(wifi_uart);
        }
        else
        {
            HAL_Delay(8);
        }
    }
    raw[i] = '\0';

    start = strstr(raw, "+IPD,");
    if (start != NULL)
    {
        start = strchr(start, ':');
        if (start != NULL)
        {
            memmove(raw, start + 1, strlen(start + 1) + 1);
        }
    }

    start = strstr(raw, "\r\n\r\n");
    if (start != NULL)
    {
        memmove(raw, start + 4, strlen(start + 4) + 1);
    }

    start = strstr(raw, "CLOSED");
    if (start != NULL)
    {
        *start = '\0';
    }

    weather_trim(raw);

    strncpy(out, raw, out_size - 1);
    out[out_size - 1] = '\0';

    return true;
}

static void weather_set_idle_state(lv_ui *ui)
{
    weather_set_label(ui->weather_screen_s_stat, "waiting...");
    weather_set_label(ui->weather_screen_w_loc, "waiting...");
    weather_set_label(ui->weather_screen_w_con, "waiting...");
    weather_set_label(ui->weather_screen_w_rt, "waiting...");
    weather_set_label(ui->weather_screen_w_at, "waiting...");
    weather_set_label(ui->weather_screen_s_sta, "waiting...");
}

void Weather_Manager_SetCredentials(const char *ssid, const char *passwd)
{
    if (ssid != NULL)
    {
        strncpy(weather_ssid, ssid, sizeof(weather_ssid) - 1);
        weather_ssid[sizeof(weather_ssid) - 1] = '\0';
    }

    if (passwd != NULL)
    {
        strncpy(weather_passwd, passwd, sizeof(weather_passwd) - 1);
        weather_passwd[sizeof(weather_passwd) - 1] = '\0';
    }
}

void Weather_Manager_SetLocation(const char *location)
{
    if (location != NULL)
    {
        strncpy(weather_location, location, sizeof(weather_location) - 1);
        weather_location[sizeof(weather_location) - 1] = '\0';
    }
}

void Weather_Manager_RequestFetch(void)
{
    weather_fetch_requested = true;
}

void Weather_Manager_Task(lv_ui *ui)
{
    char value[128];

    if (ui == NULL)
        return;

    if (ui->weather_screen == NULL)
        return;

    if (!weather_fetch_requested)
        return;
    
    weather_fetch_requested = false;

    if (lv_scr_act() != ui->weather_screen)
        return;

    weather_set_label(ui->weather_screen_w_loc, weather_location);

    if (!wifi_connected)
    {
        ESP_Init(weather_ssid, weather_passwd);
        HAL_Delay(2000);
        wifi_connected = true;
    }

    weather_set_label(ui->weather_screen_s_stat, "WiFi connected");
    weather_set_label(ui->weather_screen_s_sta, weather_ssid);

    weather_set_label(ui->weather_screen_s_stat, "Fetching condition...");
    if (weather_fetch_wttr_value("%C", value, sizeof(value)))
    {
        weather_set_label(ui->weather_screen_w_con, value);
    }
    else
    {
        weather_set_label(ui->weather_screen_w_con, "fetch failed");
    }

    weather_set_label(ui->weather_screen_s_stat, "Fetching temperature...");
    if (weather_fetch_wttr_value("%t", value, sizeof(value)))
    {
        weather_set_label(ui->weather_screen_w_rt, value);
    }
    else
    {
        weather_set_label(ui->weather_screen_w_rt, "fetch failed");
    }

    weather_set_label(ui->weather_screen_s_stat, "Fetching feels like...");
    if (weather_fetch_wttr_value("%f", value, sizeof(value)))
    {
        weather_set_label(ui->weather_screen_w_at, value);
    }
    else
    {
        weather_set_label(ui->weather_screen_w_at, "fetch failed");
    }

    weather_set_label(ui->weather_screen_s_stat, "Done");
}
