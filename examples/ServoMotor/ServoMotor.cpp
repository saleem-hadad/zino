#include <Arduino.h>
#include <ServoMotor.h>

ServoMotor motor;

void setup()
{
    motor.init(Pin(PortB, 0));
    motor.write(0); // 0º - 180º
}

void loop()
{
    motor.refresh();
}
