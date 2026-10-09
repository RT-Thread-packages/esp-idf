/*
 * SPDX-FileCopyrightText: 2015-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdbool.h>
#include "esp_debug_helpers.h"
#include "esp_log.h"
#include "sdkconfig.h"

#if CONFIG_IDF_RTOS_RTTHREAD
// RT-Thread builds have no FreeRTOS, so neither freertos/*.h nor the FreeRTOS
// SemaphoreHandle_t parameter type can be used here; only size_t is needed.
#include <stddef.h>
#else
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*shared_stack_function)(void);

#define ESP_EXECUTE_EXPRESSION_WITH_STACK(lock, stack, stack_size, expression) \
    esp_execute_shared_stack_function(lock, stack, stack_size, expression)

/**
 * @brief Calls function on user defined shared stack space
 *
 * After returning, the original stack is used again.
 *
 * @warning This function does minimal preparation of the provided piece of memory (\c stack).
 *          DO NOT do any of the following in \c function or any of its callees:
 *          * Use Thread-local storage
 *          * Use the Floating-point unit on ESP32-P4
 *          * Use the AI co-processor on ESP32-P4
 *          * Call vTaskDelete(NULL) (deleting the currently running task)
 *          Furthermore, backtraces will be wrong when called from \c function or any of its callees.
 *          The limitations are quite sever, so that we might deprecate this function in the future.
 *          If you have any use case which can only be implemented using this function, please open
 *          an issue on github.
 *
 * @param lock Mutex object to protect in case of shared stack
 * @param stack Pointer to user allocated stack
 * @param stack_size Size of current stack in bytes
 * @param function pointer to the shared stack function to be executed
 * @note  if either lock, stack or stack size is invalid, the expression will
 *          be called using the current stack.
 */
#if CONFIG_IDF_RTOS_RTTHREAD
// No FreeRTOS semaphore type under RT-Thread, so lock degrades to an unused void *.
// The name and parameter layout match the RT-Thread definitions under port/arch.
void esp_execute_shared_stack_function(void *lock,
                                       void *stack,
                                       size_t stack_size,
                                       shared_stack_function function);
#else
void esp_execute_shared_stack_function(SemaphoreHandle_t lock,
                                       void *stack,
                                       size_t stack_size,
                                       shared_stack_function function);
#endif

#ifdef __cplusplus
}
#endif
