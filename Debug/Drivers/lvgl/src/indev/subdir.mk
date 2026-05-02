################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/indev/lv_gridnav.c \
../Drivers/lvgl/src/indev/lv_indev.c \
../Drivers/lvgl/src/indev/lv_indev_gesture.c \
../Drivers/lvgl/src/indev/lv_indev_scroll.c 

OBJS += \
./Drivers/lvgl/src/indev/lv_gridnav.o \
./Drivers/lvgl/src/indev/lv_indev.o \
./Drivers/lvgl/src/indev/lv_indev_gesture.o \
./Drivers/lvgl/src/indev/lv_indev_scroll.o 

C_DEPS += \
./Drivers/lvgl/src/indev/lv_gridnav.d \
./Drivers/lvgl/src/indev/lv_indev.d \
./Drivers/lvgl/src/indev/lv_indev_gesture.d \
./Drivers/lvgl/src/indev/lv_indev_scroll.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/indev/%.o Drivers/lvgl/src/indev/%.su: ../Drivers/lvgl/src/indev/%.c Drivers/lvgl/src/indev/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-indev

clean-Drivers-2f-lvgl-2f-src-2f-indev:
	-$(RM) ./Drivers/lvgl/src/indev/lv_gridnav.d ./Drivers/lvgl/src/indev/lv_gridnav.o ./Drivers/lvgl/src/indev/lv_gridnav.su ./Drivers/lvgl/src/indev/lv_indev.d ./Drivers/lvgl/src/indev/lv_indev.o ./Drivers/lvgl/src/indev/lv_indev.su ./Drivers/lvgl/src/indev/lv_indev_gesture.d ./Drivers/lvgl/src/indev/lv_indev_gesture.o ./Drivers/lvgl/src/indev/lv_indev_gesture.su ./Drivers/lvgl/src/indev/lv_indev_scroll.d ./Drivers/lvgl/src/indev/lv_indev_scroll.o ./Drivers/lvgl/src/indev/lv_indev_scroll.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-indev

