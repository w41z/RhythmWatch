################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/drivers/wayland/lv_wayland.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_egl.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_g2d.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_shm.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_keyboard.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_pointer.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_seat.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_touch.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_window.c \
../Drivers/lvgl/src/drivers/wayland/lv_wayland_xdg_shell.c 

OBJS += \
./Drivers/lvgl/src/drivers/wayland/lv_wayland.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_egl.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_g2d.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_shm.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_keyboard.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_pointer.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_seat.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_touch.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_window.o \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_xdg_shell.o 

C_DEPS += \
./Drivers/lvgl/src/drivers/wayland/lv_wayland.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_egl.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_g2d.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_shm.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_keyboard.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_pointer.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_seat.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_touch.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_window.d \
./Drivers/lvgl/src/drivers/wayland/lv_wayland_xdg_shell.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/drivers/wayland/%.o Drivers/lvgl/src/drivers/wayland/%.su: ../Drivers/lvgl/src/drivers/wayland/%.c Drivers/lvgl/src/drivers/wayland/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DLV_CONF_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SYSTEM -DLV_LVGL_H_INCLUDE_SIMPLE -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/lvgl -I../Drivers/display -I../Drivers/testui -I../Drivers/lvgl/src -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-wayland

clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-wayland:
	-$(RM) ./Drivers/lvgl/src/drivers/wayland/lv_wayland.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_egl.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_egl.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_egl.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_g2d.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_g2d.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_g2d.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_shm.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_shm.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_backend_shm.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_keyboard.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_keyboard.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_keyboard.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_pointer.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_pointer.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_pointer.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_seat.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_seat.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_seat.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_touch.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_touch.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_touch.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_window.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_window.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_window.su ./Drivers/lvgl/src/drivers/wayland/lv_wayland_xdg_shell.d ./Drivers/lvgl/src/drivers/wayland/lv_wayland_xdg_shell.o ./Drivers/lvgl/src/drivers/wayland/lv_wayland_xdg_shell.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-wayland

