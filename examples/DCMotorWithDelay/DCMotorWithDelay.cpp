#include <Arduino.h>
#include <DCMotor.h>
#include <Pin.h>
#include <Delay.h>

Delay myDelay(1000);
DCMotor motor;
double dutyCycle = 0;

void callback()
{
    motor.setDutyCycle(dutyCycle);
    dutyCycle += 0.1; // Increase the dutyCycle by 0.1 each 1s
    if(dutyCycle > 1) dutyCycle = 0;
}

void setup()
{
    motor.init(Pin(PortB, 4), 150);
    motor.setDutyCycle(0);

    myDelay.callback = callback;
}

void loop()
{
    myDelay.refresh();
    motor.refresh();
}
