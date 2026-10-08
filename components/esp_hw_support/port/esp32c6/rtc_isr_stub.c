#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"
#include "esp_sleep.h"

void rtc_isr_noniram_disable(uint32_t cpu)
{
    (void) cpu;
}

void rtc_isr_noniram_enable(uint32_t cpu)
{
    (void) cpu;
}

esp_err_t esp_sleep_pd_config(esp_sleep_pd_domain_t domain, esp_sleep_pd_option_t option)
{
    (void) domain;
    (void) option;
    return ESP_OK;
}

void pmu_sleep_enable_hp_sleep_sysclk(bool enable)
{
    (void) enable;
}
