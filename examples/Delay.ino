#include <Arduino.h>
#include <Delay.h>

Delay myDelay;       // default duration 1000 ms.
// Delay myDelay(1000); //Other initialization

void callback()
{
    Serial.println("delay fired 🔥");
}

void setup()
{
    Serial.begin(9600);
    myDelay.init(500); //duration = 500 ms.

    myDelay.callback = callback;
}

void loop()
{
    myDelay.refresh();
    //Other stuff goes here
}
