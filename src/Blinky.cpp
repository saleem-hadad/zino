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

 Github: https://github.com/saleem-hadad/zino
*/

#include "Blinky.h"
#include <Arduino.h>
#include "GPIO.h"

Blinky::Blinky(){}

void Blinky::init(Pin pin, unsigned long onTime, unsigned long offTime)
{
    this->_pin = &pin;
    this->_onTime  = onTime;
    this->_offTime = offTime;
    this->_initialized = true;

    GPIO::setup(pin, Output);
}

void Blinky::refresh(void)
{
    if(! this->_initialized) { return; }

    unsigned long currentTime = millis();

    if(! this->_active)
    {
        if ((currentTime - this->_previousTime) >= this->_offTime)
        {
            this->_active = true;
            this->_previousTime = currentTime;
            GPIO::write(*this->_pin, 1);
        }
    }
    else
    {
        if((currentTime - this->_previousTime) >= this->_onTime)
        {
            this->_active = false;
            this->_previousTime = currentTime;
            GPIO::write(*this->_pin, 0);
        }
    }
}

void Blinky::setOnTime(unsigned long onTime)
{
    this->_onTime = onTime;
}

void Blinky::setOffTime(unsigned long offTime)
{
    this->_offTime = offTime;
}
