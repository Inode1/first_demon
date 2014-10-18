################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/firstdemon.c \
../src/my_telnet_help.c \
../src/server.c 

OBJS += \
./src/firstdemon.o \
./src/my_telnet_help.o \
./src/server.o 

C_DEPS += \
./src/firstdemon.d \
./src/my_telnet_help.d \
./src/server.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


