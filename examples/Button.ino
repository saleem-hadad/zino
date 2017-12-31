#include <Arduino.h>
#include <Button.h>
#include <Pin.h>

Button button(Pin(PortB, 5), 40, false, false);

void buttonPressed()
{
  Serial.println("Button has been pressed 🤠");
}

void setup()
{
  Serial.begin(9600);
  button.pressed = buttonPressed;
}

void loop()
{
  button.refresh();
}
