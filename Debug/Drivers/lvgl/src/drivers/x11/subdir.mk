################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/drivers/x11/lv_x11_display.c \
../Drivers/lvgl/src/drivers/x11/lv_x11_input.c 

OBJS += \
./Drivers/lvgl/src/drivers/x11/lv_x11_display.o \
./Drivers/lvgl/src/drivers/x11/lv_x11_input.o 

C_DEPS += \
./Drivers/lvgl/src/drivers/x11/lv_x11_display.d \
./Drivers/lvgl/src/drivers/x11/lv_x11_input.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/drivers/x11/%.o Drivers/lvgl/src/drivers/x11/%.su: ../Drivers/lvgl/src/drivers/x11/%.c Drivers/lvgl/src/drivers/x11/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-x11

clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-x11:
	-$(RM) ./Drivers/lvgl/src/drivers/x11/lv_x11_display.d ./Drivers/lvgl/src/drivers/x11/lv_x11_display.o ./Drivers/lvgl/src/drivers/x11/lv_x11_display.su ./Drivers/lvgl/src/drivers/x11/lv_x11_input.d ./Drivers/lvgl/src/drivers/x11/lv_x11_input.o ./Drivers/lvgl/src/drivers/x11/lv_x11_input.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-x11

