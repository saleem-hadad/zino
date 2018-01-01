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

#include "Button.h"
#include <Arduino.h>

Button::Button(Pin pin, char debouncePeriod, bool defaultHigh, bool withPullUp)
{
    this->_pin = pin;
    this->_debouncePeriod = debouncePeriod;
    this->_defaultHigh = defaultHigh;

    if (withPullUp)
    {
        GPIO::setup(pin, InputWithPullUp);
        return;
    }

    GPIO::setup(pin, Input);
}

void Button::refresh()
{
    if(this->_waiting)
    {
        if(millis() - this->_pressed_time >= this->_debouncePeriod)
        {
            this->_waiting = false;
            bool current = GPIO::read(this->_pin);

            if(current && this->pressed) {
                (*this->pressed)();
            }
            
            this->_previous = current;
        }
    }
    else
    {
        bool current = GPIO::read(this->_pin);
        if(current && ! this->_previous)
        {
            this->_pressed_time = millis();
            this->_waiting = true;
        }
        this->_previous = current;
    }
}
