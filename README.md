# RhythmWatch

RhythmWatch is an embedded firmware project for a smart watch/clock device built around the **STM32F103** microcontroller (ARM Cortex-M3). It combines sensor monitoring, Wi-Fi weather fetching, MP3 audio playback, and a touchscreen GUI into a single bare-metal application.

### Canva
<img width="864" height="443" alt="image" src="https://github.com/user-attachments/assets/fdb57372-d627-46a5-b2f1-e45285ed78b1" />

link: [https://canva.link/8xa20uo94wrfnxg](https://canva.link/8xa20uo94wrfnxg)

---

## Hardware & Key Technologies

| Technology | Role |
|---|---|
| **STM32F103** (ARM Cortex-M3) | Main MCU — runs at 72 MHz (8 MHz HSE × PLL ×9) |
| **STM32 HAL** | Low-level peripheral abstraction (GPIO, UART, RTC, DMA, timers) |
| **FSMC** | Drives the LCD display over a 16-bit parallel bus |
| **LVGL** | Renders the touchscreen GUI |
| **ESP8266** (UART3 @ 115200 baud) | Wi-Fi module for fetching weather data via AT commands |
| **DFPlayer Mini** (UART2 @ 9600 baud) | MP3 audio playback module |
| **DHT11** | Temperature & humidity sensor |
| **RTC** (LSE-driven) | Hardware real-time clock; persists across resets |
| **CMake + STM32CubeIDE** | Dual build system support |

---

## Directory Structure

```
RhythmWatch/
├── Core/
│   ├── Inc/          ← Application headers (main.h, dht11.h, lcd.h, rtc_manager.h, …)
│   └── Src/          ← Application source code
│       ├── main.c               ← Entry point, peripheral init, main loop
│       ├── dht11.c              ← DHT11 sensor driver
│       ├── lcd.c                ← LCD initialization and drawing
│       ├── rtc_manager.c        ← RTC read/write and LVGL label updates
│       ├── dfplayer_music.c     ← DFPlayer MP3 module control
│       └── weather_manager.c    ← Wi-Fi weather fetching via wttr.in
│
├── Lib/
│   ├── Inc/          ← Library headers
│   └── Src/
│       ├── ESP8266_HAL.c          ← AT-command driver for the ESP8266 Wi-Fi chip
│       ├── UartRingbuffer_multi.c ← DMA-backed ring buffer for multi-UART RX
│       ├── lcd.c                  ← Low-level LCD pixel/command driver
│       ├── rgb.c                  ← RGB color helpers
│       └── rw_rtc.c               ← Custom RTC init/persistence logic
│
├── Drivers/
│   ├── CMSIS/              ← ARM CMSIS core headers
│   ├── STM32F1xx_HAL_Driver/ ← STM32 HAL library source
│   ├── lvgl/               ← LVGL graphics library source
│   ├── display/
│   │   ├── lv_port_disp.c  ← LVGL display driver port (flush callback → LCD)
│   │   └── lv_port_indev.c ← LVGL input device port (touch input)
│   └── testui/             ← GUI Guider-generated UI code
│       ├── gui_guider.c          ← Builds all screen objects
│       ├── events_init.c         ← Button/event callbacks
│       ├── setup_scr_home.c          ← Home screen layout
│       ├── setup_scr_dht11_screen.c  ← Temperature/humidity screen
│       ├── setup_scr_rtc_screen.c    ← Clock/date screen
│       ├── setup_scr_music_screen.c  ← Music player screen
│       ├── setup_scr_weather_screen.c ← Weather display screen
│       └── guider_fonts/         ← Custom Montserrat bitmap fonts (12–30pt)
│
├── CMakeLists.txt        ← Main CMake build definition
├── CMakePresets.json     ← CMake preset for cross-compilation (arm-none-eabi-gcc)
├── STM32CubeIDE/         ← STM32CubeIDE project files
├── STM32F103XX_FLASH.ld  ← Linker script (Flash/RAM layout)
├── startup_stm32f103xe.s ← ARM startup assembly (vector table, stack init)
└── RW.ioc                ← STM32CubeMX pin/peripheral configuration
```

---

## Application Screens

The UI has **5 screens**, navigable via the touchscreen:

| Screen | Description |
|---|---|
| **Home** | Main clock face / landing screen |
| **DHT11** | Live temperature & humidity with scrolling line charts (updates every 2 s) |
| **RTC** | Current date and time from the hardware RTC (updates every 1 s) |
| **Music** | DFPlayer Mini controls — play/pause/next/prev via UART |
| **Weather** | On-demand weather fetch from `wttr.in` via ESP8266 |

---

## Main Loop Flow

```
main()
 ├── HAL_Init() + SystemClock_Config()           // System setup
 ├── MX_*_Init() calls                           // All peripheral init
 ├── LCD_INIT() + lv_init() + lv_port_*_init()  // Display + touch
 ├── setup_ui() + events_init()                  // Build LVGL screens
 └── while(1):
      ├── Every 1000 ms → RTC_Manager_Task()      // Update clock labels
      ├── Every 2000 ms (DHT11 screen) → DHT11_Read() + chart update
      ├── Weather_Manager_Task()                   // Non-blocking ESP8266 fetch
      ├── DFPlayer_Manager_Task()                  // Handle playback state
      ├── lv_timer_handler()                       // Process LVGL tasks
      └── HAL_Delay(5) + lv_tick_inc(5)           // Feed LVGL 5 ms tick
```

---

## UART Assignments

| UART | Baud | Purpose |
|---|---|---|
| USART1 | 115200 | Debug / DMA-backed ring-buffer RX |
| USART2 | 9600 | DFPlayer Mini (MP3 commands) |
| USART3 | 115200 | ESP8266 Wi-Fi (AT commands) |

---

## Getting Started

### Clone the repository
```
git clone git@github.com:w41z/RhythmWatch.git
```

### Build (CMake)
```
cmake --preset <your-preset>
cmake --build build/
```

### Build (STM32CubeIDE)
Open the `STM32CubeIDE/` project directory in STM32CubeIDE and build normally.

---

## Contributing

> **Warning:** Please start work on new branches. **DO NOT MODIFY THE `main` BRANCH DIRECTLY!**

```
git branch <name_of_branch>
git switch <name_of_branch>
```

Make a Pull Request (PR) for any upgrade or new feature!
