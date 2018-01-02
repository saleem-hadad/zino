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
 Date: 3/1/2018
 Github: https://github.com/saleem-hadad/zino
*/

#include "DCMotor.h"
#include <Arduino.h>
#include "GPIO.h"

DCMotor::DCMotor(){}

void DCMotor::init(Pin pin, unsigned int frequency)
{

    this->_pin = &pin;
    this->_period = 1000 / frequency;
    this->_blinker.init(pin, 0, this->_period);

    this->_initialized = true;
}

void DCMotor::refresh(void)
{
    if(! this->_initialized) { return; }

    this->_blinker.refresh();
}

void DCMotor::setDutyCycle(double dutyCycle)
{
    if(! this->_initialized) { return; }

    if(dutyCycle >= 1) dutyCycle = 1;
    if(dutyCycle <= 0) dutyCycle = 0;

    this->_blinker.setOnTime(this->_period * dutyCycle);
    this->_blinker.setOffTime(this->_period - (this->_period * dutyCycle));
}
