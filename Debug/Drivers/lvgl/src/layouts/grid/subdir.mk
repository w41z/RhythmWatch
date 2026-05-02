################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/layouts/grid/lv_grid.c 

OBJS += \
./Drivers/lvgl/src/layouts/grid/lv_grid.o 

C_DEPS += \
./Drivers/lvgl/src/layouts/grid/lv_grid.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/layouts/grid/%.o Drivers/lvgl/src/layouts/grid/%.su: ../Drivers/lvgl/src/layouts/grid/%.c Drivers/lvgl/src/layouts/grid/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-layouts-2f-grid

clean-Drivers-2f-lvgl-2f-src-2f-layouts-2f-grid:
	-$(RM) ./Drivers/lvgl/src/layouts/grid/lv_grid.d ./Drivers/lvgl/src/layouts/grid/lv_grid.o ./Drivers/lvgl/src/layouts/grid/lv_grid.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-layouts-2f-grid

