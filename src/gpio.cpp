#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define 	F_CPU   8000000UL
#include <util/delay.h>

int main (void)
{
	DDRC = 0xFF;
	uint8_t out = 0x01;

    UBRR1L = 51;
    UCSR1B |= 1<<3;

    while(true)
    {
        UDR1 = 'o';
        PORTC = ~out;
        _delay_ms(1000);
        out <<= 1;
        if(out == 0)
            out = 0x1;
    }
    return (0);
}
