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
	long frequency
	@return:
	void
	---
	Used to update the default settings of the DCMotor
	object. Please note that the frequency is in hz
    remember: T=1/f, e.g. f=100, period(T)=1/100
	*/
	void init(Pin pin, long frequency);

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
	setDutyCycle method:
	@params:
	Pin pin
	double dutyCycle
	@return:
	void
	---
	Used to update the dc motor DC. For example if the
    frequency set to 1(period=1s), setting DC = 0.5
    the pin will stay on for 0.5s and off for 0.5s
	*/
    void setDutyCycle(double dutyCycle);

	/*
	setFrequency method:
	@params:
	long frequency
	double dutyCycle
	@return:
	void
	---
	Used to update the PWM frequency. For example if
    the frequency set to 100 -> the period will be
	equal to f=1÷t => t=1÷f = 1 ÷ 100 = 0.01 s.
	*/
	void setFrequency(long frequency);
	void forward();
	void backward();
	void stop();
private:
	// The pin object used to be set as output.
	Pin* _pin;

    // Used to generate PWM signal on the given pin.
    Blinky _blinker;

    // Used to determin the on and off time of the blinker.
    unsigned long _period = 1;

	// Used to track if the blinky object initialized or not.
	bool _initialized = false;
};

#endif
