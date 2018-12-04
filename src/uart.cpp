#include <inttypes.h>
#include <avr/io.h>
#include "uart.hpp"
#include <avr/interrupt.h>

namespace havr
{

namespace
{
    const char * txBuffer{nullptr};
    uint16_t c{0};
    extern "C" void USART1_TX_vect(void) __attribute__ ((signal));
    void USART1_TX_vect(void)
    {
        if(c--)
            UDR1 = *txBuffer++;
    }
}

void Uart::configure()
{
    UBRR1L = 51;
    UCSR1B |= 1<<TXEN1;
    UCSR1B |= 1<<TXCIE1;
    const uint8_t GIE{7};
    SREG |= 1<<GIE;
}

void Uart::send(uint8_t byte)
{
    UDR1 = byte;
}

bool Uart::send(const char * data, uint16_t length)
{
    txBuffer = data;
    c = length;
    USART1_TX_vect();
}

uint8_t Uart::receive()
{
    return 'n';
}

}
