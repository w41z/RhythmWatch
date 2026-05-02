################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.c \
../Drivers/lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.c \
../Drivers/lvgl/src/stdlib/rtthread/lv_string_rtthread.c 

OBJS += \
./Drivers/lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.o \
./Drivers/lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.o \
./Drivers/lvgl/src/stdlib/rtthread/lv_string_rtthread.o 

C_DEPS += \
./Drivers/lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.d \
./Drivers/lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.d \
./Drivers/lvgl/src/stdlib/rtthread/lv_string_rtthread.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/stdlib/rtthread/%.o Drivers/lvgl/src/stdlib/rtthread/%.su: ../Drivers/lvgl/src/stdlib/rtthread/%.c Drivers/lvgl/src/stdlib/rtthread/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-stdlib-2f-rtthread

clean-Drivers-2f-lvgl-2f-src-2f-stdlib-2f-rtthread:
	-$(RM) ./Drivers/lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.d ./Drivers/lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.o ./Drivers/lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.su ./Drivers/lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.d ./Drivers/lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.o ./Drivers/lvgl/src/stdlib/rtthread/lv_sprintf_rtthread.su ./Drivers/lvgl/src/stdlib/rtthread/lv_string_rtthread.d ./Drivers/lvgl/src/stdlib/rtthread/lv_string_rtthread.o ./Drivers/lvgl/src/stdlib/rtthread/lv_string_rtthread.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-stdlib-2f-rtthread

