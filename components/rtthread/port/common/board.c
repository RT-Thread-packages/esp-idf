#include <rtthread.h>
#include "port_systick.h"
#include "riscv/interrupt.h"

void rt_hw_board_init(void)
{
    /* startup.c:do_core_init() already initialized the RT-Thread heap.
     * Reinitializing it here would erase and reinsert its memory object.
     */

    /* rtthread_startup() has disabled MIE. Reuse IDF's OS tick alarm; the
     * first thread's mret enables interrupts after timer/scheduler init.
     * vectors_rtthread.S saves, raises and restores the interrupt threshold in
     * software on both C3 and C6, which do not define
     * SOC_INT_HW_NESTED_SUPPORTED.
     */
    vPortSetupTimer();
    esprv_int_set_threshold(RVHAL_INTR_ENABLE_THRESH);
}
