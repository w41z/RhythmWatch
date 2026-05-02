################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/assets/animimg001.c \
../Drivers/lvgl/examples/assets/animimg002.c \
../Drivers/lvgl/examples/assets/animimg003.c \
../Drivers/lvgl/examples/assets/img_caret_down.c \
../Drivers/lvgl/examples/assets/img_cogwheel_argb.c \
../Drivers/lvgl/examples/assets/img_cogwheel_indexed16.c \
../Drivers/lvgl/examples/assets/img_cogwheel_rgb.c \
../Drivers/lvgl/examples/assets/img_hand.c \
../Drivers/lvgl/examples/assets/img_multilang_like.c \
../Drivers/lvgl/examples/assets/img_skew_strip.c \
../Drivers/lvgl/examples/assets/img_star.c \
../Drivers/lvgl/examples/assets/img_svg_img.c \
../Drivers/lvgl/examples/assets/img_transform_avatar_15.c \
../Drivers/lvgl/examples/assets/imgbtn_left.c \
../Drivers/lvgl/examples/assets/imgbtn_mid.c \
../Drivers/lvgl/examples/assets/imgbtn_right.c 

OBJS += \
./Drivers/lvgl/examples/assets/animimg001.o \
./Drivers/lvgl/examples/assets/animimg002.o \
./Drivers/lvgl/examples/assets/animimg003.o \
./Drivers/lvgl/examples/assets/img_caret_down.o \
./Drivers/lvgl/examples/assets/img_cogwheel_argb.o \
./Drivers/lvgl/examples/assets/img_cogwheel_indexed16.o \
./Drivers/lvgl/examples/assets/img_cogwheel_rgb.o \
./Drivers/lvgl/examples/assets/img_hand.o \
./Drivers/lvgl/examples/assets/img_multilang_like.o \
./Drivers/lvgl/examples/assets/img_skew_strip.o \
./Drivers/lvgl/examples/assets/img_star.o \
./Drivers/lvgl/examples/assets/img_svg_img.o \
./Drivers/lvgl/examples/assets/img_transform_avatar_15.o \
./Drivers/lvgl/examples/assets/imgbtn_left.o \
./Drivers/lvgl/examples/assets/imgbtn_mid.o \
./Drivers/lvgl/examples/assets/imgbtn_right.o 

C_DEPS += \
./Drivers/lvgl/examples/assets/animimg001.d \
./Drivers/lvgl/examples/assets/animimg002.d \
./Drivers/lvgl/examples/assets/animimg003.d \
./Drivers/lvgl/examples/assets/img_caret_down.d \
./Drivers/lvgl/examples/assets/img_cogwheel_argb.d \
./Drivers/lvgl/examples/assets/img_cogwheel_indexed16.d \
./Drivers/lvgl/examples/assets/img_cogwheel_rgb.d \
./Drivers/lvgl/examples/assets/img_hand.d \
./Drivers/lvgl/examples/assets/img_multilang_like.d \
./Drivers/lvgl/examples/assets/img_skew_strip.d \
./Drivers/lvgl/examples/assets/img_star.d \
./Drivers/lvgl/examples/assets/img_svg_img.d \
./Drivers/lvgl/examples/assets/img_transform_avatar_15.d \
./Drivers/lvgl/examples/assets/imgbtn_left.d \
./Drivers/lvgl/examples/assets/imgbtn_mid.d \
./Drivers/lvgl/examples/assets/imgbtn_right.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/assets/%.o Drivers/lvgl/examples/assets/%.su: ../Drivers/lvgl/examples/assets/%.c Drivers/lvgl/examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-assets

clean-Drivers-2f-lvgl-2f-examples-2f-assets:
	-$(RM) ./Drivers/lvgl/examples/assets/animimg001.d ./Drivers/lvgl/examples/assets/animimg001.o ./Drivers/lvgl/examples/assets/animimg001.su ./Drivers/lvgl/examples/assets/animimg002.d ./Drivers/lvgl/examples/assets/animimg002.o ./Drivers/lvgl/examples/assets/animimg002.su ./Drivers/lvgl/examples/assets/animimg003.d ./Drivers/lvgl/examples/assets/animimg003.o ./Drivers/lvgl/examples/assets/animimg003.su ./Drivers/lvgl/examples/assets/img_caret_down.d ./Drivers/lvgl/examples/assets/img_caret_down.o ./Drivers/lvgl/examples/assets/img_caret_down.su ./Drivers/lvgl/examples/assets/img_cogwheel_argb.d ./Drivers/lvgl/examples/assets/img_cogwheel_argb.o ./Drivers/lvgl/examples/assets/img_cogwheel_argb.su ./Drivers/lvgl/examples/assets/img_cogwheel_indexed16.d ./Drivers/lvgl/examples/assets/img_cogwheel_indexed16.o ./Drivers/lvgl/examples/assets/img_cogwheel_indexed16.su ./Drivers/lvgl/examples/assets/img_cogwheel_rgb.d ./Drivers/lvgl/examples/assets/img_cogwheel_rgb.o ./Drivers/lvgl/examples/assets/img_cogwheel_rgb.su ./Drivers/lvgl/examples/assets/img_hand.d ./Drivers/lvgl/examples/assets/img_hand.o ./Drivers/lvgl/examples/assets/img_hand.su ./Drivers/lvgl/examples/assets/img_multilang_like.d ./Drivers/lvgl/examples/assets/img_multilang_like.o ./Drivers/lvgl/examples/assets/img_multilang_like.su ./Drivers/lvgl/examples/assets/img_skew_strip.d ./Drivers/lvgl/examples/assets/img_skew_strip.o ./Drivers/lvgl/examples/assets/img_skew_strip.su ./Drivers/lvgl/examples/assets/img_star.d ./Drivers/lvgl/examples/assets/img_star.o ./Drivers/lvgl/examples/assets/img_star.su ./Drivers/lvgl/examples/assets/img_svg_img.d ./Drivers/lvgl/examples/assets/img_svg_img.o ./Drivers/lvgl/examples/assets/img_svg_img.su ./Drivers/lvgl/examples/assets/img_transform_avatar_15.d ./Drivers/lvgl/examples/assets/img_transform_avatar_15.o ./Drivers/lvgl/examples/assets/img_transform_avatar_15.su ./Drivers/lvgl/examples/assets/imgbtn_left.d ./Drivers/lvgl/examples/assets/imgbtn_left.o ./Drivers/lvgl/examples/assets/imgbtn_left.su ./Drivers/lvgl/examples/assets/imgbtn_mid.d ./Drivers/lvgl/examples/assets/imgbtn_mid.o ./Drivers/lvgl/examples/assets/imgbtn_mid.su ./Drivers/lvgl/examples/assets/imgbtn_right.d ./Drivers/lvgl/examples/assets/imgbtn_right.o ./Drivers/lvgl/examples/assets/imgbtn_right.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-assets

