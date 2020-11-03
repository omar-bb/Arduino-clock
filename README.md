# Arduino Clock

[![Build Actions Status](https://github.com/omar-bb/arduino-clock/workflows/build/badge.svg)](https://github.com/omar-bb/arduino-clock/actions)

a digital clock with an arduino, 4 soldered 16x16 led matrix and a DS3231 For Pi

## Table of Contents

- [Requirement](#requirement)
- [Usage](#usage)
	- [Build and upload with PlatformIO Core (CLI)](#build-and-upload-with-platformio-core-cli)
	- [Build and upload with PlatformIO IDE](#build-and-upload-with-platformio-ide)
- [Development](#development)
	- [Developing with PlatformIO Core (CLI)](#developing-with-platformio-core-cli)
	- [Developing with PlatformIO IDE](#developing-with-platformio-ide)
- [Montage](#montage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Requirement

* Operating System:

	- Windows, macOS, Linux, FreeBSD, Linux ARMv6+

* Software requirements:

	- [Python](https://www.python.org/downloads/) (3.5 or greater)

	- PlatformIO Core (CLI) (You can install it with an [Installer Script](https://docs.platformio.org/en/latest/core/installation.html#installer-script) or a [Python Package Manager](https://docs.platformio.org/en/latest/core/installation.html#python-package-manager)) or [PlatformIO IDE](https://platformio.org/install)

	- > **NOTE:** PlatformIO Core provides a rich and documented Command Line Interface (CLI). The other PlatformIO-based software and IDEs are based on PlatformIO Core CLI, such as PlatformIO IDE. In other words, they wrap PlatformIO Core with own GUI.

* Hardware requirements:

	- [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3)

	- 4 soldered [16x16 Dot LED Matrix Display](https://www.elabpeers.com/led-matrix-display.html)

	- [DS3231 Real Time Clock Module for Raspberry Pi](https://www.pishop.us/product/ds3231-real-time-clock-module-for-raspberry-pi/)

## Usage

To get started clone this repository

```
$ git clone https://github.com/omar-bb/arduino-clock.git
```

### Build and upload with PlatformIO Core (CLI)

```bash
# install project dependencies
$ platformio lib install

# Build project and upload firmware to all the devices specified in “platformio.ini”
$ platformio run --target upload

# if you're using an Arduino ISP or any other programmer to program your arduino
# use this following command
$ platformio run --target program
```

### Build and upload with PlatformIO IDE

To build and upload with PlatformIO IDE you just need to click on the upload button

## Development

If you want to contribute to this project here is a quick guide to help you use platformio awesome tools

### Developing with PlatformIO Core (CLI)

Before starting to develop with PlatformIO Core (CLI) it is better to have a virtual environment. See "[Virtual Environment](https://docs.platformio.org/en/latest/core/installation.html#virtual-environment)"

Platformio provides all commands well documented in their official website. See "[CLI Guide](https://docs.platformio.org/en/latest/core/userguide/index.html#cli-guide)"

### Developing with PlatformIO IDE

With PlatformIO IDE installed in your favourite (IDE / Code Editor) you already have a nice gui interface to get started

---

> NOTE: you can do unit tests in the "test" folder see UNITTESTING.md

## Montage

| Arduino   | 16x16 LED Matrix | DS3231 For Pi |
|-----------|------------------|---------------|
| 5V        | +5V              | +5V           |
| GND       | GND              | GND           |
| D5        | A                |               |
| D4        | B                |               |
| D3        | C                |               |
| D2        | D                |               |
| D6        | G                |               |
| D7        | DI               |               |
| D8        | CLK              |               |
| D9        | LAT              |               |
| (I2C) SDA |                  | SDA           |
| (I2C) SCL |                  | SCL           |

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

Distributed under the MIT License. See [LICENSE.md](LICENSE.md) for more information.

## Contact

Omar Ben Brahim - [@omarbb44](https://twitter.com/omarbb44) - omar@ihub-bridge.org
