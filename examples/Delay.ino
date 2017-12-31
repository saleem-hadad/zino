#include <Arduino.h>
#include <Delay.h>

Delay myDelay(1000);
// Delay myDelay; //Other initialization, default duration 1000 ms.

void callback()
{
  //Do your stuff
}

void setup()
{
  myDelay.init(1000); //default duration is 1000 ms.
  myDelay.callback = callback;
}

void loop()
{
  myDelay.refresh();
  //Other stuff goes here
}
