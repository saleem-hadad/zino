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
 Date: 8/1/2018
 Github: https://github.com/saleem-hadad/zino
*/

#include "Ultrasonic.h"
#include "GPIO.h"
#include <Arduino.h>

Ultrasonic::Ultrasonic()
{
    //
}

Ultrasonic::Ultrasonic(Pin trig, Pin echo)
{
    this->init(trig, echo);
}

void Ultrasonic::init(Pin trig, Pin echo)
{
    this->_trig = &trig;
    this->_echo = &echo;
    this->_initialized = true;

    GPIO::setup(trig, Output);
    GPIO::setup(echo, Input);
}

void Ultrasonic::setMeasurementUnit(MeasurementUnit measurementUnit)
{
    this->measurementUnit = measurementUnit;
}

float Ultrasonic::sense() {
    if(! this->_initialized) { return 0.0; }

    GPIO::write(*this->_trig, 0);
    delayMicroseconds(2);
    GPIO::write(*this->_trig, 1);
    delayMicroseconds(7);
    GPIO::write(*this->_trig, 0);

    float time = pulseIn( this->_echo->port() == PortB ? this->_echo->pin() + 8 : this->_echo->pin(), HIGH);
    time /= 58;
    if (this->measurementUnit == mm) time *= 10;
    if (this->measurementUnit == m) time /= 10;
    return time * 10;
}
