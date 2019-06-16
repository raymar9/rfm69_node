/* 
 * File: blink.c
 * Description: Toggels pin PB0 every 500ms
 * From: C-Programmierung mit AVR-GCC
 */

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

int main (void) {

   DDRB |= (1 << PB1);

   while(1) {
       PORTB ^= (1 << PB1);
       _delay_ms(500);
   }

   return 0;
}
