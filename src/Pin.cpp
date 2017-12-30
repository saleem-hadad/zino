//
// Created by Saleem Hadad on 30/12/2017.
//

#include "Pin.h"

Pin::Pin(Port port, unsigned char pin): _port(port), _pin(pin)
{
    this->_port = port;
    this->_pin  = pin;
}
