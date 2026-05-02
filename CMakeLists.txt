cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME RW)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    Core/Src/dht11.c
    Core/Src/lcd.c
    Core/Src/rtc_manager.c
    Core/Src/dfplayer_music.c
    Core/Src/weather_manager.c
    # Lib sources
    Lib/Src/ESP8266_HAL.c
    Lib/Src/UartRingbuffer_multi.c
    # LVGL display and input port implementations
    Drivers/display/lv_port_disp.c
    Drivers/display/lv_port_indev.c
    # LVGL UI components
    Drivers/testui/custom.c
    Drivers/testui/events_init.c
    Drivers/testui/gui_guider.c
    Drivers/testui/widgets_init.c
    Drivers/testui/setup_scr_home.c
    Drivers/testui/setup_scr_dht11_screen.c
    Drivers/testui/setup_scr_rtc_screen.c
    Drivers/testui/setup_scr_music_screen.c
    Drivers/testui/setup_scr_weather_screen.c
    # LVGL Custom Fonts (from GUI Guider)
    Drivers/testui/guider_fonts/lv_font_montserratMedium_12.c
    Drivers/testui/guider_fonts/lv_font_montserratMedium_13.c
    Drivers/testui/guider_fonts/lv_font_montserratMedium_16.c
    Drivers/testui/guider_fonts/lv_font_montserratMedium_20.c
    Drivers/testui/guider_fonts/lv_font_montserratMedium_30.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    Core/Inc
    Lib/Inc
    Drivers/lvgl
    Drivers/display
    Drivers/testui
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
    LV_LVGL_H_INCLUDE_SIMPLE
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# root CMakeLists.txt
set(LV_BUILD_CONF_DIR "${CMAKE_SOURCE_DIR}/Drivers/lvgl" CACHE PATH "" FORCE)
set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
add_subdirectory(Drivers/lvgl)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
    lvgl
)
