![zino](https://github.com/saleem-hadad/zino/blob/master/assets/logo.png)

# 𝓩ino ♥️

Custom C++ based Arduino library provides a convenient and fast way for developing embedded systems projects.

## Getting Started

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/GPIO.png" alt="Zino GPIO class"/>
<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Pin.png" alt="Zino Pin class"/>
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

> If you are using Atom/VSCode with Platform IO you have **two ways**

1: Create a new project, then add this line to ```platformio.ini``` file

```
lib_deps = https://github.com/saleem-hadad/zino/archive/master.zip
```

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/installing.git" alt="Zino installing process"/>

2: Create a new project then [Download the library](https://github.com/saleem-hadad/zino/archive/master.zip) and extract the files into the ```lib``` folder.

> If you are using Arduino IDE*

1. [Download the library](https://github.com/saleem-hadad/zino/archive/master.zip)
2. navigate to Arduino IDE > click on ```sketch``` > ```include Library``` > add .Zip library then add the ```zino-master.zip```

*I did NOT test the library on the Arduino IDE, so please notify me if you get any warning/error!


## Running the examples

Navigate to the examples folder, copy the code of your fav. one and paste it in ```scr/main.cpp```, then upload it, that's it 🤓

## Author(s)

* **Saleem Hadad** - *Binary Torch* - [saleem-hadad](https://github.com/saleem-hadad)

## License

This library is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.
