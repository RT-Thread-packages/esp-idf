/*
 * SPDX-FileCopyrightText: 2015-2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "soc/soc.h"
#include "soc/uart_reg.h"
#include "esp_gdbstub_common.h"
#include "sdkconfig.h"

#define UART_NUM CONFIG_ESP_CONSOLE_UART_NUM

#define GDBSTUB_MEM_REGION_COUNT 8

#define UART_REG_FIELD_LEN 0x84

typedef struct {
    intptr_t lower;
    intptr_t upper;
} mem_bound_t;

static const mem_bound_t mem_region_table[GDBSTUB_MEM_REGION_COUNT] =
{
    {SOC_DROM_LOW, SOC_DROM_HIGH},
    {SOC_IROM_LOW, SOC_IROM_HIGH},
    {SOC_IRAM_LOW, SOC_IRAM_HIGH},
    {SOC_DRAM_LOW, SOC_DRAM_HIGH},
    {SOC_IROM_MASK_LOW, SOC_IROM_MASK_HIGH},
    {SOC_DROM_MASK_LOW, SOC_DROM_MASK_HIGH},
    {SOC_RTC_IRAM_LOW, SOC_RTC_IRAM_HIGH},
    /* Skip the UART registers used by this stub. */
    {DR_REG_UART_BASE + UART_REG_FIELD_LEN, SOC_PERIPHERAL_HIGH},
};

static inline bool check_inside_valid_region(intptr_t addr)
{
    size_t i;

    for (i = 0; i < GDBSTUB_MEM_REGION_COUNT; i++) {
        if (addr >= mem_region_table[i].lower && addr < mem_region_table[i].upper) {
            return true;
        }
    }
    return false;
}

void esp_gdbstub_target_init(void)
{
}

int esp_gdbstub_getchar(void)
{
    while (REG_GET_FIELD(UART_STATUS_REG(UART_NUM), UART_RXFIFO_CNT) == 0) {
        ;
    }
    return REG_READ(UART_FIFO_AHB_REG(UART_NUM));
}

void esp_gdbstub_putchar(int c)
{
    while (REG_GET_FIELD(UART_STATUS_REG(UART_NUM), UART_TXFIFO_CNT) >= 126) {
        ;
    }
    REG_WRITE(UART_FIFO_AHB_REG(UART_NUM), c);
}

void esp_gdbstub_flush(void)
{
}

int esp_gdbstub_readmem(intptr_t addr)
{
    uint32_t val_aligned;
    uint32_t shift;

    if (!check_inside_valid_region(addr)) {
        return -1;
    }
    val_aligned = *(uint32_t *)(addr & (~3));
    shift = (addr & 3) * 8;
    return (val_aligned >> shift) & 0xff;
}

int esp_gdbstub_writemem(unsigned int addr, unsigned char data)
{
    int *i;

    if (!check_inside_valid_region(addr)) {
        return -1;
    }

    i = (int *)(addr & (~3));
    if ((addr & 3) == 0) {
        *i = (*i & 0xffffff00) | (data << 0);
    }
    if ((addr & 3) == 1) {
        *i = (*i & 0xffff00ff) | (data << 8);
    }
    if ((addr & 3) == 2) {
        *i = (*i & 0xff00ffff) | (data << 16);
    }
    if ((addr & 3) == 3) {
        *i = (*i & 0x00ffffff) | (data << 24);
    }
    return 0;
}
