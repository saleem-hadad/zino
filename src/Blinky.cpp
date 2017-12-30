//
// Created by Saleem Hadad on 30/12/2017.
//

#include "Blinky.h"
#include <Arduino.h>

Blinky::Blinky()
{
  Pin pin = Pin(PortB, 5);
  this->init(pin, 1000, 1000);
}

void Blinky::init(Pin& pin, unsigned int onTime, unsigned int offTime)
{
  this->_pin    = pin;
  this->onTime  = onTime;
  this->offTime = offTime;

  GPIO::setup(pin, Output);
}

void Blinky::refresh(void)
{
  unsigned long currentTime = millis();

  if(! this->active)
  {
    if (currentTime - this->previousTime >= this->offTime)
    {
      this->active = true;
      this->previousTime = currentTime;
      GPIO::high(this->_pin);
    }
  }
  else
  {
    if(currentTime - this->previousTime >= this->onTime)
    {
      this->active = false;
      this->previousTime = currentTime;
      GPIO::low(this->_pin);
    }
  }
}
