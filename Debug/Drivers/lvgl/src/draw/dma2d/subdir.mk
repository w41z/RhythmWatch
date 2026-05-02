################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d.c \
../Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_fill.c \
../Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_img.c 

OBJS += \
./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d.o \
./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_fill.o \
./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_img.o 

C_DEPS += \
./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d.d \
./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_fill.d \
./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_img.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/dma2d/%.o Drivers/lvgl/src/draw/dma2d/%.su: ../Drivers/lvgl/src/draw/dma2d/%.c Drivers/lvgl/src/draw/dma2d/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-dma2d

clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-dma2d:
	-$(RM) ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d.d ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d.o ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d.su ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_fill.d ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_fill.o ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_fill.su ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_img.d ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_img.o ./Drivers/lvgl/src/draw/dma2d/lv_draw_dma2d_img.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-dma2d

