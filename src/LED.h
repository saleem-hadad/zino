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
 Date: 2/1/2018
 Github: https://github.com/saleem-hadad/zino
*/

#ifndef ZINO_LED_H
#define ZINO_LED_H

#include "Pin.h"

class LED
{
public:
	/*
	LED constructor:
	@params:
	void
	@return:
	void
	*/
	LED();

	/*
	init method:
	@params:
	Pin pin
	@return:
	void
	---
	Used to set the pin of the LED as Output.
	*/
	void init(Pin pin);

    /*
    on method:
    @params:
    void
    @return:
    void
    ---
	Used to turn on the led.
    */
    void on();

    /*
    off method:
    @params:
    void
    @return:
    void
    ---
	Used to turn off the led.
    */
    void off();

    /*
    toggle method:
    @params:
    void
    @return:
    void
    ---
	Used to toggle the current status of the LED
	if it's currently on, it becomes off and
	if it's currently off, becomes on :D
    */
    void toggle();
private:
    enum LEDStatus {
        On,
        Off
    };

	// The pin object used to be set as output.
	Pin* _pin;

	// Used to track the current status of the LED, default off.
    LEDStatus _status = Off;

	// Used to track if the blinky object initialized or not.
	bool _initialized = false;
};

#endif
