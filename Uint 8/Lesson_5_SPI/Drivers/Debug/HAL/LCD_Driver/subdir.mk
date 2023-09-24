################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_Driver/STM32F103C6_LCD.c 

OBJS += \
./HAL/LCD_Driver/STM32F103C6_LCD.o 

C_DEPS += \
./HAL/LCD_Driver/STM32F103C6_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_Driver/STM32F103C6_LCD.o: ../HAL/LCD_Driver/STM32F103C6_LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/sho8l/embedded diploma/units_lab/unit8_lesson5/Drivers/Stm32_F103C6_Drivers/inc" -I../Inc -I"D:/sho8l/embedded diploma/units_lab/unit8_lesson5/Drivers/HAL/Keypad_Driver" -I"D:/sho8l/embedded diploma/units_lab/unit8_lesson5/Drivers/HAL/LCD_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD_Driver/STM32F103C6_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

