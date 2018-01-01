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
#include "GPIO.h"

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
	
	void init(Pin pin, unsigned int onTime, unsigned int offTime);
	void refresh(void);


private:
	Pin* _pin;
  void setup(void);
	bool active = false;
  unsigned int onTime;
  unsigned int offTime;
  unsigned long previousTime=0;
};

#endif
