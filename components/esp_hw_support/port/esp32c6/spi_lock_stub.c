#include <stdbool.h>
#include "driver/spi_common.h"
#include "esp_private/spi_common_internal.h"

bool spicommon_bus_using_iomux(spi_host_device_t host)
{
    (void) host;
    return true;
}

spi_bus_lock_handle_t spi_bus_lock_get_by_id(spi_host_device_t host_id)
{
    (void) host_id;
    return 0;
}
