################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_1.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_10.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_11.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_12.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_2.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_3.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_4.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_5.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_6.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_7.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_8.c \
../Drivers/lvgl/examples/widgets/scale/lv_example_scale_9.c 

OBJS += \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_1.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_10.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_11.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_12.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_2.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_3.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_4.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_5.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_6.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_7.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_8.o \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_9.o 

C_DEPS += \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_1.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_10.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_11.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_12.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_2.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_3.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_4.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_5.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_6.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_7.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_8.d \
./Drivers/lvgl/examples/widgets/scale/lv_example_scale_9.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/widgets/scale/%.o Drivers/lvgl/examples/widgets/scale/%.su: ../Drivers/lvgl/examples/widgets/scale/%.c Drivers/lvgl/examples/widgets/scale/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-scale

clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-scale:
	-$(RM) ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_1.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_1.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_1.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_10.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_10.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_10.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_11.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_11.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_11.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_12.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_12.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_12.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_2.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_2.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_2.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_3.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_3.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_3.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_4.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_4.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_4.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_5.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_5.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_5.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_6.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_6.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_6.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_7.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_7.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_7.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_8.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_8.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_8.su ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_9.d ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_9.o ./Drivers/lvgl/examples/widgets/scale/lv_example_scale_9.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-scale

