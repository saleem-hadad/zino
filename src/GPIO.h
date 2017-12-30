//
// Created by Saleem Hadad on 30/12/2017.
//

#ifndef ZINO_GPIO_H
#define ZINO_GPIO_H

#include "Pin.h"

class GPIO {
private:
  GPIO();
public:
    static void setup(Pin& pin, PinMode mode);
    static void assignRegisters(Port port, unsigned char** DDR, unsigned char** PORT, unsigned char** PIN);
    static void write(Pin& pin, char value);
    static void high(Pin& pin);
    static void low(Pin& pin);
};

#endif