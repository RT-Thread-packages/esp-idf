/*
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include "esp_attr.h"
#include "hal/lp_timer_ll.h"

static DRAM_ATTR struct {
    lp_timer_dev_t *dev;
} lp_timer_context = { .dev = &LP_TIMER };

uint64_t IRAM_ATTR lp_timer_hal_get_cycle_count(void)
{
    lp_timer_ll_counter_snapshot(lp_timer_context.dev);

    uint32_t lo = lp_timer_ll_get_counter_value_low(lp_timer_context.dev, 0);
    uint32_t hi = lp_timer_ll_get_counter_value_high(lp_timer_context.dev, 0);

    lp_timer_counter_value_t result = {
        .lo = lo,
        .hi = hi
    };
    return result.val;
}
