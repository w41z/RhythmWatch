################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/display/lv_port_disp.c \
../Drivers/display/lv_port_indev.c 

OBJS += \
./Drivers/display/lv_port_disp.o \
./Drivers/display/lv_port_indev.o 

C_DEPS += \
./Drivers/display/lv_port_disp.d \
./Drivers/display/lv_port_indev.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/display/%.o Drivers/display/%.su: ../Drivers/display/%.c Drivers/display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-display

clean-Drivers-2f-display:
	-$(RM) ./Drivers/display/lv_port_disp.d ./Drivers/display/lv_port_disp.o ./Drivers/display/lv_port_disp.su ./Drivers/display/lv_port_indev.d ./Drivers/display/lv_port_indev.o ./Drivers/display/lv_port_indev.su

.PHONY: clean-Drivers-2f-display

