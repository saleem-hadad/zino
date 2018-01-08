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

enum MeasurementUnit {
    m,
    cm,
    mm
};

class Ultrasonic
{
public:
    /*
	Ultrasonic constructor:
	@params:
    void
	@return:
	void
	*/
	Ultrasonic();

	/*
	Ultrasonic constructor:
	@params:
    Pin trig
    Pin echo
	@return:
	void
	*/
	Ultrasonic(Pin trig, Pin echo);

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
	refresh method:
	@params:
	void
	@return:
	void
	---
	Should be placed in the main loop of the program.
	*/
	void refresh();

    /*
	sense method:
	@params:
	void
	@return:
	flot
	---
	...
	*/
    float sense();

    /*
	setMeasurementUnit method:
	@params:
	void
	@return:
	flot
	---
	MeasurementUnit measurementUnit
	*/
    void setMeasurementUnit(MeasurementUnit measurementUnit);
private:
	// The pins objects used to be set as input/output.
	Pin* _trig;
    Pin* _echo;

    MeasurementUnit measurementUnit = cm;
	// Used to track if the ultrasonic object initialized or not.
	bool _initialized = false;
};

#endif
