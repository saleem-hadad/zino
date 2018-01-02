#include <Arduino.h>
#include <Button.h>
#include <Pin.h>
#include <LED.h>

Button button;
LED led;

void buttonPressed()
{
    led.toggle();
}

void setup()
{
    button.init(Pin(PortB, 5), 40, false, false);
    button.pressed = buttonPressed;

    led.init(Pin(PortB, 4));
}

void loop()
{
    button.refresh();
}
