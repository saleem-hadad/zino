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
private:
  Port _port;
  unsigned char _pin;
public:
    Pin(Port port, unsigned char pin);
    Port port();
    unsigned char pin();
};


#endif
