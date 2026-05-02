################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/drivers/opengles/lv_opengles_debug.c \
../Drivers/lvgl/src/drivers/opengles/lv_opengles_driver.c \
../Drivers/lvgl/src/drivers/opengles/lv_opengles_egl.c \
../Drivers/lvgl/src/drivers/opengles/lv_opengles_glfw.c \
../Drivers/lvgl/src/drivers/opengles/lv_opengles_texture.c 

OBJS += \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_debug.o \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_driver.o \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_egl.o \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_glfw.o \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_texture.o 

C_DEPS += \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_debug.d \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_driver.d \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_egl.d \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_glfw.d \
./Drivers/lvgl/src/drivers/opengles/lv_opengles_texture.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/drivers/opengles/%.o Drivers/lvgl/src/drivers/opengles/%.su: ../Drivers/lvgl/src/drivers/opengles/%.c Drivers/lvgl/src/drivers/opengles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-opengles

clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-opengles:
	-$(RM) ./Drivers/lvgl/src/drivers/opengles/lv_opengles_debug.d ./Drivers/lvgl/src/drivers/opengles/lv_opengles_debug.o ./Drivers/lvgl/src/drivers/opengles/lv_opengles_debug.su ./Drivers/lvgl/src/drivers/opengles/lv_opengles_driver.d ./Drivers/lvgl/src/drivers/opengles/lv_opengles_driver.o ./Drivers/lvgl/src/drivers/opengles/lv_opengles_driver.su ./Drivers/lvgl/src/drivers/opengles/lv_opengles_egl.d ./Drivers/lvgl/src/drivers/opengles/lv_opengles_egl.o ./Drivers/lvgl/src/drivers/opengles/lv_opengles_egl.su ./Drivers/lvgl/src/drivers/opengles/lv_opengles_glfw.d ./Drivers/lvgl/src/drivers/opengles/lv_opengles_glfw.o ./Drivers/lvgl/src/drivers/opengles/lv_opengles_glfw.su ./Drivers/lvgl/src/drivers/opengles/lv_opengles_texture.d ./Drivers/lvgl/src/drivers/opengles/lv_opengles_texture.o ./Drivers/lvgl/src/drivers/opengles/lv_opengles_texture.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-opengles

