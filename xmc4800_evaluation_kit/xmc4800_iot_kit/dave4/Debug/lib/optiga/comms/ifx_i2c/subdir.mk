################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_config.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_data_link_layer.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_physical_layer.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_presentation_layer.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_transport_layer.c 

OBJS += \
./lib/optiga/comms/ifx_i2c/ifx_i2c.o \
./lib/optiga/comms/ifx_i2c/ifx_i2c_config.o \
./lib/optiga/comms/ifx_i2c/ifx_i2c_data_link_layer.o \
./lib/optiga/comms/ifx_i2c/ifx_i2c_physical_layer.o \
./lib/optiga/comms/ifx_i2c/ifx_i2c_presentation_layer.o \
./lib/optiga/comms/ifx_i2c/ifx_i2c_transport_layer.o 

C_DEPS += \
./lib/optiga/comms/ifx_i2c/ifx_i2c.d \
./lib/optiga/comms/ifx_i2c/ifx_i2c_config.d \
./lib/optiga/comms/ifx_i2c/ifx_i2c_data_link_layer.d \
./lib/optiga/comms/ifx_i2c/ifx_i2c_physical_layer.d \
./lib/optiga/comms/ifx_i2c/ifx_i2c_presentation_layer.d \
./lib/optiga/comms/ifx_i2c/ifx_i2c_transport_layer.d 


# Each subdirectory must supply rules for building sources it contributes
lib/optiga/comms/ifx_i2c/ifx_i2c.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/optiga/comms/ifx_i2c/ifx_i2c_config.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_config.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/optiga/comms/ifx_i2c/ifx_i2c_data_link_layer.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_data_link_layer.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/optiga/comms/ifx_i2c/ifx_i2c_physical_layer.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_physical_layer.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/optiga/comms/ifx_i2c/ifx_i2c_presentation_layer.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_presentation_layer.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/optiga/comms/ifx_i2c/ifx_i2c_transport_layer.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/comms/ifx_i2c/ifx_i2c_transport_layer.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

