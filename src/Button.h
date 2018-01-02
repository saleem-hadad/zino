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

#ifndef ZINO_BUTTON_H
#define ZINO_BUTTON_H

#include "Pin.h"

class Button
{
public:
	/*
	Button constructor:
	@params:
	void
	@return:
	void
	*/
	Button();

	/*
	init method:
	@params:
	Pin pin
	char debouncePeriod
	bool defaultHigh
	bool withPullUp
	@return:
	void
	*/
	void init(Pin pin, char debouncePeriod, bool defaultHigh, bool withPullUp);

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
	pressed pointer function:
	@params:
	void
	@return:
	void
	---
	Used as callback function to higher level where you
	can get a notification when the button has been
	pressed, keep in mine no bouncing here 😏.
    */
	void (*pressed)(void);

private:
	// The pin object used to be set as input w/o pullup.
	Pin* _pin;

	// Set if the default reading from the pin is heigh.
	bool _defaultHigh;

	// Used to track if the button object initialized or not.
	bool _initialized = false;

	/*
	Used as a trigger to indicate if the button has been
	pressed or not so that a new logic will happened.
	*/
	bool _waiting = false;

	// Used to track the first low to high transition.
	bool _previous = false;

	/*
	The time interval we should wait until the next reading
	from the pin so that we can solve the bouncing issue.
	*/
	unsigned char _debouncePeriod;

	/*
	The time when the button pressed and a transition
	happened, so that we can check again after the
	period to ensure the transition is real.
	*/
	unsigned long _pressed_time = 0;
};

#endif
