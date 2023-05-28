################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SEMS_Sources/Com.c \
../SEMS_Sources/Hash.c \
../SEMS_Sources/Main.c \
../SEMS_Sources/Patcher.c \
../SEMS_Sources/RSA.c \
../SEMS_Sources/Random.c \
../SEMS_Sources/SymEncrypt.c \
../SEMS_Sources/Unlock.c 

OBJS += \
./SEMS_Sources/Com.o \
./SEMS_Sources/Hash.o \
./SEMS_Sources/Main.o \
./SEMS_Sources/Patcher.o \
./SEMS_Sources/RSA.o \
./SEMS_Sources/Random.o \
./SEMS_Sources/SymEncrypt.o \
./SEMS_Sources/Unlock.o 

C_DEPS += \
./SEMS_Sources/Com.d \
./SEMS_Sources/Hash.d \
./SEMS_Sources/Main.d \
./SEMS_Sources/Patcher.d \
./SEMS_Sources/RSA.d \
./SEMS_Sources/Random.d \
./SEMS_Sources/SymEncrypt.d \
./SEMS_Sources/Unlock.d 


# Each subdirectory must supply rules for building sources it contributes
SEMS_Sources/%.o: ../SEMS_Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

