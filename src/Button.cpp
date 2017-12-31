//
// Created by Saleem Hadad on 30/12/2017.
//

#include "Button.h"
#include <Arduino.h>

Button::Button(Pin pin, char debouncePeriod, bool defaultHigh, bool withPullUp)
{
  this->_pin = pin;
  this->_debouncePeriod = debouncePeriod;
  this->_defaultHigh = defaultHigh;

  if (withPullUp) {
    GPIO::setup(pin, InputWithPullUp);
  }
  else
  {
    GPIO::setup(pin, Input);
  }
}

void Button::refresh()
{
  if(this->_waiting)
  {
    if(millis() - this->_pressed_time >= this->_debouncePeriod)
    {
      this->_waiting = false;
      bool current = GPIO::read(this->_pin);
      if(current)
      {
        (*this->pressed)();
      }
      this->_previous = current;
    }
  }
  else
  {
    bool current = GPIO::read(this->_pin);
    if(current && ! this->_previous)
    {
      this->_pressed_time = millis();
      this->_waiting = true;
    }
    this->_previous = current;
  }
}
