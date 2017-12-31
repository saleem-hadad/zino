#include <Arduino.h>
#include <Delay.h>

Delay myDelay;

void callback()
{
  //Do your stuff
}

void setup()
{
  myDelay.callback = callback;
}

void loop()
{
  myDelay.refresh();
  
  //Other stuff goes here
}
