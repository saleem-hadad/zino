#include <Arduino.h>
#include <Blinky.h>
#include <Pin.h>

Blinky leds[4];

void setup()
{
    leds[0].init(Pin(PortB, 0), 600, 650);
    leds[1].init(Pin(PortB, 1), 700, 100);
    leds[2].init(Pin(PortB, 2), 300, 540);
    leds[3].init(Pin(PortB, 3), 100, 100);
}

void loop()
{
    for (int index = 0; index < 4; index++) {
        leds[index].refresh();
    }
}
