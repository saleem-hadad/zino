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

#ifndef ZINO_DCMOTOR_H
#define ZINO_DCMOTOR_H

#include "Pin.h"
#include "Blinky.h"

class DCMotor
{
public:
	/*
	DCMotor constructor:
	@params:
	void
	@return:
	void
	*/
	DCMotor();

	/*
	init method:
	@params:
	Pin pin
	unsigned int onTime
	unsigned int offTime
	@return:
	void
	---
	Used to update the default settings of the DCMotor
	object. Please note that the onTime and offTime
	both are in ms, e.g. 1 s = to 1000 ms.
	*/
	void init(Pin pin, unsigned int frequency);

	/*
	refresh method:
	@params:
	void
	@return:
	void
	---
	Should be placed in the main loop of the program.
	*/
	void refresh(void);

    void setDutyCycle(double dutyCycle);
private:
	// The pin object used to be set as output.
	Pin* _pin;

    Blinky _blinker;

	// Used to track if the blinky object initialized or not.
	bool _initialized = false;

	unsigned long _period = 1;
};

#endif
