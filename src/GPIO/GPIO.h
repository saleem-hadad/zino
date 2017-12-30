//
// Created by Saleem Hadad on 30/12/2017.
//

#ifndef ZINO_GPIO_H
#define ZINO_GPIO_H

#include "Pin.h"

class GPIO {
public:
    GPIO();
    static GPIO shared = GPIO();
    void setup(Pin& pin, PinMode mode);
};


#endif
