from building import *
import os
import re
import glob as pyglob

cwd = GetCurrentDir()

src = []
path = []

def _glob(*patterns):
    res = []
    for p in patterns:
        for f in pyglob.glob(os.path.join(cwd, p)):
            if os.path.isfile(f) and f not in res:
                res.append(os.path.relpath(f, cwd))
    return res

esp32c3_adc_src = [
    'components/esp_adc/adc_cali_curve_fitting.c',
    'components/esp_adc/adc_cali.c',
    'components/esp_adc/adc_common.c',
    'components/esp_adc/adc_continuous.c',
    # dropped (no v6.1 equivalent): components/esp_adc/adc_lock.c
    'components/esp_adc/adc_oneshot.c',
    # dropped (no v6.1 equivalent): components/esp_adc/deprecated/esp32c3/esp_adc_cal_legacy.c
    'components/esp_adc/esp32c3/curve_fitting_coefficients.c',
]

esp32c3_src = [
    'components/esp_app_format/esp_app_desc.c',
    'components/esp_ringbuf/ringbuf.c',
    'components/esp_pm/pm_trace.c',
    'components/esp_pm/pm_locks.c',
    'components/esp_pm/pm_impl.c',
    'components/cxx/cxx_exception_stubs.cpp',
    'components/cxx/cxx_guards.cpp',
    # dropped (no v6.1 equivalent): components/freertos/FreeRTOS-openocd.c
    # dropped (no v6.1 equivalent): components/app_update/esp_ota_app_desc.c
    'components/app_update/esp_ota_ops.c',
    'components/esp_common/src/esp_err_to_name.c',
    'components/bootloader_support/src/esp32c3/bootloader_esp32c3.c',
    'components/bootloader_support/src/esp32c3/bootloader_soc.c',
    'components/bootloader_support/src/bootloader_init.c',
    'components/bootloader_support/src/bootloader_console.c',
    'components/mbedtls/esp_crt_bundle/esp_crt_bundle.c',
]

# ESP-IDF v6.1 ships mbedtls 4.x with a different source layout;
# collect the library and the ESP port sources by glob instead.
esp32c3_mbedtls_src = []
esp32c3_mbedtls_src += _glob('components/mbedtls/mbedtls/library/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/mbedtls/tf-psa-crypto/core/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/mbedtls/tf-psa-crypto/drivers/builtin/src/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/mbedtls/tf-psa-crypto/extras/*.c')
# mbedtls 4.x moved these out of library/ into the tf-psa-crypto tree
esp32c3_mbedtls_src += _glob('components/mbedtls/mbedtls/tf-psa-crypto/utilities/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/mbedtls/tf-psa-crypto/platform/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/sha/core/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/sha/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/aes/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/aes/dma/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/psa_crypto_storage/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/psa_driver/esp_aes/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/psa_driver/esp_mac/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/psa_driver/esp_md/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/psa_driver/esp_sha/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/psa_driver/esp_sha/core/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/bignum/*.c')
esp32c3_mbedtls_src += _glob('components/mbedtls/port/md/*.c')
# The AES/SHA hardware back ends come in two flavours and
# components/mbedtls/CMakeLists.txt only picks the *crypto_dma* one for SoCs
# without a GDMA block; ESP32-C3/C6 have GDMA.  The BSD socket shims are only
# built when lwIP is part of the build (or on the linux target), which the
# scons BSPs never are, and mbedtls' own net_sockets.c is replaced by the port
# one, which is not built at all here.
esp32c3_mbedtls_src = [f for f in esp32c3_mbedtls_src
                       if f not in ('components/mbedtls/port/aes/dma/esp_aes_crypto_dma_impl.c',
                                    'components/mbedtls/port/sha/core/esp_sha_crypto_dma_impl.c',
                                    'components/mbedtls/port/net_sockets.c',
                                    'components/mbedtls/mbedtls/library/net_sockets.c',
                                    # needs the nvs_flash component, which the scons
                                    # BSPs do not build (ESP-IDF guards it with
                                    # BUILD_COMPONENTS in components/mbedtls/CMakeLists.txt)
                                    'components/mbedtls/port/psa_crypto_storage/esp_psa_its.c')]

esp32c3_hal_src = [
    'components/esp_hal_wdt/xt_wdt_hal.c',
    # dropped (no v6.1 equivalent on the ESP32-C3): components/esp_hal_security/mpu_hal.c
    'components/hal/efuse_hal.c',
    'components/esp_hal_gpio/rtc_io_hal.c',
    'components/hal/esp32c3/efuse_hal.c',
    'components/hal/mmu_hal.c',
    'components/esp_hal_wdt/wdt_hal_iram.c',
    'components/hal/cache_hal.c',
    'components/esp_hal_gpspi/spi_hal_iram.c',
    'components/esp_hal_timg/timer_hal.c',
    # dropped (no v6.1 equivalent): components/hal/timer_hal_iram.c
    'components/esp_hal_gpspi/spi_slave_hal.c',
    'components/esp_hal_gpspi/spi_hal.c',
    'components/esp_hal_gpspi/spi_slave_hal_iram.c',
    'components/esp_hal_ledc/ledc_hal.c',
    'components/esp_hal_i2c/i2c_hal.c',
    'components/esp_hal_gpio/gpio_hal.c',
    'components/esp_hal_i2c/i2c_hal_iram.c',
    'components/esp_hal_ledc/ledc_hal_iram.c',
    'components/esp_hal_uart/uart_hal_iram.c',
    'components/esp_hal_uart/uart_hal.c',
    'components/esp_hal_mspi/spi_flash_encrypt_hal_iram.c',
    'components/esp_hal_mspi/spi_flash_hal.c',
    'components/esp_hal_security/sha_hal.c',
    'components/esp_hal_systimer/systimer_hal.c',
    'components/esp_hal_ana_conv/adc_oneshot_hal.c',
    'components/esp_hal_rmt/rmt_hal.c',
    'components/esp_hal_gpio/sdm_hal.c',
    'components/esp_hal_ana_conv/adc_hal_common.c',
    'components/esp_hal_mspi/spi_flash_hal_iram.c',
    'components/esp_hal_security/ds_hal.c',
    # dropped (no v6.1 equivalent): components/hal/twai_hal_iram.c
    # v6.1 split components/hal/gdma_hal.c into esp_hal_dma
    'components/esp_hal_dma/gdma_hal_top.c',
    'components/esp_hal_dma/gdma_hal_ahb_v1.c',
    # dropped (no v6.1 equivalent): components/hal/twai_hal.c
    'components/esp_hal_clock/esp32c3/clk_tree_hal.c',
    'components/esp_hal_wdt/xt_wdt_hal.c',
    'components/esp_hal_pmu/brownout_hal.c',
    'components/esp_hal_i2s/i2s_hal.c',
    'components/esp_hal_mspi/spi_flash_hal_gpspi.c',
    'components/esp_hal_pmu/esp32c3/rtc_cntl_hal.c',
    'components/esp_hal_ana_conv/adc_hal.c',
    'components/esp_hal_security/aes_hal.c',
    'components/esp_hal_security/hmac_hal.c',
    'components/esp_hal_gpspi/spi_slave_hd_hal.c',
]

esp32c3_soc_src = [
    'components/soc/lldesc.c',
    'components/soc/dport_access_common.c',
    'components/soc/esp32c3/gpio_periph.c',
    'components/esp_hal_gpio/esp32c3/sdm_periph.c',
    'components/soc/esp32c3/interrupts.c',
    'components/esp_hal_rmt/esp32c3/rmt_periph.c',
    'components/esp_hal_ledc/esp32c3/ledc_periph.c',
    'components/esp_hal_i2s/esp32c3/i2s_periph.c',
    'components/esp_hal_gpio/esp32c3/dedic_gpio_periph.c',
    'components/esp_hal_ana_conv/esp32c3/adc_periph.c',
    'components/esp_hal_dma/esp32c3/gdma_periph.c',
    'components/esp_hal_i2c/esp32c3/i2c_periph.c',
    'components/esp_hal_gpspi/esp32c3/spi_periph.c',
    'components/esp_hal_ana_conv/esp32c3/temperature_sensor_periph.c',
    'components/esp_hal_uart/esp32c3/uart_periph.c',
    'components/esp_hal_timg/esp32c3/timer_periph.c',
    # v6.1: MPI_BLOCK_BASES / MPI_OPERATIONS_REG moved here
    'components/soc/esp32c3/mpi_periph.c',
]

esp32c3_esp_hw_support_src = [
    'components/esp_hw_support/esp_memory_utils.c',
    'components/esp_hw_support/hw_random.c',
    'components/esp_hw_support/clk_ctrl_os.c',
    'components/esp_hw_support/esp_clk.c',
    'components/esp_hw_support/cpu.c',
    'components/esp_hw_support/mac_addr.c',
    # dropped (no v6.1 equivalent): components/esp_hw_support/sleep_mac_bb.c
    'components/esp_hw_support/periph_ctrl.c',
    'components/esp_hw_support/sleep_gpio.c',
    'components/esp_hw_support/sleep_modes.c',
    'components/esp_hw_support/rtc_module.c',
    'components/esp_hw_support/intr_alloc.c',
    'components/esp_hw_support/regi2c_ctrl.c',
    'components/esp_hw_support/port/esp32c3/systimer.c',
    # dropped (no v6.1 equivalent on the ESP32-C3, needs CONFIG_SOC_PAU_SUPPORTED): components/esp_hw_support/sleep_retention.c
    'components/esp_hw_support/adc_share_hw_ctrl.c',
    # dropped (no v6.1 equivalent): components/esp_hw_support/port/async_memcpy_impl_gdma.c
    'components/esp_hw_support/port/esp32c3/rtc_clk_init.c',
    # dropped (no v6.1 equivalent): components/esp_hw_support/port/esp32c3/rtc_pm.c
    'components/esp_driver_dma/src/esp_async_memcpy.c',
    'components/esp_hw_support/port/esp32c3/rtc_sleep.c',
    'components/esp_driver_dma/src/gdma.c',
    'components/esp_hw_support/port/esp32c3/rtc_init.c',
    'components/esp_hw_support/port/esp32c3/rtc_time.c',
    'components/esp_hw_support/port/esp32c3/chip_info.c',
    'components/esp_hw_support/port/esp32c3/rtc_clk.c',
    'components/esp_security/src/esp_hmac.c',
    'components/esp_security/src/esp_crypto_lock.c',
    'components/esp_hw_support/port/esp_memprot_conv.c',
    'components/esp_hw_support/port/esp32c3/adc2_init_cal.c',
    'components/esp_security/src/esp_ds.c',
    'components/esp_hw_support/port/esp32c3/esp_memprot.c',
    # new in v6.1
    'components/esp_hw_support/port/esp32c3/esp_clk_tree.c',
    'components/esp_hw_support/port/esp32c3/cpu_region_protect.c',
    'components/esp_hw_support/port/esp32c3/esp_cpu_intr.c',
    'components/esp_hw_support/port/esp32c3/sar_periph_ctrl.c',
    'components/esp_hw_support/esp_gpio_reserve.c',
    'components/esp_hw_support/sar_periph_ctrl_common.c',
    'components/esp_hw_support/clk_utils.c',
    'components/esp_hw_support/sleep_cache.c',
    'components/esp_hw_support/sleep_console.c',
    'components/esp_hw_support/sleep_event.c',
    'components/esp_hw_support/sleep_modem.c',
    'components/esp_hw_support/sleep_uart.c',
    'components/esp_hw_support/mspi/mspi_timing_tuning/mspi_timing_tuning.c',
    'components/esp_security/src/esp_crypto_periph_clk.c',
    'components/esp_security/src/esp32c3/esp_crypto_clk.c',
    # new in v6.1: the memory management unit moved into its own component
    'components/esp_mm/esp_mmu_map.c',
    'components/esp_mm/esp_cache_utils.c',
    # new in v6.1
    'components/esp_mm/esp_cache_msync.c',
    'components/esp_mm/port/esp32c3/ext_mem_layout.c',
    'components/esp_hw_support/heap_align_hw.c',
    'components/esp_hw_support/port/esp_clk_tree_common.c',
]

esp32c3_bootloader_support_src = [
    'components/bootloader_support/src/bootloader_random_esp32c3.c',
    'components/bootloader_support/src/bootloader_mem.c',
    'components/bootloader_support/src/bootloader_common.c',
    'components/bootloader_support/src/bootloader_clock_init.c',
    'components/bootloader_support/src/bootloader_random.c',
    'components/bootloader_support/src/bootloader_common_loader.c',
    'components/bootloader_support/src/flash_partitions.c',
    'components/bootloader_support/bootloader_flash/src/bootloader_flash.c',
    'components/bootloader_support/src/flash_encrypt.c',
    'components/bootloader_support/src/secure_boot.c',
    'components/bootloader_support/src/bootloader_efuse.c',
    'components/bootloader_support/src/bootloader_utility.c',
    'components/bootloader_support/src/esp_image_format.c',
    'components/bootloader_support/bootloader_flash/src/bootloader_flash_config_esp32c3.c',
    'components/bootloader_support/bootloader_flash/src/flash_qio_mode.c',
    'components/bootloader_support/src/bootloader_sha.c',
]

esp32c3_esp_system_src = [
    'components/esp_system/int_wdt.c',
    'components/esp_system/esp_err.c',
    'components/esp_system/esp_ipc.c',
    'components/esp_system/crosscore_int.c',
    'components/esp_system/port/soc/esp32c3/reset_reason.c',
    'components/esp_system/esp_system.c',
    'components/esp_system/freertos_hooks.c',
    # dropped (no v6.1 equivalent): components/esp_system/port/brownout.c
    'components/esp_system/stack_check.c',
    'components/esp_system/panic.c',
    'components/esp_system/system_time.c',
    'components/esp_system/task_wdt/task_wdt.c',
    # new in v6.1: the TWDT back end, picked by CONFIG_ESP_TASK_WDT_USE_ESP_TIMER
    'components/esp_system/task_wdt/task_wdt_impl_timergroup.c',
    # dropped (no v6.1 equivalent): components/esp_system/debug_stubs.c
    'components/esp_system/startup.c',
    'components/esp_system/ubsan.c',
    'components/esp_system/xt_wdt.c',
    'components/esp_system/port/soc/esp32c3/cache_err_int.c',
    'components/esp_system/port/cpu_start.c',
    'components/esp_system/port/soc/esp32c3/apb_backup_dma.c',
    'components/esp_system/port/panic_handler.c',
    # dropped (xtensa only): components/esp_system/port/arch/xtensa/expression_with_stack_asm.S
    'components/esp_system/port/soc/esp32c3/system_internal.c',
    'components/esp_system/port/soc/esp32c3/clk.c',
    'components/esp_system/port/arch/riscv/debug_stubs.c',
    'components/esp_system/port/arch/riscv/expression_with_stack.c',
    'components/esp_system/port/arch/riscv/panic_arch.c',
    'components/esp_system/eh_frame_parser.c',
    # new in v6.1
    'components/esp_system/port/esp_system_chip.c',
    'components/esp_system/port/arch/riscv/debug_helpers.c',
    'components/esp_hal_security/mpi_hal.c',
    'components/esp_libc/src/timekeeping.c',
    'components/mbedtls/port/crypto_shared_gdma/esp_crypto_shared_gdma.c',
]

esp32c3_esp_rom_src = [
    'components/esp_rom/patches/esp_rom_sys.c',
    'components/esp_rom/patches/esp_rom_crc.c',
    # dropped (no v6.1 equivalent): components/esp_rom/patches/esp_rom_uart.c
    'components/esp_rom/patches/esp_rom_spiflash.c',
    # dropped (no v6.1 equivalent): components/esp_rom/patches/esp_rom_regi2c.c
    # dropped (no v6.1 equivalent): components/esp_rom/patches/esp_rom_systimer.c
    'components/esp_rom/patches/esp_rom_efuse.c',
]

esp32c3_heap_src = [
    'components/heap/port/esp32c3/memory_layout.c',
    'components/heap/multi_heap.c',
    'components/heap/port/memory_layout_utils.c',
    'components/heap/heap_caps_init.c',
    'components/heap/heap_caps.c',
    # new in v6.1: heap_caps.c grew a thin layer over the multi-heap
    # implementation, which lives in heap_caps_base.c
    'components/heap/heap_caps_base.c',
    'components/heap/tlsf/tlsf.c',
]

esp32c3_spi_flash_src = [
    'components/spi_flash/flash_brownout_hook.c',
    'components/spi_flash/spi_flash_chip_drivers.c',
    'components/spi_flash/spi_flash_chip_issi.c',
    'components/esp_partition/partition_target.c',
    'components/esp_partition/partition.c',
    'components/spi_flash/spi_flash_chip_gd.c',
    'components/spi_flash/spi_flash_chip_mxic.c',
    'components/spi_flash/spi_flash_chip_boya.c',
    'components/spi_flash/spi_flash_chip_winbond.c',
    'components/spi_flash/spi_flash_chip_generic.c',
    'components/spi_flash/spi_flash_chip_th.c',
    'components/spi_flash/spi_flash_chip_mxic_opi.c',
    'components/spi_flash/memspi_host_driver.c',
    'components/spi_flash/cache_utils.c',
    'components/spi_flash/spi_flash_os_func_app.c',
    # dropped (no v6.1 equivalent): components/spi_flash/esp32c3/flash_ops_esp32c3.c
    'components/spi_flash/flash_ops.c',
    'components/spi_flash/flash_mmap.c',
    'components/spi_flash/spi_flash_os_func_noos.c',
    'components/spi_flash/esp_flash_spi_init.c',
    'components/spi_flash/esp_flash_api.c',
]

esp32c3_newlib_src = [
    'components/esp_libc/src/heap.c',
    'components/esp_libc/src/assert.c',
    # dropped (no v6.1 equivalent): components/newlib/pthread.c
    'components/esp_libc/src/abort.c',
    'components/esp_libc/src/poll.c',
    'components/esp_libc/src/newlib_init.c',
    # new in v6.1: provides _system_r/_raise_r so that libc.a members which
    # also define system()/raise() are not pulled in alongside syscalls.c
    'components/esp_libc/src/reent_syscalls.c',
    'components/esp_libc/src/termios.c',
    # dropped (no v6.1 equivalent): components/newlib/random.c
    'components/esp_libc/src/locks.c',
    'components/esp_libc/src/reent_init.c',
    'components/esp_libc/src/syscalls.c',
    'components/esp_libc/src/sysconf.c',
    'components/esp_libc/src/port/esp_time_impl.c',
    'components/esp_libc/src/realpath.c',
    'components/esp_libc/src/time.c',
    'components/esp_libc/src/stdatomic.c',
]

# FreeRTOS V11 event-list helpers that ESP-IDF v6.1's esp_ringbuf needs and the
# FreeRTOS-Wrapper kernel does not have; see the file header for details.
esp32c3_rtwrapper_compat_src = [
    'components/rtthread/scons/event_list.c',
]

esp32c3_log_src = [
    'components/log/src/log.c',
    'components/log/src/buffer/log_buffers.c',
    # dropped (no v6.1 equivalent): components/log/log_freertos.c
    # new in v6.1: log.c was split up - log_print.c holds the printf plumbing,
    # log_format_text.c the text formatter, log_level/ the per-tag bookkeeping
    # and src/os/ the parts that need a FreeRTOS-ish system (the scons BSPs run
    # on the FreeRTOS-Wrapper kernel, so the "os" flavour is the right one).
    'components/log/src/log_print.c',
    'components/log/src/log_format_text.c',
    'components/log/src/log_timestamp_common.c',
    'components/log/src/log_level/log_level.c',
    'components/log/src/log_level/tag_log_level/tag_log_level.c',
    # CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_AND_LINKED_LIST (the Kconfig default):
    # only the linked list back end is built, the array/binary-heap caches
    # need CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_SIZE
    'components/log/src/log_level/tag_log_level/linked_list/log_linked_list.c',
    'components/log/src/os/log_timestamp.c',
    'components/log/src/os/log_lock.c',
    'components/log/src/os/log_write.c',
    'components/log/src/os/util.c',
    'components/log/src/util.c',
]

esp32c3_driver_src = [
    'components/esp_driver_gpio/src/dedic_gpio.c',
    'components/esp_hw_support/spi_bus_lock.c',
    # new in v6.1: the shared per-group part of the GPTimer driver
    'components/esp_driver_gptimer/src/gptimer_common.c',
    'components/esp_driver_gpio/src/rtc_io.c',
    'components/esp_driver_sdspi/src/sdspi_crc.c',
    'components/esp_driver_gptimer/src/gptimer.c',
    'components/esp_driver_spi/src/gpspi/spi_master.c',
    'components/esp_driver_sdspi/src/sdspi_transaction.c',
    'components/esp_driver_gpio/src/gpio.c',
    'components/esp_driver_sdspi/src/sdspi_host.c',
    'components/esp_driver_ledc/src/ledc.c',
    'components/esp_driver_spi/src/gpspi/spi_slave.c',
    'components/esp_driver_uart/src/uart.c',
    'components/driver/i2c/i2c.c',
    'components/esp_driver_spi/src/gpspi/spi_common.c',
    'components/esp_driver_sdm/src/sdm.c',
    'components/esp_driver_rmt/src/rmt_common.c',
    'components/esp_driver_rmt/src/rmt_encoder.c',
    'components/esp_driver_rmt/src/rmt_rx.c',
    'components/esp_driver_rmt/src/rmt_tx.c',
    'components/esp_driver_i2s/i2s_std.c',
    'components/esp_driver_tsens/src/temperature_sensor.c',
    'components/esp_driver_i2s/i2s_common.c',
    'components/esp_driver_i2s/i2s_tdm.c',
    'components/esp_driver_usb_serial_jtag/src/usb_serial_jtag.c',
    'components/esp_driver_spi/src/gpspi/spi_slave_hd.c',
    'components/esp_driver_i2s/i2s_pdm.c',
    'components/driver/twai/twai.c',
]

esp32c3_freertos_additions_src = [
    # ESP-IDF's FreeRTOS API additions (the xQueue/xSemaphore/xEventGroup
    # "*WithCaps" family).  ESP-IDF's own implementation is built against the
    # static-allocation API of the FreeRTOS V11 kernel it ships, which the
    # FreeRTOS-Wrapper kernel does not have, so the scons build provides its own
    # on top of the wrapper's dynamic API instead:
    # dropped (no v6.1 equivalent): components/freertos/esp_additions/idf_additions.c
    # dropped (no v6.1 equivalent): components/freertos/esp_additions/idf_additions_event_groups.c
    'components/rtthread/scons/idf_additions_wrapper.c',
]

esp32c3_pthread_src = [
    'components/pthread/pthread_local_storage.c',
    'components/pthread/pthread_cond_var.c',
    'components/pthread/pthread_rwlock.c',
    'components/pthread/pthread.c',
]

esp32c3_riscv_src = [
    'components/riscv/vectors.S',
    'components/riscv/instruction_decode.c',
    'components/riscv/interrupt.c',
    # new in v6.1: the ESP32-C3 has neither CLIC nor PLIC, so components/riscv
    # falls back to the generic interrupt-controller layer
    'components/riscv/interrupt_intc.c',
    'components/riscv/vectors_intc.S',
    # new in v6.1: RT-Thread entry point for machine-mode interrupts
    'components/riscv/vectors_rtthread.S',
    'components/riscv/rv_utils.c',
]

esp32c3_efuse_src = [
    'components/efuse/esp32c3/esp_efuse_table.c',
    'components/efuse/esp32c3/esp_efuse_utility.c',
    'components/efuse/esp32c3/esp_efuse_fields.c',
    'components/efuse/src/esp_efuse_utility.c',
    'components/efuse/esp32c3/esp_efuse_rtc_calib.c',
    'components/efuse/src/esp_efuse_api.c',
    'components/efuse/src/esp_efuse_fields.c',
    'components/efuse/src/efuse_controller/keys/with_key_purposes/esp_efuse_api_key.c',
]

esp32c3_esp_timer_src = [
    'components/esp_timer/src/esp_timer_impl_systimer.c',
    'components/esp_timer/src/system_time.c',
    'components/esp_timer/src/esp_timer.c',
    'components/esp_timer/src/ets_timer_legacy.c',
    # new in v6.1: the systimer back end got a common part
    'components/esp_timer/src/esp_timer_impl_common.c',
]

esp32c3_wifi_src = [
    'components/esp_coex/src/coexist.c',
    'components/esp_wifi/src/mesh_event.c',
    'components/esp_wifi/src/smartconfig.c',
    'components/esp_wifi/src/smartconfig_ack.c',
    'components/esp_wifi/src/wifi_init.c',
    'components/esp_wifi/src/wifi_netif.c',
    'components/esp_wifi/src/wifi_default_ap.c',
    'components/esp_wifi/esp32c3/esp_adapter.c',
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libcoexist.a
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libcore.a
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libespnow.a
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libmesh.a
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libnet80211.a
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libpp.a
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libsmartconfig.a
    # dropped (no v6.1 equivalent): components/esp_wifi/lib/esp32c3/libwapi.a
]

esp32c3_wpa_supplicant_src = [
    'components/wpa_supplicant/port/os_xtensa.c',
    'components/wpa_supplicant/port/eloop.c',
    'components/wpa_supplicant/src/ap/ap_config.c',
    'components/wpa_supplicant/src/ap/ieee802_1x.c',
    'components/wpa_supplicant/src/ap/wpa_auth.c',
    'components/wpa_supplicant/src/ap/wpa_auth_ie.c',
    'components/wpa_supplicant/src/ap/sta_info.c',
    'components/wpa_supplicant/src/common/sae.c',
    'components/wpa_supplicant/src/common/wpa_common.c',
    'components/wpa_supplicant/src/utils/bitfield.c',
    'components/wpa_supplicant/src/crypto/aes-siv.c',
    'components/wpa_supplicant/src/crypto/sha256-kdf.c',
    'components/wpa_supplicant/src/crypto/ccmp.c',
    'components/wpa_supplicant/src/crypto/aes-gcm.c',
    'components/wpa_supplicant/src/crypto/crypto_ops.c',
    'components/wpa_supplicant/src/crypto/dh_group5.c',
    'components/wpa_supplicant/src/crypto/dh_groups.c',
    'components/wpa_supplicant/src/crypto/ms_funcs.c',
    'components/wpa_supplicant/src/crypto/sha1-tlsprf.c',
    'components/wpa_supplicant/src/crypto/sha256-tlsprf.c',
    'components/wpa_supplicant/src/crypto/sha384-tlsprf.c',
    'components/wpa_supplicant/src/crypto/sha256-prf.c',
    'components/wpa_supplicant/src/crypto/sha1-prf.c',
    'components/wpa_supplicant/src/crypto/sha384-prf.c',
    'components/wpa_supplicant/src/crypto/md4-internal.c',
    'components/wpa_supplicant/src/crypto/sha1-tprf.c',
    'components/wpa_supplicant/src/eap_common/eap_wsc_common.c',
    'components/wpa_supplicant/src/common/ieee802_11_common.c',
    'components/wpa_supplicant/src/eap_peer/chap.c',
    'components/wpa_supplicant/src/eap_peer/eap.c',
    'components/wpa_supplicant/src/eap_peer/eap_common.c',
    'components/wpa_supplicant/src/eap_peer/eap_mschapv2.c',
    'components/wpa_supplicant/src/eap_peer/eap_peap.c',
    'components/wpa_supplicant/src/eap_peer/eap_peap_common.c',
    'components/wpa_supplicant/src/eap_peer/eap_tls.c',
    'components/wpa_supplicant/src/eap_peer/eap_tls_common.c',
    'components/wpa_supplicant/src/eap_peer/eap_ttls.c',
    'components/wpa_supplicant/src/eap_peer/mschapv2.c',
    'components/wpa_supplicant/src/eap_peer/eap_fast.c',
    'components/wpa_supplicant/src/eap_peer/eap_fast_common.c',
    'components/wpa_supplicant/src/rsn_supp/pmksa_cache.c',
    'components/wpa_supplicant/src/rsn_supp/wpa.c',
    'components/wpa_supplicant/src/rsn_supp/wpa_ie.c',
    'components/wpa_supplicant/src/utils/base64.c',
    'components/wpa_supplicant/src/utils/common.c',
    'components/wpa_supplicant/src/utils/ext_password.c',
    'components/wpa_supplicant/src/utils/uuid.c',
    'components/wpa_supplicant/src/utils/wpabuf.c',
    'components/wpa_supplicant/src/utils/wpa_debug.c',
    'components/wpa_supplicant/src/utils/json.c',
    'components/wpa_supplicant/src/wps/wps.c',
    'components/wpa_supplicant/src/wps/wps_attr_build.c',
    'components/wpa_supplicant/src/wps/wps_attr_parse.c',
    'components/wpa_supplicant/src/wps/wps_attr_process.c',
    'components/wpa_supplicant/src/wps/wps_common.c',
    'components/wpa_supplicant/src/wps/wps_dev_attr.c',
    'components/wpa_supplicant/src/wps/wps_enrollee.c',
    # dropped (no v6.1 equivalent): components/wpa_supplicant/esp_supplicant/src/esp_wpa2.c
    'components/wpa_supplicant/esp_supplicant/src/esp_wpa_main.c',
    'components/wpa_supplicant/esp_supplicant/src/esp_wpas_glue.c',
    'components/wpa_supplicant/esp_supplicant/src/esp_common.c',
    'components/wpa_supplicant/esp_supplicant/src/esp_wps.c',
    'components/wpa_supplicant/esp_supplicant/src/esp_wpa3.c',
    'components/wpa_supplicant/esp_supplicant/src/esp_owe.c',
    'components/wpa_supplicant/esp_supplicant/src/esp_hostap.c',
    'components/wpa_supplicant/esp_supplicant/src/crypto/tls_mbedtls.c',
    'components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls.c',
    'components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls-bignum.c',
    'components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls-rsa.c',
    'components/wpa_supplicant/esp_supplicant/src/crypto/crypto_mbedtls-ec.c',
    'components/wpa_supplicant/src/crypto/rc4.c',
    'components/wpa_supplicant/src/crypto/des-internal.c',
    'components/wpa_supplicant/src/crypto/aes-omac1.c',
    'components/wpa_supplicant/src/crypto/aes-wrap.c',
    'components/wpa_supplicant/src/crypto/aes-unwrap.c',
    'components/wpa_supplicant/src/crypto/aes-ccm.c',
]

esp32c3_netif_src = [
    'components/esp_netif/esp_netif_handlers.c',
    'components/esp_netif/esp_netif_objects.c',
    'components/esp_netif/esp_netif_defaults.c',
    'components/esp_netif/lwip/esp_netif_lwip.c',
    'components/esp_netif/lwip/esp_netif_lwip_defaults.c',
    'components/esp_netif/lwip/netif/wlanif.c',
    'components/esp_netif/lwip/netif/ethernetif.c',
    'components/esp_netif/lwip/netif/esp_pbuf_ref.c',
    'components/esp_netif/loopback/esp_netif_loopback.c',
]

esp32c3_lwip_src = [
    'components/lwip/apps/sntp/sntp.c',
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/api_lib.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/api_msg.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/err.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/if_api.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/netbuf.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/netdb.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/netifapi.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/sockets.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/api/tcpip.c
    'components/lwip/apps/sntp/sntp.c',
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/apps/netbiosns/netbiosns.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/def.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/dns.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/inet_chksum.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/init.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ip.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/mem.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/memp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/netif.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/pbuf.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/raw.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/stats.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/sys.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/tcp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/tcp_in.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/tcp_out.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/timeouts.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/udp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/autoip.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/dhcp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/etharp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/icmp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/igmp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/ip4.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/ip4_napt.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/ip4_addr.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv4/ip4_frag.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/dhcp6.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/ethip6.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/icmp6.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/inet6.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/ip6_addr.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/ip6.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/ip6_frag.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/mld6.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/core/ipv6/nd6.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ethernet.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/bridgeif.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/bridgeif_fdb.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/slipif.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/auth.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/ccp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/chap-md5.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/chap-new.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/chap_ms.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/demand.c
    'components/wpa_supplicant/src/eap_peer/eap.c',
    'components/mbedtls/mbedtls/tf-psa-crypto/drivers/builtin/src/ecp.c',
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/eui64.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/fsm.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/ipcp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/ipv6cp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/lcp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/mppe.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/magic.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/multilink.c
    'components/esp_netif/lwip/netif/ppp.c',
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/pppapi.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/pppcrypt.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/pppoe.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/pppol2tp.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/pppos.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/upap.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/utils.c
    # dropped (no v6.1 equivalent): components/lwip/lwip/src/netif/ppp/vj.c
    'components/lwip/port/hooks/tcp_isn_default.c',
    'components/lwip/port/hooks/lwip_default_hooks.c',
    'components/lwip/port/debug/lwip_debug.c',
    'components/lwip/port/freertos/sys_arch.c',
    'components/lwip/port/sockets_ext.c',
    # dropped (no v6.1 equivalent): components/lwip/port/esp32/vfs_lwip.c
    # dropped (no v6.1 equivalent): components/lwip/apps/ping/esp_ping.c
    # dropped (no v6.1 equivalent): components/lwip/apps/ping/ping.c
    'components/lwip/apps/ping/ping_sock.c',
    'components/lwip/apps/dhcpserver/dhcpserver.c',
]

esp32c3_vfs_src = [
    'components/vfs/vfs_eventfd.c',
    'components/vfs/vfs.c',
    # dropped (no v6.1 equivalent): components/vfs/vfs_uart.c
    'components/vfs/vfs_semihost.c',
    # dropped (no v6.1 equivalent): components/vfs/vfs_console.c
    # dropped (no v6.1 equivalent): components/vfs/vfs_usb_serial_jtag.c
]

esp32c3_nvs_flash_src = [
    'components/nvs_flash/src/nvs_api.cpp',
    'components/nvs_flash/src/nvs_cxx_api.cpp',
    'components/nvs_flash/src/nvs_item_hash_list.cpp',
    'components/nvs_flash/src/nvs_page.cpp',
    'components/nvs_flash/src/nvs_pagemanager.cpp',
    'components/nvs_flash/src/nvs_storage.cpp',
    'components/nvs_flash/src/nvs_handle_simple.cpp',
    'components/nvs_flash/src/nvs_handle_locked.cpp',
    'components/nvs_flash/src/nvs_partition.cpp',
    'components/nvs_flash/src/nvs_partition_lookup.cpp',
    'components/nvs_flash/src/nvs_partition_manager.cpp',
    'components/nvs_flash/src/nvs_types.cpp',
]

esp32c3_esp_event_src = [
    'components/esp_event/esp_event.c',
    'components/esp_event/default_event_loop.c',
    'components/esp_event/esp_event_private.c',
]

esp32c3_bt_src = [
    'components/bt/controller/esp32c3/bt.c',
    'components/bt/common/btc/core/btc_alarm.c',
    'components/bt/common/api/esp_blufi_api.c',
    'components/bt/common/btc/core/btc_task.c',
    'components/bt/common/btc/core/btc_manage.c',
    'components/bt/common/btc/profile/esp/blufi/blufi_prf.c',
    'components/bt/common/btc/profile/esp/blufi/blufi_protocol.c',
    'components/bt/common/osi/alarm.c',
    'components/bt/common/osi/allocator.c',
    'components/bt/common/osi/buffer.c',
    'components/bt/common/osi/config.c',
    'components/bt/common/osi/fixed_queue.c',
    'components/bt/common/osi/pkt_queue.c',
    'components/bt/common/osi/fixed_pkt_queue.c',
    'components/bt/common/osi/future.c',
    'components/bt/common/osi/hash_functions.c',
    'components/bt/common/osi/hash_map.c',
    'components/bt/common/osi/list.c',
    'components/bt/common/osi/mutex.c',
    'components/bt/common/osi/thread.c',
    'components/bt/common/osi/osi.c',
    'components/bt/common/osi/semaphore.c',
    'components/bt/porting/mem/bt_osi_mem.c',
    'components/bt/esp_ble_iso/host/utils/addr.c',
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/gatt/src/ble_svc_gatt.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/tps/src/ble_svc_tps.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/ias/src/ble_svc_ias.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/ipss/src/ble_svc_ipss.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/ans/src/ble_svc_ans.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/gap/src/ble_svc_gap.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/bas/src/ble_svc_bas.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/dis/src/ble_svc_dis.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/services/lls/src/ble_svc_lls.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_conn.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_store_util.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_sm.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_shutdown.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_sig_cmd.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_cmd.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_att_svr.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_id.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_gatts_lcl.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_ibeacon.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_atomic.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_sm_alg.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_stop.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_evt.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_mqueue.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_periodic_sync.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_att.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_gattc.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_store.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_sm_lgcy.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_cfg.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_monitor.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_att_clt.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_coc.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_mbuf.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_att_cmd.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_log.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_eddystone.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_startup.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_sig.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_gap.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_sm_cmd.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_uuid.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_pvcy.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_flow.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_sm_sc.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_misc.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_gatts.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_adv.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_util.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/src/ble_hs_resolv.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/store/ram/src/ble_store_ram.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/store/config/src/ble_store_config.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/nimble/host/store/config/src/ble_store_nvs.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/porting/nimble/src/nimble_port.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/porting/npl/freertos/src/nimble_port_freertos.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/porting/nimble/src/endian.c
    'components/bt/porting/mem/os_mempool.c',
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/porting/nimble/src/mem.c
    # dropped (no v6.1 equivalent): components/bt/host/nimble/nimble/porting/nimble/src/os_mbuf.c
    'components/bt/porting/mem/os_msys_init.c',
    'components/bt/porting/npl/freertos/src/npl_os_freertos.c',
    'components/bt/host/nimble/esp-hci/src/esp_nimble_hci.c',
    'components/bt/common/btc/profile/esp/blufi/nimble_host/esp_blufi.c',
    # dropped (no v6.1 equivalent): components/bt/controller/lib_esp32c3_family/esp32c3/libbtdm_app.a
]

esp32c3_esp_phy_src = [
    'components/esp_phy/src/lib_printf.c',
    'components/esp_phy/src/phy_override.c',
    'components/esp_phy/src/phy_init.c',
    # dropped (no v6.1 equivalent): components/esp_phy/lib/esp32c3/libphy.a
    # dropped (no v6.1 equivalent): components/esp_phy/lib/esp32c3/libbtbb.a
]

# ESP-IDF v6.1 only builds the gdb stub when CONFIG_ESP_SYSTEM_GDBSTUB /
# CONFIG_ESP_GDBSTUB_SUPPORT_TASKS are on; gdbstub.c calls command_name_matches()
# from outside that guard, so the whole component is only added for BSPs that
# enable the stub (BSP_ENABLE_GDBSTUB).
esp32c3_esp_gdbsub_src = [
    'components/esp_gdbstub/src/port/riscv/gdbstub_riscv.c',
    'components/esp_gdbstub/src/gdbstub.c',
    'components/esp_gdbstub/src/packet.c',
]

# ---------------------------------------------------------------------------
# ESP-IDF v6.1 include paths.
#
# v6.1 split the former `hal`/`driver` components into dozens of per-peripheral
# `esp_hal_*` / `esp_driver_*` / `esp_hal_*_ll` components and moved the SoC
# headers below `components/<comp>/<target>/include`.  Hard-coding every path
# would break again on the next IDF release, so mirror what
# tools/cmake/component.cmake does for `idf_component_register()`: scan the
# component tree for the conventional include roots and for the literal
# INCLUDE_DIRS / PRIV_INCLUDE_DIRS entries of each CMakeLists.txt, then keep the
# few paths that CMake expresses through variables only.
# ---------------------------------------------------------------------------
IDF_CHIP = 'esp32c3'

_CMAKE_KW = re.compile(r'(?:^|[\s(])(INCLUDE_DIRS|PRIV_INCLUDE_DIRS)(.*?)\)', re.S)
_CMAKE_STR = re.compile(r'"([^"]*)"|([^\s"()]+)')
_OTHER_ARCH_RE = re.compile(r'(^|/)(xtensa)(/|$)')


def _cmake_split(chunk):
    return [quoted if quoted else bare
            for quoted, bare in _CMAKE_STR.findall(chunk)]


def _cmake_vars(text):
    """Best-effort value of the simple CMake variables used for include dirs."""
    values = {}
    for match in re.finditer(r'set\(\s*([A-Za-z_][A-Za-z0-9_]*)\s+([^)]*)\)', text):
        values.setdefault(match.group(1), []).extend(_cmake_split(match.group(2)))
    for match in re.finditer(r'list\(\s*APPEND\s+([A-Za-z_][A-Za-z0-9_]*)\s+([^)]*)\)', text):
        values.setdefault(match.group(1), []).extend(_cmake_split(match.group(2)))
    return values


def _cmake_include_dirs(comp_dir):
    """Literal INCLUDE_DIRS / PRIV_INCLUDE_DIRS entries of a component."""
    cmakelists = os.path.join(comp_dir, 'CMakeLists.txt')
    if not os.path.isfile(cmakelists):
        return []
    try:
        handle = open(cmakelists, encoding='utf-8', errors='ignore')
    except OSError:
        return []
    with handle:
        text = handle.read()
    variables = _cmake_vars(text)
    found = []
    for keyword, chunk in _CMAKE_KW.findall(text):
        for quoted, bare in _CMAKE_STR.findall(chunk):
            entry = quoted if quoted else bare
            if not entry:
                continue
            reference = re.match(r'^\$\{([A-Za-z_][A-Za-z0-9_]*)\}$', entry)
            if reference:
                # a plain variable reference stands for every value assigned
                # to that variable
                entries = variables.get(reference.group(1), [''])
            else:
                entries = [entry]
            for entry in entries:
                if not entry:
                    continue
                entry = entry.replace('${CMAKE_CURRENT_LIST_DIR}', comp_dir)
                entry = entry.replace('${CMAKE_CURRENT_SOURCE_DIR}', comp_dir)
                entry = entry.replace('${CMAKE_CURRENT_BINARY_DIR}', comp_dir)
                # the per-target include roots are spelled `${target}/include`
                # (or `${target_folder}`, `${idf_target}`, `${IDF_TARGET}`)
                entry = re.sub(r'\$\{(?:target_folder|target|idf_target|IDF_TARGET)\}',
                               IDF_CHIP, entry)
                if '$' in entry or entry.endswith('.a'):
                    continue
                # esp_gdbstub and a few other components list the include dir
                # of every architecture it supports; skip the Xtensa ones
                if _OTHER_ARCH_RE.search(entry):
                    continue
                full = entry if os.path.isabs(entry) else os.path.join(comp_dir, entry)
                if os.path.isdir(full):
                    found.append(os.path.relpath(full, cwd))
    return found


_CMAKE_REQ = re.compile(r'(?:^|[\s(])REQUIRES(.*?)\)', re.S)


def _cmake_requires(comp_dir):
    """Component names listed in REQUIRES / PRIV_REQUIRES of a component."""
    cmakelists = os.path.join(comp_dir, 'CMakeLists.txt')
    if not os.path.isfile(cmakelists):
        return []
    try:
        handle = open(cmakelists, encoding='utf-8', errors='ignore')
    except OSError:
        return []
    with handle:
        text = handle.read()
    variables = _cmake_vars(text)
    found = []
    for chunk in _CMAKE_REQ.findall(text):
        if chunk.startswith('_COMMON'):
            continue
        for quoted, bare in _CMAKE_STR.findall(chunk):
            entry = quoted if quoted else bare
            if not entry:
                continue
            reference = re.match(r'^\$\{([A-Za-z_][A-Za-z0-9_]*)\}$', entry)
            entries = variables.get(reference.group(1), []) if reference else [entry]
            for entry in entries:
                # generator expressions and unresolved variables are skipped
                if not entry or '$' in entry or entry.startswith('\\'):
                    continue
                if os.path.isdir(os.path.join(cwd, 'components', entry)):
                    found.append(entry)
    return found


def _source_components(sources):
    """The components the file lists above take their sources from."""
    found = []
    for item in sources:
        match = re.match(r'components/([^/]+)/', item)
        if match and match.group(1) not in found:
            found.append(match.group(1))
    return found


def _required_components(components):
    """Close `components` over REQUIRES / PRIV_REQUIRES."""
    ordered = []
    pending = list(components)
    while pending:
        comp = pending.pop(0)
        if comp in ordered:
            continue
        ordered.append(comp)
        pending += _cmake_requires(os.path.join(cwd, 'components', comp))
    return ordered


def _component_include_dirs(comp_rel):
    """Conventional include roots of one component, for the current chip."""
    comp_dir = os.path.join(cwd, comp_rel)
    sub_dirs = [
        '',
        os.path.join('port', ''),
        IDF_CHIP,
        os.path.join('port', IDF_CHIP),
    ]
    names = ['include', 'private_include', 'priv_include', 'register', 'src']
    res = []
    for sub in sub_dirs:
        for name in names:
            rel = os.path.join(comp_rel, sub, name) if sub else os.path.join(comp_rel, name)
            if os.path.isdir(os.path.join(cwd, rel)):
                res.append(rel)
    return res


def _all_component_include_dirs(components):
    res = []
    comps = os.path.join(cwd, 'components')
    if not os.path.isdir(comps):
        return res
    for comp in components:
        if not os.path.isdir(os.path.join(comps, comp)):
            continue
        # the `linux` component provides the host libc (newlib/bsd) headers used
        # by idf.py's native unit tests; it would shadow the toolchain headers
        if comp == 'linux':
            continue
        comp_dir = os.path.join(comps, comp)
        if not os.path.isdir(comp_dir):
            continue
        # The CMake order matters: some components chain their generic and
        # per-target headers through #include_next in opposite directions
        # (hal puts the per-target root first, efuse puts the generic one
        # first), so follow what the component itself declares.
        res += _cmake_include_dirs(comp_dir)
        res += _component_include_dirs(os.path.join('components', comp))
        # nested components: chip directories plus the sub-directories that
        # the component's CMakeLists.txt refers to (bootloader_flash,
        # esp_supplicant, csi, ...)
        named = set(d.split(os.sep, 2)[2] for d in _cmake_include_dirs(comp_dir)
                    if d.startswith(os.path.join('components', comp, '')))
        for sub in sorted(os.listdir(comp_dir)):
            if sub != IDF_CHIP and sub not in named:
                continue
            sub_dir = os.path.join(comp_dir, sub)
            if not os.path.isdir(sub_dir):
                continue
            sub_rel = os.path.join('components', comp, sub)
            res += [d for d in _cmake_include_dirs(sub_dir) if d.startswith(sub_rel)]
            res += _component_include_dirs(sub_rel)
    return [d for d in res if not _is_host_only(d)]


def _is_host_only(rel):
    """True for headers that only exist in the idf.py host ('linux') build.

    They shadow the toolchain headers (components/linux carries a whole newlib,
    components/vfs/linux_include a dummy `struct _reent`, ...) and must never
    end up on the include path of a cross build.
    """
    return any(part == 'linux' or part.startswith('linux_')
               for part in rel.split(os.sep))



esp32c3_adc_path = [
    'components/esp_adc/include',
    'components/esp_adc/include/esp_adc',
    'components/esp_adc/include/esp_private',
    'components/esp_adc/esp32c3/include',
    'components/esp_adc/interface',
    'components/esp_adc/deprecated/include',
]
esp32c3_adc_path = [p for p in esp32c3_adc_path if os.path.isdir(os.path.join(cwd, p))]

esp32c3_src += esp32c3_mbedtls_src

if GetDepend(['SOC_ESP32_C3']):
    src += esp32c3_src
    src += esp32c3_riscv_src
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
    src += esp32c3_rtwrapper_compat_src
    src += esp32c3_driver_src
    src += esp32c3_pthread_src
    src += esp32c3_freertos_additions_src
    src += esp32c3_efuse_src
    src += esp32c3_esp_timer_src
    if GetDepend(['BSP_ENABLE_GDBSTUB']):
        src += esp32c3_esp_gdbsub_src
    if GetDepend(['BSP_USING_ADC']):
        src += esp32c3_adc_src
    CPPDEFINES = [ 'IDF_VER=\\"999\\"', 'PROJECT_VER=\\"999\\"', '_GNU_SOURCE', 'MULTI_HEAP_FREERTOS', 'ESP_PLATFORM=1', 'IDF_TARGET=esp32c3', '_POSIX_READER_WRITER_LOCKS', 'PROJECT_NAME=\\"rtthread\\"', 'MBEDTLS_CONFIG_FILE=\\"mbedtls/esp_config.h\\"', 'TF_PSA_CRYPTO_USER_CONFIG_FILE=\\"mbedtls/esp_config.h\\"', 'ESPRESSIF_USE', 'CONFIG_CRYPTO_MBEDTLS', 'UNITY_INCLUDE_CONFIG_H', '__ets__', 'ESP_PLATFORM' ]

# The RT-Thread scons build shims have to be searched before everything else,
# including the FreeRTOS-Wrapper include dir: they forward
# <freertos/FreeRTOS.h> to the wrapper kernel with #include_next and then append
# ESP-IDF's FreeRTOS API additions, which upstream FreeRTOS V11 includes at the
# end of its own FreeRTOS.h.
Env.Prepend(CPPPATH = [os.path.join(cwd, 'components/rtthread/scons/include')])

esp32c3_path = []
# Only the components the source lists above come from, plus what they pull in
# through REQUIRES / PRIV_REQUIRES.  A flat build puts every -I on every
# command line, so pulling in unrelated components would expose headers whose
# Kconfig options the RT-Thread sdkconfig.h does not define (esp_common's
# generated esp_err_to_name.c probes the include path with __has_include and
# would otherwise drag in the whole lwip / wifi / bt stack).
esp32c3_path += _all_component_include_dirs(
    _required_components(_source_components(src)))
esp32c3_path += [
    # the FreeRTOS headers that the wrapper does not ship come from the
    # ESP-IDF kernel copy, searched after the wrapper's own include dir
    'components/freertos/FreeRTOS-Kernel/include',
    # ESP-IDF's FreeRTOS API additions (freertos/idf_additions.h); the scons
    # build only needs the declarations, the implementation is not built
    'components/freertos/esp_additions/include',
    # esp_libc owns the newlib/picolibc compatibility headers; it has to be
    # searched before the toolchain headers it wraps with #include_next.
    'components/esp_libc/platform_include',
    'components/heap/tlsf',
    # the per-chip SoC memprot headers live below esp_hw_support/include/soc/<target>
    'components/esp_hw_support/include/soc/esp32c3',
    'components/esp_system/port/include/private',
    'components/esp_system/port/include/riscv',
    'components/esp_system/port/arch/riscv/include',
    'components/esp_system/port/arch/riscv',
    'components/mbedtls/mbedtls/include',
    'components/mbedtls/mbedtls/library',
    'components/mbedtls/port/include',
    'components/mbedtls/port/psa_driver/include',
    'components/mbedtls/port/psa_crypto_storage/include',
    'components/mbedtls/esp_crt_bundle/include',
    'components/esp_gdbstub/src/port/riscv',
    # tf-psa-crypto (the crypto backend mbedtls 4.x is built on) keeps its
    # internal headers in a handful of directories next to the public
    # tf-psa-crypto/include; keep this list in sync with
    # TF_PSA_CRYPTO_PRIVATE_INCLUDE_DIRS in components/mbedtls/mbedtls/CMakeLists.txt
    'components/mbedtls/mbedtls/tf-psa-crypto/include',
    'components/mbedtls/mbedtls/tf-psa-crypto/core',
    'components/mbedtls/mbedtls/tf-psa-crypto/dispatch',
    'components/mbedtls/mbedtls/tf-psa-crypto/drivers/builtin/include',
    'components/mbedtls/mbedtls/tf-psa-crypto/drivers/builtin/src',
    'components/mbedtls/mbedtls/tf-psa-crypto/extras',
    'components/mbedtls/mbedtls/tf-psa-crypto/platform',
    'components/mbedtls/mbedtls/tf-psa-crypto/utilities',
    # the ESP port of mbedTLS is split into per-feature subdirectories that each
    # ship their own include/ (port/aes/dma/include/esp_aes_dma_priv.h etc.);
    # ESP-IDF's CMake adds them per subdirectory, add them here as well.
    # port/include/mbedtls is deliberately left out: it shadows headers of the
    # upstream library and ESP-IDF does not put it on the include path either.
    'components/mbedtls/port/aes/include',
    'components/mbedtls/port/aes/dma/include',
    'components/mbedtls/port/include/aes',
    'components/mbedtls/port/include/psa',
    'components/mbedtls/port/include/sha',
    'components/mbedtls/port/sha/core/include',
    'components/mbedtls/port/psa_driver/esp_rsa_ds/include',
    'components/mbedtls/port/psa_driver/esp_sha/include',
]
esp32c3_path = [p for p in esp32c3_path if os.path.isdir(os.path.join(cwd, p))
               and not _is_host_only(p)]
esp32c3_path = list(dict.fromkeys(esp32c3_path))
if GetDepend(['SOC_ESP32_C3']):
    if GetDepend(['BSP_USING_ADC']):
        esp32c3_path += esp32c3_adc_path
    path += esp32c3_path

LIB_PATH = []
LIB = []

# ESP-IDF's CMake build collects the per-component linker fragments into the
# final link line; the scons BSPs carry their own sections.ld, so the pieces
# that a v6.1 component newly relies on are added here.  LINKFLAGS has to stay
# a whitespace separated string (rtconfig.LFLAGS is one, and SCons only splits
# a string value), hence building the new value by hand instead of going
# through DefineGroup(LINKFLAGS=...).
LINKFLAGS = ' '.join([
    str(Env.get('LINKFLAGS', '')),
    # components/esp_hal_regi2c: the ROM regi2c implementation of this SoC
    '-Wl,-T,' + os.path.join(cwd, 'components/esp_hal_regi2c/esp32c3/rom.regi2c.ld'),
    # components/esp_libc: esp_rom_newlib_init_common_mutexes() lives in ROM
    '-Wl,-T,' + os.path.join(cwd, 'components/esp_rom/esp32c3/ld/esp32c3.rom.libc.ld'),
    # components/riscv: esprv_int_* aliases of the ROM interrupt API
    '-Wl,-T,' + os.path.join(cwd, 'components/riscv/ld/rom.api.ld'),
])
Env['LINKFLAGS'] = LINKFLAGS

group = DefineGroup('esp-idf', src, depend = ['PKG_USING_ESP_IDF'], CPPPATH = path, LIBS = LIB, LIBPATH = LIB_PATH, CPPDEFINES = CPPDEFINES)

Return('group')
