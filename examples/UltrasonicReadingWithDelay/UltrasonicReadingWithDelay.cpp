#include <Arduino.h>
#include <GPIO.h>
#include <Ultrasonic.h>
#include <Pin.h>
#include <Delay.h>

Pin trig(PortB, 3);
Pin echo(PortB, 4);

Ultrasonic ultrasonic;
Delay myDelay;

void callback()
{
    Serial.println( ultrasonic.sense() );
}

void setup()
{
    Serial.begin(9600);

    myDelay.callback = callback;

    ultrasonic.init(trig, echo);
    ultrasonic.setMeasurementUnit(MeasurementUnit::MM); // Optional: default is CM
}

void loop()
{
    myDelay.refresh();
}
