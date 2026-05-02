################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/porting/lv_port_disp_template.c \
../Drivers/lvgl/examples/porting/lv_port_fs_template.c \
../Drivers/lvgl/examples/porting/lv_port_indev_template.c \
../Drivers/lvgl/examples/porting/lv_port_lcd_stm32_template.c 

OBJS += \
./Drivers/lvgl/examples/porting/lv_port_disp_template.o \
./Drivers/lvgl/examples/porting/lv_port_fs_template.o \
./Drivers/lvgl/examples/porting/lv_port_indev_template.o \
./Drivers/lvgl/examples/porting/lv_port_lcd_stm32_template.o 

C_DEPS += \
./Drivers/lvgl/examples/porting/lv_port_disp_template.d \
./Drivers/lvgl/examples/porting/lv_port_fs_template.d \
./Drivers/lvgl/examples/porting/lv_port_indev_template.d \
./Drivers/lvgl/examples/porting/lv_port_lcd_stm32_template.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/porting/%.o Drivers/lvgl/examples/porting/%.su: ../Drivers/lvgl/examples/porting/%.c Drivers/lvgl/examples/porting/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-porting

clean-Drivers-2f-lvgl-2f-examples-2f-porting:
	-$(RM) ./Drivers/lvgl/examples/porting/lv_port_disp_template.d ./Drivers/lvgl/examples/porting/lv_port_disp_template.o ./Drivers/lvgl/examples/porting/lv_port_disp_template.su ./Drivers/lvgl/examples/porting/lv_port_fs_template.d ./Drivers/lvgl/examples/porting/lv_port_fs_template.o ./Drivers/lvgl/examples/porting/lv_port_fs_template.su ./Drivers/lvgl/examples/porting/lv_port_indev_template.d ./Drivers/lvgl/examples/porting/lv_port_indev_template.o ./Drivers/lvgl/examples/porting/lv_port_indev_template.su ./Drivers/lvgl/examples/porting/lv_port_lcd_stm32_template.d ./Drivers/lvgl/examples/porting/lv_port_lcd_stm32_template.o ./Drivers/lvgl/examples/porting/lv_port_lcd_stm32_template.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-porting

