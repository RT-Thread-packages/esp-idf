# RT-Thread component

Run RT-Thread instead of FreeRTOS on ESP32-C3 and ESP32-C6 with ESP-IDF v6.1.
The kernel comes from an unmodified upstream RT-Thread checkout; the CPU port,
`rtconfig.h` and board init live in this component.

## Supported chips

| Chip | Status |
| --- | --- |
| ESP32-C3 | Tested on a board: boots into the demo threads, passes a 3 minute flash erase/write stress test |
| ESP32-C6 | Builds and links, not tested on a board yet |

Single core only. Wi-Fi, Bluetooth and light sleep are not supported yet.

## Enable

`idf.py menuconfig` → `Component config` → `FreeRTOS` → `Extra` →
`Replace FreeRTOS with RT-Thread`, or in `sdkconfig.defaults`:

```
CONFIG_IDF_RTOS_RTTHREAD=y
CONFIG_FREERTOS_HZ=1000
```

`CONFIG_FREERTOS_HZ` must match `RT_TICK_PER_SECOND` (1000).

## Build

```sh
git clone https://github.com/RT-Thread/rt-thread.git
export RTTHREAD_ROOT=$PWD/rt-thread
cd your_project
idf.py set-target esp32c3   # or esp32c6
idf.py build flash monitor
```

`RTTHREAD_ROOT` can also be passed as `-DRTTHREAD_ROOT=<path>`. The application
provides `rt_hw_console_output()` if it wants `rt_kprintf()` output.

## Notes

- Do not call the RT-Thread scheduler while the flash cache is disabled; the
  FreeRTOS port adapters abort with a clear message if that happens.
- With `CONFIG_IDF_RTOS_RTTHREAD=n` this component is empty and the build is
  the same as stock ESP-IDF.
