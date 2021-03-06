################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/PID.c \
../Core/Src/adxl345.c \
../Core/Src/analog_read.c \
../Core/Src/app_freertos.c \
../Core/Src/as5600.c \
../Core/Src/main.c \
../Core/Src/pwm.c \
../Core/Src/stm32g0xx_hal_msp.c \
../Core/Src/stm32g0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32g0xx.c 

C_DEPS += \
./Core/Src/PID.d \
./Core/Src/adxl345.d \
./Core/Src/analog_read.d \
./Core/Src/app_freertos.d \
./Core/Src/as5600.d \
./Core/Src/main.d \
./Core/Src/pwm.d \
./Core/Src/stm32g0xx_hal_msp.d \
./Core/Src/stm32g0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32g0xx.d 

OBJS += \
./Core/Src/PID.o \
./Core/Src/adxl345.o \
./Core/Src/analog_read.o \
./Core/Src/app_freertos.o \
./Core/Src/as5600.o \
./Core/Src/main.o \
./Core/Src/pwm.o \
./Core/Src/stm32g0xx_hal_msp.o \
./Core/Src/stm32g0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32g0xx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx '-DCMSIS_device_header=<stm32g0xx.h>' -c -I../Core/Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/PID.d ./Core/Src/PID.o ./Core/Src/adxl345.d ./Core/Src/adxl345.o ./Core/Src/analog_read.d ./Core/Src/analog_read.o ./Core/Src/app_freertos.d ./Core/Src/app_freertos.o ./Core/Src/as5600.d ./Core/Src/as5600.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/pwm.d ./Core/Src/pwm.o ./Core/Src/stm32g0xx_hal_msp.d ./Core/Src/stm32g0xx_hal_msp.o ./Core/Src/stm32g0xx_it.d ./Core/Src/stm32g0xx_it.o ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/system_stm32g0xx.d ./Core/Src/system_stm32g0xx.o

.PHONY: clean-Core-2f-Src

