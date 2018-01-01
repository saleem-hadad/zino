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
 Date: 30/12/2017
 Github: https://github.com/saleem-hadad/zino
*/

#ifndef ZINO_Blinky_h
#define ZINO_Blinky_h

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
	unsigned int onTime
	unsigned int offTime
	@return:
	void
	---
	Used to update the default settings of the Blinky
	object. Please note that the onTime and offTime
	both are in ms, e.g. 1 s = to 1000 ms.
	*/
	void init(Pin pin, unsigned int onTime, unsigned int offTime);

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

private:
	// The pin object used to be set as output.
	Pin* _pin;

	// Used to handle toggling functionality.
	bool active = false;

	// The amount of time the pin's status is high.
	unsigned int onTime;

	// The amount of time the pin's status is low.
	unsigned int offTime;

	// Used to track how many ms passed.
	unsigned long previousTime = 0;
};

#endif
