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

#ifndef ZINO_GPIO_H
#define ZINO_GPIO_H 1

#include "Pin.h"

class GPIO {
    // static GPIO* _instance;
public:
    /*
    shared static method:
    @params:
    void
    @return:
    GPIO*
    ---

	*/
    static GPIO* shared()
    {
        // if(_instance != nullptr){
        //     return _instance;
        // }
        // GPIO io;
        // _instance = &io;
        // return _instance;

        static GPIO _instance;
        return &_instance;
    }

    /*
    setup static method:
    @params:
    Pin& pin
    PinMode mode
    @return:
    void
    ---
    Use it to setup the needed pin mode to the
    selected pin & port on the Arduino board
	*/
    void setup(Pin& pin, PinMode mode)
    {
        if(mode == Output)
        {
            *this->_ddrb |= 1 << pin.pin();
        }
        else if(mode == Input)
        {
            *this->_ddrb &= ~(1 << pin.pin());
        }
        else if(mode == InputWithPullUp)
        {
            *this->_ddrb &= ~(1 << pin.pin());
            *this->_portb |= (1 << pin.pin());
        }
    }

    /*
    read static method:
    @params:
    Pin& pin
    @return:
    bool
    ---
    Use it to read the current status of a given
    pin on a spicific digital port, e.g. PortB
	*/
    bool read(Pin& pin)
    {
        return (*this->_pinb & (1 << pin.pin()));
    }

    /*
    write static method:
    @params:
    Pin& pin
    char value
    @return:
    void
    ---
    Use it to write digital or analog values to
    any pin on given a digital/analog port.
	*/
    void write(Pin& pin, char value)
    {
        if(value)
        {
            *_portb |= (1 << pin.pin());
            return;
        }

        *_portb &= ~(1 << pin.pin());
    }

    /*
    high static method:
    @params:
    Pin& pin
    @return:
    void
    ---
    Use it as a shortcut to write high value to
    any pin on a given digital port only.
	*/
    void high(Pin& pin)
    {
        this->write(pin, 1);
    }

    /*
    low static method:
    @params:
    Pin& pin
    @return:
    void
    ---
    Use it as a shortcut to write low value to
    any pin on a given digital port only.
	*/
    void low(Pin& pin)
    {
        this->write(pin, 0);
    }
private:
    GPIO(){}
    unsigned char *_ddrb  = (unsigned char*) 0x24;
    unsigned char *_portb = (unsigned char*) 0x25;
    unsigned char *_pinb  = (unsigned char*) 0x23;

    unsigned char *_ddrd  = (unsigned char*) 0x24;
    unsigned char *_portd = (unsigned char*) 0x25;
    unsigned char *_pind  = (unsigned char*) 0x23;

    unsigned char *_ddrc  = (unsigned char*) 0x24;
    unsigned char *_portc = (unsigned char*) 0x25;
    unsigned char *_pinc  = (unsigned char*) 0x23;
};

#endif
