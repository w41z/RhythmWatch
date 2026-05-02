################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/lv_draw.c \
../Drivers/lvgl/src/draw/lv_draw_3d.c \
../Drivers/lvgl/src/draw/lv_draw_arc.c \
../Drivers/lvgl/src/draw/lv_draw_blur.c \
../Drivers/lvgl/src/draw/lv_draw_buf.c \
../Drivers/lvgl/src/draw/lv_draw_image.c \
../Drivers/lvgl/src/draw/lv_draw_label.c \
../Drivers/lvgl/src/draw/lv_draw_line.c \
../Drivers/lvgl/src/draw/lv_draw_mask.c \
../Drivers/lvgl/src/draw/lv_draw_rect.c \
../Drivers/lvgl/src/draw/lv_draw_triangle.c \
../Drivers/lvgl/src/draw/lv_draw_vector.c \
../Drivers/lvgl/src/draw/lv_image_decoder.c 

OBJS += \
./Drivers/lvgl/src/draw/lv_draw.o \
./Drivers/lvgl/src/draw/lv_draw_3d.o \
./Drivers/lvgl/src/draw/lv_draw_arc.o \
./Drivers/lvgl/src/draw/lv_draw_blur.o \
./Drivers/lvgl/src/draw/lv_draw_buf.o \
./Drivers/lvgl/src/draw/lv_draw_image.o \
./Drivers/lvgl/src/draw/lv_draw_label.o \
./Drivers/lvgl/src/draw/lv_draw_line.o \
./Drivers/lvgl/src/draw/lv_draw_mask.o \
./Drivers/lvgl/src/draw/lv_draw_rect.o \
./Drivers/lvgl/src/draw/lv_draw_triangle.o \
./Drivers/lvgl/src/draw/lv_draw_vector.o \
./Drivers/lvgl/src/draw/lv_image_decoder.o 

C_DEPS += \
./Drivers/lvgl/src/draw/lv_draw.d \
./Drivers/lvgl/src/draw/lv_draw_3d.d \
./Drivers/lvgl/src/draw/lv_draw_arc.d \
./Drivers/lvgl/src/draw/lv_draw_blur.d \
./Drivers/lvgl/src/draw/lv_draw_buf.d \
./Drivers/lvgl/src/draw/lv_draw_image.d \
./Drivers/lvgl/src/draw/lv_draw_label.d \
./Drivers/lvgl/src/draw/lv_draw_line.d \
./Drivers/lvgl/src/draw/lv_draw_mask.d \
./Drivers/lvgl/src/draw/lv_draw_rect.d \
./Drivers/lvgl/src/draw/lv_draw_triangle.d \
./Drivers/lvgl/src/draw/lv_draw_vector.d \
./Drivers/lvgl/src/draw/lv_image_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/%.o Drivers/lvgl/src/draw/%.su: ../Drivers/lvgl/src/draw/%.c Drivers/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw

clean-Drivers-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Drivers/lvgl/src/draw/lv_draw.d ./Drivers/lvgl/src/draw/lv_draw.o ./Drivers/lvgl/src/draw/lv_draw.su ./Drivers/lvgl/src/draw/lv_draw_3d.d ./Drivers/lvgl/src/draw/lv_draw_3d.o ./Drivers/lvgl/src/draw/lv_draw_3d.su ./Drivers/lvgl/src/draw/lv_draw_arc.d ./Drivers/lvgl/src/draw/lv_draw_arc.o ./Drivers/lvgl/src/draw/lv_draw_arc.su ./Drivers/lvgl/src/draw/lv_draw_blur.d ./Drivers/lvgl/src/draw/lv_draw_blur.o ./Drivers/lvgl/src/draw/lv_draw_blur.su ./Drivers/lvgl/src/draw/lv_draw_buf.d ./Drivers/lvgl/src/draw/lv_draw_buf.o ./Drivers/lvgl/src/draw/lv_draw_buf.su ./Drivers/lvgl/src/draw/lv_draw_image.d ./Drivers/lvgl/src/draw/lv_draw_image.o ./Drivers/lvgl/src/draw/lv_draw_image.su ./Drivers/lvgl/src/draw/lv_draw_label.d ./Drivers/lvgl/src/draw/lv_draw_label.o ./Drivers/lvgl/src/draw/lv_draw_label.su ./Drivers/lvgl/src/draw/lv_draw_line.d ./Drivers/lvgl/src/draw/lv_draw_line.o ./Drivers/lvgl/src/draw/lv_draw_line.su ./Drivers/lvgl/src/draw/lv_draw_mask.d ./Drivers/lvgl/src/draw/lv_draw_mask.o ./Drivers/lvgl/src/draw/lv_draw_mask.su ./Drivers/lvgl/src/draw/lv_draw_rect.d ./Drivers/lvgl/src/draw/lv_draw_rect.o ./Drivers/lvgl/src/draw/lv_draw_rect.su ./Drivers/lvgl/src/draw/lv_draw_triangle.d ./Drivers/lvgl/src/draw/lv_draw_triangle.o ./Drivers/lvgl/src/draw/lv_draw_triangle.su ./Drivers/lvgl/src/draw/lv_draw_vector.d ./Drivers/lvgl/src/draw/lv_draw_vector.o ./Drivers/lvgl/src/draw/lv_draw_vector.su ./Drivers/lvgl/src/draw/lv_image_decoder.d ./Drivers/lvgl/src/draw/lv_image_decoder.o ./Drivers/lvgl/src/draw/lv_image_decoder.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw

