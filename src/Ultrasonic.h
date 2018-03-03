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
#include "Sensor.h"

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
	void init(Pin trig, Pin echo);

    /*
	sense method:
	@params:
	void
	@return:
	int
	---
	*/
    int sense();

    /*
	setMeasurementUnit method:
	@params:
	MeasurementUnit measurementUnit
	@return:
	void
	---
	*/
    void setMeasurementUnit(MeasurementUnit measurementUnit);
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
