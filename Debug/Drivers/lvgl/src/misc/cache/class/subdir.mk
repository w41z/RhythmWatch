################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/misc/cache/class/lv_cache_lru_ll.c \
../Drivers/lvgl/src/misc/cache/class/lv_cache_lru_rb.c \
../Drivers/lvgl/src/misc/cache/class/lv_cache_sc_da.c 

OBJS += \
./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_ll.o \
./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_rb.o \
./Drivers/lvgl/src/misc/cache/class/lv_cache_sc_da.o 

C_DEPS += \
./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_ll.d \
./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_rb.d \
./Drivers/lvgl/src/misc/cache/class/lv_cache_sc_da.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/misc/cache/class/%.o Drivers/lvgl/src/misc/cache/class/%.su: ../Drivers/lvgl/src/misc/cache/class/%.c Drivers/lvgl/src/misc/cache/class/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-misc-2f-cache-2f-class

clean-Drivers-2f-lvgl-2f-src-2f-misc-2f-cache-2f-class:
	-$(RM) ./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_ll.d ./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_ll.o ./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_ll.su ./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_rb.d ./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_rb.o ./Drivers/lvgl/src/misc/cache/class/lv_cache_lru_rb.su ./Drivers/lvgl/src/misc/cache/class/lv_cache_sc_da.d ./Drivers/lvgl/src/misc/cache/class/lv_cache_sc_da.o ./Drivers/lvgl/src/misc/cache/class/lv_cache_sc_da.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-misc-2f-cache-2f-class

