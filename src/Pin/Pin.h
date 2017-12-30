//
// Created by Saleem Hadad on 30/12/2017.
//

#ifndef ZINO_PIN_H
#define ZINO_PIN_H

enum PinMode {
    Output,
    Input,
    InputPullUp
};

enum Port {
    B,
    D,
    C
};

class Pin {
public:
    Pin(Port port, unsigned char pin);
};


#endif
