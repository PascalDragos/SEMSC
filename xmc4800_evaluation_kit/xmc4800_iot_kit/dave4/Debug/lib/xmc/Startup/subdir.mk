################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Startup/system_XMC4800.c 

S_UPPER_SRCS += \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Startup/startup_XMC4800.S 

OBJS += \
./lib/xmc/Startup/startup_XMC4800.o \
./lib/xmc/Startup/system_XMC4800.o 

S_UPPER_DEPS += \
./lib/xmc/Startup/startup_XMC4800.d 

C_DEPS += \
./lib/xmc/Startup/system_XMC4800.d 


# Each subdirectory must supply rules for building sources it contributes
lib/xmc/Startup/startup_XMC4800.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Startup/startup_XMC4800.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC Assembler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -x assembler-with-cpp -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -Wall -Wa,-adhlns="$@.lst" -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/xmc/Startup/system_XMC4800.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Startup/system_XMC4800.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

