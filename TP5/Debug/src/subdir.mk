################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp \
../src/parque.cpp 

OBJS += \
./src/Test.o \
./src/parque.o 

CPP_DEPS += \
./src/Test.d \
./src/parque.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -I"/home/meias/2ºano/AEDA/WORKSPACE/TP5/cute" -I"/home/meias/2ºano/AEDA/WORKSPACE/TP5/boost" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


