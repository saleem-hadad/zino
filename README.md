<h6 align="center">
    <img src="https://github.com/saleem-hadad/zino/blob/master/assets/logo.png"/>
</h6>

<p align="center">
<a href="https://travis-ci.org/saleem-hadad/zino"><img src="https://travis-ci.org/saleem-hadad/zino.svg" alt="Build Status"></a>
<a href="https://github.com/saleem-hadad/zino"><img src="https://poser.pugx.org/laravel/framework/license.svg" alt="License"></a>
</p>


# 𝓩ino ♥️

Custom C++ based Arduino library provides a convenient and fast way for developing embedded systems projects.

## Getting Started

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Pin.png" alt="Zino Pin class"/>

The library introduces this new concept of shaping the pin as an object which has a port address and pin number.

The **Pin** class used in many different other classes to handle the process of assigning the pin either ```Output```, ```Input``` or ```InputWithPullUp``` resister.

The reason for using Pin class instead of the pin number as Arduino library uses is first for educational purpose where the students can get a clue of the register concept and also to make the code very clean and organised. However, the library also supports the pin number method if you still like it!

```c
#include <Pin.h>

Pin redLedPin(PortB, 0);            // portName: PortB, pinNumber: 0 // same as digital pin 8
Pin greenLedPin(PortD, 1);          // portName: PortD, pinNumber: 1 // same as digital pin 1
Pin temperatureSensorPin(PortC, 4); // portName: PortC, pinNumber: 4 // same as analog pin A4
```

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/GPIO.png" alt="Zino GPIO class"/>

The library has its own ```GPIO``` wrapper(class) to use, which is much more faster than the Arduino library. [See the comparison](https://github.com/saleem-hadad/zino/blob/master/examples/CompareFrequencies/CompareFrequencies.cpp).

Working with I/O using ```GPIO``` class is pretty straightforward! Here some examples:

```c
// Blinking LED on and off without delay.
#include <GPIO.h>
#include <Pin.h>

Pin redLedPin(PortB, 0);

void setup()
{
    GPIO::setup(redLedPin, Output); // You can choose Output, Input or InputWithPullUp
}

void loop()
{
    GPIO::high(redLedPin);      // Turn on the LED
    GPIO::low(redLedPin);       // Turn off the LED
    //or
    GPIO::write(redLedPin, 1);  // Turn on the LED
    GPIO::write(redLedPin, 0);  // Turn off the LED
}
```

```c
// Reading analog input from PortC, pin number 4 and print the result to the serial.
#include <Arduino.h>
#include <GPIO.h>
#include <Pin.h>

Pin temperatureSensorPin(PortC, 4);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // For analog reading you don't have to call GPIO::setup method :)
    int temperature = GPIO::read(temperatureSensorPin);
    Serial.println(temperature);
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/button.png" alt="Zino Button class"/>

The library solves some of the common issue when working with push buttons, like edge detection and bouncing problem.

The class ```Button``` provides very easy way to handle physical actions like button pressed, or long press(in development), here an example:

```c
// Print "Button has been pressed 🤠" to the serial when the button pressed.
#include <Arduino.h>
#include <Button.h>
#include <Pin.h>

Button button;

void buttonPressed()
{
    Serial.println("Button has been pressed 🤠");
}

void setup()
{
    Serial.begin(9600);

    // The 1st parameter: the pin connected with the button
    // The 2nd parameter: the debouncing period [35-40 ms is recommended]
    // The 3rd parameter: true or false [default logic is high?]
    // The 4th parameter: true or false [with internal Pull Up?]
    button.init(Pin(PortB, 5), 40, false, false);
    button.pressed = buttonPressed; // set the handler
}

void loop()
{
    button.refresh(); // important
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/LED.png" alt="Zino LED class"/>

LEDs are the fun things to play with 🤓, for that, the ```LED``` class handles some cool features that you might need to control the LEDs very easily.

```c
#include <Arduino.h>
#include <Pin.h>
#include <LED.h>

Pin ledPin(PortB, 4); // same as digital pin 12
LED led;

void setup()
{
    led.init(ledPin);
}

void loop()
{
    led.on();
    led.off();
    // or
    led.toggle();
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Blinky.png" alt="Zino Blinky class"/>

The ```Blinky``` class provides an easy way for blinking(flashing) LEDs, generating a square wave or controlling DC motors.. etc.

Here is an example of how to use it in your applications:

```c
/*
    Blinking an LED connected to PortB on pin 0 (same as digital pin 8)
    for a period of 1000ms on and 100ms off, without using the delay
    Arduino library's function, and without affecting other codes
*/
#include <Arduino.h>
#include <Blinky.h>
#include <Pin.h>

Blinky led;

void setup()
{
    led.init(Pin(PortB, 0), 1000, 100); // (pin, onTime, offTime)
}

void loop()
{
    led.refresh();
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/DCMotor.png" alt="Zino DCMotor class"/>

(*This class still in development*)

Controlling DC Motors needs a lot of hardware and software configurations to be handled. However, ```DCMotor``` class provides a convenient way of controlling the DC motors by generating a software PWM signal on any digital pin and not only the timers ones (with [~] label), which means you can control the dc motor by any digital pin 😎

```c
#include <Arduino.h>
#include <DCMotor.h>
#include <Pin.h>

DCMotor motor;

void setup()
{
    motor.init(Pin(PortB, 4), 200); // provide the pin and frequency(in hz) needed
    motor.setDutyCycle(0.5);        // control the speed by adjusting the dutyCycle between 0.0 and 1.0
}

void loop()
{
    motor.refresh();
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Delay.png" alt="Zino Delay class"/>

Most probably you came across this issue when you deal with the delay function that Arduino library provides, which halts the CPU for specific period in ms. However, you might need to perform an action with delay without delaying the whole process. For example, you might need to send a message to the serial port every 1s without affecting other functionalities! for that, the Zino library provides an alternative way for using the delay function, here is an example:

```c
#include <Arduino.h>
#include <Delay.h>

Delay myDelay;       // default duration 1000 ms.
// Delay myDelay(1000); //Other initialization

void callback()
{
    Serial.println("Hello world 🖐"); // print "Hello world 🖐" every 0.5 s
}

void setup()
{
    Serial.begin(9600);
    myDelay.init(500); // duration = 500 ms. (0.5 s)

    myDelay.callback = callback; // set the callback to be notified
}

void loop()
{
    myDelay.refresh();
    //Other stuff goes here
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/AnalogComparator.png" alt="Zino AnalogComparator class"/>


The Atmega328 chip has a built-in analog comparator. That is, it can give a high output when an incoming voltage passes a threshold.

The incoming voltage is on the AIN0 (positive terminal) pin which is pin 12 on the actual chip, and D6 on the Arduino board. The reference voltage (negative terminal) pin is pin 13 on the chip, and D7 on the Arduino.

This is faster than doing an ADC (analog to digital) comparison because it is comparing to a single voltage, not attempting to do a full conversion (which can take almost 104 uS).

You can select the internal bandgab (1.1 v) as the positive terminal (D6) and use the navigate terminal as your input to compare. However, if you don't want to use the internal bandgab, you have to supply the voltage (0-5 v) reference on pin D6.

An example sketch follows:

```c
#include <AnalogComparator.h>

AnalogComparator comparator;

void comparatorCallback(bool aboveThreshold)
{
    /*
        1. if the voltage supplied to pin D7 > D6(either internal bandgab or custom reference): the aboveThreshold value is true
        2. if the voltage supplied to pin D7 < D6(either internal bandgab or custom reference): the aboveThreshold value is false
    */

    // your logic goes here
}

void setup()
{
    comparator.init(true, true); // enabled, bandgabSelected
    comparator.callback = comparatorCallback; // important
}

void loop()
{
    comparator.refresh();
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Ultrasonic.png" alt="Zino Ultrasonic class"/>

👉 *Theoretical informations*

Ultrasonic is an adjective referring to ultrasound.
Ultrasound and ultrasonic may also refer to: Medical ultrasonography, an ultrasound-based diagnostic imaging technique. Ultrasound (band), a rock band.

Working principal:

1. Trig send the Ping signal to the sensor so that the sensor start giving the pulse to measure the distance.
2. Echo get the reflection of the ultrasonic wave.
3. As long as reflection signal is High it means there is an object.

👉 *Technical informations*

The Zino library encapsulates the essential methods needed to measure the distance from an ultrasonic sensor in the ```Ultrasonic``` class, all you have to do is to call the ```sense``` method which will return back the measured distance according to the subjected ```MeasurementUnit```, which is by default in cm.

An example sketch follows:

```c
#include <Ultrasonic.h>
#include <Pin.h>

Pin trig(PortB, 3);
Pin echo(PortB, 4);

Ultrasonic ultrasonic;

void setup()
{
    Serial.begin(9600);
    ultrasonic.init(trig, echo);
}

void loop()
{
    Serial.println( ultrasonic.sense() );
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/PowerManager.png" alt="Zino PowerManager class"/>

The ```PowerManager``` class used to reduce the power consumption by the Arduino chip, *[please refer to this article to understand the Arduino power management before you use this class](https://playground.arduino.cc/Learning/ArduinoSleepCode)*. There are two static methods available:

1. ```sleep```:
    + Turning off ADC
    + Turning off Analog Comparator
    + Sleep with power-down mode
2. ```deepSleep```:
    + BOD disabled
    + BOD sleep enable
    + Turning off ADC
    + Turning off Analog Comparator
    + Sleep with power-down mode

An example sketch follows:

```c
#include <Arduino.h>
#include <PowerManager.h>

void setup()
{
    PowerManager::sleep();
    // or
    PowerManager::deepSleep();
}

void loop()
{
    //
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

## Development

### Future implementation and classes

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/future.png" alt="Zino Future process"/>

### Supported Boards

+ UNO

### Prerequisites

It's highly recommended to avoid using Arduino IDE, instead, use [Atom](https://atom.io/) or [VSCode](https://code.visualstudio.com/) text-editor with [Platform IO](http://platformio.org/platformio-ide) for a better development environment.

### Installing

#### If you are using Atom/VSCode with Platform IO you have **two ways**

1. First way (recommended ✌️)

Create a new project, then add this line to ```platformio.ini``` file

```
lib_deps = https://github.com/saleem-hadad/zino/archive/master.zip
```

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/installing.gif" alt="Zino installing process"/>

2. Second way

Create a new project then [Download the library](https://github.com/saleem-hadad/zino/archive/master.zip) and extract the files into the ```lib``` folder.

#### If you are using Arduino IDE*

1. [Download the library](https://github.com/saleem-hadad/zino/archive/master.zip)
2. navigate to Arduino IDE > click on ```sketch``` > ```include Library``` > add .Zip library then add the ```zino-master.zip```

*I did NOT test the library on the Arduino IDE, so please notify me if you get any warning/error!


## Running the examples

Navigate to the examples folder, copy the code of your fav. one and paste it in ```scr/main.cpp```, then upload it, that's it 🤓

## Author(s)

* [saleem-hadad](https://github.com/saleem-hadad) - *Binary Torch*

See also the list of [contributors](https://github.com/saleem-hadad/zino/contributors) who participated in this project.


## License

This library is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.
