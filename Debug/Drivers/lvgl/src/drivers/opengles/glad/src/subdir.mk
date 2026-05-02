################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/drivers/opengles/glad/src/egl.c \
../Drivers/lvgl/src/drivers/opengles/glad/src/gl.c \
../Drivers/lvgl/src/drivers/opengles/glad/src/gles2.c 

OBJS += \
./Drivers/lvgl/src/drivers/opengles/glad/src/egl.o \
./Drivers/lvgl/src/drivers/opengles/glad/src/gl.o \
./Drivers/lvgl/src/drivers/opengles/glad/src/gles2.o 

C_DEPS += \
./Drivers/lvgl/src/drivers/opengles/glad/src/egl.d \
./Drivers/lvgl/src/drivers/opengles/glad/src/gl.d \
./Drivers/lvgl/src/drivers/opengles/glad/src/gles2.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/drivers/opengles/glad/src/%.o Drivers/lvgl/src/drivers/opengles/glad/src/%.su: ../Drivers/lvgl/src/drivers/opengles/glad/src/%.c Drivers/lvgl/src/drivers/opengles/glad/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-opengles-2f-glad-2f-src

clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-opengles-2f-glad-2f-src:
	-$(RM) ./Drivers/lvgl/src/drivers/opengles/glad/src/egl.d ./Drivers/lvgl/src/drivers/opengles/glad/src/egl.o ./Drivers/lvgl/src/drivers/opengles/glad/src/egl.su ./Drivers/lvgl/src/drivers/opengles/glad/src/gl.d ./Drivers/lvgl/src/drivers/opengles/glad/src/gl.o ./Drivers/lvgl/src/drivers/opengles/glad/src/gl.su ./Drivers/lvgl/src/drivers/opengles/glad/src/gles2.d ./Drivers/lvgl/src/drivers/opengles/glad/src/gles2.o ./Drivers/lvgl/src/drivers/opengles/glad/src/gles2.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-opengles-2f-glad-2f-src

