################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/xmc/XMCLib/src/subdir.mk
-include lib/xmc/Startup/subdir.mk
-include lib/xmc/Newlib/subdir.mk
-include lib/xmc/Dave/Generated/USBD_VCOM/virtual_com/subdir.mk
-include lib/xmc/Dave/Generated/USBD_VCOM/class_driver/device/subdir.mk
-include lib/xmc/Dave/Generated/USBD_VCOM/subdir.mk
-include lib/xmc/Dave/Generated/USBD/usb/core/xmc4000/subdir.mk
-include lib/xmc/Dave/Generated/USBD/usb/core/subdir.mk
-include lib/xmc/Dave/Generated/USBD/subdir.mk
-include lib/xmc/Dave/Generated/UART/subdir.mk
-include lib/xmc/Dave/Generated/TIMER/subdir.mk
-include lib/xmc/Dave/Generated/INTERRUPT/subdir.mk
-include lib/xmc/Dave/Generated/I2C_MASTER/subdir.mk
-include lib/xmc/Dave/Generated/GLOBAL_CCU8/subdir.mk
-include lib/xmc/Dave/Generated/GLOBAL_CCU4/subdir.mk
-include lib/xmc/Dave/Generated/E_EEPROM_XMC4/subdir.mk
-include lib/xmc/Dave/Generated/DIGITAL_IO/subdir.mk
-include lib/xmc/Dave/Generated/CPU_CTRL_XMC4/subdir.mk
-include lib/xmc/Dave/Generated/CLOCK_XMC4/subdir.mk
-include lib/xmc/Dave/Generated/subdir.mk
-include lib/pal/subdir.mk
-include lib/optiga/util/subdir.mk
-include lib/optiga/crypt/subdir.mk
-include lib/optiga/comms/ifx_i2c/subdir.mk
-include lib/optiga/comms/subdir.mk
-include lib/optiga/common/subdir.mk
-include lib/optiga/cmd/subdir.mk
-include lib/externals/mbedtls/subdir.mk
-include examples/subdir.mk
-include SEMS_Sources/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
SEMS.hex \

SECONDARY_LIST += \
SEMS.lst \

SECONDARY_SIZE += \
SEMS.siz \


LIST_FILES = $(addsuffix .o.lst, $(basename $(OBJS))) 
MAP_FILE = "SEMS.map"

TOOLCHAIN_ROOT=C:/Infineon/Tools/DAVE IDE/4.5.0.202105191637/eclipse/ARM-GCC-49
PROJECT_LOC=D:/School/diseratie/SEMS/xmc4800_evaluation_kit/xmc4800_iot_kit/dave4

# All Target
all: SEMS.elf secondary-outputs

# Tool invocations
SEMS.elf: $(OBJS) ../linker_script.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	$(file >objects.rsp,$(OBJS))
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -T"../linker_script.ld" -nostartfiles -Xlinker --gc-sections -specs=nano.specs -specs=nosys.specs -Wl,-Map,$(MAP_FILE) -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "SEMS.elf" "@objects.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo.
SEMS.hex: SEMS.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objcopy" -O ihex "SEMS.elf" "SEMS.hex"
	@echo 'Finished building: $@'
	@echo.
SEMS.lst: SEMS.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objdump" -h -S "SEMS.elf" > "SEMS.lst"
	@echo 'Finished building: $@'
	@echo.
SEMS.siz: SEMS.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-size" --format=berkeley "SEMS.elf"
	@echo 'Finished building: $@'
	@echo.
# Other Targets
clean:
	-$(RM) $(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS)
	-$(RM) SEMS_Sources/Constructor.o SEMS_Sources/Decoder.o SEMS_Sources/ECC.o SEMS_Sources/Hash.o SEMS_Sources/Init.o SEMS_Sources/Nonce.o SEMS_Sources/Packer.o SEMS_Sources/RSA.o SEMS_Sources/Random.o SEMS_Sources/SecCom.o SEMS_Sources/SecNvm.o SEMS_Sources/SecUnlock.o SEMS_Sources/Skey.o SEMS_Sources/SymEncrypt.o SEMS_Sources/Terminal.o SEMS_Sources/Test.o SEMS_Sources/Timer.o examples/example_optiga_crypt_clear_auto_state.o examples/example_optiga_crypt_ecc_generate_keypair.o examples/example_optiga_crypt_ecdh.o examples/example_optiga_crypt_ecdsa_sign.o examples/example_optiga_crypt_ecdsa_verify.o examples/example_optiga_crypt_hash.o examples/example_optiga_crypt_hkdf.o examples/example_optiga_crypt_hmac.o examples/example_optiga_crypt_random.o examples/example_optiga_crypt_rsa_decrypt.o examples/example_optiga_crypt_rsa_encrypt_message.o examples/example_optiga_crypt_rsa_encrypt_session.o examples/example_optiga_crypt_rsa_generate_keypair.o examples/example_optiga_crypt_rsa_sign.o examples/example_optiga_crypt_rsa_verify.o examples/example_optiga_crypt_symmetric_encrypt_decrypt.o examples/example_optiga_crypt_symmetric_encrypt_decrypt_ecb.o examples/example_optiga_crypt_symmetric_generate_key.o examples/example_optiga_crypt_tls_prf_sha256.o examples/example_optiga_hibernate_restore.o examples/example_optiga_hmac_verify_with_authorization_reference.o examples/example_optiga_init_deinit.o examples/example_optiga_util_protected_update.o examples/example_optiga_util_read_data.o examples/example_optiga_util_update_count.o examples/example_optiga_util_write_data.o examples/example_pair_host_and_optiga_using_pre_shared_secret.o examples/example_read_coprocessor_id.o examples/example_utilities.o examples/optiga_shell.o lib/externals/mbedtls/aes.o lib/externals/mbedtls/ccm.o lib/externals/mbedtls/cipher.o lib/externals/mbedtls/cipher_wrap.o lib/externals/mbedtls/md.o lib/externals/mbedtls/md_wrap.o 
	-$(RM) lib/externals/mbedtls/platform_util.o lib/externals/mbedtls/sha256.o lib/externals/mbedtls/ssl_ciphersuites.o lib/optiga/cmd/optiga_cmd.o lib/optiga/common/optiga_lib_common.o lib/optiga/common/optiga_lib_logger.o lib/optiga/comms/ifx_i2c/ifx_i2c.o lib/optiga/comms/ifx_i2c/ifx_i2c_config.o lib/optiga/comms/ifx_i2c/ifx_i2c_data_link_layer.o lib/optiga/comms/ifx_i2c/ifx_i2c_physical_layer.o lib/optiga/comms/ifx_i2c/ifx_i2c_presentation_layer.o lib/optiga/comms/ifx_i2c/ifx_i2c_transport_layer.o lib/optiga/comms/optiga_comms_ifx_i2c.o lib/optiga/crypt/optiga_crypt.o lib/optiga/util/optiga_util.o lib/pal/pal.o lib/pal/pal_crypt_mbedtls.o lib/pal/pal_gpio.o lib/pal/pal_i2c.o lib/pal/pal_ifx_i2c_config.o lib/pal/pal_logger.o lib/pal/pal_os_datastore.o lib/pal/pal_os_event.o lib/pal/pal_os_lock.o lib/pal/pal_os_memory.o lib/pal/pal_os_timer.o lib/xmc/Dave/Generated/CLOCK_XMC4/clock_xmc4.o lib/xmc/Dave/Generated/CLOCK_XMC4/clock_xmc4_conf.o lib/xmc/Dave/Generated/CPU_CTRL_XMC4/cpu_ctrl_xmc4.o lib/xmc/Dave/Generated/CPU_CTRL_XMC4/cpu_ctrl_xmc4_conf.o lib/xmc/Dave/Generated/DAVE.o lib/xmc/Dave/Generated/DIGITAL_IO/digital_io.o lib/xmc/Dave/Generated/DIGITAL_IO/digital_io_conf.o lib/xmc/Dave/Generated/E_EEPROM_XMC4/e_eeprom_xmc4.o lib/xmc/Dave/Generated/E_EEPROM_XMC4/e_eeprom_xmc4_conf.o lib/xmc/Dave/Generated/GLOBAL_CCU4/global_ccu4.o lib/xmc/Dave/Generated/GLOBAL_CCU4/global_ccu4_conf.o lib/xmc/Dave/Generated/GLOBAL_CCU8/global_ccu8.o lib/xmc/Dave/Generated/GLOBAL_CCU8/global_ccu8_conf.o lib/xmc/Dave/Generated/I2C_MASTER/i2c_master.o lib/xmc/Dave/Generated/I2C_MASTER/i2c_master_conf.o lib/xmc/Dave/Generated/INTERRUPT/interrupt.o lib/xmc/Dave/Generated/INTERRUPT/interrupt_conf.o lib/xmc/Dave/Generated/TIMER/timer.o lib/xmc/Dave/Generated/TIMER/timer_conf.o lib/xmc/Dave/Generated/UART/uart.o lib/xmc/Dave/Generated/UART/uart_conf.o lib/xmc/Dave/Generated/USBD/usb/core/usb_task.o 
	-$(RM) lib/xmc/Dave/Generated/USBD/usb/core/xmc4000/usbd_endpoint_stream_xmc4000.o lib/xmc/Dave/Generated/USBD/usb/core/xmc4000/usbd_endpoint_xmc4000.o lib/xmc/Dave/Generated/USBD/usbd.o lib/xmc/Dave/Generated/USBD/usbd_conf.o lib/xmc/Dave/Generated/USBD_VCOM/class_driver/device/cdc_class_device.o lib/xmc/Dave/Generated/USBD_VCOM/usbd_vcom.o lib/xmc/Dave/Generated/USBD_VCOM/usbd_vcom_conf.o lib/xmc/Dave/Generated/USBD_VCOM/virtual_com/descriptors.o lib/xmc/Newlib/syscalls.o lib/xmc/Startup/startup_XMC4800.o lib/xmc/Startup/system_XMC4800.o lib/xmc/XMCLib/src/xmc4_eru.o lib/xmc/XMCLib/src/xmc4_flash.o lib/xmc/XMCLib/src/xmc4_gpio.o lib/xmc/XMCLib/src/xmc4_rtc.o lib/xmc/XMCLib/src/xmc4_scu.o lib/xmc/XMCLib/src/xmc_can.o lib/xmc/XMCLib/src/xmc_ccu4.o lib/xmc/XMCLib/src/xmc_ccu8.o lib/xmc/XMCLib/src/xmc_common.o lib/xmc/XMCLib/src/xmc_dac.o lib/xmc/XMCLib/src/xmc_dma.o lib/xmc/XMCLib/src/xmc_dsd.o lib/xmc/XMCLib/src/xmc_ebu.o lib/xmc/XMCLib/src/xmc_ecat.o lib/xmc/XMCLib/src/xmc_eru.o lib/xmc/XMCLib/src/xmc_eth_mac.o lib/xmc/XMCLib/src/xmc_eth_phy_dp83848.o lib/xmc/XMCLib/src/xmc_eth_phy_ksz8031rnl.o lib/xmc/XMCLib/src/xmc_eth_phy_ksz8081rnb.o lib/xmc/XMCLib/src/xmc_fce.o lib/xmc/XMCLib/src/xmc_gpio.o lib/xmc/XMCLib/src/xmc_hrpwm.o lib/xmc/XMCLib/src/xmc_i2c.o lib/xmc/XMCLib/src/xmc_i2s.o lib/xmc/XMCLib/src/xmc_ledts.o lib/xmc/XMCLib/src/xmc_posif.o lib/xmc/XMCLib/src/xmc_rtc.o lib/xmc/XMCLib/src/xmc_sdmmc.o lib/xmc/XMCLib/src/xmc_spi.o lib/xmc/XMCLib/src/xmc_uart.o lib/xmc/XMCLib/src/xmc_usbd.o lib/xmc/XMCLib/src/xmc_usbh.o lib/xmc/XMCLib/src/xmc_usic.o lib/xmc/XMCLib/src/xmc_vadc.o lib/xmc/XMCLib/src/xmc_wdt.o main_xmc4800_example.o  SEMS.elf $(LIST_FILES) $(MAP_FILE) objects.rsp
	-@echo.
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
