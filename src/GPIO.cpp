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

volatile unsigned char* admux = (unsigned char*) 0x7C;
volatile unsigned char*adcsra = (unsigned char*) 0x7A;
volatile unsigned char* adch  = (unsigned char*) 0x79;
volatile unsigned char* adcl  = (unsigned char*) 0x78;

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

int GPIO::read(Pin& pin)
{
    if (pin.port() == PortB) {
        return (*pinb & (1 << pin.pin())) ? 1 : 0;
    }else if(pin.port() == PortB){
        return (*pind & (1 << pin.pin())) ? 1 : 0;
    }

    return GPIO::analogRead(pin.pin());
}

int GPIO::analogRead(char pin)
{
         if(pin == 0) *admux  = 0b01000000;
    else if(pin == 1) *admux |= 0b01000001;
    else if(pin == 2) *admux |= 0b01000010;
    else if(pin == 3) *admux |= 0b01000011;
    else if(pin == 4) *admux |= 0b01000100;
    else if(pin == 5) *admux |= 0b01000101;
    else return 0;

    *adcsra = 0b11000111;
    *adcsra |= (1 << 6);
    while (((*adcsra) & (1 << 6))) {}
    int lowbyte = (*adcl);
    int highbyte = (*adch);
    int value = ((highbyte << 8) | lowbyte);
    return value;
}

void GPIO::write(Pin& pin, char value)
{
    char p = pin.pin();
    Port port = pin.port();

    switch (port) {
        case PortB:
            if(value) *portb |= (1 << p);
            else     *portb &= ~(1 << p);
            break;
        case PortD:
            if(value) *portd |= (1 << p);
            else     *portd &= ~(1 << p);
            break;
        case PortC:
            break;
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
