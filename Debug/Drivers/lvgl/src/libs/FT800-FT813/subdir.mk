################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/FT800-FT813/EVE_commands.c \
../Drivers/lvgl/src/libs/FT800-FT813/EVE_supplemental.c 

OBJS += \
./Drivers/lvgl/src/libs/FT800-FT813/EVE_commands.o \
./Drivers/lvgl/src/libs/FT800-FT813/EVE_supplemental.o 

C_DEPS += \
./Drivers/lvgl/src/libs/FT800-FT813/EVE_commands.d \
./Drivers/lvgl/src/libs/FT800-FT813/EVE_supplemental.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/FT800-FT813/%.o Drivers/lvgl/src/libs/FT800-FT813/%.su: ../Drivers/lvgl/src/libs/FT800-FT813/%.c Drivers/lvgl/src/libs/FT800-FT813/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-FT800-2d-FT813

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-FT800-2d-FT813:
	-$(RM) ./Drivers/lvgl/src/libs/FT800-FT813/EVE_commands.d ./Drivers/lvgl/src/libs/FT800-FT813/EVE_commands.o ./Drivers/lvgl/src/libs/FT800-FT813/EVE_commands.su ./Drivers/lvgl/src/libs/FT800-FT813/EVE_supplemental.d ./Drivers/lvgl/src/libs/FT800-FT813/EVE_supplemental.o ./Drivers/lvgl/src/libs/FT800-FT813/EVE_supplemental.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-FT800-2d-FT813

