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
 Date: 16/1/2018
 Github: https://github.com/saleem-hadad/zino
*/

#ifndef ZINO_SERVOMOTOR_H
#define ZINO_SERVOMOTOR_H

#include "Pin.h"
#include "Blinky.h"

class ServoMotor
{
public:
	/*
	ServoMotor constructor:
	@params:
	void
	@return:
	void
	*/
	ServoMotor();

	/*
	init method:
	@params:
	Pin pin
	@return:
	void
	---
	Used to provide the pin connected with the servo.
	*/
	void init(Pin pin);

	/*
	write method:
	@params:
	int angle
	@return:
	void
	---
	Set the needed angle from 0º - 180º;
	*/
	void write(int angle);

    /*
    write method:
    @params:
    int min
    int max
    @return:
    void
    ---
	Used to update the default min/max pulse width
	which normally they are different from servo
	to another. Pls. refere to the datasheet.
    */
    void setPulseWidthRange(int min, int max);

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

    // Used to generate PWM signal on the given pin.
    Blinky _blinker;

    // Used to determin the on and off time of the blinker.
    int _period = 30;

	// Used to track if the ServoMotor object initialized or not.
	bool _initialized = false;

    //
    int _minPulseWidth = 544;

    //
    int _maxPulseWidth = 2400;
};

#endif
