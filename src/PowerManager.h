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

 Github: https://github.com/saleem-hadad/zino
*/

#ifndef ZINO_POWERMANAGER_H
#define ZINO_POWERMANAGER_H

#include "Pin.h"

class PowerManager
{
public:
    /*
    sleep method:
    @params:
    void
    @return:
    void
    ---
    1. Turning off ADC
    2. Turning off Analog Comparator
    3. Sleep with power-down mode
    */
    static void sleep();

    /*
    deepSleep method:
    @params:
    void
    @return:
    void
    ---
    1. BOD disabled
    2. BOD sleep enable
    3. Turning off ADC
    4. Turning off Analog Comparator
    5. Sleep with power-down mode
    */
    static void deepSleep();
};

#endif
