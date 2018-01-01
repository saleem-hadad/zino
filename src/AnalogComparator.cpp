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
 Date: 1/1/2018
 Github: https://github.com/saleem-hadad/zino
*/

#include "AnalogComparator.h"
#include <Arduino.h>

AnalogComparator::AnalogComparator()
{
    this->enable();
    this->enableBandgab();
}

AnalogComparator::AnalogComparator(bool enabled, bool bandgabSelected)
{
    if(enabled) this->enable();
    if(bandgabSelected) this->enableBandgab();
}

void AnalogComparator::init(bool enabled, bool bandgabSelected)
{
    if(enabled) this->enable();
    if(bandgabSelected) this->enableBandgab();
}

void AnalogComparator::refresh()
{
    if(this->aboveThreshold())
    {
        if (this->callback) (*this->callback)(true);
        return;
    }

    if (this->callback) (*this->callback)(false);
}

void AnalogComparator::enable()
{
    *this->_acsr &= ~(1 << this->_acd);
}

void AnalogComparator::disable()
{
    *this->_acsr |= (1 << this->_acd);
}

void AnalogComparator::enableBandgab()
{
    *this->_acsr |= (1 << this->_acbg);
}

void AnalogComparator::disableBandgab()
{
    *this->_acsr &= ~(1 << this->_acbg);
}

bool AnalogComparator::aboveThreshold()
{
    return (*this->_acsr & (1 << this->_aco)) == 0;
}
