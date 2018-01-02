#include <Arduino.h>
#include <DCMotor.h>
#include <Pin.h>

DCMotor motor;

void setup()
{
    motor.init(Pin(PortB, 4), 200);
    motor.setDutyCycle(0.5);
}

void loop()
{
    motor.refresh();
}
