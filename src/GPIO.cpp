//
// Created by Saleem Hadad on 30/12/2017.
//

#include "GPIO.h"

void GPIO::setup(Pin& pin, PinMode mode)
{
  unsigned char *DDR;
  unsigned char *PORT;
  unsigned char *PIN;

  GPIO::assignRegisters(pin.port(), &DDR, &PORT, &PIN);

  if(mode == Output)
  {
    *DDR = 1 << pin.pin();
  }
  else if(mode == Input)
  {
    *DDR &= ~(1 << pin.pin());
  }
  else if(mode == InputWithPullUp)
  {
    *DDR &= ~(1 << pin.pin());
    *PORT|= (1 << pin.pin());
  }
}

void GPIO::assignRegisters(Port port, unsigned char** DDR, unsigned char** PORT, unsigned char** PIN)
{
  if(port == PortB)
  {
    *DDR  = (unsigned char*) 0x24;
    *PORT = (unsigned char*) 0x25;
    *PIN  = (unsigned char*) 0x23;
  }
}

void GPIO::write(Pin& pin, char value)
{
  unsigned char *DDR;
  unsigned char *PORT;
  unsigned char *PIN;

  GPIO::assignRegisters(pin.port(), &DDR, &PORT, &PIN);

  if(value)
  {
    *PORT |= (1 << pin.pin());
  }
  else
  {
    *PORT &= ~(1 << pin.pin());
  }
}

void GPIO::high(Pin& pin)
{
  GPIO::write(pin, 1);
}

void GPIO::low(Pin& pin)
{
  GPIO::write(pin, 0);
}
