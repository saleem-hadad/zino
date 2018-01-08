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

    char pin = this->_echo->port() == PortB ? this->_echo->pin() + 8 : this->_echo->pin();
    float time = pulseIn(pin , HIGH);
    time /= 58;

         if (this->measurementUnit == MeasurementUnit::MM) time *= 10;
    else if (this->measurementUnit == MeasurementUnit::M) time /= 100;

    return time;
}
