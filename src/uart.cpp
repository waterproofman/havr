#include <inttypes.h>
#include <avr/io.h>
#include "uart.hpp"

void Uart::configure()
{
    DDRC = 0xFF;
    uint8_t out = 0x01;

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

