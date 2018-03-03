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

#ifndef ZINO_ULTRASONIC_H
#define ZINO_ULTRASONIC_H

#include "Pin.h"
#include "GPIO.h"
#include "Sensor.h"
#include <Arduino.h>

enum class MeasurementUnit
{
    M,
    CM,
    MM
};

class Ultrasonic: Sensor
{
public:
	/*
	init method:
	@params:
	Pin trig
    Pin echo
	@return:
	void
	*/
	void init(Pin trig, Pin echo)
    {
        this->_trig = &trig;
        this->_echo = &echo;
        this->_initialized = true;

        GPIO::setup(trig, Output);
        GPIO::setup(echo, Input);
    }

    /*
	sense method:
	@params:
	void
	@return:
	float
	---
	*/
    int sense()
    {
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

    /*
	setMeasurementUnit method:
	@params:
	MeasurementUnit measurementUnit
	@return:
	void
	---
	*/
    void setMeasurementUnit(MeasurementUnit measurementUnit)
    {
        this->measurementUnit = measurementUnit;
    }
private:
	// The pins objects used to be set as input/output.
	Pin* _trig;
    Pin* _echo;

    //
    MeasurementUnit measurementUnit = MeasurementUnit::CM;

	// Used to track if the ultrasonic object initialized or not.
	bool _initialized = false;
};

#endif
