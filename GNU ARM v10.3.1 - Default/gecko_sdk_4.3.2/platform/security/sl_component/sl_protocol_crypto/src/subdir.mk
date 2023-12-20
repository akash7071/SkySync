################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk/platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.c \
C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk/platform/security/sl_component/sl_protocol_crypto/src/sli_radioaes_management.c 

OBJS += \
./gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.o \
./gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_radioaes_management.o 

C_DEPS += \
./gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.d \
./gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_radioaes_management.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.o: C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk/platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.c gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DEFR32BG22C224F512GM40=1' '-DSL_APP_PROPERTIES=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync\config" -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync\config\btconf" -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/bgstack/ll/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/debug-print" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_cryptoacc_library/include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_cryptoacc_library/src" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib/dmd" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/gatt_service_device_information" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib/glib" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/src/ls013b7dh03" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/config" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/config/preset" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/library" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/inc/memlcd_usart" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_psa_driver/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/wmbus" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/sidewalk" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_power_manager_init" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/se_manager/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/se_manager/src" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/si1133/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_protocol_crypto/src" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync\autogen" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_radioaes_management.o: C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk/platform/security/sl_component/sl_protocol_crypto/src/sli_radioaes_management.c gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DEFR32BG22C224F512GM40=1' '-DSL_APP_PROPERTIES=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync\config" -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync\config\btconf" -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32BG22/Include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/bgstack/ll/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//protocol/flex/debug-print" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_cryptoacc_library/include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_cryptoacc_library/src" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib/dmd" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/gatt_service_device_information" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/middleware/glib/glib" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/driver/i2cspm/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/src/ls013b7dh03" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/config" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/config/preset" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_mbedtls_support/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/include" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/mbedtls/library" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/memlcd/inc/memlcd_usart" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/third_party/printf/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_psa_driver/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/wmbus" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/sidewalk" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_power_manager_init" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/se_manager/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/se_manager/src" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/si1133/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/security/sl_component/sl_protocol_crypto/src" -I"C:/Users/akash/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\akash\SimplicityStudio\v5_workspace\SkySync\autogen" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.2/platform/security/sl_component/sl_protocol_crypto/src/sli_radioaes_management.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


