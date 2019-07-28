#include "avrhal/timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIM0_OVF_vect) {
    timers[0].overflow_cb();
}

void Timer_Initialize(Timer* self, uint8_t clock_select, void* overflow_cb) {
    // Set compare match output modes
    TCCR0A = (0 << COM0A1) | (0 << COM0A0) | (0 << COM0B1) | (0 << COM0B0);
    // Set waveform generation mode
    TCCR0A |= (0 << WGM01) | (0 << WGM00);
    TCCR0B = (0 << WGM02);

    // Set clock select
    if (clock_select > 7) {
        clock_select = 0;
    }
    self->clock_select = clock_select;
    self->overflow_cb = overflow_cb;
}

void Timer_Start(Timer* self) {
    // Enable overflow interrupt
    if (self->overflow_cb) {
        TIMSK |= 1 << TOIE0;
    }
    // Set clock source to start timer
    TCCR0B = (TCCR0B & ~0b111u) | self->clock_select;
}

void Timer_Stop(Timer* self) {
    // Disable timer interrupts
    TIMSK &= ~0x1A;
    // Set no clock source to stop timer
    TCCR0B &= ~0b111u;
}

void Timer_Clear(Timer* self, bool restart) {
    Timer_Stop(self);
    // Reset prescaler counter
    GTCCR |= 1 << PSR0;
    // Clear timer interrupt flags
    TIFR |= (1 << OCF0A) | (1 << OCF0B) | (1 << TOV0);
    // Reset Counter
    TCNT0 = 0;
    if (restart) {
        Timer_Start(self);
    }
}