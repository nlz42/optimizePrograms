################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/OptimizePrograms.cpp \
../src/TestArrays.cpp 

OBJS += \
./src/OptimizePrograms.o \
./src/TestArrays.o 

CPP_DEPS += \
./src/OptimizePrograms.d \
./src/TestArrays.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\Users\nlz\workspace-CPP\gTest\googletest-master\googletest\include" -O3 -pedantic-errors -Wall -Wextra -Werror -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


