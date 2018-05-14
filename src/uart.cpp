#include <inttypes.h>
#include <avr/io.h>
#include "uart.hpp"

namespace havr
{

namespace
{
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
