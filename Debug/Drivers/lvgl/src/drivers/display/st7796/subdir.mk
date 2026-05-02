################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/drivers/display/st7796/lv_st7796.c 

OBJS += \
./Drivers/lvgl/src/drivers/display/st7796/lv_st7796.o 

C_DEPS += \
./Drivers/lvgl/src/drivers/display/st7796/lv_st7796.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/drivers/display/st7796/%.o Drivers/lvgl/src/drivers/display/st7796/%.su: ../Drivers/lvgl/src/drivers/display/st7796/%.c Drivers/lvgl/src/drivers/display/st7796/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-display-2f-st7796

clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-display-2f-st7796:
	-$(RM) ./Drivers/lvgl/src/drivers/display/st7796/lv_st7796.d ./Drivers/lvgl/src/drivers/display/st7796/lv_st7796.o ./Drivers/lvgl/src/drivers/display/st7796/lv_st7796.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-display-2f-st7796

