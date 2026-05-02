################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/debugging/vg_lite_tvg/vg_lite_matrix.c 

OBJS += \
./Drivers/lvgl/src/debugging/vg_lite_tvg/vg_lite_matrix.o 

C_DEPS += \
./Drivers/lvgl/src/debugging/vg_lite_tvg/vg_lite_matrix.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/debugging/vg_lite_tvg/%.o Drivers/lvgl/src/debugging/vg_lite_tvg/%.su: ../Drivers/lvgl/src/debugging/vg_lite_tvg/%.c Drivers/lvgl/src/debugging/vg_lite_tvg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-debugging-2f-vg_lite_tvg

clean-Drivers-2f-lvgl-2f-src-2f-debugging-2f-vg_lite_tvg:
	-$(RM) ./Drivers/lvgl/src/debugging/vg_lite_tvg/vg_lite_matrix.d ./Drivers/lvgl/src/debugging/vg_lite_tvg/vg_lite_matrix.o ./Drivers/lvgl/src/debugging/vg_lite_tvg/vg_lite_matrix.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-debugging-2f-vg_lite_tvg

