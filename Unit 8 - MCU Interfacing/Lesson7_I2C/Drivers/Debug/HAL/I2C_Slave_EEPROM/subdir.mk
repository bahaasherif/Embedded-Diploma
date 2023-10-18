################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_Slave_EEPROM/STM32F103C6_EEPROM.c 

OBJS += \
./HAL/I2C_Slave_EEPROM/STM32F103C6_EEPROM.o 

C_DEPS += \
./HAL/I2C_Slave_EEPROM/STM32F103C6_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_Slave_EEPROM/STM32F103C6_EEPROM.o: ../HAL/I2C_Slave_EEPROM/STM32F103C6_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/sho8l/embedded diploma/units_lab/unit8_lesson7/Drivers/HAL/I2C_Slave_EEPROM" -I"D:/sho8l/embedded diploma/units_lab/unit8_lesson7/Drivers/HAL/Keypad_Driver" -I"D:/sho8l/embedded diploma/units_lab/unit8_lesson7/Drivers/HAL/LCD_Driver" -I"D:/sho8l/embedded diploma/units_lab/unit8_lesson7/Drivers/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_Slave_EEPROM/STM32F103C6_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

