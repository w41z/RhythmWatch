################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_vector.c \
../Drivers/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.c 

OBJS += \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_vector.o \
./Drivers/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.o 

C_DEPS += \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_vector.d \
./Drivers/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/nema_gfx/%.o Drivers/lvgl/src/draw/nema_gfx/%.su: ../Drivers/lvgl/src/draw/nema_gfx/%.c Drivers/lvgl/src/draw/nema_gfx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-nema_gfx

clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-nema_gfx:
	-$(RM) ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.su ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_vector.d ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_vector.o ./Drivers/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_vector.su ./Drivers/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.d ./Drivers/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.o ./Drivers/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-nema_gfx

