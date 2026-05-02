################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/widgets/property/lv_animimage_properties.c \
../Drivers/lvgl/src/widgets/property/lv_arc_properties.c \
../Drivers/lvgl/src/widgets/property/lv_bar_properties.c \
../Drivers/lvgl/src/widgets/property/lv_buttonmatrix_properties.c \
../Drivers/lvgl/src/widgets/property/lv_chart_properties.c \
../Drivers/lvgl/src/widgets/property/lv_checkbox_properties.c \
../Drivers/lvgl/src/widgets/property/lv_dropdown_properties.c \
../Drivers/lvgl/src/widgets/property/lv_image_properties.c \
../Drivers/lvgl/src/widgets/property/lv_keyboard_properties.c \
../Drivers/lvgl/src/widgets/property/lv_label_properties.c \
../Drivers/lvgl/src/widgets/property/lv_led_properties.c \
../Drivers/lvgl/src/widgets/property/lv_line_properties.c \
../Drivers/lvgl/src/widgets/property/lv_menu_properties.c \
../Drivers/lvgl/src/widgets/property/lv_obj_properties.c \
../Drivers/lvgl/src/widgets/property/lv_roller_properties.c \
../Drivers/lvgl/src/widgets/property/lv_scale_properties.c \
../Drivers/lvgl/src/widgets/property/lv_slider_properties.c \
../Drivers/lvgl/src/widgets/property/lv_span_properties.c \
../Drivers/lvgl/src/widgets/property/lv_spinbox_properties.c \
../Drivers/lvgl/src/widgets/property/lv_spinner_properties.c \
../Drivers/lvgl/src/widgets/property/lv_style_properties.c \
../Drivers/lvgl/src/widgets/property/lv_switch_properties.c \
../Drivers/lvgl/src/widgets/property/lv_table_properties.c \
../Drivers/lvgl/src/widgets/property/lv_tabview_properties.c \
../Drivers/lvgl/src/widgets/property/lv_textarea_properties.c 

OBJS += \
./Drivers/lvgl/src/widgets/property/lv_animimage_properties.o \
./Drivers/lvgl/src/widgets/property/lv_arc_properties.o \
./Drivers/lvgl/src/widgets/property/lv_bar_properties.o \
./Drivers/lvgl/src/widgets/property/lv_buttonmatrix_properties.o \
./Drivers/lvgl/src/widgets/property/lv_chart_properties.o \
./Drivers/lvgl/src/widgets/property/lv_checkbox_properties.o \
./Drivers/lvgl/src/widgets/property/lv_dropdown_properties.o \
./Drivers/lvgl/src/widgets/property/lv_image_properties.o \
./Drivers/lvgl/src/widgets/property/lv_keyboard_properties.o \
./Drivers/lvgl/src/widgets/property/lv_label_properties.o \
./Drivers/lvgl/src/widgets/property/lv_led_properties.o \
./Drivers/lvgl/src/widgets/property/lv_line_properties.o \
./Drivers/lvgl/src/widgets/property/lv_menu_properties.o \
./Drivers/lvgl/src/widgets/property/lv_obj_properties.o \
./Drivers/lvgl/src/widgets/property/lv_roller_properties.o \
./Drivers/lvgl/src/widgets/property/lv_scale_properties.o \
./Drivers/lvgl/src/widgets/property/lv_slider_properties.o \
./Drivers/lvgl/src/widgets/property/lv_span_properties.o \
./Drivers/lvgl/src/widgets/property/lv_spinbox_properties.o \
./Drivers/lvgl/src/widgets/property/lv_spinner_properties.o \
./Drivers/lvgl/src/widgets/property/lv_style_properties.o \
./Drivers/lvgl/src/widgets/property/lv_switch_properties.o \
./Drivers/lvgl/src/widgets/property/lv_table_properties.o \
./Drivers/lvgl/src/widgets/property/lv_tabview_properties.o \
./Drivers/lvgl/src/widgets/property/lv_textarea_properties.o 

C_DEPS += \
./Drivers/lvgl/src/widgets/property/lv_animimage_properties.d \
./Drivers/lvgl/src/widgets/property/lv_arc_properties.d \
./Drivers/lvgl/src/widgets/property/lv_bar_properties.d \
./Drivers/lvgl/src/widgets/property/lv_buttonmatrix_properties.d \
./Drivers/lvgl/src/widgets/property/lv_chart_properties.d \
./Drivers/lvgl/src/widgets/property/lv_checkbox_properties.d \
./Drivers/lvgl/src/widgets/property/lv_dropdown_properties.d \
./Drivers/lvgl/src/widgets/property/lv_image_properties.d \
./Drivers/lvgl/src/widgets/property/lv_keyboard_properties.d \
./Drivers/lvgl/src/widgets/property/lv_label_properties.d \
./Drivers/lvgl/src/widgets/property/lv_led_properties.d \
./Drivers/lvgl/src/widgets/property/lv_line_properties.d \
./Drivers/lvgl/src/widgets/property/lv_menu_properties.d \
./Drivers/lvgl/src/widgets/property/lv_obj_properties.d \
./Drivers/lvgl/src/widgets/property/lv_roller_properties.d \
./Drivers/lvgl/src/widgets/property/lv_scale_properties.d \
./Drivers/lvgl/src/widgets/property/lv_slider_properties.d \
./Drivers/lvgl/src/widgets/property/lv_span_properties.d \
./Drivers/lvgl/src/widgets/property/lv_spinbox_properties.d \
./Drivers/lvgl/src/widgets/property/lv_spinner_properties.d \
./Drivers/lvgl/src/widgets/property/lv_style_properties.d \
./Drivers/lvgl/src/widgets/property/lv_switch_properties.d \
./Drivers/lvgl/src/widgets/property/lv_table_properties.d \
./Drivers/lvgl/src/widgets/property/lv_tabview_properties.d \
./Drivers/lvgl/src/widgets/property/lv_textarea_properties.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/widgets/property/%.o Drivers/lvgl/src/widgets/property/%.su: ../Drivers/lvgl/src/widgets/property/%.c Drivers/lvgl/src/widgets/property/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-property

clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-property:
	-$(RM) ./Drivers/lvgl/src/widgets/property/lv_animimage_properties.d ./Drivers/lvgl/src/widgets/property/lv_animimage_properties.o ./Drivers/lvgl/src/widgets/property/lv_animimage_properties.su ./Drivers/lvgl/src/widgets/property/lv_arc_properties.d ./Drivers/lvgl/src/widgets/property/lv_arc_properties.o ./Drivers/lvgl/src/widgets/property/lv_arc_properties.su ./Drivers/lvgl/src/widgets/property/lv_bar_properties.d ./Drivers/lvgl/src/widgets/property/lv_bar_properties.o ./Drivers/lvgl/src/widgets/property/lv_bar_properties.su ./Drivers/lvgl/src/widgets/property/lv_buttonmatrix_properties.d ./Drivers/lvgl/src/widgets/property/lv_buttonmatrix_properties.o ./Drivers/lvgl/src/widgets/property/lv_buttonmatrix_properties.su ./Drivers/lvgl/src/widgets/property/lv_chart_properties.d ./Drivers/lvgl/src/widgets/property/lv_chart_properties.o ./Drivers/lvgl/src/widgets/property/lv_chart_properties.su ./Drivers/lvgl/src/widgets/property/lv_checkbox_properties.d ./Drivers/lvgl/src/widgets/property/lv_checkbox_properties.o ./Drivers/lvgl/src/widgets/property/lv_checkbox_properties.su ./Drivers/lvgl/src/widgets/property/lv_dropdown_properties.d ./Drivers/lvgl/src/widgets/property/lv_dropdown_properties.o ./Drivers/lvgl/src/widgets/property/lv_dropdown_properties.su ./Drivers/lvgl/src/widgets/property/lv_image_properties.d ./Drivers/lvgl/src/widgets/property/lv_image_properties.o ./Drivers/lvgl/src/widgets/property/lv_image_properties.su ./Drivers/lvgl/src/widgets/property/lv_keyboard_properties.d ./Drivers/lvgl/src/widgets/property/lv_keyboard_properties.o ./Drivers/lvgl/src/widgets/property/lv_keyboard_properties.su ./Drivers/lvgl/src/widgets/property/lv_label_properties.d ./Drivers/lvgl/src/widgets/property/lv_label_properties.o ./Drivers/lvgl/src/widgets/property/lv_label_properties.su ./Drivers/lvgl/src/widgets/property/lv_led_properties.d ./Drivers/lvgl/src/widgets/property/lv_led_properties.o ./Drivers/lvgl/src/widgets/property/lv_led_properties.su ./Drivers/lvgl/src/widgets/property/lv_line_properties.d ./Drivers/lvgl/src/widgets/property/lv_line_properties.o ./Drivers/lvgl/src/widgets/property/lv_line_properties.su ./Drivers/lvgl/src/widgets/property/lv_menu_properties.d ./Drivers/lvgl/src/widgets/property/lv_menu_properties.o ./Drivers/lvgl/src/widgets/property/lv_menu_properties.su ./Drivers/lvgl/src/widgets/property/lv_obj_properties.d ./Drivers/lvgl/src/widgets/property/lv_obj_properties.o ./Drivers/lvgl/src/widgets/property/lv_obj_properties.su ./Drivers/lvgl/src/widgets/property/lv_roller_properties.d ./Drivers/lvgl/src/widgets/property/lv_roller_properties.o ./Drivers/lvgl/src/widgets/property/lv_roller_properties.su ./Drivers/lvgl/src/widgets/property/lv_scale_properties.d ./Drivers/lvgl/src/widgets/property/lv_scale_properties.o ./Drivers/lvgl/src/widgets/property/lv_scale_properties.su ./Drivers/lvgl/src/widgets/property/lv_slider_properties.d ./Drivers/lvgl/src/widgets/property/lv_slider_properties.o ./Drivers/lvgl/src/widgets/property/lv_slider_properties.su ./Drivers/lvgl/src/widgets/property/lv_span_properties.d ./Drivers/lvgl/src/widgets/property/lv_span_properties.o ./Drivers/lvgl/src/widgets/property/lv_span_properties.su ./Drivers/lvgl/src/widgets/property/lv_spinbox_properties.d ./Drivers/lvgl/src/widgets/property/lv_spinbox_properties.o ./Drivers/lvgl/src/widgets/property/lv_spinbox_properties.su ./Drivers/lvgl/src/widgets/property/lv_spinner_properties.d ./Drivers/lvgl/src/widgets/property/lv_spinner_properties.o ./Drivers/lvgl/src/widgets/property/lv_spinner_properties.su ./Drivers/lvgl/src/widgets/property/lv_style_properties.d ./Drivers/lvgl/src/widgets/property/lv_style_properties.o ./Drivers/lvgl/src/widgets/property/lv_style_properties.su ./Drivers/lvgl/src/widgets/property/lv_switch_properties.d ./Drivers/lvgl/src/widgets/property/lv_switch_properties.o ./Drivers/lvgl/src/widgets/property/lv_switch_properties.su ./Drivers/lvgl/src/widgets/property/lv_table_properties.d ./Drivers/lvgl/src/widgets/property/lv_table_properties.o ./Drivers/lvgl/src/widgets/property/lv_table_properties.su ./Drivers/lvgl/src/widgets/property/lv_tabview_properties.d ./Drivers/lvgl/src/widgets/property/lv_tabview_properties.o ./Drivers/lvgl/src/widgets/property/lv_tabview_properties.su ./Drivers/lvgl/src/widgets/property/lv_textarea_properties.d ./Drivers/lvgl/src/widgets/property/lv_textarea_properties.o ./Drivers/lvgl/src/widgets/property/lv_textarea_properties.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-property

