/* 
 * File: blink.c
 * Description: Toggels pin PB0 every 500ms
 * From: C-Programmierung mit AVR-GCC
 */

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avrhal/io.h>

int main (void) {

    Io_SetOutput(PB1);

    while(1) {
        Io_Toggle(PB1);
       _delay_ms(1000);
    }

    return 0;
}
