//
// Created by Saleem Hadad on 30/12/2017.
//

#ifndef ZINO_Blinky_h
#define ZINO_Blinky_h

#include "Pin.h"
#include "GPIO.h"

class Blinky
{
public:
	Blinky();
  void init(Pin& pin, unsigned int onTime, unsigned int offTime);
  void refresh(void);

private:
  void setup(void);
	bool active = false;
  unsigned int onTime;
  unsigned int offTime;
  unsigned long previousTime=0;
  Pin& _pin;
};

#endif
