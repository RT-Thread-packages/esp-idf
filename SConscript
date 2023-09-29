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
                cwd + '/components/mbedtls/port/include',
                cwd + '/components/mbedtls/mbedtls/include',
                cwd + '/components/mbedtls/mbedtls/library',
                cwd + '/components/log/include',
                cwd + '/components/esp_hw_support/include/soc/esp32c3',
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
                cwd + '/components/hal/esp32c3/include',

                cwd + '/components/esp_system/port/include/riscv',

                cwd + '/components/esp_gdbstub/include',
                cwd + '/components/esp_gdbstub/private_include',
                cwd + '/components/esp_gdbstub/esp32c3',
                cwd + '/components/esp_gdbstub/riscv/'
            ]

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
components/mbedtls/esp_crt_bundle/esp_crt_bundle.c
""")
# components/freertos/esp_additions/freertos_v8_compat.c

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
components/esp_system/eh_frame_parser.c
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

esp32c3_wifi_src = Split("""
components/esp_wifi/src/coexist.c
components/esp_wifi/src/mesh_event.c
components/esp_wifi/src/smartconfig.c
components/esp_wifi/src/smartconfig_ack.c
components/esp_wifi/src/wifi_init.c
components/esp_wifi/src/wifi_netif.c
components/esp_wifi/src/wifi_default_ap.c
components/esp_wifi/esp32c3/esp_adapter.c
components/esp_wifi/lib/esp32c3/libcoexist.a
components/esp_wifi/lib/esp32c3/libcore.a
components/esp_wifi/lib/esp32c3/libespnow.a
components/esp_wifi/lib/esp32c3/libmesh.a
components/esp_wifi/lib/esp32c3/libnet80211.a
components/esp_wifi/lib/esp32c3/libpp.a
components/esp_wifi/lib/esp32c3/libsmartconfig.a
components/esp_wifi/lib/esp32c3/libwapi.a
""")
#components/esp_wifi/src/wifi_default.c

esp32c3_wpa_supplicant_src = Split("""
components/wpa_supplicant/port/os_xtensa.c
components/wpa_supplicant/port/eloop.c
components/wpa_supplicant/src/ap/ap_config.c
components/wpa_supplicant/src/ap/ieee802_1x.c
components/wpa_supplicant/src/ap/wpa_auth.c
components/wpa_supplicant/src/ap/wpa_auth_ie.c
components/wpa_supplicant/src/ap/sta_info.c
components/wpa_supplicant/src/common/sae.c
components/wpa_supplicant/src/common/wpa_common.c
components/wpa_supplicant/src/utils/bitfield.c
components/wpa_supplicant/src/crypto/aes-siv.c
components/wpa_supplicant/src/crypto/sha256-kdf.c
components/wpa_supplicant/src/crypto/ccmp.c
components/wpa_supplicant/src/crypto/aes-gcm.c
components/wpa_supplicant/src/crypto/crypto_ops.c
components/wpa_supplicant/src/crypto/dh_group5.c
components/wpa_supplicant/src/crypto/dh_groups.c
components/wpa_supplicant/src/crypto/ms_funcs.c
components/wpa_supplicant/src/crypto/sha1-tlsprf.c
components/wpa_supplicant/src/crypto/sha256-tlsprf.c
components/wpa_supplicant/src/crypto/sha384-tlsprf.c
components/wpa_supplicant/src/crypto/sha256-prf.c
components/wpa_supplicant/src/crypto/sha1-prf.c
components/wpa_supplicant/src/crypto/sha384-prf.c
components/wpa_supplicant/src/crypto/md4-internal.c
components/wpa_supplicant/src/crypto/sha1-tprf.c
components/wpa_supplicant/src/eap_common/eap_wsc_common.c
components/wpa_supplicant/src/common/ieee802_11_common.c
components/wpa_supplicant/src/eap_peer/chap.c
components/wpa_supplicant/src/eap_peer/eap.c
components/wpa_supplicant/src/eap_peer/eap_common.c
components/wpa_supplicant/src/eap_peer/eap_mschapv2.c
components/wpa_supplicant/src/eap_peer/eap_peap.c
components/wpa_supplicant/src/eap_peer/eap_peap_common.c
components/wpa_supplicant/src/eap_peer/eap_tls.c
components/wpa_supplicant/src/eap_peer/eap_tls_common.c
components/wpa_supplicant/src/eap_peer/eap_ttls.c
components/wpa_supplicant/src/eap_peer/mschapv2.c
components/wpa_supplicant/src/eap_peer/eap_fast.c
components/wpa_supplicant/src/eap_peer/eap_fast_common.c
components/wpa_supplicant/src/rsn_supp/pmksa_cache.c
components/wpa_supplicant/src/rsn_supp/wpa.c
components/wpa_supplicant/src/rsn_supp/wpa_ie.c
components/wpa_supplicant/src/utils/base64.c
components/wpa_supplicant/src/utils/common.c
components/wpa_supplicant/src/utils/ext_password.c
components/wpa_supplicant/src/utils/uuid.c
components/wpa_supplicant/src/utils/wpabuf.c
components/wpa_supplicant/src/utils/wpa_debug.c
components/wpa_supplicant/src/utils/json.c
components/wpa_supplicant/src/wps/wps.c
components/wpa_supplicant/src/wps/wps_attr_build.c
components/wpa_supplicant/src/wps/wps_attr_parse.c
components/wpa_supplicant/src/wps/wps_attr_process.c
components/wpa_supplicant/src/wps/wps_common.c
components/wpa_supplicant/src/wps/wps_dev_attr.c
components/wpa_supplicant/src/wps/wps_enrollee.c
components/wpa_supplicant/esp_supplicant/src/esp_wpa2.c
components/wpa_supplicant/esp_supplicant/src/esp_wpa_main.c
components/wpa_supplicant/esp_supplicant/src/esp_wpas_glue.c
components/wpa_supplicant/esp_supplicant/src/esp_common.c
components/wpa_supplicant/esp_supplicant/src/esp_wps.c
components/wpa_supplicant/esp_supplicant/src/esp_wpa3.c
components/wpa_supplicant/esp_supplicant/src/esp_owe.c
components/wpa_supplicant/esp_supplicant/src/esp_hostap.c
components/wpa_supplicant/esp_supplicant/src/crypto/tls_mbedtls.c
components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls.c
components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls-bignum.c
components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls-rsa.c
components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls-ec.c
components/wpa_supplicant/src/crypto/rc4.c
components/wpa_supplicant/src/crypto/des-internal.c
components/wpa_supplicant/src/crypto/aes-omac1.c
components/wpa_supplicant/src/crypto/aes-wrap.c
components/wpa_supplicant/src/crypto/aes-unwrap.c
components/wpa_supplicant/src/crypto/aes-ccm.c
""")

# components/wpa_supplicant/src/eap_peer/eap_fast_pac.c

esp32c3_netif_src = Split("""
components/esp_netif/esp_netif_handlers.c
components/esp_netif/esp_netif_objects.c
components/esp_netif/esp_netif_defaults.c
components/esp_netif/lwip/esp_netif_lwip.c
components/esp_netif/lwip/esp_netif_lwip_defaults.c
components/esp_netif/lwip/netif/wlanif.c
components/esp_netif/lwip/netif/ethernetif.c
components/esp_netif/lwip/netif/esp_pbuf_ref.c
components/esp_netif/loopback/esp_netif_loopback.c
""")

esp32c3_lwip_src = Split("""
components/lwip/apps/sntp/sntp.c
components/lwip/lwip/src/api/api_lib.c
components/lwip/lwip/src/api/api_msg.c
components/lwip/lwip/src/api/err.c
components/lwip/lwip/src/api/if_api.c
components/lwip/lwip/src/api/netbuf.c
components/lwip/lwip/src/api/netdb.c
components/lwip/lwip/src/api/netifapi.c
components/lwip/lwip/src/api/sockets.c
components/lwip/lwip/src/api/tcpip.c
components/lwip/lwip/src/apps/sntp/sntp.c
components/lwip/lwip/src/apps/netbiosns/netbiosns.c
components/lwip/lwip/src/core/def.c
components/lwip/lwip/src/core/dns.c
components/lwip/lwip/src/core/inet_chksum.c
components/lwip/lwip/src/core/init.c
components/lwip/lwip/src/core/ip.c
components/lwip/lwip/src/core/mem.c
components/lwip/lwip/src/core/memp.c
components/lwip/lwip/src/core/netif.c
components/lwip/lwip/src/core/pbuf.c
components/lwip/lwip/src/core/raw.c
components/lwip/lwip/src/core/stats.c
components/lwip/lwip/src/core/sys.c
components/lwip/lwip/src/core/tcp.c
components/lwip/lwip/src/core/tcp_in.c
components/lwip/lwip/src/core/tcp_out.c
components/lwip/lwip/src/core/timeouts.c
components/lwip/lwip/src/core/udp.c
components/lwip/lwip/src/core/ipv4/autoip.c
components/lwip/lwip/src/core/ipv4/dhcp.c
components/lwip/lwip/src/core/ipv4/etharp.c
components/lwip/lwip/src/core/ipv4/icmp.c
components/lwip/lwip/src/core/ipv4/igmp.c
components/lwip/lwip/src/core/ipv4/ip4.c
components/lwip/lwip/src/core/ipv4/ip4_napt.c
components/lwip/lwip/src/core/ipv4/ip4_addr.c
components/lwip/lwip/src/core/ipv4/ip4_frag.c
components/lwip/lwip/src/core/ipv6/dhcp6.c
components/lwip/lwip/src/core/ipv6/ethip6.c
components/lwip/lwip/src/core/ipv6/icmp6.c
components/lwip/lwip/src/core/ipv6/inet6.c
components/lwip/lwip/src/core/ipv6/ip6_addr.c
components/lwip/lwip/src/core/ipv6/ip6.c
components/lwip/lwip/src/core/ipv6/ip6_frag.c
components/lwip/lwip/src/core/ipv6/mld6.c
components/lwip/lwip/src/core/ipv6/nd6.c
components/lwip/lwip/src/netif/ethernet.c
components/lwip/lwip/src/netif/bridgeif.c
components/lwip/lwip/src/netif/bridgeif_fdb.c
components/lwip/lwip/src/netif/slipif.c
components/lwip/lwip/src/netif/ppp/auth.c
components/lwip/lwip/src/netif/ppp/ccp.c
components/lwip/lwip/src/netif/ppp/chap-md5.c
components/lwip/lwip/src/netif/ppp/chap-new.c
components/lwip/lwip/src/netif/ppp/chap_ms.c
components/lwip/lwip/src/netif/ppp/demand.c
components/lwip/lwip/src/netif/ppp/eap.c
components/lwip/lwip/src/netif/ppp/ecp.c
components/lwip/lwip/src/netif/ppp/eui64.c
components/lwip/lwip/src/netif/ppp/fsm.c
components/lwip/lwip/src/netif/ppp/ipcp.c
components/lwip/lwip/src/netif/ppp/ipv6cp.c
components/lwip/lwip/src/netif/ppp/lcp.c
components/lwip/lwip/src/netif/ppp/mppe.c
components/lwip/lwip/src/netif/ppp/magic.c
components/lwip/lwip/src/netif/ppp/multilink.c
components/lwip/lwip/src/netif/ppp/ppp.c
components/lwip/lwip/src/netif/ppp/pppapi.c
components/lwip/lwip/src/netif/ppp/pppcrypt.c
components/lwip/lwip/src/netif/ppp/pppoe.c
components/lwip/lwip/src/netif/ppp/pppol2tp.c
components/lwip/lwip/src/netif/ppp/pppos.c
components/lwip/lwip/src/netif/ppp/upap.c
components/lwip/lwip/src/netif/ppp/utils.c
components/lwip/lwip/src/netif/ppp/vj.c
components/lwip/port/esp32/hooks/tcp_isn_default.c
components/lwip/port/esp32/hooks/lwip_default_hooks.c
components/lwip/port/esp32/debug/lwip_debug.c
components/lwip/port/esp32/freertos/sys_arch.c
components/lwip/port/esp32/sockets_ext.c
components/lwip/port/esp32/vfs_lwip.c
components/lwip/apps/ping/esp_ping.c
components/lwip/apps/ping/ping.c
components/lwip/apps/ping/ping_sock.c
components/lwip/apps/dhcpserver/dhcpserver.c
""")

esp32c3_vfs_src = Split("""
components/vfs/vfs_eventfd.c
components/vfs/vfs.c
components/vfs/vfs_uart.c
components/vfs/vfs_semihost.c
components/vfs/vfs_console.c
components/vfs/vfs_usb_serial_jtag.c
""")

esp32c3_nvs_flash_src = Split("""
components/nvs_flash/src/nvs_api.cpp
components/nvs_flash/src/nvs_cxx_api.cpp
components/nvs_flash/src/nvs_item_hash_list.cpp
components/nvs_flash/src/nvs_page.cpp
components/nvs_flash/src/nvs_pagemanager.cpp
components/nvs_flash/src/nvs_storage.cpp
components/nvs_flash/src/nvs_handle_simple.cpp
components/nvs_flash/src/nvs_handle_locked.cpp
components/nvs_flash/src/nvs_partition.cpp
components/nvs_flash/src/nvs_partition_lookup.cpp
components/nvs_flash/src/nvs_partition_manager.cpp
components/nvs_flash/src/nvs_types.cpp
""")

esp32c3_esp_event_src = Split("""
components/esp_event/esp_event.c
components/esp_event/default_event_loop.c
components/esp_event/esp_event_private.c
""")

esp32c3_bt_src = Split("""
components/bt/controller/esp32c3/bt.c
components/bt/common/btc/core/btc_alarm.c
components/bt/common/api/esp_blufi_api.c
components/bt/common/btc/core/btc_task.c
components/bt/common/btc/core/btc_manage.c
components/bt/common/btc/profile/esp/blufi/blufi_prf.c
components/bt/common/btc/profile/esp/blufi/blufi_protocol.c
components/bt/common/osi/alarm.c
components/bt/common/osi/allocator.c
components/bt/common/osi/buffer.c
components/bt/common/osi/config.c
components/bt/common/osi/fixed_queue.c
components/bt/common/osi/pkt_queue.c
components/bt/common/osi/fixed_pkt_queue.c
components/bt/common/osi/future.c
components/bt/common/osi/hash_functions.c
components/bt/common/osi/hash_map.c
components/bt/common/osi/list.c
components/bt/common/osi/mutex.c
components/bt/common/osi/thread.c
components/bt/common/osi/osi.c
components/bt/common/osi/semaphore.c
components/bt/porting/mem/bt_osi_mem.c
components/bt/host/nimble/nimble/nimble/host/util/src/addr.c
components/bt/host/nimble/nimble/nimble/host/services/gatt/src/ble_svc_gatt.c
components/bt/host/nimble/nimble/nimble/host/services/tps/src/ble_svc_tps.c
components/bt/host/nimble/nimble/nimble/host/services/ias/src/ble_svc_ias.c
components/bt/host/nimble/nimble/nimble/host/services/ipss/src/ble_svc_ipss.c
components/bt/host/nimble/nimble/nimble/host/services/ans/src/ble_svc_ans.c
components/bt/host/nimble/nimble/nimble/host/services/gap/src/ble_svc_gap.c
components/bt/host/nimble/nimble/nimble/host/services/bas/src/ble_svc_bas.c
components/bt/host/nimble/nimble/nimble/host/services/dis/src/ble_svc_dis.c
components/bt/host/nimble/nimble/nimble/host/services/lls/src/ble_svc_lls.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_conn.c
components/bt/host/nimble/nimble/nimble/host/src/ble_store_util.c
components/bt/host/nimble/nimble/nimble/host/src/ble_sm.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_shutdown.c
components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_sig_cmd.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_cmd.c
components/bt/host/nimble/nimble/nimble/host/src/ble_att_svr.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_id.c
components/bt/host/nimble/nimble/nimble/host/src/ble_gatts_lcl.c
components/bt/host/nimble/nimble/nimble/host/src/ble_ibeacon.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_atomic.c
components/bt/host/nimble/nimble/nimble/host/src/ble_sm_alg.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_stop.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_evt.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_mqueue.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_periodic_sync.c
components/bt/host/nimble/nimble/nimble/host/src/ble_att.c
components/bt/host/nimble/nimble/nimble/host/src/ble_gattc.c
components/bt/host/nimble/nimble/nimble/host/src/ble_store.c
components/bt/host/nimble/nimble/nimble/host/src/ble_sm_lgcy.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_cfg.c
components/bt/host/nimble/nimble/nimble/host/src/ble_monitor.c
components/bt/host/nimble/nimble/nimble/host/src/ble_att_clt.c
components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_coc.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_mbuf.c
components/bt/host/nimble/nimble/nimble/host/src/ble_att_cmd.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_log.c
components/bt/host/nimble/nimble/nimble/host/src/ble_eddystone.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_startup.c
components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_sig.c
components/bt/host/nimble/nimble/nimble/host/src/ble_gap.c
components/bt/host/nimble/nimble/nimble/host/src/ble_sm_cmd.c
components/bt/host/nimble/nimble/nimble/host/src/ble_uuid.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_pvcy.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_flow.c
components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap.c
components/bt/host/nimble/nimble/nimble/host/src/ble_sm_sc.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_misc.c
components/bt/host/nimble/nimble/nimble/host/src/ble_gatts.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_adv.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_util.c
components/bt/host/nimble/nimble/nimble/host/src/ble_hs_resolv.c
components/bt/host/nimble/nimble/nimble/host/store/ram/src/ble_store_ram.c
components/bt/host/nimble/nimble/nimble/host/store/config/src/ble_store_config.c
components/bt/host/nimble/nimble/nimble/host/store/config/src/ble_store_nvs.c
components/bt/host/nimble/nimble/porting/nimble/src/nimble_port.c
components/bt/host/nimble/nimble/porting/npl/freertos/src/nimble_port_freertos.c
components/bt/host/nimble/nimble/porting/nimble/src/endian.c
components/bt/host/nimble/nimble/porting/nimble/src/os_mempool.c
components/bt/host/nimble/nimble/porting/nimble/src/mem.c
components/bt/host/nimble/nimble/porting/nimble/src/os_mbuf.c
components/bt/host/nimble/nimble/porting/nimble/src/os_msys_init.c
components/bt/host/nimble/nimble/porting/npl/freertos/src/npl_os_freertos.c
components/bt/host/nimble/esp-hci/src/esp_nimble_hci.c
components/bt/common/btc/profile/esp/blufi/nimble_host/esp_blufi.c
components/bt/controller/lib_esp32c3_family/esp32c3/libbtdm_app.a
""")

esp32c3_esp_phy_src = Split("""
components/esp_phy/src/lib_printf.c
components/esp_phy/src/phy_override.c
components/esp_phy/src/phy_init.c
components/esp_phy/lib/esp32c3/libphy.a
components/esp_phy/lib/esp32c3/libbtbb.a
""")

esp32c3_esp_gdbsub_src = Split("""
components/esp_gdbstub/esp32c3/gdbstub_esp32c3.c
components/esp_gdbstub/riscv/gdbstub_riscv.c
components/esp_gdbstub/src/gdbstub.c
components/esp_gdbstub/src/packet.c
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
    src += esp32c3_esp_gdbsub_src
    path += esp32c3_path
    CPPDEFINES = [ 'IDF_VER=\\"999\\\"', 'PROJECT_VER=\\"999\\"' ,'_GNU_SOURCE' , 'MULTI_HEAP_FREERTOS', 'ESP_PLATFORM=1', 'IDF_TARGET=esp32c3', '_POSIX_READER_WRITER_LOCKS' , 'PROJECT_NAME=\\"rtthread\\"' , 'MBEDTLS_CONFIG_FILE=\\"mbedtls/esp_config.h\\"', 'ESPRESSIF_USE', 'CONFIG_CRYPTO_MBEDTLS', 'CONFIG_ECC', 'CONFIG_IEEE80211W', 'CONFIG_NO_RADIUS', 'CONFIG_OWE_STA', 'CONFIG_SHA256', 'CONFIG_WPA3_SAE', 'CONFIG_WPS', 'EAP_MSCHAPv2', 'EAP_PEAP', 'EAP_PEER_METHOD', 'EAP_TLS ', 'EAP_TTLS', 'ESP32_WORKAROUND','ESP_SUPPLICANT', 'IEEE8021X_EAPOL', 'UNITY_INCLUDE_CONFIG_H', 'USE_WPA2_TASK', 'USE_WPS_TASK', '__ets__', 'ESP_PLATFORM']

LIB_PATH = []
LIB = []

if GetDepend(['BSP_USING_WIFI']) or GetDepend(['BSP_USING_BLE']) :
    src += esp32c3_wifi_src
    src += esp32c3_wpa_supplicant_src
    src += esp32c3_nvs_flash_src
    src += esp32c3_esp_phy_src
    src += esp32c3_esp_event_src
    LIB_PATH.append(cwd + '/components/esp_phy/lib/esp32c3/')
    LIB_PATH.append(cwd + '/components/esp_wifi/lib/esp32c3/')
    LIB.append('btbb')
    LIB.append('coexist')
    LIB.append('espnow')
    LIB.append('net80211')
    LIB.append('pp')
    LIB.append('smartconfig')
    LIB.append('wapi')
    LIB.append('core')
    LIB.append('mesh')
    LIB.append('phy')
    path += [                
        cwd + '/components/esp_wifi/include',
        cwd + '/components/esp_event/include',
        cwd + '/components/nvs_flash/include',
        cwd + '/components/esp_phy/include',
        cwd + '/components/esp_netif/include',
        cwd + '/components/esp_phy/include',
        cwd + '/components/esp_phy/esp32c3/include',
        cwd + '/components/wpa_supplicant/include',
        cwd + '/components/wpa_supplicant/port/include',
        cwd + '/components/wpa_supplicant/esp_supplicant/include',
        cwd + '/components/wpa_supplicant/esp_supplicant/src',
        cwd + '/components/wpa_supplicant/src',
        cwd + '/components/wpa_supplicant/src/utils',
        cwd + '/components/wpa_supplicant/src/crypto',
        cwd + '/components/nvs_flash/include',
        cwd + '/components/nvs_flash/private_include',
        cwd + '/components/esp_event/include',
        cwd + '/components/esp_event/private_include',
        cwd + '/components/esp_netif/include'
    ]


if GetDepend(['BSP_USING_BLE']) :
    src += esp32c3_bt_src
    src += esp32c3_lwip_src
    src += esp32c3_netif_src
    src += esp32c3_vfs_src
    LIB_PATH.append(cwd + '/components/bt/controller/lib_esp32c3_family/esp32c3/')
    LIB.append('btdm_app')
    path += [
        cwd + '/components/bt/include/esp32c3/include',
        cwd + '/components/bt/common/osi/include',
        cwd + '/components/bt/common/api/include/api',
        cwd + '/components/bt/common/btc/profile/esp/blufi/include',
        cwd + '/components/bt/common/btc/profile/esp/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/ans/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/bas/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/dis/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/gap/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/gatt/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/ias/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/ipss/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/lls/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/services/tps/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/util/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/store/ram/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/host/store/config/include',
        cwd + '/components/bt/porting/include',
        cwd + '/components/bt/host/nimble/nimble/porting/nimble/include',
        cwd + '/components/bt/host/nimble/port/include',
        cwd + '/components/bt/host/nimble/nimble/porting/npl/freertos/include',
        cwd + '/components/bt/host/nimble/nimble/nimble/include',
        cwd + '/components/bt/host/nimble/esp-hci/include',
        cwd + '/components/bt/common/btc/include',
        cwd + '/components/bt/common/btc/profile/esp/blufi/include',
        cwd + '/components/bt/common/btc/profile/esp/include',
        cwd + '/components/bt/common/include',
        cwd + '/components/bt/porting/mem',

        cwd + '/components/lwip/include',
        cwd + '/components/lwip/include/apps',
        cwd + '/components/lwip/include/apps/sntp',
        cwd + '/components/lwip/lwip/src/include',
        cwd + '/components/lwip/port/esp32/include',
        cwd + '/components/lwip/port/esp32/include/arch',

        cwd + '/components/esp_netif/include',
        cwd + '/components/esp_netif/private_include',
        
        cwd + '/components/vfs/include',
        cwd + '/components/vfs/private_include/'
    ]

group = DefineGroup('esp-idf', src, depend = ['PKG_USING_ESP_IDF'], CPPPATH = path, LIBS = LIB, LIBPATH = LIB_PATH, CPPDEFINES = CPPDEFINES)

Return('group')