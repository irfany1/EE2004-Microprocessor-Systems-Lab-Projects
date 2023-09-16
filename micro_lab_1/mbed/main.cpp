#include "mbed.h"

DigitalOut green_led(PA_5);
DigitalIn blue_button(PC_13);

int main()
{
    int counter = 0;

    while (true) {
        if (blue_button == 0) {
            counter = counter +1;
            thread_sleep_for(200);
        }
        if (counter==3) {
            green_led.write(1);
            thread_sleep_for(100);
            green_led.write(0);
            thread_sleep_for(100);
            green_led.write(1);
            thread_sleep_for(100);
            green_led.write(0);
            thread_sleep_for(100);
            counter = 4;
        }
        if (counter==8) {
            green_led.write(1);
            thread_sleep_for(300);
            green_led.write(0);
            thread_sleep_for(300);
            green_led.write(1);
            thread_sleep_for(300);
            green_led.write(0);
            thread_sleep_for(300);
            green_led.write(1);
            thread_sleep_for(300);
            green_led.write(0);
            thread_sleep_for(300);
            counter = 0;
        }
    }
}
