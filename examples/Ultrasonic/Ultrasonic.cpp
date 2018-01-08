#include <Arduino.h>
#include <Ultrasonic.h>
#include <Pin.h>

Pin trig(PortB, 3);
Pin echo(PortB, 4);

Ultrasonic ultrasonic;

void setup()
{
    Serial.begin(9600);

    ultrasonic.init(trig, echo);
    ultrasonic.setMeasurementUnit(MeasurementUnit::MM); // Optional: default is CM
}

void loop()
{
    Serial.println( ultrasonic.sense() );
}
