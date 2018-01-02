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

#include "Blinky.h"
#include <Arduino.h>
#include "GPIO.h"

Blinky::Blinky(){}

void Blinky::init(Pin pin, unsigned int onTime, unsigned int offTime)
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
        if (currentTime - this->_previousTime >= this->_offTime)
        {
            this->_active = true;
            this->_previousTime = currentTime;
            GPIO::high(*this->_pin);
        }
    }
    else
    {
        if(currentTime - this->_previousTime >= this->_onTime)
        {
            this->_active = false;
            this->_previousTime = currentTime;
            GPIO::low(*this->_pin);
        }
    }
}

void Blinky::setOnTime(unsigned int onTime)
{
    this->_onTime  = onTime;
}

void Blinky::setOffTime(unsigned int offTime)
{
    this->_offTime = offTime;
}
