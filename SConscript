from building import *

cwd = GetCurrentDir()

src = []
path = []

esp32c3_path = [cwd + '/components/hal/esp32c3/include',
                cwd + '/components/hal/include',
                cwd + '/components/soc/esp32c3/include',
                cwd + '/components/hal/platform_port/include',
                cwd + '/components/esp_system/include',
                cwd + '/components/esp_hw_support/include',
                cwd + '/components/esp_common/include',
                cwd + '/components/driver/include',
                cwd + '/components/esp_rom/include',
                cwd + '/components/riscv/include',
                cwd + '/components/heap/include',
                cwd + '/components/newlib/platform_include',
                cwd + '/components/esp_ringbuf/include',
                cwd + '/components/soc/include',
                cwd + '/components/mbedtls/mbedtls/include',
                cwd + '/components/mbedtls/mbedtls/library',
                cwd + '/components/log/include',
                cwd + '/components/esp_hw_support/include/soc/esp32c3',
                cwd + '/components/mbedtls/port/include',
                cwd + '/components/mbedtls/port/aes/dma/include',
                cwd + '/components/mbedtls/port/sha/dma/include',

                cwd + '/components/spi_flash/include',
                cwd + '/components/esp_system/port/include',
                cwd + '/components/esp_system/port/include/private',
                cwd + '/components/bootloader_support/bootloader_flash/include',
                cwd + '/components/efuse/include',
                cwd + '/components/efuse/esp32c3/include',
                cwd + '/components/esp_rom/esp32c3',
                cwd + '/components/esp_hw_support/include/soc',
                cwd + '/components/bootloader_support/include',
                cwd + '/components/esp_pm/include',
                cwd + '/components/esp_timer/include',
                cwd + '/components/pthread/include',

                cwd + '/components/esp_hw_support/port/include',
                cwd + '/components/esp_hw_support/include/esp_private',

                cwd + '/components/bootloader_support/private_include',
                cwd + '/components/esp_app_format/include',

                cwd + '/components/heap/tlsf',

                cwd + '/components/spi_flash/include/spi_flash',
                cwd + '/components/app_update/include',

                cwd + '/components/newlib/priv_include',

                cwd + '/components/efuse/private_include',
                cwd + '/components/efuse/esp32c3/private_include',

                cwd + '/components/esp_timer/private_include',
                cwd + '/components/mbedtls/esp_crt_bundle/include',
                cwd + '/components/hal/esp32c3/include']

esp32c3_src = Split("""
components/esp_app_format/esp_app_desc.c
components/esp_ringbuf/ringbuf.c
components/esp_pm/pm_trace.c
components/esp_pm/pm_locks.c
components/esp_pm/pm_impl.c
components/cxx/cxx_exception_stubs.cpp
components/cxx/cxx_guards.cpp
components/freertos/FreeRTOS-openocd.c
components/app_update/esp_ota_app_desc.c
components/app_update/esp_ota_ops.c
components/esp_common/src/esp_err_to_name.c

components/bootloader_support/src/esp32c3/bootloader_esp32c3.c
components/bootloader_support/src/esp32c3/bootloader_soc.c
components/bootloader_support/src/bootloader_init.c
components/bootloader_support/src/bootloader_console.c
components/freertos/esp_additions/freertos_v8_compat.c
components/mbedtls/esp_crt_bundle/esp_crt_bundle.c
""")

esp32c3_mbedtls_src = Split("""
components/mbedtls/mbedtls/library/timing.c
components/mbedtls/mbedtls/library/debug.c
components/mbedtls/mbedtls/library/ssl_cookie.c
components/mbedtls/mbedtls/library/ssl_cache.c
components/mbedtls/mbedtls/library/ssl_ciphersuites.c
components/mbedtls/mbedtls/library/psa_crypto_rsa.c
components/mbedtls/mbedtls/library/ssl_client.c
components/mbedtls/mbedtls/library/ssl_tls13_server.c
components/mbedtls/mbedtls/library/ssl_tls13_generic.c
components/mbedtls/mbedtls/library/ssl_ticket.c
components/mbedtls/mbedtls/library/ssl_tls13_keys.c
components/mbedtls/mbedtls/library/../../port/mbedtls_debug.c
components/mbedtls/mbedtls/library/ssl_msg.c
components/mbedtls/mbedtls/library/ssl_tls13_client.c
components/mbedtls/mbedtls/library/x509.c
components/mbedtls/mbedtls/library/x509_create.c
components/mbedtls/mbedtls/library/ssl_tls12_client.c
components/mbedtls/mbedtls/library/x509_crl.c
components/mbedtls/mbedtls/library/x509write_crt.c
components/mbedtls/mbedtls/library/ssl_tls12_server.c
components/mbedtls/mbedtls/library/aesni.c
components/mbedtls/mbedtls/library/x509_csr.c
components/mbedtls/mbedtls/library/aes.c
components/mbedtls/mbedtls/library/x509write_csr.c
components/mbedtls/mbedtls/library/base64.c
components/mbedtls/mbedtls/library/asn1parse.c
components/mbedtls/mbedtls/library/camellia.c
components/mbedtls/mbedtls/library/aria.c
components/mbedtls/mbedtls/library/chacha20.c
components/mbedtls/mbedtls/library/ssl_tls.c
components/mbedtls/mbedtls/library/asn1write.c
components/mbedtls/mbedtls/library/chachapoly.c
components/mbedtls/mbedtls/library/x509_crt.c
components/mbedtls/mbedtls/library/ccm.c
components/mbedtls/mbedtls/library/cipher_wrap.c
components/mbedtls/mbedtls/library/cmac.c
components/mbedtls/mbedtls/library/des.c
components/mbedtls/mbedtls/library/dhm.c
components/mbedtls/mbedtls/library/ecjpake.c
components/mbedtls/mbedtls/library/constant_time.c
components/mbedtls/mbedtls/library/ctr_drbg.c
components/mbedtls/mbedtls/library/cipher.c
components/mbedtls/mbedtls/library/ecdsa.c
components/mbedtls/mbedtls/library/entropy_poll.c
components/mbedtls/mbedtls/library/ecdh.c
components/mbedtls/mbedtls/library/bignum.c
components/mbedtls/mbedtls/library/entropy.c
components/mbedtls/mbedtls/library/hkdf.c
components/mbedtls/mbedtls/library/error.c
components/mbedtls/mbedtls/library/memory_buffer_alloc.c
components/mbedtls/mbedtls/library/hmac_drbg.c
components/mbedtls/mbedtls/library/md.c
components/mbedtls/mbedtls/library/gcm.c
components/mbedtls/mbedtls/library/nist_kw.c
components/mbedtls/mbedtls/library/md5.c
components/mbedtls/mbedtls/library/mps_reader.c
components/mbedtls/mbedtls/library/mps_trace.c
components/mbedtls/mbedtls/library/padlock.c
components/mbedtls/mbedtls/library/ecp_curves.c
components/mbedtls/mbedtls/library/oid.c
components/mbedtls/mbedtls/library/pem.c
components/mbedtls/mbedtls/library/pk_wrap.c
components/mbedtls/mbedtls/library/pkcs12.c
components/mbedtls/mbedtls/library/ecp.c
components/mbedtls/mbedtls/library/pk.c
components/mbedtls/mbedtls/library/platform.c
components/mbedtls/mbedtls/library/pkcs5.c
components/mbedtls/mbedtls/library/poly1305.c
components/mbedtls/mbedtls/library/platform_util.c
components/mbedtls/mbedtls/library/pkwrite.c
components/mbedtls/mbedtls/library/psa_crypto_cipher.c
components/mbedtls/mbedtls/library/psa_crypto_client.c
components/mbedtls/mbedtls/library/psa_crypto_ecp.c
components/mbedtls/mbedtls/library/psa_crypto_aead.c
components/mbedtls/mbedtls/library/pkparse.c
components/mbedtls/mbedtls/library/psa_crypto_hash.c
components/mbedtls/mbedtls/library/sha1.c
components/mbedtls/mbedtls/library/psa_crypto_driver_wrappers.c
components/mbedtls/mbedtls/library/psa_crypto_mac.c
components/mbedtls/mbedtls/library/psa_crypto_se.c
components/mbedtls/mbedtls/library/ripemd160.c
components/mbedtls/mbedtls/library/psa_crypto_storage.c
components/mbedtls/mbedtls/library/psa_its_file.c
components/mbedtls/mbedtls/library/psa_crypto_slot_management.c
components/mbedtls/mbedtls/library/ssl_debug_helpers_generated.c
components/mbedtls/mbedtls/library/version_features.c
components/mbedtls/mbedtls/library/rsa_alt_helpers.c
components/mbedtls/mbedtls/library/sha256.c
components/mbedtls/mbedtls/library/version.c
components/mbedtls/mbedtls/library/threading.c
components/mbedtls/mbedtls/library/timing.c
components/mbedtls/mbedtls/library/../../port/esp_mem.c
components/mbedtls/mbedtls/library/../../port/sha/dma/esp_sha_gdma_impl.c
components/mbedtls/mbedtls/library/../../port/aes/dma/esp_aes_gdma_impl.c
components/mbedtls/mbedtls/library/sha512.c
components/mbedtls/mbedtls/library/../../port/crypto_shared_gdma/esp_crypto_shared_gdma.c
components/mbedtls/mbedtls/library/../../port/esp_hardware.c
components/mbedtls/mbedtls/library/../../port/esp_timing.c
components/mbedtls/mbedtls/library/rsa.c
components/mbedtls/mbedtls/library/../../port/aes/esp_aes_xts.c
components/mbedtls/mbedtls/library/../../port/sha/dma/esp_sha1.c
components/mbedtls/mbedtls/library/../../port/sha/esp_sha.c
components/mbedtls/mbedtls/library/../../port/aes/esp_aes_common.c
components/mbedtls/mbedtls/library/../../port/esp_bignum.c
components/mbedtls/mbedtls/library/psa_crypto.c
components/mbedtls/mbedtls/library/../../port/sha/dma/esp_sha512.c
components/mbedtls/mbedtls/library/../../port/sha/dma/esp_sha256.c
components/mbedtls/mbedtls/library/../../port/sha/dma/sha.c
components/mbedtls/mbedtls/library/../../port/md/esp_md.c
components/mbedtls/mbedtls/library/../../port/aes/dma/esp_aes.c
components/mbedtls/mbedtls/library/../../port/esp32c3/bignum.c
""")

esp32c3_hal_src = Split("""
components/hal/xt_wdt_hal.c
components/hal/mpu_hal.c
components/hal/efuse_hal.c
components/hal/rtc_io_hal.c
components/hal/esp32c3/efuse_hal.c
components/hal/mmu_hal.c
components/hal/wdt_hal_iram.c
components/hal/cache_hal.c
components/hal/spi_hal_iram.c
components/hal/timer_hal.c
components/hal/timer_hal_iram.c
components/hal/spi_slave_hal.c
components/hal/spi_hal.c
components/hal/spi_slave_hal_iram.c
components/hal/ledc_hal.c
components/hal/i2c_hal.c
components/hal/gpio_hal.c
components/hal/i2c_hal_iram.c
components/hal/ledc_hal_iram.c
components/hal/uart_hal_iram.c
components/hal/uart_hal.c
components/hal/spi_flash_encrypt_hal_iram.c
components/hal/spi_flash_hal.c
components/hal/sha_hal.c
components/hal/systimer_hal.c
components/hal/adc_oneshot_hal.c
components/hal/rmt_hal.c
components/hal/sdm_hal.c
components/hal/adc_hal_common.c
components/hal/spi_flash_hal_iram.c
components/hal/ds_hal.c
components/hal/twai_hal_iram.c
components/hal/gdma_hal.c
components/hal/twai_hal.c
components/hal/xt_wdt_hal.c
components/hal/esp32c3/brownout_hal.c
components/hal/i2s_hal.c
components/hal/spi_flash_hal_gpspi.c
components/hal/esp32c3/rtc_cntl_hal.c
components/hal/adc_hal.c
components/hal/aes_hal.c
components/hal/esp32c3/hmac_hal.c
components/hal/spi_slave_hd_hal.c
""")

esp32c3_soc_src = Split("""
components/soc/lldesc.c
components/soc/dport_access_common.c
components/soc/esp32c3/gpio_periph.c
components/soc/esp32c3/sdm_periph.c
components/soc/esp32c3/interrupts.c
components/soc/esp32c3/rmt_periph.c
components/soc/esp32c3/ledc_periph.c
components/soc/esp32c3/i2s_periph.c
components/soc/esp32c3/dedic_gpio_periph.c
components/soc/esp32c3/adc_periph.c
components/soc/esp32c3/gdma_periph.c
components/soc/esp32c3/i2c_periph.c
components/soc/esp32c3/spi_periph.c
components/soc/esp32c3/temperature_sensor_periph.c
components/soc/esp32c3/uart_periph.c
components/soc/esp32c3/timer_periph.c
""")

esp32c3_esp_hw_support_src = Split("""
components/esp_hw_support/esp_memory_utils.c
components/esp_hw_support/hw_random.c
components/esp_hw_support/clk_ctrl_os.c
components/esp_hw_support/esp_clk.c
components/esp_hw_support/cpu.c
components/esp_hw_support/mac_addr.c
components/esp_hw_support/sleep_mac_bb.c
components/esp_hw_support/periph_ctrl.c
components/esp_hw_support/sleep_gpio.c
components/esp_hw_support/sleep_modes.c
components/esp_hw_support/rtc_module.c
components/esp_hw_support/intr_alloc.c
components/esp_hw_support/regi2c_ctrl.c
components/esp_hw_support/port/esp32c3/systimer.c
components/esp_hw_support/sleep_retention.c
components/esp_hw_support/adc_share_hw_ctrl.c
components/esp_hw_support/port/async_memcpy_impl_gdma.c
components/esp_hw_support/port/esp32c3/rtc_clk_init.c
components/esp_hw_support/port/esp32c3/rtc_pm.c
components/esp_hw_support/esp_async_memcpy.c
components/esp_hw_support/port/esp32c3/rtc_sleep.c
components/esp_hw_support/gdma.c
components/esp_hw_support/port/esp32c3/rtc_init.c
components/esp_hw_support/port/esp32c3/rtc_time.c
components/esp_hw_support/port/esp32c3/chip_info.c
components/esp_hw_support/port/esp32c3/rtc_clk.c
components/esp_hw_support/port/esp32c3/esp_hmac.c
components/esp_hw_support/port/esp32c3/esp_crypto_lock.c
components/esp_hw_support/port/esp_memprot_conv.c
components/esp_hw_support/port/esp32c3/adc2_init_cal.c
components/esp_hw_support/port/esp32c3/esp_ds.c
components/esp_hw_support/port/esp32c3/esp_memprot.c
""")

esp32c3_bootloader_support_src = Split("""
components/bootloader_support/src/bootloader_random_esp32c3.c
components/bootloader_support/src/bootloader_mem.c
components/bootloader_support/src/bootloader_common.c
components/bootloader_support/src/bootloader_clock_init.c
components/bootloader_support/src/bootloader_random.c
components/bootloader_support/src/bootloader_common_loader.c
components/bootloader_support/src/flash_partitions.c
components/bootloader_support/bootloader_flash/src/bootloader_flash.c
components/bootloader_support/src/flash_encrypt.c
components/bootloader_support/src/secure_boot.c
components/bootloader_support/src/bootloader_efuse.c
components/bootloader_support/src/bootloader_utility.c
components/bootloader_support/src/esp_image_format.c
components/bootloader_support/bootloader_flash/src/bootloader_flash_config_esp32c3.c
components/bootloader_support/bootloader_flash/src/flash_qio_mode.c
components/bootloader_support/src/idf/bootloader_sha.c
""")

esp32c3_esp_system_src = Split("""
components/esp_system/int_wdt.c
components/esp_system/esp_err.c
components/esp_system/esp_ipc.c
components/esp_system/crosscore_int.c
components/esp_system/port/soc/esp32c3/reset_reason.c
components/esp_system/esp_system.c
components/esp_system/freertos_hooks.c
components/esp_system/port/brownout.c
components/esp_system/stack_check.c
components/esp_system/panic.c
components/esp_system/system_time.c
components/esp_system/task_wdt.c
components/esp_system/debug_stubs.c
components/esp_system/startup.c
components/esp_system/ubsan.c
components/esp_system/xt_wdt.c
components/esp_system/port/soc/esp32c3/cache_err_int.c
components/esp_system/port/cpu_start.c
components/esp_system/port/soc/esp32c3/apb_backup_dma.c
components/esp_system/port/panic_handler.c
components/esp_system/port/arch/riscv/expression_with_stack_asm.S
components/esp_system/port/soc/esp32c3/system_internal.c
components/esp_system/port/soc/esp32c3/clk.c
components/esp_system/port/arch/riscv/debug_stubs.c
components/esp_system/port/arch/riscv/expression_with_stack.c
components/esp_system/port/arch/riscv/panic_arch.c
""")

esp32c3_esp_rom_src = Split("""
components/esp_rom/patches/esp_rom_sys.c
components/esp_rom/patches/esp_rom_crc.c
components/esp_rom/patches/esp_rom_uart.c
components/esp_rom/patches/esp_rom_spiflash.c
components/esp_rom/patches/esp_rom_regi2c.c
components/esp_rom/patches/esp_rom_systimer.c
components/esp_rom/patches/esp_rom_efuse.c
""")

esp32c3_heap_src = Split("""
components/heap/port/esp32c3/memory_layout.c
components/heap/multi_heap.c
components/heap/port/memory_layout_utils.c
components/heap/heap_caps_init.c
components/heap/heap_caps.c
components/heap/tlsf/tlsf.c
""")

esp32c3_spi_flash_src = Split("""
components/spi_flash/flash_brownout_hook.c
components/spi_flash/spi_flash_chip_drivers.c
components/spi_flash/spi_flash_chip_issi.c
components/spi_flash/partition_target.c
components/spi_flash/partition.c
components/spi_flash/spi_flash_chip_gd.c
components/spi_flash/spi_flash_chip_mxic.c
components/spi_flash/spi_flash_chip_boya.c
components/spi_flash/spi_flash_chip_winbond.c
components/spi_flash/spi_flash_chip_generic.c
components/spi_flash/spi_flash_chip_th.c
components/spi_flash/spi_flash_chip_mxic_opi.c
components/spi_flash/memspi_host_driver.c
components/spi_flash/cache_utils.c
components/spi_flash/spi_flash_os_func_app.c
components/spi_flash/esp32c3/flash_ops_esp32c3.c
components/spi_flash/flash_ops.c
components/spi_flash/flash_mmap.c
components/spi_flash/spi_flash_os_func_noos.c
components/spi_flash/esp_flash_spi_init.c
components/spi_flash/esp_flash_api.c
""")

esp32c3_newlib_src = Split("""
components/newlib/heap.c
components/newlib/assert.c
components/newlib/pthread.c
components/newlib/abort.c
components/newlib/poll.c
components/newlib/newlib_init.c
components/newlib/termios.c
components/newlib/random.c
components/newlib/locks.c
components/newlib/reent_init.c
components/newlib/syscalls.c
components/newlib/sysconf.c
components/newlib/port/esp_time_impl.c
components/newlib/realpath.c
components/newlib/time.c
components/newlib/stdatomic.c
""")

esp32c3_log_src = Split("""
components/log/log.c
components/log/log_buffers.c
components/log/log_freertos.c
""")

esp32c3_driver_src = Split("""
components/driver/gpio/dedic_gpio.c
components/driver/spi_bus_lock.c
components/driver/gpio/rtc_io.c
components/driver/sdspi_crc.c
components/driver/gptimer.c
components/driver/spi_master.c
components/driver/sdspi_transaction.c
components/driver/gpio/gpio.c
components/driver/sdspi_host.c
components/driver/ledc.c
components/driver/spi_slave.c
components/driver/uart.c
components/driver/i2c.c
components/driver/spi_common.c
components/driver/sdm.c
components/driver/rmt/rmt_common.c
components/driver/rmt/rmt_encoder.c
components/driver/rmt/rmt_rx.c
components/driver/rmt/rmt_tx.c
components/driver/i2s/i2s_std.c
components/driver/temperature_sensor.c
components/driver/i2s/i2s_common.c
components/driver/i2s/i2s_tdm.c
components/driver/usb_serial_jtag.c
components/driver/spi_slave_hd.c
components/driver/i2s/i2s_pdm.c
components/driver/twai.c
""")

esp32c3_pthread_src = Split("""
components/pthread/pthread_local_storage.c
components/pthread/pthread_cond_var.c
components/pthread/pthread_rwlock.c
components/pthread/pthread.c
""")

esp32c3_riscv_src = Split("""
components/riscv/vectors.S
components/riscv/instruction_decode.c
components/riscv/interrupt.c
""")

esp32c3_efuse_src = Split("""
components/efuse/esp32c3/esp_efuse_table.c
components/efuse/esp32c3/esp_efuse_utility.c
components/efuse/esp32c3/esp_efuse_fields.c
components/efuse/src/esp_efuse_utility.c
components/efuse/esp32c3/esp_efuse_rtc_calib.c
components/efuse/src/esp_efuse_api.c
components/efuse/src/esp_efuse_fields.c
components/efuse/src/efuse_controller/keys/with_key_purposes/esp_efuse_api_key.c
""")

esp32c3_esp_timer_src = Split("""
components/esp_timer/src/esp_timer_impl_systimer.c
components/esp_timer/src/system_time.c
components/esp_timer/src/esp_timer.c
components/esp_timer/src/ets_timer_legacy.c
""")

if GetDepend(['SOC_ESP32_C3']):
    src += esp32c3_src
    src += esp32c3_riscv_src
    src += esp32c3_mbedtls_src
    src += esp32c3_esp_system_src
    src += esp32c3_hal_src
    src += esp32c3_soc_src
    src += esp32c3_esp_hw_support_src
    src += esp32c3_bootloader_support_src
    src += esp32c3_esp_rom_src
    src += esp32c3_heap_src
    src += esp32c3_spi_flash_src
    src += esp32c3_newlib_src
    src += esp32c3_log_src
    src += esp32c3_driver_src
    src += esp32c3_pthread_src
    src += esp32c3_efuse_src
    src += esp32c3_esp_timer_src
    path += esp32c3_path
    CPPDEFINES = [ 'IDF_VER=\\"999\\\"', 'PROJECT_VER=\\"999\\"' ,'_GNU_SOURCE' , 'MULTI_HEAP_FREERTOS', 'ESP_PLATFORM=1', 'IDF_TARGET=esp32c3', '_POSIX_READER_WRITER_LOCKS' , 'PROJECT_NAME=\\"rtthread\\"' , 'MBEDTLS_CONFIG_FILE=\\"mbedtls/esp_config.h\\"']
# [163/442] /home/balance/.espressif/tools/riscv32-esp-elf/esp-2022r1-11.2.0/riscv32-esp-elf/bin/riscv32-esp-elf-gcc -DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\" -Iconfig -I../packages/ESP-IDF-latest/components/esp_system/include -I../packages/ESP-IDF-latest/components/esp_system/port/include -I../packages/ESP-IDF-latest/components/esp_system/port/. -I../packages/ESP-IDF-latest/components/esp_system/port/soc -I../packages/ESP-IDF-latest/components/esp_system/port/include/riscv -I../packages/ESP-IDF-latest/components/esp_system/port/include/private -I../packages/ESP-IDF-latest/components/newlib/platform_include -I../packages/FreeRTOS_Wrapper-latest/FreeRTOS/include -I../packages/ESP-IDF-latest/components/freertos/esp_additions/include -I../packages/ESP-IDF-latest/components/freertos/esp_additions/include/freertos -I../packages/FreeRTOS_Wrapper-latest/FreeRTOS/portable/esp-idf/riscv/include -I../packages/ESP-IDF-latest/components/esp_hw_support/include -I../packages/ESP-IDF-latest/components/esp_hw_support/include/soc -I../packages/ESP-IDF-latest/components/esp_hw_support/include/soc/esp32c3 -I../packages/ESP-IDF-latest/components/esp_hw_support/port/esp32c3/. -I../packages/ESP-IDF-latest/components/esp_hw_support/port/esp32c3/private_include -I../packages/ESP-IDF-latest/components/heap/include -I../packages/ESP-IDF-latest/components/log/include -I../packages/ESP-IDF-latest/components/soc/include -I../packages/ESP-IDF-latest/components/soc/esp32c3/. -I../packages/ESP-IDF-latest/components/soc/esp32c3/include -I../packages/ESP-IDF-latest/components/hal/esp32c3/include -I../packages/ESP-IDF-latest/components/hal/include -I../packages/ESP-IDF-latest/components/hal/platform_port/include -I../packages/ESP-IDF-latest/components/esp_rom/include -I../packages/ESP-IDF-latest/components/esp_rom/include/esp32c3 -I../packages/ESP-IDF-latest/components/esp_rom/esp32c3 -I../packages/ESP-IDF-latest/components/esp_common/include -I../packages/ESP-IDF-latest/components/riscv/include -I/home/balance/Desktop/rt-thread/libcpu/risc-v/common -I/home/balance/Desktop/rt-thread/components/drivers/include -I../drivers -I/home/balance/Desktop/rt-thread/components/finsh -I../ -I/home/balance/Desktop/rt-thread/include -I../packages/ESP-IDF-latest/components/esp_ringbuf/include -I../packages/ESP-IDF-latest/components/efuse/include -I../packages/ESP-IDF-latest/components/efuse/esp32c3/include -I../packages/ESP-IDF-latest/components/esp_timer/include -I../packages/ESP-IDF-latest/components/driver/include -I../packages/ESP-IDF-latest/components/driver/deprecated -I../packages/ESP-IDF-latest/components/esp_pm/include -I../packages/ESP-IDF-latest/components/mbedtls/port/include -I../packages/ESP-IDF-latest/components/mbedtls/mbedtls/include -I../packages/ESP-IDF-latest/components/mbedtls/mbedtls/library -I../packages/ESP-IDF-latest/components/mbedtls/esp_crt_bundle/include -I../packages/ESP-IDF-latest/components/esp_app_format/include -I../packages/ESP-IDF-latest/components/bootloader_support/include -I../packages/ESP-IDF-latest/components/bootloader_support/bootloader_flash/include -I../packages/ESP-IDF-latest/components/app_update/include -I../packages/ESP-IDF-latest/components/spi_flash/include -I../packages/ESP-IDF-latest/components/pthread/include -march=rv32imc    -ffunction-sections -fdata-sections -Wall -Werror=all -Wno-error=unused-function -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-enum-conversion -gdwarf-4 -ggdb -nostartfiles -Og -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3=. -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3/packages/ESP-IDF-latest=/IDF -fstrict-volatile-bitfields -Wno-error=unused-but-set-variable -fno-jump-tables -fno-tree-switch-conversion -std=gnu17 -Wno-old-style-declaration -D_GNU_SOURCE -DIDF_VER=\"v5.0-dev-5148-g259c1776e9\" -DESP_PLATFORM -D_POSIX_READER_WRITER_LOCKS -Wno-format -MD  -c ../packages/ESP-IDF-latest/components/esp_system/crosscore_int.c
# [391/442] /home/balance/.espressif/tools/riscv32-esp-elf/esp-2022r1-11.2.0/riscv32-esp-elf/bin/riscv32-esp-elf-gcc -DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\" -Iconfig -I../packages/ESP-IDF-latest/components/esp_timer/include -I../packages/ESP-IDF-latest/components/esp_timer/private_include -I../packages/ESP-IDF-latest/components/newlib/platform_include -I../packages/FreeRTOS_Wrapper-latest/FreeRTOS/include -I../packages/ESP-IDF-latest/components/freertos/esp_additions/include -I../packages/ESP-IDF-latest/components/freertos/esp_additions/include/freertos -I../packages/FreeRTOS_Wrapper-latest/FreeRTOS/portable/esp-idf/riscv/include -I../packages/ESP-IDF-latest/components/esp_hw_support/include -I../packages/ESP-IDF-latest/components/esp_hw_support/include/soc -I../packages/ESP-IDF-latest/components/esp_hw_support/include/soc/esp32c3 -I../packages/ESP-IDF-latest/components/esp_hw_support/port/esp32c3/. -I../packages/ESP-IDF-latest/components/esp_hw_support/port/esp32c3/private_include -I../packages/ESP-IDF-latest/components/heap/include -I../packages/ESP-IDF-latest/components/log/include -I../packages/ESP-IDF-latest/components/soc/include -I../packages/ESP-IDF-latest/components/soc/esp32c3/. -I../packages/ESP-IDF-latest/components/soc/esp32c3/include -I../packages/ESP-IDF-latest/components/hal/esp32c3/include -I../packages/ESP-IDF-latest/components/hal/include -I../packages/ESP-IDF-latest/components/hal/platform_port/include -I../packages/ESP-IDF-latest/components/esp_rom/include -I../packages/ESP-IDF-latest/components/esp_rom/include/esp32c3 -I../packages/ESP-IDF-latest/components/esp_rom/esp32c3 -I../packages/ESP-IDF-latest/components/esp_common/include -I../packages/ESP-IDF-latest/components/esp_system/include -I../packages/ESP-IDF-latest/components/esp_system/port/soc -I../packages/ESP-IDF-latest/components/esp_system/port/include/riscv -I../packages/ESP-IDF-latest/components/esp_system/port/include/private -I../packages/ESP-IDF-latest/components/riscv/include -I/home/balance/Desktop/rt-thread/libcpu/risc-v/common -I/home/balance/Desktop/rt-thread/components/drivers/include -I../drivers -I/home/balance/Desktop/rt-thread/components/finsh -I../ -I/home/balance/Desktop/rt-thread/include -I../packages/ESP-IDF-latest/components/esp_ringbuf/include -I../packages/ESP-IDF-latest/components/efuse/include -I../packages/ESP-IDF-latest/components/efuse/esp32c3/include -I../packages/ESP-IDF-latest/components/driver/include -I../packages/ESP-IDF-latest/components/driver/deprecated -I../packages/ESP-IDF-latest/components/esp_pm/include -I../packages/ESP-IDF-latest/components/mbedtls/port/include -I../packages/ESP-IDF-latest/components/mbedtls/mbedtls/include -I../packages/ESP-IDF-latest/components/mbedtls/mbedtls/library -I../packages/ESP-IDF-latest/components/mbedtls/esp_crt_bundle/include -I../packages/ESP-IDF-latest/components/esp_app_format/include -I../packages/ESP-IDF-latest/components/bootloader_support/include -I../packages/ESP-IDF-latest/components/bootloader_support/bootloader_flash/include -I../packages/ESP-IDF-latest/components/app_update/include -I../packages/ESP-IDF-latest/components/spi_flash/include -I../packages/ESP-IDF-latest/components/pthread/include -march=rv32imc    -ffunction-sections -fdata-sections -Wall -Werror=all -Wno-error=unused-function -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-enum-conversion -gdwarf-4 -ggdb -nostartfiles -Og -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3=. -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3/packages/ESP-IDF-latest=/IDF -fstrict-volatile-bitfields -Wno-error=unused-but-set-variable -fno-jump-tables -fno-tree-switch-conversion -std=gnu17 -Wno-old-style-declaration -D_GNU_SOURCE -DIDF_VER=\"v5.0-dev-5148-g259c1776e9\" -DESP_PLATFORM -D_POSIX_READER_WRITER_LOCKS -MD -MT esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj -MF esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj.d -o esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj   -c ../packages/ESP-IDF-latest/components/esp_timer/src/esp_timer.c
# [159/442] /home/balance/.espressif/tools/riscv32-esp-elf/esp-2022r1-11.2.0/riscv32-esp-elf/bin/riscv32-esp-elf-gcc -DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\" -Iconfig -I../packages/ESP-IDF-latest/components/pthread/include -I../packages/ESP-IDF-latest/components/newlib/platform_include -I../packages/FreeRTOS_Wrapper-latest/FreeRTOS/include -I../packages/ESP-IDF-latest/components/freertos/esp_additions/include -I../packages/ESP-IDF-latest/components/freertos/esp_additions/include/freertos -I../packages/FreeRTOS_Wrapper-latest/FreeRTOS/portable/esp-idf/riscv/include -I../packages/ESP-IDF-latest/components/esp_hw_support/include -I../packages/ESP-IDF-latest/components/esp_hw_support/include/soc -I../packages/ESP-IDF-latest/components/esp_hw_support/include/soc/esp32c3 -I../packages/ESP-IDF-latest/components/esp_hw_support/port/esp32c3/. -I../packages/ESP-IDF-latest/components/esp_hw_support/port/esp32c3/private_include -I../packages/ESP-IDF-latest/components/heap/include -I../packages/ESP-IDF-latest/components/log/include -I../packages/ESP-IDF-latest/components/soc/include -I../packages/ESP-IDF-latest/components/soc/esp32c3/. -I../packages/ESP-IDF-latest/components/soc/esp32c3/include -I../packages/ESP-IDF-latest/components/hal/esp32c3/include -I../packages/ESP-IDF-latest/components/hal/include -I../packages/ESP-IDF-latest/components/hal/platform_port/include -I../packages/ESP-IDF-latest/components/esp_rom/include -I../packages/ESP-IDF-latest/components/esp_rom/include/esp32c3 -I../packages/ESP-IDF-latest/components/esp_rom/esp32c3 -I../packages/ESP-IDF-latest/components/esp_common/include -I../packages/ESP-IDF-latest/components/esp_system/include -I../packages/ESP-IDF-latest/components/esp_system/port/soc -I../packages/ESP-IDF-latest/components/esp_system/port/include/riscv -I../packages/ESP-IDF-latest/components/esp_system/port/include/private -I../packages/ESP-IDF-latest/components/riscv/include -I/home/balance/Desktop/rt-thread/libcpu/risc-v/common -I/home/balance/Desktop/rt-thread/components/drivers/include -I../drivers -I/home/balance/Desktop/rt-thread/components/finsh -I../ -I/home/balance/Desktop/rt-thread/include -I../packages/ESP-IDF-latest/components/esp_ringbuf/include -I../packages/ESP-IDF-latest/components/efuse/include -I../packages/ESP-IDF-latest/components/efuse/esp32c3/include -I../packages/ESP-IDF-latest/components/esp_timer/include -I../packages/ESP-IDF-latest/components/driver/include -I../packages/ESP-IDF-latest/components/driver/deprecated -I../packages/ESP-IDF-latest/components/esp_pm/include -I../packages/ESP-IDF-latest/components/mbedtls/port/include -I../packages/ESP-IDF-latest/components/mbedtls/mbedtls/include -I../packages/ESP-IDF-latest/components/mbedtls/mbedtls/library -I../packages/ESP-IDF-latest/components/mbedtls/esp_crt_bundle/include -I../packages/ESP-IDF-latest/components/esp_app_format/include -I../packages/ESP-IDF-latest/components/bootloader_support/include -I../packages/ESP-IDF-latest/components/bootloader_support/bootloader_flash/include -I../packages/ESP-IDF-latest/components/app_update/include -I../packages/ESP-IDF-latest/components/spi_flash/include -march=rv32imc    -ffunction-sections -fdata-sections -Wall -Werror=all -Wno-error=unused-function -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-enum-conversion -gdwarf-4 -ggdb -nostartfiles -Og -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3=. -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3/packages/ESP-IDF-latest=/IDF -fstrict-volatile-bitfields -Wno-error=unused-but-set-variable -fno-jump-tables -fno-tree-switch-conversion -std=gnu17 -Wno-old-style-declaration -D_GNU_SOURCE -DIDF_VER=\"v5.0-dev-5148-g259c1776e9\" -DESP_PLATFORM -D_POSIX_READER_WRITER_LOCKS -Wno-format -MD -MT esp-idf/pthread/CMakeFiles/__idf_pthread.dir/pthread_rwlock.c.obj -MF esp-idf/pthread/CMakeFiles/__idf_pthread.dir/pthread_rwlock.c.obj.d -o esp-idf/pthread/CMakeFiles/__idf_pthread.dir/pthread_rwlock.c.obj   -c ../packages/ESP-IDF-latest/components/pthread/pthread_rwlock.c
#  -march=rv32imc    -ffunction-sections -fdata-sections -Wall -Werror=all -Wno-error=unused-function -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wextra -Wno-unused-parameter -Wno-sign-compare -Wno-enum-conversion -gdwarf-4 -ggdb -nostartfiles -Og -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3=. -fmacro-prefix-map=/home/balance/Desktop/rt-thread/bsp/ESP32_C3/packages/ESP-IDF-latest=/IDF -fstrict-volatile-bitfields -Wno-error=unused-but-set-variable -fno-jump-tables -fno-tree-switch-conversion -std=gnu17 -Wno-old-style-declaration -D_GNU_SOURCE -DIDF_VER=\"v5.0-dev-5148-g259c1776e9\" -DESP_PLATFORM -D_POSIX_READER_WRITER_LOCKS -Wno-format -MD -MT esp-idf/pthread/CMakeFiles/__idf_pthread.dir/pthread_rwlock.c.obj -MF esp-idf/pthread/CMakeFiles/__idf_pthread.dir/pthread_rwlock.c.obj.d -o esp-idf/pthread/CMakeFiles/__idf_pthread.dir/pthread_rwlock.c.obj   -c ../packages/ESP-IDF-latest/components/pthread/pthread_rwlock.c

LIB_PATH = []
LIB = []
# LIB_PATH += [cwd + '/components/esp_phy/lib/esp32']
# LIB += ['rtc']

group = DefineGroup('esp-idf', src, depend = ['PKG_USING_ESP_IDF'], CPPPATH = path, LIBS = LIB, LIBPATH = LIB_PATH, CPPDEFINES = CPPDEFINES)

Return('group')