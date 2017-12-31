//
// Created by Saleem Hadad on 1/1/2018.
//

#include "Delay.h"
#include <Arduino.h>

Delay::Delay()
{
  this->init(this->_threshold);
}

Delay::Delay(int duration)
{
  this->init(duration);
}

void Delay::init(int duration)
{
  this->_threshold = duration;
}

void Delay::refresh()
{
  if(! this->_enabled) { return; }

  if(int(millis() - this->_previous) > this->_threshold){
    if(this->callback) (*this->callback)();
    this->_previous = millis();
  }
}

void Delay::enable()
{
  this->_enabled = true;
}

void Delay::disable()
{
  this->_enabled = false;
}
