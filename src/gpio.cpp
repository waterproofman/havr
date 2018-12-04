#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define 	F_CPU   8000000UL
#include <util/delay.h>

#include "uart.hpp"

int main (void)
{
    havr::Uart uart;
    uart.configure();

	DDRC = 0xFF;
	uint8_t out = 0x01;
    while(true)
    {
        uart.send("Ala",3);
        _delay_ms(1000);
        uart.send('#');
        _delay_ms(1000);
        PORTC = ~out;
        _delay_ms(1000);
        out <<= 1;
        if(out == 0)
            out = 0x1;
    }
    return (0);
}
