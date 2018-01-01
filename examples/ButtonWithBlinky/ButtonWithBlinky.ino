#include <Arduino.h>
#include <Blinky.h>
#include <Button.h>
#include <Pin.h>

Blinky leds[5];
Button button(Pin(PortB, 5), 40, false, false);

void buttonPressed()
{
    Serial.println("Button has been pressed :)");
}

void setup()
{
    Serial.begin(9600);
    button.pressed = buttonPressed;
    leds[0].init(Pin(PortB, 0), 600, 650);
    leds[1].init(Pin(PortB, 1), 700, 100);
    leds[2].init(Pin(PortB, 2), 300, 540);
    leds[3].init(Pin(PortB, 3), 100, 100);
    leds[4].init(Pin(PortB, 4), 450, 357);
}

void loop()
{
    for (int index = 0; index < 5; index++) {
        leds[index].refresh();
    }

    button.refresh();
}
