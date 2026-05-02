################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/demos/widgets/lv_demo_widgets.c \
../Drivers/lvgl/demos/widgets/lv_demo_widgets_analytics.c \
../Drivers/lvgl/demos/widgets/lv_demo_widgets_components.c \
../Drivers/lvgl/demos/widgets/lv_demo_widgets_profile.c \
../Drivers/lvgl/demos/widgets/lv_demo_widgets_shop.c 

OBJS += \
./Drivers/lvgl/demos/widgets/lv_demo_widgets.o \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_analytics.o \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_components.o \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_profile.o \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_shop.o 

C_DEPS += \
./Drivers/lvgl/demos/widgets/lv_demo_widgets.d \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_analytics.d \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_components.d \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_profile.d \
./Drivers/lvgl/demos/widgets/lv_demo_widgets_shop.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/demos/widgets/%.o Drivers/lvgl/demos/widgets/%.su: ../Drivers/lvgl/demos/widgets/%.c Drivers/lvgl/demos/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-demos-2f-widgets

clean-Drivers-2f-lvgl-2f-demos-2f-widgets:
	-$(RM) ./Drivers/lvgl/demos/widgets/lv_demo_widgets.d ./Drivers/lvgl/demos/widgets/lv_demo_widgets.o ./Drivers/lvgl/demos/widgets/lv_demo_widgets.su ./Drivers/lvgl/demos/widgets/lv_demo_widgets_analytics.d ./Drivers/lvgl/demos/widgets/lv_demo_widgets_analytics.o ./Drivers/lvgl/demos/widgets/lv_demo_widgets_analytics.su ./Drivers/lvgl/demos/widgets/lv_demo_widgets_components.d ./Drivers/lvgl/demos/widgets/lv_demo_widgets_components.o ./Drivers/lvgl/demos/widgets/lv_demo_widgets_components.su ./Drivers/lvgl/demos/widgets/lv_demo_widgets_profile.d ./Drivers/lvgl/demos/widgets/lv_demo_widgets_profile.o ./Drivers/lvgl/demos/widgets/lv_demo_widgets_profile.su ./Drivers/lvgl/demos/widgets/lv_demo_widgets_shop.d ./Drivers/lvgl/demos/widgets/lv_demo_widgets_shop.o ./Drivers/lvgl/demos/widgets/lv_demo_widgets_shop.su

.PHONY: clean-Drivers-2f-lvgl-2f-demos-2f-widgets

