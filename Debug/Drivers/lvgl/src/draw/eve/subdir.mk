################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/eve/lv_draw_eve.c \
../Drivers/lvgl/src/draw/eve/lv_draw_eve_arc.c \
../Drivers/lvgl/src/draw/eve/lv_draw_eve_fill.c \
../Drivers/lvgl/src/draw/eve/lv_draw_eve_image.c \
../Drivers/lvgl/src/draw/eve/lv_draw_eve_letter.c \
../Drivers/lvgl/src/draw/eve/lv_draw_eve_line.c \
../Drivers/lvgl/src/draw/eve/lv_draw_eve_ram_g.c \
../Drivers/lvgl/src/draw/eve/lv_draw_eve_triangle.c \
../Drivers/lvgl/src/draw/eve/lv_eve.c 

OBJS += \
./Drivers/lvgl/src/draw/eve/lv_draw_eve.o \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_arc.o \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_fill.o \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_image.o \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_letter.o \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_line.o \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_ram_g.o \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_triangle.o \
./Drivers/lvgl/src/draw/eve/lv_eve.o 

C_DEPS += \
./Drivers/lvgl/src/draw/eve/lv_draw_eve.d \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_arc.d \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_fill.d \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_image.d \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_letter.d \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_line.d \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_ram_g.d \
./Drivers/lvgl/src/draw/eve/lv_draw_eve_triangle.d \
./Drivers/lvgl/src/draw/eve/lv_eve.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/eve/%.o Drivers/lvgl/src/draw/eve/%.su: ../Drivers/lvgl/src/draw/eve/%.c Drivers/lvgl/src/draw/eve/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-eve

clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-eve:
	-$(RM) ./Drivers/lvgl/src/draw/eve/lv_draw_eve.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve.su ./Drivers/lvgl/src/draw/eve/lv_draw_eve_arc.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve_arc.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve_arc.su ./Drivers/lvgl/src/draw/eve/lv_draw_eve_fill.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve_fill.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve_fill.su ./Drivers/lvgl/src/draw/eve/lv_draw_eve_image.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve_image.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve_image.su ./Drivers/lvgl/src/draw/eve/lv_draw_eve_letter.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve_letter.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve_letter.su ./Drivers/lvgl/src/draw/eve/lv_draw_eve_line.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve_line.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve_line.su ./Drivers/lvgl/src/draw/eve/lv_draw_eve_ram_g.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve_ram_g.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve_ram_g.su ./Drivers/lvgl/src/draw/eve/lv_draw_eve_triangle.d ./Drivers/lvgl/src/draw/eve/lv_draw_eve_triangle.o ./Drivers/lvgl/src/draw/eve/lv_draw_eve_triangle.su ./Drivers/lvgl/src/draw/eve/lv_eve.d ./Drivers/lvgl/src/draw/eve/lv_eve.o ./Drivers/lvgl/src/draw/eve/lv_eve.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-eve

