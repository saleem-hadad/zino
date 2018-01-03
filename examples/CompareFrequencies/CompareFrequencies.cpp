#include <Arduino.h>
#include <Pin.h>
#include <LED.h>
#include <GPIO.h>

Pin ledPin = Pin(PortB, 0);
LED led;

void setup()
{
    led.init(ledPin);

    while(1)
    {
        // freq. ~= 147 Khz
        digitalWrite(8, 1);
        digitalWrite(8, 0);

        // freq. ~= 200 Khz
        led.toggle();

        // freq. ~= 440 Khz
        GPIO::write(ledPin, 1);
        GPIO::write(ledPin, 0);
    }
}

void loop(){}
