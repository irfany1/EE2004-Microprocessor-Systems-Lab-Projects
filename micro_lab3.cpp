#include <cstdio>
#include <mbed.h>


#define BUTTON1_THRESHOLD 3
#define TICKER_PERIOD 300ms
#define SEC 1000ms


InterruptIn button1(BUTTON1);
DigitalOut led1(LED1);
DigitalOut led2(D12);


Ticker ticker;
Timeout timeout;


volatile int counterButton = 0;
volatile int counterTicker = 0;


void tick();
void button1Pressed();
void handleTimeout();


int main() {
    button1.mode(PullUp); 
    button1.fall(&button1Pressed); 

    led1 = 0;
    led2 = 0;


    timeout.attach(&handleTimeout, SEC);
    ticker.attach(&tick, TICKER_PERIOD);

    while(1){
        if(counterButton > 3){
        led2 = 1;
        timeout.attach(&handleTimeout, SEC);
        }
        thread_sleep_for(50);
    }
}


void tick(){

    if(counterTicker == 5){
        counterTicker = 0;
        counterButton = 0;
        led1 = !led1;
        printf("\n");
    }
    counterTicker++;
    printf("Ticker Counter: %d\n",counterTicker);
}

void button1Pressed() {
    counterButton++;
    printf("Button Counter: %d\n", counterButton);
}

void handleTimeout() {
    led2 = 0;
    counterButton = 0;
}
