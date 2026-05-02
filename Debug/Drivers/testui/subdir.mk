################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/testui/custom.c \
../Drivers/testui/events_init.c \
../Drivers/testui/gui_guider.c \
../Drivers/testui/setup_scr_dht11_screen.c \
../Drivers/testui/setup_scr_home.c \
../Drivers/testui/setup_scr_music_screen.c \
../Drivers/testui/setup_scr_rtc_screen.c \
../Drivers/testui/setup_scr_weather_screen.c \
../Drivers/testui/widgets_init.c 

OBJS += \
./Drivers/testui/custom.o \
./Drivers/testui/events_init.o \
./Drivers/testui/gui_guider.o \
./Drivers/testui/setup_scr_dht11_screen.o \
./Drivers/testui/setup_scr_home.o \
./Drivers/testui/setup_scr_music_screen.o \
./Drivers/testui/setup_scr_rtc_screen.o \
./Drivers/testui/setup_scr_weather_screen.o \
./Drivers/testui/widgets_init.o 

C_DEPS += \
./Drivers/testui/custom.d \
./Drivers/testui/events_init.d \
./Drivers/testui/gui_guider.d \
./Drivers/testui/setup_scr_dht11_screen.d \
./Drivers/testui/setup_scr_home.d \
./Drivers/testui/setup_scr_music_screen.d \
./Drivers/testui/setup_scr_rtc_screen.d \
./Drivers/testui/setup_scr_weather_screen.d \
./Drivers/testui/widgets_init.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/testui/%.o Drivers/testui/%.su: ../Drivers/testui/%.c Drivers/testui/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-testui

clean-Drivers-2f-testui:
	-$(RM) ./Drivers/testui/custom.d ./Drivers/testui/custom.o ./Drivers/testui/custom.su ./Drivers/testui/events_init.d ./Drivers/testui/events_init.o ./Drivers/testui/events_init.su ./Drivers/testui/gui_guider.d ./Drivers/testui/gui_guider.o ./Drivers/testui/gui_guider.su ./Drivers/testui/setup_scr_dht11_screen.d ./Drivers/testui/setup_scr_dht11_screen.o ./Drivers/testui/setup_scr_dht11_screen.su ./Drivers/testui/setup_scr_home.d ./Drivers/testui/setup_scr_home.o ./Drivers/testui/setup_scr_home.su ./Drivers/testui/setup_scr_music_screen.d ./Drivers/testui/setup_scr_music_screen.o ./Drivers/testui/setup_scr_music_screen.su ./Drivers/testui/setup_scr_rtc_screen.d ./Drivers/testui/setup_scr_rtc_screen.o ./Drivers/testui/setup_scr_rtc_screen.su ./Drivers/testui/setup_scr_weather_screen.d ./Drivers/testui/setup_scr_weather_screen.o ./Drivers/testui/setup_scr_weather_screen.su ./Drivers/testui/widgets_init.d ./Drivers/testui/widgets_init.o ./Drivers/testui/widgets_init.su

.PHONY: clean-Drivers-2f-testui

