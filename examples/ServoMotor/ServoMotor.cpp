#include <Arduino.h>
#include <ServoMotor.h>

ServoMotor motor;

void setup()
{
    motor.init(Pin(PortB, 0), 20);
    motor.write(10);
}

void loop()
{
    motor.refresh();
}
