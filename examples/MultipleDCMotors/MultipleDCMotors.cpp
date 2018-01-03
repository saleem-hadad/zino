#include <Arduino.h>
#include <DCMotor.h>
#include <Pin.h>

DCMotor motors[4];

void setup()
{
    motors[0].init(Pin(PortB, 4), 150);
    motors[0].setDutyCycle(0.3);

    motors[1].init(Pin(PortB, 3), 150);
    motors[1].setDutyCycle(0.5);

    motors[2].init(Pin(PortB, 2), 150);
    motors[2].setDutyCycle(0.8);

    motors[3].init(Pin(PortB, 1), 150);
    motors[3].setDutyCycle(1);
}

void loop()
{
    motors[0].refresh();
    motors[1].refresh();
    motors[2].refresh();
    motors[3].refresh();
}
