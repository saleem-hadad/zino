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
 Date: 30/12/2017
 Github: https://github.com/saleem-hadad/zino
*/

#ifndef ZINO_PIN_H
#define ZINO_PIN_H

/*
PinMode enum:
Used to indicate the pin's mode required by any
device in used in the application, example an
LED is considered as Input/InputWithPullUp.
*/
enum PinMode {
    Output,
    Input,
    InputWithPullUp
};

/*
Port enum:
Used to indicate which port on the board needed
in the application so we avoid any kind of
string based naming to prevent errors.
*/
enum Port {
    PortB,
    PortD,
    PortC
};

class Pin {
public:
    /*
    Pin constructor:
    @params:
    char pin
    @return:
    void
	*/
    Pin(char pin);

    /*
    Pin constructor:
    @params:
    Port port
    char pin
    @return:
    void
	*/
    Pin(Port port, char pin);

    /*
    port getter:
    @params:
    void
    @return:
    Port port
	*/
    Port port();

    /*
    pin getter:
    @params:
    void
    @return:
    char pin
	*/
    char pin();
private:
    // Port enum
    Port _port;

    // Pin's location on the selected port
    char _pin;
};


#endif
