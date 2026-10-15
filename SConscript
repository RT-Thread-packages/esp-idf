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
    'components/esp_hal_ana_conv/temperature_sensor_hal.c',
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
    'components/esp_hw_support/sar_tsens_ctrl.c',
    'components/esp_hw_support/spi_share_hw_ctrl.c',
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
    # vPortYield for the v6.1 bt controller's OSI function table; declared in
    # the scons <freertos/portmacro.h> shim
    'components/rtthread/scons/port_compat.c',
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
    'components/esp_wifi/src/lib_printf.c',
    'components/esp_wifi/src/smartconfig.c',
    # dropped (v6.1 only builds it with the ESP lwIP socket API available,
    # CONFIG_ESP_NETIF_USES_TCPIP_WITH_BSD_API, which the scons Wi-Fi build
    # does not provide): components/esp_wifi/src/smartconfig_ack.c
    'components/esp_wifi/src/wifi_init.c',
    'components/esp_wifi/src/wifi_netif.c',
    'components/esp_wifi/src/wifi_default_ap.c',
    'components/esp_wifi/esp32c3/esp_adapter.c',
    'components/esp_coex/esp32c3/esp_coex_adapter.c',
    'components/esp_wifi/regulatory/esp_wifi_regulatory.c',
    # the prebuilt wifi libraries (libcore.a, libnet80211.a, libpp.a, ...) are
    # linked through LIB / LIB_PATH below; v6.1 moved libcoexist.a from
    # components/esp_wifi/lib to components/esp_coex/lib
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
    'components/wpa_supplicant/src/common/dragonfly.c',
    'components/wpa_supplicant/src/ap/pmksa_cache_auth.c',
    'components/wpa_supplicant/src/ap/ieee802_11.c',
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
    'components/lwip/lwip/src/api/api_lib.c',
    'components/lwip/lwip/src/api/api_msg.c',
    'components/lwip/lwip/src/api/err.c',
    'components/lwip/lwip/src/api/if_api.c',
    'components/lwip/lwip/src/api/netbuf.c',
    'components/lwip/lwip/src/api/netdb.c',
    'components/lwip/lwip/src/api/netifapi.c',
    'components/lwip/lwip/src/api/sockets.c',
    'components/lwip/lwip/src/api/tcpip.c',
    'components/lwip/lwip/src/apps/sntp/sntp.c',
    'components/lwip/lwip/src/apps/netbiosns/netbiosns.c',
    'components/lwip/lwip/src/core/def.c',
    'components/lwip/lwip/src/core/dns.c',
    'components/lwip/lwip/src/core/inet_chksum.c',
    'components/lwip/lwip/src/core/init.c',
    'components/lwip/lwip/src/core/ip.c',
    'components/lwip/lwip/src/core/mem.c',
    'components/lwip/lwip/src/core/memp.c',
    'components/lwip/lwip/src/core/netif.c',
    'components/lwip/lwip/src/core/pbuf.c',
    'components/lwip/lwip/src/core/raw.c',
    'components/lwip/lwip/src/core/stats.c',
    'components/lwip/lwip/src/core/sys.c',
    'components/lwip/lwip/src/core/tcp.c',
    'components/lwip/lwip/src/core/tcp_in.c',
    'components/lwip/lwip/src/core/tcp_out.c',
    'components/lwip/lwip/src/core/timeouts.c',
    'components/lwip/lwip/src/core/udp.c',
    'components/lwip/lwip/src/core/ipv4/autoip.c',
    'components/lwip/lwip/src/core/ipv4/dhcp.c',
    'components/lwip/lwip/src/core/ipv4/etharp.c',
    'components/lwip/lwip/src/core/ipv4/icmp.c',
    'components/lwip/lwip/src/core/ipv4/igmp.c',
    'components/lwip/lwip/src/core/ipv4/ip4.c',
    'components/lwip/lwip/src/core/ipv4/ip4_napt.c',
    'components/lwip/lwip/src/core/ipv4/ip4_addr.c',
    'components/lwip/lwip/src/core/ipv4/ip4_frag.c',
    'components/lwip/lwip/src/core/ipv6/dhcp6.c',
    'components/lwip/lwip/src/core/ipv6/ethip6.c',
    'components/lwip/lwip/src/core/ipv6/icmp6.c',
    'components/lwip/lwip/src/core/ipv6/inet6.c',
    'components/lwip/lwip/src/core/ipv6/ip6_addr.c',
    'components/lwip/lwip/src/core/ipv6/ip6.c',
    'components/lwip/lwip/src/core/ipv6/ip6_frag.c',
    'components/lwip/lwip/src/core/ipv6/mld6.c',
    'components/lwip/lwip/src/core/ipv6/nd6.c',
    'components/lwip/lwip/src/netif/ethernet.c',
    'components/lwip/lwip/src/netif/bridgeif.c',
    'components/lwip/lwip/src/netif/bridgeif_fdb.c',
    'components/lwip/lwip/src/netif/slipif.c',
    'components/lwip/lwip/src/netif/ppp/auth.c',
    'components/lwip/lwip/src/netif/ppp/ccp.c',
    'components/lwip/lwip/src/netif/ppp/chap-md5.c',
    'components/lwip/lwip/src/netif/ppp/chap-new.c',
    'components/lwip/lwip/src/netif/ppp/chap_ms.c',
    'components/lwip/lwip/src/netif/ppp/demand.c',
    'components/lwip/lwip/src/netif/ppp/eap.c',
    'components/lwip/lwip/src/netif/ppp/ecp.c',
    'components/lwip/lwip/src/netif/ppp/eui64.c',
    'components/lwip/lwip/src/netif/ppp/fsm.c',
    'components/lwip/lwip/src/netif/ppp/ipcp.c',
    'components/lwip/lwip/src/netif/ppp/ipv6cp.c',
    'components/lwip/lwip/src/netif/ppp/lcp.c',
    'components/lwip/lwip/src/netif/ppp/mppe.c',
    'components/lwip/lwip/src/netif/ppp/magic.c',
    'components/lwip/lwip/src/netif/ppp/multilink.c',
    'components/lwip/lwip/src/netif/ppp/ppp.c',
    'components/lwip/lwip/src/netif/ppp/pppapi.c',
    'components/lwip/lwip/src/netif/ppp/pppcrypt.c',
    'components/lwip/lwip/src/netif/ppp/pppoe.c',
    'components/lwip/lwip/src/netif/ppp/pppol2tp.c',
    'components/lwip/lwip/src/netif/ppp/pppos.c',
    'components/lwip/lwip/src/netif/ppp/upap.c',
    'components/lwip/lwip/src/netif/ppp/utils.c',
    'components/lwip/lwip/src/netif/ppp/vj.c',
    'components/wpa_supplicant/src/eap_peer/eap.c',
    'components/mbedtls/mbedtls/tf-psa-crypto/drivers/builtin/src/ecp.c',
    # dropped (v6.1 only builds it with CONFIG_PPP_SUPPORT / CONFIG_LWIP_PPP_SUPPORT,
    # which the scons BSPs do not enable; lwipopts.h then leaves PPP_SUPPORT=0 and
    # the ppp_pcb type this shim uses does not exist): components/esp_netif/lwip/netif/ppp.c
    'components/lwip/port/hooks/tcp_isn_default.c',
    'components/lwip/port/hooks/lwip_default_hooks.c',
    'components/lwip/port/debug/lwip_debug.c',
    'components/lwip/port/freertos/sys_arch.c',
    'components/lwip/port/sockets_ext.c',
    'components/lwip/apps/ping/ping_sock.c',
    'components/lwip/apps/dhcpserver/dhcpserver.c',
    # dropped (v6.1 reworked the VFS/socket bridge): components/lwip/port/esp32/vfs_lwip.c
    # dropped (v6.1 equivalent): components/lwip/apps/ping/esp_ping.c
    # dropped (v6.1 equivalent): components/lwip/apps/ping/ping.c
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
    'components/nvs_flash/src/nvs_platform.cpp',
    'components/nvs_flash/src/nvs_encrypted_partition.cpp',
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
    # v6.1 moved the mem/npl porting layer out of the nimble submodule into
    # components/bt/porting; the ESP32-C3 keeps the submodule's nimble_port /
    # mem / os_mbuf as well because it is not a "nimble controller" SoC (see
    # components/bt/host/nimble/CMakeLists.txt)
    'components/bt/porting/mem/os_mempool.c',
    'components/bt/host/nimble/nimble/porting/nimble/src/os_msys_init.c',
    'components/bt/host/nimble/nimble/porting/npl/freertos/src/npl_os_freertos.c',
    # nimble host (components/bt/host/nimble/nimble submodule)
    'components/bt/host/nimble/nimble/nimble/transport/src/transport.c',
    'components/bt/host/nimble/nimble/nimble/transport/esp_ipc_legacy/src/hci_esp_ipc_legacy.c',
    'components/bt/host/nimble/port/src/nvs_port.c',
    'components/bt/host/nimble/port/src/esp_nimble_mem.c',
    'components/bt/host/nimble/nimble/nimble/host/util/src/addr.c',
    'components/bt/host/nimble/nimble/nimble/host/services/gatt/src/ble_svc_gatt.c',
    'components/bt/host/nimble/nimble/nimble/host/services/tps/src/ble_svc_tps.c',
    'components/bt/host/nimble/nimble/nimble/host/services/ias/src/ble_svc_ias.c',
    'components/bt/host/nimble/nimble/nimble/host/services/ipss/src/ble_svc_ipss.c',
    'components/bt/host/nimble/nimble/nimble/host/services/ans/src/ble_svc_ans.c',
    'components/bt/host/nimble/nimble/nimble/host/services/gap/src/ble_svc_gap.c',
    'components/bt/host/nimble/nimble/nimble/host/services/bas/src/ble_svc_bas.c',
    'components/bt/host/nimble/nimble/nimble/host/services/dis/src/ble_svc_dis.c',
    'components/bt/host/nimble/nimble/nimble/host/services/lls/src/ble_svc_lls.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_conn.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_store_util.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_sm.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_shutdown.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_sig_cmd.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_cmd.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_id.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_att_svr.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_gatts_lcl.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_ibeacon.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_atomic.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_sm_alg.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_stop.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_evt.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_mqueue.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_periodic_sync.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_att.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_gattc.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_store.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_sm_lgcy.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_cfg.c',
    # dropped (only built with BLE monitor support): components/bt/host/nimble/nimble/nimble/host/src/ble_monitor.c
    'components/bt/host/nimble/nimble/nimble/host/src/ble_att_clt.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_coc.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_mbuf.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_att_cmd.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_log.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_eddystone.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_startup.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap_sig.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_gap.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_sm_cmd.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_uuid.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_pvcy.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_flow.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_l2cap.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_sm_sc.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_misc.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_gatts.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_adv.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_hci_util.c',
    'components/bt/host/nimble/nimble/nimble/host/src/ble_hs_resolv.c',
    'components/bt/host/nimble/nimble/nimble/host/store/ram/src/ble_store_ram.c',
    'components/bt/host/nimble/nimble/nimble/host/store/config/src/ble_store_config.c',
    'components/bt/host/nimble/nimble/nimble/host/store/config/src/ble_store_nvs.c',
    'components/bt/host/nimble/nimble/porting/nimble/src/nimble_port.c',
    'components/bt/host/nimble/nimble/porting/nimble/src/endian.c',
    'components/bt/host/nimble/nimble/porting/nimble/src/mem.c',
    'components/bt/host/nimble/nimble/porting/nimble/src/os_mbuf.c',
    'components/bt/host/nimble/nimble/porting/npl/freertos/src/nimble_port_freertos.c',
    # dropped (v6.1 moved them to components/bt/porting, which is built instead):
    #   components/bt/host/nimble/nimble/porting/nimble/src/os_msys_init.c
    #   components/bt/host/nimble/nimble/porting/npl/freertos/src/npl_os_freertos.c
    'components/bt/host/nimble/esp-hci/src/esp_nimble_hci.c',
    'components/bt/common/btc/profile/esp/blufi/nimble_host/esp_blufi.c',
]


esp32c3_esp_phy_src = [
    'components/esp_phy/src/lib_printf.c',
    'components/esp_phy/src/phy_override.c',
    'components/esp_phy/src/phy_init.c',
    'components/esp_phy/src/phy_common.c',
    'components/esp_phy/src/btbb_init.c',
    'components/esp_phy/esp32c3/phy_init_data.c',
    # libphy.a / libbtbb.a are linked through LIB / LIB_PATH below
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
# The chip whose per-target include roots the scan below resolves ${target} /
# ${IDF_TARGET} to.  ESP32-C6 reuses the C3 source lists (see the SOC_ESP32_C6
# branch further down), so only the chip name changes.
IDF_CHIP = 'esp32c6' if GetDepend(['SOC_ESP32_C6']) else 'esp32c3'

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

# ---------------------------------------------------------------------------
# ESP32-C6: v6.1 keeps the C3 and C6 components in the same layout, so the C3
# source lists above are reused with every `esp32c3` path swapped for its
# `esp32c6` counterpart.  Entries whose C6 counterpart does not exist in the
# tree are dropped (the C6 SoC has no such port / peripheral file).  IDF_CHIP
# is already esp32c6, so the include-dir scan and the fixed path list below
# resolve the per-target directories for the C6.
#
# Wi-Fi / BLE are out of scope here: the C6 BSPs build the plain default
# configuration (the radio source lists below are still the C3 ones).
# ---------------------------------------------------------------------------
if GetDepend(['SOC_ESP32_C6']):
    _c6_extra_src = [
        # The ESP32-C6 has PMU / PAU / light-sleep hardware
        # (SOC_PMU_SUPPORTED, SOC_PAU_SUPPORTED) that the ESP32-C3 lacks, so
        # the C3 lists above have no entry for the corresponding port files.
        # They are added only for the C6 to keep the C3 build unchanged.
        'components/esp_hw_support/port/esp32c6/pmu_param.c',
        'components/esp_hw_support/port/esp32c6/pmu_init.c',
        'components/esp_hw_support/port/esp32c6/pmu_sleep.c',
        'components/esp_hw_support/port/esp32c6/ocode_init.c',
        'components/esp_hw_support/port/esp32c6/io_mux.c',
        'components/esp_hw_support/port/esp32c6/peripheral_domain_pd.c',
        'components/esp_hw_support/port/esp32c6/system_periph_retention.c',
        'components/esp_hw_support/pmu_share_hw.c',
        'components/esp_hw_support/sleep_retention.c',
        'components/esp_hw_support/sleep_system_peripheral.c',
        'components/esp_hw_support/sleep_mspi.c',
        'components/esp_hw_support/sleep_usb.c',
        'components/esp_hw_support/port/pau_regdma.c',
        'components/esp_hw_support/port/regdma_link.c',
        'components/esp_hw_support/lowpower/port/esp32c6/sleep_clock.c',
        'components/esp_hw_support/lowpower/port/esp32c6/sleep_modem_state.c',
        'components/esp_hw_support/modem/modem_clock.c',
        'components/esp_hw_support/modem/port/esp32c6/modem_clock_impl.c',
        'components/hal/esp32c6/modem_clock_hal.c',
        'components/esp_hal_pmu/esp32c6/pmu_hal.c',
        'components/esp_hal_pmu/esp32c6/pau_hal.c',
        'components/esp_hal_gpio/esp32c6/rtc_io_periph.c',
        'components/esp_hal_regi2c/esp32c6/regi2c_impl.c',
        'components/esp_hal_security/apm_hal.c',
    ]
    src += [p for p in _c6_extra_src if os.path.exists(os.path.join(cwd, p))]

    def _to_c6(items):
        out = []
        for item in items:
            if 'esp32c3' not in item:
                out.append(item)
                continue
            alt = item.replace('esp32c3', 'esp32c6')
            if os.path.exists(os.path.join(cwd, alt)):
                out.append(alt)
        return out

    src += _to_c6(esp32c3_src)
    src += _to_c6(esp32c3_riscv_src)
    src += _to_c6(esp32c3_esp_system_src)
    src += _to_c6(esp32c3_hal_src)
    src += _to_c6(esp32c3_soc_src)
    src += _to_c6(esp32c3_esp_hw_support_src)
    src += _to_c6(esp32c3_bootloader_support_src)
    src += _to_c6(esp32c3_esp_rom_src)
    src += _to_c6(esp32c3_heap_src)
    src += _to_c6(esp32c3_spi_flash_src)
    src += _to_c6(esp32c3_newlib_src)
    src += _to_c6(esp32c3_log_src)
    src += _to_c6(esp32c3_rtwrapper_compat_src)
    src += _to_c6(esp32c3_driver_src)
    src += _to_c6(esp32c3_pthread_src)
    src += _to_c6(esp32c3_freertos_additions_src)
    src += _to_c6(esp32c3_efuse_src)
    src += _to_c6(esp32c3_esp_timer_src)
    if GetDepend(['BSP_ENABLE_GDBSTUB']):
        src += _to_c6(esp32c3_esp_gdbsub_src)
    if GetDepend(['BSP_USING_ADC']):
        src += _to_c6(esp32c3_adc_src)
    # C3-only peripherals whose source file does not carry `esp32c3` in its
    # path, so _to_c6() keeps them although the C6 has no such block (the C6
    # has no XT WDT).
    #
    # The ESP mbedtls PSA driver sources are picked up by the mbedtls globs
    # above, but upstream's components/mbedtls/CMakeLists.txt only compiles
    # them when the matching Kconfig switch is on.  The C6 sdkconfig shim keeps
    # CONFIG_MBEDTLS_HARDWARE_AES / _HARDWARE_SHA unset (software crypto), so
    # these files must be dropped: their signatures use the
    # esp_aes_operation_t / esp_cmac_operation_t /
    # esp_hmac_transparent_operation_t types, which the port headers only
    # declare when ESP_AES_DRIVER_ENABLED / ESP_CMAC_DRIVER_ENABLED /
    # ESP_HMAC_TRANSPARENT_DRIVER_ENABLED are defined.
    _c6_drop = ('xt_wdt_hal.c', 'esp_memprot_conv.c',
                'psa_crypto_driver_esp_aes.c',
                'psa_crypto_driver_esp_cmac.c',
                'psa_crypto_driver_esp_hmac_transparent.c')
    src = [p for p in src if os.path.basename(p) not in _c6_drop]
    CPPDEFINES = [ 'IDF_VER=\\"999\\"', 'PROJECT_VER=\\"999\\"', '_GNU_SOURCE',
                   'MULTI_HEAP_FREERTOS', 'ESP_PLATFORM=1', 'IDF_TARGET=esp32c6',
                   'SOC_MMU_PAGE_SIZE=0x10000', '_POSIX_READER_WRITER_LOCKS',
                   'PROJECT_NAME=\\"rtthread\\"',
                   'MBEDTLS_CONFIG_FILE=\\"mbedtls/esp_config.h\\"',
                   'TF_PSA_CRYPTO_USER_CONFIG_FILE=\\"mbedtls/esp_config.h\\"',
                   'ESPRESSIF_USE', 'CONFIG_CRYPTO_MBEDTLS', 'UNITY_INCLUDE_CONFIG_H',
                   '__ets__', 'ESP_PLATFORM' ]

LIB_PATH = []
LIB = []
esp32c3_bt_path = []
esp32c3_wifi_path = []

# Wi-Fi and BLE share the radio stack: esp_wifi shim sources, the supplicant,
# nvs_flash, esp_event and esp_phy (plus the prebuilt esp_wifi / esp_phy / esp_coex
# libraries).  The ESP lwIP port (esp32c3_lwip_src / esp32c3_netif_src) is only
# built for BLE: a plain Wi-Fi configuration enables RT-Thread's own lwIP
# (RT_USING_LWIP) and compiling the ESP lwIP port as well would define every
# symbol of the stack twice.
if GetDepend(['BSP_USING_WIFI']) or GetDepend(['BSP_USING_BLE']):
    src += esp32c3_wifi_src
    src += esp32c3_wpa_supplicant_src
    src += esp32c3_nvs_flash_src
    src += esp32c3_esp_phy_src
    src += esp32c3_esp_event_src
    LIB_PATH += [os.path.join(cwd, 'components/esp_phy/lib/esp32c3'),
                 os.path.join(cwd, 'components/esp_wifi/lib/esp32c3'),
                 os.path.join(cwd, 'components/esp_coex/lib/esp32c3')]
    # v6.1 moved libcoexist.a from components/esp_wifi/lib to components/esp_coex/lib
    LIB += ['btbb', 'coexist', 'espnow', 'net80211', 'pp', 'smartconfig',
            'wapi', 'core', 'mesh', 'phy']
    # the wpa_supplicant port: the feature macros its v6.1 CMakeLists.txt sets
    # unconditionally (plus WPA3 / OWE, which the scons sdkconfig.h does not
    # derive from Kconfig)
    CPPDEFINES += ['ESP_SUPPLICANT', 'IEEE8021X_EAPOL', 'EAP_PEER_METHOD',
                   'EAP_MSCHAPv2', 'EAP_TTLS', 'EAP_TLS', 'EAP_PEAP',
                   'USE_WPA2_TASK', 'USE_WPS_TASK', 'CONFIG_WPS', 'CONFIG_ECC',
                   'CONFIG_IEEE80211W', 'CONFIG_SHA256', 'CONFIG_NO_RADIUS',
                   'CONFIG_OWE_STA', 'CONFIG_WPA3_SAE', 'ESP32_WORKAROUND']
    # header-only dependency of the esp_wifi public headers (esp_mesh.h's
    # esp_ip4_addr_t); no esp_netif source is compiled in the plain Wi-Fi
    # build, so the auto-collected include dirs would not have it
    esp32c3_wifi_path += ['components/esp_netif/include']

if GetDepend(['BSP_USING_BLE']):
    src += esp32c3_bt_src
    src += esp32c3_lwip_src
    src += esp32c3_netif_src
    src += esp32c3_vfs_src
    # v6.1's esp_sntp.h keeps a set of deprecated translating inlines
    # (sntp_init() -> esp_sntp_init(), ...) that are only meant for code
    # *outside* the lwIP/esp_netif components; inside them the real lwIP
    # declarations are used instead.  ESP-IDF's CMake sets these two defines
    # PRIVATE on the lwip/esp_netif component targets, the flat scons build
    # has to define them itself or the two sets of prototypes collide.
    CPPDEFINES += ['ESP_LWIP_COMPONENT_BUILD', 'ESP_NETIF_COMPONENT_BUILD']
    LIB_PATH.append(os.path.join(cwd, 'components/bt/controller/lib_esp32c3_family/esp32c3'))
    LIB.append('btdm_app')
    # the include roots of the nimble host live three levels below components/bt,
    # deeper than the one-level scan in _all_component_include_dirs() goes
    esp32c3_bt_path += [
        'components/bt/include/esp32c3/include',
        'components/bt/common/osi/include',
        'components/bt/common/hci_log/include',
        'components/bt/common/api/include/api',
        'components/bt/common/btc/include',
        'components/bt/common/btc/profile/esp/blufi/include',
        'components/bt/common/btc/profile/esp/include',
        'components/bt/common/include',
        'components/bt/porting/include',
        'components/bt/porting/mem',
        'components/bt/host/nimble/nimble/porting/npl/freertos/include',
        'components/bt/host/nimble/port/include',
        'components/bt/host/nimble/nimble/nimble/host/include',
        'components/bt/host/nimble/nimble/nimble/host/services/ans/include',
        'components/bt/host/nimble/nimble/nimble/host/services/bas/include',
        'components/bt/host/nimble/nimble/nimble/host/services/dis/include',
        'components/bt/host/nimble/nimble/nimble/host/services/gap/include',
        'components/bt/host/nimble/nimble/nimble/host/services/gatt/include',
        'components/bt/host/nimble/nimble/nimble/host/services/ias/include',
        'components/bt/host/nimble/nimble/nimble/host/services/ipss/include',
        'components/bt/host/nimble/nimble/nimble/host/services/lls/include',
        'components/bt/host/nimble/nimble/nimble/host/services/tps/include',
        'components/bt/host/nimble/nimble/nimble/host/util/include',
        'components/bt/host/nimble/nimble/nimble/host/store/ram/include',
        'components/bt/host/nimble/nimble/nimble/host/store/config/include',
        'components/bt/host/nimble/nimble/nimble/include',
        'components/bt/host/nimble/nimble/nimble/include/nimble',
        'components/bt/host/nimble/nimble/nimble/transport/include',
        'components/bt/host/nimble/nimble/porting/nimble/include',
        'components/bt/host/nimble/nimble/porting/nimble/include/mem',
        'components/bt/host/nimble/nimble/porting/npl/freertos/include',
        'components/bt/host/nimble/esp-hci/include',
        'components/lwip/port/include',
        'components/lwip/include',
        'components/lwip/include/apps',
        'components/lwip/lwip/src/include',
        'components/lwip/port/esp32xx/include',
        'components/lwip/port/esp32xx/include/arch',
        'components/esp_netif/include',
        'components/esp_netif/private_include',
        'components/vfs/include',
    ]

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
# A plain Wi-Fi build keeps using RT-Thread's own lwIP (RT_USING_LWIP); the
# auto-collected ESP lwIP include dirs would shadow its headers for every
# other component, so they are dropped unless the ESP lwIP port itself is
# part of the build (BLE).
if GetDepend(['BSP_USING_WIFI']) and not GetDepend(['BSP_USING_BLE']):
    esp32c3_path = [p for p in esp32c3_path
                    if not p.startswith('components/lwip/')]
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
    'components/esp_hw_support/include/soc/' + IDF_CHIP,
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
esp32c3_path += [p for p in esp32c3_bt_path
                 if os.path.isdir(os.path.join(cwd, p))
                 and p not in esp32c3_path]
esp32c3_path += [p for p in esp32c3_wifi_path
                 if os.path.isdir(os.path.join(cwd, p))
                 and p not in esp32c3_path]
if GetDepend(['SOC_ESP32_C3']) or GetDepend(['SOC_ESP32_C6']):
    if GetDepend(['BSP_USING_ADC']):
        if GetDepend(['SOC_ESP32_C6']):
            esp32c3_path += _to_c6(esp32c3_adc_path)
        else:
            esp32c3_path += esp32c3_adc_path
    path += esp32c3_path

# ESP-IDF's CMake build collects the per-component linker fragments into the
# final link line; the scons BSPs carry their own sections.ld, so the pieces
# that a v6.1 component newly relies on are added here.  LINKFLAGS has to stay
# a whitespace separated string (rtconfig.LFLAGS is one, and SCons only splits
# a string value), hence building the new value by hand instead of going
# through DefineGroup(LINKFLAGS=...).
_linker_scripts = []
# components/esp_hal_regi2c: the ROM regi2c implementation of this SoC.  The
# linker fragment only exists for the targets that keep the ROM implementation
# (the C6 uses the software regi2c_impl.c instead and ships no rom.regi2c.ld).
_regi2c_ld = os.path.join(cwd, 'components/esp_hal_regi2c', IDF_CHIP, 'rom.regi2c.ld')
if os.path.isfile(_regi2c_ld):
    _linker_scripts.append('-Wl,-T,' + _regi2c_ld)
# components/esp_libc: esp_rom_newlib_init_common_mutexes() lives in ROM
_rom_libc_ld = os.path.join(cwd, 'components/esp_rom', IDF_CHIP, 'ld',
                            IDF_CHIP + '.rom.libc.ld')
if os.path.isfile(_rom_libc_ld):
    _linker_scripts.append('-Wl,-T,' + _rom_libc_ld)
# components/riscv: esprv_int_* aliases of the ROM interrupt API
_linker_scripts.append('-Wl,-T,' + os.path.join(cwd, 'components/riscv/ld/rom.api.ld'))
LINKFLAGS = ' '.join([str(Env.get('LINKFLAGS', ''))] + _linker_scripts)
Env['LINKFLAGS'] = LINKFLAGS

if LIB:
    lib_link_flags = []
    for lp in LIB_PATH:
        lib_link_flags.append('-L' + lp)
    lib_link_flags.append('-Wl,--whole-archive')
    for l in LIB:
        lib_link_flags.append('-l' + l)
    lib_link_flags.append('-Wl,--no-whole-archive')
    LINKFLAGS = LINKFLAGS + ' ' + ' '.join(lib_link_flags)
    Env['LINKFLAGS'] = LINKFLAGS
    LIB = []
    LIB_PATH = []

group = DefineGroup('esp-idf', src, depend = ['PKG_USING_ESP_IDF'], CPPPATH = path, LIBS = LIB, LIBPATH = LIB_PATH, CPPDEFINES = CPPDEFINES)

Return('group')
