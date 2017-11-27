#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define 	F_CPU   8000000UL
#include <util/delay.h>


int main (void)
{
	DDRC = 0xFF;
    while(true)
    {
        _delay_ms(1000);
        PORTC ^= 0xFF;

    }
    return (0);
}
