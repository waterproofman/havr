#include <inttypes.h>
#include <avr/io.h>
#include "uart.hpp"

#include <avr/interrupt.h>



namespace havr
{

namespace
{
    ISR(USART1_TX_vect)
    {
        static bool once = false;
        if(!once)
        {
            UDR1 = 'i';
            once = true;
        }
        else
        {
            once = false;
        }
    }

    void rxIsr()
    {
    }

    void txIsr()
    {
    }
}

void Uart::configure()
{
    UBRR1L = 51;
    UCSR1B |= 1<<3;
    UCSR1B |= 1<<6;
    SREG |= 1<<7;
}

void Uart::send(uint8_t byte)
{
    UDR1 = byte;
}

uint8_t Uart::receive()
{
    return 'n';
}

}
