################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/debugging/test/lv_test_display.c \
../Drivers/lvgl/src/debugging/test/lv_test_fs.c \
../Drivers/lvgl/src/debugging/test/lv_test_helpers.c \
../Drivers/lvgl/src/debugging/test/lv_test_indev.c \
../Drivers/lvgl/src/debugging/test/lv_test_indev_gesture.c \
../Drivers/lvgl/src/debugging/test/lv_test_screenshot_compare.c 

OBJS += \
./Drivers/lvgl/src/debugging/test/lv_test_display.o \
./Drivers/lvgl/src/debugging/test/lv_test_fs.o \
./Drivers/lvgl/src/debugging/test/lv_test_helpers.o \
./Drivers/lvgl/src/debugging/test/lv_test_indev.o \
./Drivers/lvgl/src/debugging/test/lv_test_indev_gesture.o \
./Drivers/lvgl/src/debugging/test/lv_test_screenshot_compare.o 

C_DEPS += \
./Drivers/lvgl/src/debugging/test/lv_test_display.d \
./Drivers/lvgl/src/debugging/test/lv_test_fs.d \
./Drivers/lvgl/src/debugging/test/lv_test_helpers.d \
./Drivers/lvgl/src/debugging/test/lv_test_indev.d \
./Drivers/lvgl/src/debugging/test/lv_test_indev_gesture.d \
./Drivers/lvgl/src/debugging/test/lv_test_screenshot_compare.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/debugging/test/%.o Drivers/lvgl/src/debugging/test/%.su: ../Drivers/lvgl/src/debugging/test/%.c Drivers/lvgl/src/debugging/test/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-debugging-2f-test

clean-Drivers-2f-lvgl-2f-src-2f-debugging-2f-test:
	-$(RM) ./Drivers/lvgl/src/debugging/test/lv_test_display.d ./Drivers/lvgl/src/debugging/test/lv_test_display.o ./Drivers/lvgl/src/debugging/test/lv_test_display.su ./Drivers/lvgl/src/debugging/test/lv_test_fs.d ./Drivers/lvgl/src/debugging/test/lv_test_fs.o ./Drivers/lvgl/src/debugging/test/lv_test_fs.su ./Drivers/lvgl/src/debugging/test/lv_test_helpers.d ./Drivers/lvgl/src/debugging/test/lv_test_helpers.o ./Drivers/lvgl/src/debugging/test/lv_test_helpers.su ./Drivers/lvgl/src/debugging/test/lv_test_indev.d ./Drivers/lvgl/src/debugging/test/lv_test_indev.o ./Drivers/lvgl/src/debugging/test/lv_test_indev.su ./Drivers/lvgl/src/debugging/test/lv_test_indev_gesture.d ./Drivers/lvgl/src/debugging/test/lv_test_indev_gesture.o ./Drivers/lvgl/src/debugging/test/lv_test_indev_gesture.su ./Drivers/lvgl/src/debugging/test/lv_test_screenshot_compare.d ./Drivers/lvgl/src/debugging/test/lv_test_screenshot_compare.o ./Drivers/lvgl/src/debugging/test/lv_test_screenshot_compare.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-debugging-2f-test

