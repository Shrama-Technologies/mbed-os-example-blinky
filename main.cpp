/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500


int main()
{
	int count = 0;

    // Initialise the digital pin LED1 as an output
    DigitalOut led1(LED1);
    DigitalOut led0(LED0);

    while (true) {
		count++;
		if (count < 20) {
			led1 = 1;
			led0 = !led0;
		} else if (count < 40) {
			led0 = 1;
			led1 = !led1;
		} else if (count < 60) {
			led0 = !led0;
			if (led0) {
				led1 = !led1;
			}
		} else if (count < 80){
			led0 = !led0;
			led1 = !led1;
		} else {
			count = 0;
		}

        ThisThread::sleep_for(BLINKING_RATE);
    }
}
