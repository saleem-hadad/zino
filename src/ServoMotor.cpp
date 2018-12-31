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

#include "ServoMotor.h"
#include <Arduino.h>

ServoMotor::ServoMotor(){}

void ServoMotor::init(Pin pin)
{
    this->_pin = &pin;
    this->_blinker.init(pin, 0, this->_period);

    this->_initialized = true;
}

void ServoMotor::write(int angle)
{
    if(! this->_initialized) { return; }

    long l = angle;
    l = map(l, 0, 180, this->_minPulseWidth, this->_maxPulseWidth);
    this->_blinker.setOnTime(l * 0.001);
    this->_blinker.setOffTime(this->_period - 0.001);
}

void ServoMotor::setPulseWidthRange(int min, int max)
{
    this->_minPulseWidth = min;
    this->_maxPulseWidth = max;
}

void ServoMotor::refresh(void)
{
    if(! this->_initialized) { return; }

    this->_blinker.refresh();
}
