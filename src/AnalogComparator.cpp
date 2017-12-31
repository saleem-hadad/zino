//
// Created by Saleem Hadad on 1/1/2018.
//

#include "AnalogComparator.h"
#include <Arduino.h>

AnalogComparator::AnalogComparator(bool enabled, bool bandgabSelected)
{
  if(enabled) this->enable();
  if(bandgabSelected) *this->_acsr |= (1 << this->_acbg);
}

void AnalogComparator::refresh()
{
  if(this->aboveThreshold())
  {
    (*this->output)(true);
    return;
  }

  (*this->output)(false);
}

void AnalogComparator::enable()
{
  *this->_acsr &= ~(1 << this->_acd);
}

void AnalogComparator::disable()
{
  *this->_acsr |= (1 << this->_acd);
}

bool AnalogComparator::aboveThreshold()
{
  return (*this->_acsr & (1 << this->_aco)) == 0;
}
