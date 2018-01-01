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

#ifndef HAVE_GPIO_REGISTERS
#define HAVE_GPIO_REGISTERS

volatile unsigned char *pinb  = (unsigned char*) 0x23;
volatile unsigned char *ddrb  = (unsigned char*) 0x24;
volatile unsigned char *portb = (unsigned char*) 0x25;

volatile unsigned char *pind  = (unsigned char*) 0x29;
volatile unsigned char *ddrd  = (unsigned char*) 0x2A;
volatile unsigned char *portd = (unsigned char*) 0x2B;

volatile unsigned char *pinc  = (unsigned char*) 0x26;
volatile unsigned char *ddrc  = (unsigned char*) 0x27;
volatile unsigned char *portc = (unsigned char*) 0x28;

#endif


GPIO::GPIO()
{
    //
}

void GPIO::setup(Pin& pin, PinMode mode)
{
    if(pin.port() == PortB)
    {
        if(mode == Output) {
            *ddrb |= 1 << pin.pin();
        }else if(mode == Input) {
            *ddrb &= ~(1 << pin.pin());
        }else if(mode == InputWithPullUp) {
            *ddrb &= ~(1 << pin.pin());
            *portb |= (1 << pin.pin());
        }
    }
    else if(pin.port() == PortD)
    {
        if(mode == Output) {
            *ddrd |= 1 << pin.pin();
        }else if(mode == Input) {
            *ddrd &= ~(1 << pin.pin());
        }else if(mode == InputWithPullUp) {
            *ddrd &= ~(1 << pin.pin());
            *portd |= (1 << pin.pin());
        }
    }
}

bool GPIO::read(Pin& pin)
{
    if(pin.port() == PortB)
    {
        return (*pinb & (1 << pin.pin()));
    }
    else if(pin.port() == PortD)
    {
        return (*pind & (1 << pin.pin()));
    }
    else
    {
        //analog read
    }
}

void GPIO::write(Pin& pin, char value)
{
    if(pin.port() == PortB)
    {
        if(value) *portb |= (1 << pin.pin());
        else     *portb &= ~(1 << pin.pin());
    }
    else if(pin.port() == PortD)
    {
        if(value) *portd |= (1 << pin.pin());
        else     *portd &= ~(1 << pin.pin());
    }
}

void GPIO::high(Pin& pin)
{
    GPIO::write(pin, 1);
}

void GPIO::low(Pin& pin)
{
    GPIO::write(pin, 0);
}
