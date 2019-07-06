#include "avrhal/io.h"

#include <avr/io.h>

#if defined (__AVR_ATtiny85__)

void Io_SetInput(uint8_t pin) {
    if (pin > 5) return;
    DDRB &= ~(1u << pin);
}

void Io_SetOutput(uint8_t pin) {
    if (pin > 5) return;
    DDRB |= (1u << pin);
}

void Io_EnablePullUp(uint8_t pin) {
    if (pin > 5) return;
    PORTB |= (1u << pin);
}

void Io_DisablePullUp(uint8_t pin) {
    if (pin > 5) return;
    PORTB &= ~(1u << pin);
}

void Io_SetHigh(uint8_t pin) {
    if (pin > 5) return;
    PORTB |= (1u << pin);
}

void Io_SetLow(uint8_t pin) {
    if (pin > 5) return;
    PORTB &= ~(1u << pin);
}

void Io_Toggle(uint8_t pin) {
    if (pin > 5) return;
    PORTB ^= (1u << pin);
}

uint8_t Io_GetValue(uint8_t pin) {
    if (pin > 5) return 0;
    return (PINB >> pin) & 1u;
}

#else
#error "libavr_io: not suitable for this device!"
#endif
