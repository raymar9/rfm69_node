#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include <avrhal/io.h>
#include <avrhal/timer.h>

void toggle_led() {
    Io_Toggle(PB1);
}

int main (void) {

    Io_SetOutput(PB1);

    Timer_Initialize(&timers[0], 5, &toggle_led);
    Timer_Clear(&timers[0], false);
    Timer_Start(&timers[0]);
    sei();

    while(1) {
    }

    return 0;
}
