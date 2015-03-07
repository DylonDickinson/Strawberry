################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BasicMember.cpp \
../BoundaryCheck.cpp \
../BulkClub.cpp \
../Date.cpp \
../OneTransactionDay.cpp \
../OutputErrorMessage.cpp \
../PreferredMember.cpp \
../ReadInMembers.cpp \
../ReadInTransactions.cpp \
../Transaction.cpp \
../main.cpp 

OBJS += \
./BasicMember.o \
./BoundaryCheck.o \
./BulkClub.o \
./Date.o \
./OneTransactionDay.o \
./OutputErrorMessage.o \
./PreferredMember.o \
./ReadInMembers.o \
./ReadInTransactions.o \
./Transaction.o \
./main.o 

CPP_DEPS += \
./BasicMember.d \
./BoundaryCheck.d \
./BulkClub.d \
./Date.d \
./OneTransactionDay.d \
./OutputErrorMessage.d \
./PreferredMember.d \
./ReadInMembers.d \
./ReadInTransactions.d \
./Transaction.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


