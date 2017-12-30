//
// Created by Saleem Hadad on 30/12/2017.
//

#include "Pin.h"

Pin::Pin(Port port, char pin): _port(port), _pin(pin)
{
    this->_port = port;
    this->_pin  = pin;
}

Port Pin::port()
{
  return this->_port;
}

char Pin::pin()
{
  return this->_pin;
}
