################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BasicMember.cpp \
../BulkClub.cpp \
../Date.cpp \
../PreferredMember.cpp \
../ReadInMembers.cpp \
../Transaction.cpp \
../main.cpp 

OBJS += \
./BasicMember.o \
./BulkClub.o \
./Date.o \
./PreferredMember.o \
./ReadInMembers.o \
./Transaction.o \
./main.o 

CPP_DEPS += \
./BasicMember.d \
./BulkClub.d \
./Date.d \
./PreferredMember.d \
./ReadInMembers.d \
./Transaction.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


