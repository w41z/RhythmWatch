################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/testui/images/_homebutton_RGB565A8_30x30.c \
../Drivers/testui/images/_homebutton_RGB565A8_35x35.c 

OBJS += \
./Drivers/testui/images/_homebutton_RGB565A8_30x30.o \
./Drivers/testui/images/_homebutton_RGB565A8_35x35.o 

C_DEPS += \
./Drivers/testui/images/_homebutton_RGB565A8_30x30.d \
./Drivers/testui/images/_homebutton_RGB565A8_35x35.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/testui/images/%.o Drivers/testui/images/%.su: ../Drivers/testui/images/%.c Drivers/testui/images/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-testui-2f-images

clean-Drivers-2f-testui-2f-images:
	-$(RM) ./Drivers/testui/images/_homebutton_RGB565A8_30x30.d ./Drivers/testui/images/_homebutton_RGB565A8_30x30.o ./Drivers/testui/images/_homebutton_RGB565A8_30x30.su ./Drivers/testui/images/_homebutton_RGB565A8_35x35.d ./Drivers/testui/images/_homebutton_RGB565A8_35x35.o ./Drivers/testui/images/_homebutton_RGB565A8_35x35.su

.PHONY: clean-Drivers-2f-testui-2f-images

