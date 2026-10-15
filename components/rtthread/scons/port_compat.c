/*
 * SPDX-FileCopyrightText: 2026 RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/*
 * The ESP-IDF v6.1 bt controller takes vPortYield by pointer in its OSI
 * function table.  The RT-Thread scons build runs on the FreeRTOS-Wrapper
 * kernel, where the port's yield primitive is rt_thread_yield().
 */
#include <rtthread.h>

void vPortYield(void)
{
    rt_thread_yield();
}

/*
 * Weak stubs for WPS SoftAP registrar entry points: wps.c references them
 * from wps_process_msg / wps_get_msg, but SoftAP registrar sources
 * (wps_registrar.c) are only built when CONFIG_ESP_WIFI_WPS_SOFTAP_REGISTRAR
 * is enabled.
 */
__attribute__((weak)) void *wps_registrar_get_msg(void *wps, void *op_code)
{
    (void)wps;
    (void)op_code;
    return (void *)0;
}

__attribute__((weak)) int wps_registrar_process_msg(void *wps, int op_code, const void *msg)
{
    (void)wps;
    (void)op_code;
    (void)msg;
    return 0;
}
