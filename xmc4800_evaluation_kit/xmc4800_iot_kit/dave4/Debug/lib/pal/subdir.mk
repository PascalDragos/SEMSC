################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/pal_crypt_mbedtls.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_gpio.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_i2c.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_ifx_i2c_config.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_logger.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_datastore.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_event.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_lock.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_memory.c \
D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_timer.c 

OBJS += \
./lib/pal/pal.o \
./lib/pal/pal_crypt_mbedtls.o \
./lib/pal/pal_gpio.o \
./lib/pal/pal_i2c.o \
./lib/pal/pal_ifx_i2c_config.o \
./lib/pal/pal_logger.o \
./lib/pal/pal_os_datastore.o \
./lib/pal/pal_os_event.o \
./lib/pal/pal_os_lock.o \
./lib/pal/pal_os_memory.o \
./lib/pal/pal_os_timer.o 

C_DEPS += \
./lib/pal/pal.d \
./lib/pal/pal_crypt_mbedtls.d \
./lib/pal/pal_gpio.d \
./lib/pal/pal_i2c.d \
./lib/pal/pal_ifx_i2c_config.d \
./lib/pal/pal_logger.d \
./lib/pal/pal_os_datastore.d \
./lib/pal/pal_os_event.d \
./lib/pal/pal_os_lock.d \
./lib/pal/pal_os_memory.d \
./lib/pal/pal_os_timer.d 


# Each subdirectory must supply rules for building sources it contributes
lib/pal/pal.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_crypt_mbedtls.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/pal_crypt_mbedtls.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_gpio.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_i2c.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_ifx_i2c_config.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_ifx_i2c_config.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_logger.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_logger.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_os_datastore.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_datastore.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_os_event.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_event.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_os_lock.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_lock.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_os_memory.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_memory.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.
lib/pal/pal_os_timer.o: D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/pal/xmc4800/pal_os_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/XMCLib/inc" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/common/Dave/Generated" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/examples/optiga/include" -I"D:/School/diseratie/SEMS/xmc4800_evaluation_kit/optiga-trust-m/externals/mbedtls/include" -O3 -ffunction-sections -fdata-sections -Wall -Werror -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

