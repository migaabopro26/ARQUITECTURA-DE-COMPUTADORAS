#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= 0x07;
    DDRD &= ~0x07;
    PORTD |= 0x07;

    PORTB |= 0x07;
    _delay_ms(1000);
    PORTB &= ~0x07;

    while (1) {
        PORTB = (PORTB & ~0x07) | ((~PIND) & 0x07);
    }

    return 0;
}