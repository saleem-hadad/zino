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

#ifndef ZINO_BLINKY_H
#define ZINO_BLINKY_H

#include "Pin.h"

class Blinky
{
public:
	/*
	Blinky constructor:
	@params:
	void
	@return:
	void
	*/
	Blinky();

	/*
	init method:
	@params:
	Pin pin
	unsigned long onTime
	unsigned long offTime
	@return:
	void
	---
	Used to update the default settings of the Blinky
	object. Please note that the onTime and offTime
	both are in ms, e.g. 1 s = to 1000 ms.
	*/
	void init(Pin pin, unsigned long onTime, unsigned long offTime);

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

	/*
	setOnTime method:
	@params:
	Pin pin
	unsigned long onTime
	@return:
	void
	---
	Used to update the amount of time the pin will
	set as High. Please note that the value of
	onTime in ms, e.g. 1 s equal to 1000 ms.
	*/
	void setOnTime(unsigned long onTime);

	/*
	setOnTime method:
	@params:
	Pin pin
	unsigned long onTime
	@return:
	void
	---
	Used to update the amount of time the pin will
	set as Low. Please note that the value of
	offTime in ms, e.g. 1 s = to 1000 ms.
	*/
	void setOffTime(unsigned long offTime);
private:
	// The pin object used to be set as output.
	Pin* _pin;

	// Used to track if the blinky object initialized or not.
	bool _initialized = false;

	// Used to handle toggling functionality.
	bool _active = false;

	// The amount of time the pin's status is high.
	unsigned long _onTime;

	// The amount of time the pin's status is low.
	unsigned long _offTime;

	// Used to track how many ms passed.
	unsigned long _previousTime = 0;
};

#endif
