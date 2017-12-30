//
// Created by Saleem Hadad on 30/12/2017.
//

#ifndef ZINO_Blinky_h
#define ZINO_Blinky_h

#include <Arduino.h>

class Blinky
{
	public:
	  void init(char port, char pin, unsigned int onTime, unsigned int offTime);
	  void refresh(void);

	private:
	  void setup(void);
	  unsigned char * portDirection;
	  unsigned char * portWriter;
	  unsigned int onTime;
	  unsigned int offTime;
	  unsigned long previousTime=0;
	  char pin;
};

#endif
