################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/layouts/grid/lv_example_grid_1.c \
../Drivers/lvgl/examples/layouts/grid/lv_example_grid_2.c \
../Drivers/lvgl/examples/layouts/grid/lv_example_grid_3.c \
../Drivers/lvgl/examples/layouts/grid/lv_example_grid_4.c \
../Drivers/lvgl/examples/layouts/grid/lv_example_grid_5.c \
../Drivers/lvgl/examples/layouts/grid/lv_example_grid_6.c 

OBJS += \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_1.o \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_2.o \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_3.o \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_4.o \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_5.o \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_6.o 

C_DEPS += \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_1.d \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_2.d \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_3.d \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_4.d \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_5.d \
./Drivers/lvgl/examples/layouts/grid/lv_example_grid_6.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/layouts/grid/%.o Drivers/lvgl/examples/layouts/grid/%.su: ../Drivers/lvgl/examples/layouts/grid/%.c Drivers/lvgl/examples/layouts/grid/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-layouts-2f-grid

clean-Drivers-2f-lvgl-2f-examples-2f-layouts-2f-grid:
	-$(RM) ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_1.d ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_1.o ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_1.su ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_2.d ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_2.o ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_2.su ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_3.d ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_3.o ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_3.su ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_4.d ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_4.o ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_4.su ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_5.d ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_5.o ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_5.su ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_6.d ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_6.o ./Drivers/lvgl/examples/layouts/grid/lv_example_grid_6.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-layouts-2f-grid

