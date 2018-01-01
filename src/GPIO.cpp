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

unsigned char *DDR_B  = (unsigned char*) 0x24;
unsigned char *PORT_B = (unsigned char*) 0x25;
unsigned char *PIN_B  = (unsigned char*) 0x23;

void GPIO::setup(Pin& pin, PinMode mode)
{
    if(mode == Output)
    {
        *DDR_B |= 1 << pin.pin();
    }
    else if(mode == Input)
    {
        *DDR_B &= ~(1 << pin.pin());
    }
    else if(mode == InputWithPullUp)
    {
        *DDR_B &= ~(1 << pin.pin());
        *PORT_B |= (1 << pin.pin());
    }
}

void GPIO::write(Pin& pin, char value)
{
    if(value)
    {
        *PORT_B |= (1 << pin.pin());
        return;
    }

    *PORT_B &= ~(1 << pin.pin());
}

void GPIO::high(Pin& pin)
{
    GPIO::write(pin, 1);
}

void GPIO::low(Pin& pin)
{
    GPIO::write(pin, 0);
}

bool GPIO::read(Pin& pin)
{
    return (*PIN_B & (1 << pin.pin()));
}
