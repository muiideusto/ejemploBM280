/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "BME280.h"

#define WAIT_TIME_MS 500 
DigitalOut led1(LED1);
BME280 sensor(PB_9,PB_8);

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    while (true)
    {
        led1 = !led1;
        printf("%2.2f degC, %04.2f hPa, %2.2f %%\n", sensor.getTemperature(), sensor.getPressure(), sensor.getHumidity());
        thread_sleep_for(WAIT_TIME_MS);
    }
}
