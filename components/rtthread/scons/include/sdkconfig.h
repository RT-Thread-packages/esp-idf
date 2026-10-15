/*
 * SPDX-FileCopyrightText: 2026 RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/*
 * RT-Thread scons build shim for <sdkconfig.h>.
 *
 * The ESP BSPs ship a hand written bsp/ESP/libraries/drivers/sdkconfig.h that
 * was generated for ESP-IDF v5.1.  ESP-IDF v6.1 added Kconfig symbols and
 * reworked the component set, so the v5.1 header no longer describes the tree
 * that is actually compiled here.
 *
 * Rather than duplicating (and having to keep re-duplicating) the generated
 * header, chain to the BSP one and append the v6.1 defaults that the compiled
 * sources need.  This directory is searched first (see the Env.Prepend() in
 * the root SConscript), so #include_next finds the BSP header below.
 */
#ifndef RT_THREAD_SCONS_SDKCONFIG_H
#define RT_THREAD_SCONS_SDKCONFIG_H

/* the BSP's hand written ESP-IDF v5.1 header, searched after this directory */
#include_next <sdkconfig.h>

/* --------------------------------------------------------------------------
 * Symbols new in ESP-IDF v6.1.
 * -------------------------------------------------------------------------- */

/* new in v6.1 (components/freertos/Kconfig): the old CONFIG_FREERTOS_UNICORE
   is kept for compatibility, but the kernel and the porting layer now take the
   core count from this one.  Same default as the Kconfig. */
#ifndef CONFIG_FREERTOS_NUMBER_OF_CORES
#  ifdef CONFIG_FREERTOS_UNICORE
#    define CONFIG_FREERTOS_NUMBER_OF_CORES 1
#  else
#    define CONFIG_FREERTOS_NUMBER_OF_CORES 2
#  endif
#endif

/* new in v6.1 (components/esp_stdio/Kconfig): esp_rom's UART helpers need the
   ROM console port number, which used to be identical to the UART number. */
#ifndef CONFIG_ESP_CONSOLE_ROM_SERIAL_PORT_NUM
#  define CONFIG_ESP_CONSOLE_ROM_SERIAL_PORT_NUM CONFIG_ESP_CONSOLE_UART_NUM
#endif

/* new in v6.1 (components/esp_timer/Kconfig): the timer task and the timer ISR
   can be pinned to a core.  Only CPU0 is possible on the unicore targets the
   scons BSPs build, and CONFIG_FREERTOS_NO_AFFINITY is already defined by the
   BSP header for targets where pinning is not available. */
#ifndef CONFIG_ESP_TIMER_TASK_AFFINITY
#  if defined(CONFIG_FREERTOS_UNICORE) || defined(CONFIG_FREERTOS_NO_AFFINITY)
#    define CONFIG_ESP_TIMER_TASK_AFFINITY CONFIG_FREERTOS_NO_AFFINITY
#  else
#    define CONFIG_ESP_TIMER_TASK_AFFINITY 0
#  endif
#endif
#ifndef CONFIG_ESP_TIMER_ISR_AFFINITY
#  if defined(CONFIG_FREERTOS_UNICORE) || defined(CONFIG_FREERTOS_NO_AFFINITY)
#    define CONFIG_ESP_TIMER_ISR_AFFINITY CONFIG_FREERTOS_NO_AFFINITY
#  else
#    define CONFIG_ESP_TIMER_ISR_AFFINITY 0
#  endif
#endif

/* new in v6.1 (components/esp_system/Kconfig): components/esp_system moved the
   task watchdog behind an abstraction layer (esp_task_wdt_impl_*.c), so
   esp_private/esp_task_wdt.h only declares its API when this is set.  These are
   the Kconfig defaults for a target with a timer group (everything but C2). */
#ifndef CONFIG_ESP_TASK_WDT_EN
#  define CONFIG_ESP_TASK_WDT_EN 1
#endif
#ifndef CONFIG_ESP_TASK_WDT_USE_ESP_TIMER
#  define CONFIG_ESP_TASK_WDT_USE_ESP_TIMER 0
#endif
#ifndef CONFIG_ESP_TASK_WDT_INIT
#  define CONFIG_ESP_TASK_WDT_INIT 1
#endif
#ifndef CONFIG_ESP_TASK_WDT_PANIC
#  define CONFIG_ESP_TASK_WDT_PANIC 0
#endif
#ifndef CONFIG_ESP_TASK_WDT_TIMEOUT_S
#  define CONFIG_ESP_TASK_WDT_TIMEOUT_S 5
#endif
#ifndef CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU0
#  define CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU0 1
#endif

/* new in v6.1: mbedTLS 4.x (components/mbedtls/mbedtls) replaced the individual
   MBEDTLS_X509_CRT_PARSE_C / MBEDTLS_X509_CSR_PARSE_C feature macros behind a
   common MBEDTLS_X509_USE_C umbrella; the parse macros still exist but are now
   rejected by mbedtls_check_config.h unless the umbrella is enabled. */
#ifndef CONFIG_MBEDTLS_X509_USE_C
#  define CONFIG_MBEDTLS_X509_USE_C 1
#endif
#ifndef CONFIG_MBEDTLS_X509_CRT_PARSE_C
#  define CONFIG_MBEDTLS_X509_CRT_PARSE_C 1
#endif
/* The BSP header still enables MBEDTLS_KEY_EXCHANGE_ECDHE_RSA /
   MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA.  In mbedTLS 4.x those key exchanges are
   checked against the PSA configuration, which esp_config.h derives from the
   generic public-key wrapper options below, so the wrappers they need have to
   be enabled as well. */
#ifndef CONFIG_MBEDTLS_PK_C
#  define CONFIG_MBEDTLS_PK_C 1
#endif
#ifndef CONFIG_MBEDTLS_RSA_C
#  define CONFIG_MBEDTLS_RSA_C 1
#endif
#ifndef CONFIG_MBEDTLS_PKCS1_V15
#  define CONFIG_MBEDTLS_PKCS1_V15 1
#endif
/* ... and the parsers X.509 and the TLS handshake hash are built from. */
#ifndef CONFIG_MBEDTLS_ASN1_PARSE_C
#  define CONFIG_MBEDTLS_ASN1_PARSE_C 1
#endif
#ifndef CONFIG_MBEDTLS_PK_PARSE_C
#  define CONFIG_MBEDTLS_PK_PARSE_C 1
#endif
#ifndef CONFIG_MBEDTLS_SHA256_C
#  define CONFIG_MBEDTLS_SHA256_C 1
#endif
/* PEM (and with it every X.509 certificate path) is Base64. */
#ifndef CONFIG_MBEDTLS_BASE64_C
#  define CONFIG_MBEDTLS_BASE64_C 1
#endif
/* Hardware interrupt priority of the AES / bignum helpers.  Only reached when
   the BSP enables CONFIG_MBEDTLS_AES_USE_INTERRUPT /
   CONFIG_MBEDTLS_MPI_USE_INTERRUPT; the Kconfig default is level 0. */
#ifndef CONFIG_MBEDTLS_AES_INTERRUPT_LEVEL
#  define CONFIG_MBEDTLS_AES_INTERRUPT_LEVEL 0
#endif
#ifndef CONFIG_MBEDTLS_MPI_INTERRUPT_LEVEL
#  define CONFIG_MBEDTLS_MPI_INTERRUPT_LEVEL 0
#endif

/* new in v6.1 (components/spi_flash/Kconfig): the flash driver may either run
   its functions from IRAM or put the flash into suspend mode while they run;
   esp_flash_spi_init.c rejects having both disabled. */
#ifndef CONFIG_SPI_FLASH_PLACE_FUNCTIONS_IN_IRAM
#  define CONFIG_SPI_FLASH_PLACE_FUNCTIONS_IN_IRAM 1
#endif

/* new in v6.1 (components/log/Kconfig.level_settings): the choice that decides
   how per-tag log levels are looked up.  components/log/CMakeLists.txt picks
   the linked-list back end for this choice; the array/binary-heap caches are
   only built for LOG_TAG_LEVEL_IMPL_CACHE_ARRAY. */
#ifndef CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_AND_LINKED_LIST
#  define CONFIG_LOG_TAG_LEVEL_IMPL_CACHE_AND_LINKED_LIST 1
#endif

#endif /* RT_THREAD_SCONS_SDKCONFIG_H */
