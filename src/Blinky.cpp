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

#include "Blinky.h"
#include <Arduino.h>

Blinky::Blinky()
{
  //
}

void Blinky::init(Pin pin, unsigned int onTime, unsigned int offTime)
{
  this->_pin    = &pin;
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
      GPIO::high(*this->_pin);
    }
  }
  else
  {
    if(currentTime - this->previousTime >= this->onTime)
    {
      this->active = false;
      this->previousTime = currentTime;
      GPIO::low(*this->_pin);
    }
  }
}
