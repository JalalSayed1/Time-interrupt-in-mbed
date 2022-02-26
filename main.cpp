#include "mbed.h"

Ticker TimerInt;
volatile int i;
DigitalOut gpo(PTD6);

void flip()
{
    i = !i;
    gpo = 1;
}

int main()
{
    TimerInt.attach(&flip, 0.001); // setup ticker to call flip at 1000Hz
    i = 0;

    // spin in a main loop.
    while (true)
    {
        // lots of real stuff happening here
        gpo = 0;
    }
}
