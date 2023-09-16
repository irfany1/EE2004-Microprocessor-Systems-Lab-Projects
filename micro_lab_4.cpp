#include "mbed.h"
#include <cstdio>

AnalogIn anin(PC_5);
DigitalOut led1(LED1);
DigitalOut led2(PA_6);

float voltage;

int main(void)
{
    while(true){

        voltage = anin.read()*3.3f;
        printf("voltage = %f \n", voltage);

        if (voltage<1.6f){
            led1 = 1;
            led2 = 0;
        } 
        else if(voltage>1.6f){
            led1 = 0;
            led2 = 1;
        }  
    }
}