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

#include "Delay.h"
#include <Arduino.h>

Delay::Delay()
{
    this->init(this->_threshold);
}

Delay::Delay(int duration)
{
    this->init(duration);
}

void Delay::init(int duration)
{
    this->_threshold = duration;
}

void Delay::refresh()
{
    if(! this->_enabled) { return; }

    if(int(millis() - this->_previous) > this->_threshold){
        if(this->callback) (*this->callback)();
        this->_previous = millis();
    }
}

void Delay::enable()
{
    this->_enabled = true;
}

void Delay::disable()
{
    this->_enabled = false;
}
