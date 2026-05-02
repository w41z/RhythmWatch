################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_1.c \
../Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_2.c \
../Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_approve.c 

OBJS += \
./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_1.o \
./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_2.o \
./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_approve.o 

C_DEPS += \
./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_1.d \
./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_2.d \
./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_approve.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/widgets/lottie/%.o Drivers/lvgl/examples/widgets/lottie/%.su: ../Drivers/lvgl/examples/widgets/lottie/%.c Drivers/lvgl/examples/widgets/lottie/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-lottie

clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-lottie:
	-$(RM) ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_1.d ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_1.o ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_1.su ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_2.d ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_2.o ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_2.su ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_approve.d ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_approve.o ./Drivers/lvgl/examples/widgets/lottie/lv_example_lottie_approve.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-lottie

