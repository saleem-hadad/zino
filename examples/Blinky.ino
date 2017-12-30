#include <Arduino.h>
#include <Blinky.h>
#include <Pin.h>

Pin ledPin = Pin(PortB, 5);
Blinky led;

void setup()
{
  led.init(ledPin, 100, 500);
}

void loop()
{
  led.refresh();
}
