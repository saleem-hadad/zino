//
// Created by Saleem Hadad on 30/12/2017.
//

#include "Blinky.h"

Blinky::Blinky()
{
  Pin pin = Pin(B, 5);
  this->init(pin, 1000, 1000);
}

void Blinky::init(Pin& pin, unsigned int onTime, unsigned int offTime)
{
  this->_pin    = pin;
  this->onTime  = onTime;
  this->offTime = offTime;
}

void Blinky::refresh(void)
{
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}
