################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/drivers/display/drm/lv_linux_drm.c \
../Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_common.c \
../Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_egl.c 

OBJS += \
./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm.o \
./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_common.o \
./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_egl.o 

C_DEPS += \
./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm.d \
./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_common.d \
./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_egl.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/drivers/display/drm/%.o Drivers/lvgl/src/drivers/display/drm/%.su: ../Drivers/lvgl/src/drivers/display/drm/%.c Drivers/lvgl/src/drivers/display/drm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-display-2f-drm

clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-display-2f-drm:
	-$(RM) ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm.d ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm.o ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm.su ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_common.d ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_common.o ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_common.su ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_egl.d ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_egl.o ./Drivers/lvgl/src/drivers/display/drm/lv_linux_drm_egl.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-display-2f-drm

