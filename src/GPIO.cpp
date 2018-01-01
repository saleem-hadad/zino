/*
 .----------------.  .----------------.  .-----------------. .----------------.
| .--------------. || .--------------. || .--------------. || .--------------. |
| |   ________   | || |     _____    | || | ____  _____  | || |     ____     | |
| |  |  __   _|  | || |    |_   _|   | || ||_   \|_   _| | || |   .'    `.   | |
| |  |_/  / /    | || |      | |     | || |  |   \ | |   | || |  /  .--.  \  | |
| |     .'.' _   | || |      | |     | || |  | |\ \| |   | || |  | |    | |  | |
| |   _/ /__/ |  | || |     _| |_    | || | _| |_\   |_  | || |  \  `--'  /  | |
| |  |________|  | || |    |_____|   | || ||_____|\____| | || |   `.____.'   | |
| |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'

 Created by: Saleem Hadad
 Date: 30/12/2017
 Github: https://github.com/saleem-hadad/zino
*/

#include "GPIO.h"

volatile unsigned char *_ddrb  = (unsigned char*) 0x24;
volatile unsigned char *_portb = (unsigned char*) 0x25;
volatile unsigned char *_pinb  = (unsigned char*) 0x23;

GPIO::GPIO()
{
    //
}

void GPIO::setup(Pin& pin, PinMode mode)
{
    if(mode == Output)
    {
        *_ddrb |= 1 << pin.pin();
    }
    else if(mode == Input)
    {
        *_ddrb &= ~(1 << pin.pin());
    }
    else if(mode == InputWithPullUp)
    {
        *_ddrb &= ~(1 << pin.pin());
        *_portb |= (1 << pin.pin());
    }
}

bool GPIO::read(Pin& pin)
{
    return (*_pinb & (1 << pin.pin()));
}

void GPIO::write(Pin& pin, char value)
{
    if(value)
    {
        *_portb |= (1 << pin.pin());
        return;
    }

    *_portb &= ~(1 << pin.pin());
}

void GPIO::high(Pin& pin)
{
    GPIO::write(pin, 1);
}

void GPIO::low(Pin& pin)
{
    GPIO::write(pin, 0);
}
