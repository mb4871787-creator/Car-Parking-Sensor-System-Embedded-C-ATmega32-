################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BUZZER.c \
../LED.c \
../adc.c \
../car_parking_project.c \
../gpio.c \
../icu.c \
../lcd.c \
../ultrasonic_sensor.c 

OBJS += \
./BUZZER.o \
./LED.o \
./adc.o \
./car_parking_project.o \
./gpio.o \
./icu.o \
./lcd.o \
./ultrasonic_sensor.o 

C_DEPS += \
./BUZZER.d \
./LED.d \
./adc.d \
./car_parking_project.d \
./gpio.d \
./icu.d \
./lcd.d \
./ultrasonic_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


