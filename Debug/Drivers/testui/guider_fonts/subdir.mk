################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/testui/guider_fonts/lv_font_montserratMedium_12.c \
../Drivers/testui/guider_fonts/lv_font_montserratMedium_13.c \
../Drivers/testui/guider_fonts/lv_font_montserratMedium_16.c \
../Drivers/testui/guider_fonts/lv_font_montserratMedium_20.c \
../Drivers/testui/guider_fonts/lv_font_montserratMedium_30.c 

OBJS += \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_12.o \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_13.o \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_16.o \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_20.o \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_30.o 

C_DEPS += \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_12.d \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_13.d \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_16.d \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_20.d \
./Drivers/testui/guider_fonts/lv_font_montserratMedium_30.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/testui/guider_fonts/%.o Drivers/testui/guider_fonts/%.su: ../Drivers/testui/guider_fonts/%.c Drivers/testui/guider_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-testui-2f-guider_fonts

clean-Drivers-2f-testui-2f-guider_fonts:
	-$(RM) ./Drivers/testui/guider_fonts/lv_font_montserratMedium_12.d ./Drivers/testui/guider_fonts/lv_font_montserratMedium_12.o ./Drivers/testui/guider_fonts/lv_font_montserratMedium_12.su ./Drivers/testui/guider_fonts/lv_font_montserratMedium_13.d ./Drivers/testui/guider_fonts/lv_font_montserratMedium_13.o ./Drivers/testui/guider_fonts/lv_font_montserratMedium_13.su ./Drivers/testui/guider_fonts/lv_font_montserratMedium_16.d ./Drivers/testui/guider_fonts/lv_font_montserratMedium_16.o ./Drivers/testui/guider_fonts/lv_font_montserratMedium_16.su ./Drivers/testui/guider_fonts/lv_font_montserratMedium_20.d ./Drivers/testui/guider_fonts/lv_font_montserratMedium_20.o ./Drivers/testui/guider_fonts/lv_font_montserratMedium_20.su ./Drivers/testui/guider_fonts/lv_font_montserratMedium_30.d ./Drivers/testui/guider_fonts/lv_font_montserratMedium_30.o ./Drivers/testui/guider_fonts/lv_font_montserratMedium_30.su

.PHONY: clean-Drivers-2f-testui-2f-guider_fonts

