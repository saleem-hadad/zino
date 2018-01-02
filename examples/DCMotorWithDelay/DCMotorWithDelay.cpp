#include <Arduino.h>
#include <DCMotor.h>
#include <Pin.h>
#include <Delay.h>

Delay myDelay(1000);
DCMotor motor;
double dutyCycle = 0;

void callback()
{
    if(dutyCycle > 1) dutyCycle = 0;
    dutyCycle += 0.1; // Increase the dutyCycle each 1s

    motor.setDutyCycle(dutyCycle);
}

void setup()
{
    motor.init(Pin(PortB, 4), 100);
    motor.setDutyCycle(0);

    myDelay.callback = callback;
}

void loop()
{
    myDelay.refresh();
    motor.refresh();
}
