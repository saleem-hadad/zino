#include <Arduino.h>
#include <PowerManager.h>

void setup()
{
    PowerManager::sleep();
    // or
    PowerManager::deepSleep();
}

void loop()
{
    //
}
