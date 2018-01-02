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
 Date: 2/1/2018
 Github: https://github.com/saleem-hadad/zino
*/

#include "LED.h"
#include "GPIO.h"

LED::LED(){}

void LED::init(Pin pin)
{
    this->_pin = &pin;
    this->_initialized = true;

    GPIO::setup(pin, Output);
}

void LED::on()
{
    if(! this->_initialized) { return; }

    this->_status = On;
    GPIO::high(*this->_pin);
}

void LED::off()
{
    if(! this->_initialized) { return; }

    this->_status = Off;
    GPIO::low(*this->_pin);
}

void LED::toggle()
{
    if(! this->_initialized) { return; }

    if(this->_status == On){
        this->off();
        return;
    }

    this->on();
}
