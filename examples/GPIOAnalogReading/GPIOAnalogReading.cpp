#include <Arduino.h>
#include <GPIO.h>
#include <Pin.h>

Pin analogSensorPin = Pin(PortC, 5);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println(
        GPIO::read(analogSensorPin)
    );
}
