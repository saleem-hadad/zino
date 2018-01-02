#include <Arduino.h>
#include <Button.h>
#include <Pin.h>

Button button;

void buttonPressed()
{
    Serial.println("Button has been pressed 🤠");
}

void setup()
{
    Serial.begin(9600);
    button.init(Pin(PortB, 5), 40, false, false);
    button.pressed = buttonPressed;
}

void loop()
{
    button.refresh();
}
