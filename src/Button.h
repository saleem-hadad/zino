//
// Created by Saleem Hadad on 31/12/2017.
//

#ifndef ZINO_BUTTON_h
#define ZINO_BUTTON_h

#include "Pin.h"
#include "GPIO.h"

class Button
{
public:
	Button(Pin pin, char debouncePeriod, bool defaultHigh, bool withPullUp);
	void refresh();
  void (*pressed)(void);

private:
	Pin& _pin;
  bool _defaultHigh;
  bool _waiting = false;
  bool _previous = false;
  unsigned char _debouncePeriod;
  unsigned long _pressed_time = 0;
};

#endif
