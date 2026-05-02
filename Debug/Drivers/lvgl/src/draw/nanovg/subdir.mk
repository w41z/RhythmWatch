################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_3d.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_arc.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_border.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_box_shadow.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_fill.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_grad.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_image.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_label.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_layer.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_line.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_mask_rect.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_triangle.c \
../Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_vector.c \
../Drivers/lvgl/src/draw/nanovg/lv_nanovg_fbo_cache.c \
../Drivers/lvgl/src/draw/nanovg/lv_nanovg_image_cache.c \
../Drivers/lvgl/src/draw/nanovg/lv_nanovg_utils.c 

OBJS += \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_3d.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_arc.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_border.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_box_shadow.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_fill.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_grad.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_image.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_label.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_layer.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_line.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_mask_rect.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_triangle.o \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_vector.o \
./Drivers/lvgl/src/draw/nanovg/lv_nanovg_fbo_cache.o \
./Drivers/lvgl/src/draw/nanovg/lv_nanovg_image_cache.o \
./Drivers/lvgl/src/draw/nanovg/lv_nanovg_utils.o 

C_DEPS += \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_3d.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_arc.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_border.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_box_shadow.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_fill.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_grad.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_image.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_label.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_layer.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_line.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_mask_rect.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_triangle.d \
./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_vector.d \
./Drivers/lvgl/src/draw/nanovg/lv_nanovg_fbo_cache.d \
./Drivers/lvgl/src/draw/nanovg/lv_nanovg_image_cache.d \
./Drivers/lvgl/src/draw/nanovg/lv_nanovg_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/nanovg/%.o Drivers/lvgl/src/draw/nanovg/%.su: ../Drivers/lvgl/src/draw/nanovg/%.c Drivers/lvgl/src/draw/nanovg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-nanovg

clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-nanovg:
	-$(RM) ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_3d.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_3d.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_3d.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_arc.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_arc.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_arc.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_border.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_border.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_border.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_box_shadow.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_box_shadow.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_box_shadow.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_fill.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_fill.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_fill.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_grad.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_grad.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_grad.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_image.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_image.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_image.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_label.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_label.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_label.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_layer.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_layer.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_layer.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_line.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_line.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_line.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_mask_rect.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_mask_rect.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_mask_rect.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_triangle.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_triangle.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_triangle.su ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_vector.d ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_vector.o ./Drivers/lvgl/src/draw/nanovg/lv_draw_nanovg_vector.su ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_fbo_cache.d ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_fbo_cache.o ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_fbo_cache.su ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_image_cache.d ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_image_cache.o ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_image_cache.su ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_utils.d ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_utils.o ./Drivers/lvgl/src/draw/nanovg/lv_nanovg_utils.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-nanovg

