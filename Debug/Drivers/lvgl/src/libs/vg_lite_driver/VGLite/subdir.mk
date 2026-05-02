################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite.c \
../Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_image.c \
../Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_matrix.c \
../Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_path.c \
../Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_stroke.c 

OBJS += \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite.o \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_image.o \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_matrix.o \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_path.o \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_stroke.o 

C_DEPS += \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite.d \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_image.d \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_matrix.d \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_path.d \
./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_stroke.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/vg_lite_driver/VGLite/%.o Drivers/lvgl/src/libs/vg_lite_driver/VGLite/%.su: ../Drivers/lvgl/src/libs/vg_lite_driver/VGLite/%.c Drivers/lvgl/src/libs/vg_lite_driver/VGLite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-vg_lite_driver-2f-VGLite

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-vg_lite_driver-2f-VGLite:
	-$(RM) ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite.d ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite.o ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite.su ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_image.d ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_image.o ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_image.su ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_matrix.d ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_matrix.o ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_matrix.su ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_path.d ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_path.o ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_path.su ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_stroke.d ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_stroke.o ./Drivers/lvgl/src/libs/vg_lite_driver/VGLite/vg_lite_stroke.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-vg_lite_driver-2f-VGLite

