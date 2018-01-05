![zino](https://github.com/saleem-hadad/zino/blob/master/assets/logo.png)

# 𝓩ino ♥️

Custom C++ based Arduino library provides a convenient and fast way for developing embedded systems projects.

## Getting Started

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Pin.png" alt="Zino Pin class"/>

The library introduces this new concept of shaping the pin as an object which has a port address and pin number.

The **Pin** class used in many different other classes to handle the process of assigning the pin either ```Output```, ```Input``` or ```InputWithPullUp``` resister. 

The reason for using Pin class instead of the pin number as Arduino library uses is first for educational purpose where the students can get a clue of the register concept and also to make the code very clean and organised.

```c
#include <Pin.h>

Pin redLedPin(PortB, 0);            // portName: PortB, pinNumber: 0 // same as digital pin 8
Pin greenLedPin(PortD, 1);          // portName: PortD, pinNumber: 1 // same as digital pin 1
Pin temperatureSensorPin(PortC, 4); // portName: PortC, pinNumber: 4 // same as analog pin A4
```

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/GPIO.png" alt="Zino GPIO class"/>
<img src="https://github.com/saleem-hadad/zino/blob/master/assets/button.png" alt="Zino Button class"/>
<img src="https://github.com/saleem-hadad/zino/blob/master/assets/LED.png" alt="Zino LED class"/>
<img src="https://github.com/saleem-hadad/zino/blob/master/assets/DCMotor.png" alt="Zino DCMotor class"/>
<img src="https://github.com/saleem-hadad/zino/blob/master/assets/AnalogComparator.png" alt="Zino AnalogComparator class"/>
<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Delay.png" alt="Zino Delay class"/>
<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Blinky.png" alt="Zino Blinky class"/>

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

* **Saleem Hadad** - *Binary Torch* - [saleem-hadad](https://github.com/saleem-hadad)

## License

This library is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.
