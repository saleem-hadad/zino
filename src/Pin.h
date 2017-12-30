//
// Created by Saleem Hadad on 30/12/2017.
//

#ifndef ZINO_PIN_H
#define ZINO_PIN_H

enum PinMode {
    Output,
    Input,
    InputWithPullUp
};

enum Port {
    PortB,
    PortD,
    PortC
};

class Pin {
private:
  Port _port;
  char _pin;
public:
    Pin(Port port, char pin);
    Port port();
    char pin();
};


#endif
