################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/widgets/arclabel/lv_example_arclabel_1.c 

OBJS += \
./Drivers/lvgl/examples/widgets/arclabel/lv_example_arclabel_1.o 

C_DEPS += \
./Drivers/lvgl/examples/widgets/arclabel/lv_example_arclabel_1.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/widgets/arclabel/%.o Drivers/lvgl/examples/widgets/arclabel/%.su: ../Drivers/lvgl/examples/widgets/arclabel/%.c Drivers/lvgl/examples/widgets/arclabel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-arclabel

clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-arclabel:
	-$(RM) ./Drivers/lvgl/examples/widgets/arclabel/lv_example_arclabel_1.d ./Drivers/lvgl/examples/widgets/arclabel/lv_example_arclabel_1.o ./Drivers/lvgl/examples/widgets/arclabel/lv_example_arclabel_1.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-arclabel

