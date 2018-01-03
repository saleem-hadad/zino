#include <Arduino.h>
#include <GPIO.h>
#include <DCMotor.h>
#include <Pin.h>

Pin potentiometer = Pin(PortC, 5);
DCMotor motor;

void setup()
{
    motor.init(Pin(PortB, 4), 150);
    motor.setDutyCycle(0);
}

void loop()
{
    motor.setDutyCycle(
        double(GPIO::read(potentiometer)) / 1024
    );

    motor.refresh();
}
