# Arduino-clock [![Build Status](https://travis-ci.org/omar-bb/Arduino-clock.svg?branch=master)](https://travis-ci.org/github/omar-bb/Arduino-clock)

An arduino clock with a 16x64 matrix and a DS3231 For Pi

## Getting Started

Clone the project whith typing this command on your terminal it will copy the project on your local machine

```
$ git clone https://github.com/omar-bb/Arduino-clock.git
```

### Prerequisites

To compile and upload the code on to the arduino you have to install the platform io extension

* PlatformIO Visual Studio Code :
    - https://platformio.org/install/ide?install=vscode

    <hr>

* PlatformIO Atom :
    - https://platformio.org/install/ide?install=atom

## Built With

* ### [Arduino](https://www.arduino.cc/)

<img src="static/Arduino.png" width=50%>

* ### Four (16x16 Matrix)

<img src="static/Matrix.jpg" width=50%>

* ### DS3231 For Pi

<img src="static/DS3231.webp" width=50%>

* ### [PlatformIO](https://platformio.org/)
    - Arduino Platform an alternative for the basic ide 

* ### [RTCLib](https://github.com/adafruit/RTClib)
    - The DS3231 library

### Montage

| Arduino   | 16*16 LED Matrix | DS3231 For Pi |
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

### Uploading sketch

Click on the upload button to upload the sketch into the Arduino

* Upload On Visual Studio Code :

    - <img src="static/Step 1.png">

<hr>

* Upload On Atom :

    - <img src="static/Step 1 (Atom).png">

* If you have a problem uploading your sketch try to specify the upload port it might work

> The following explanation was taken from the official documentation.

<h3>Upload Port</h3>

This option is used by “uploader” tool when sending firmware to board via `upload_port`. For example,

* `/dev/ttyUSB0` - Serial port (Unix-based OS)
* `COM3` - Serial port (Windows OS)
* `192.168.0.13` - IP address when using OTA
* `/media/disk` - physical path to media disk/flash drive (Mbed enabled boards)
* `D:` - physical path to media disk/flash drive (Windows OS).

If `upload_port` isn’t specified, then PlatformIO will try to detect it automatically.

To print all available serial ports please use [platformio device list](https://docs.platformio.org/en/latest/core/userguide/device/cmd_list.html#cmd-device-list) command.

This option can also be set by global environment variable `PLATFORMIO_UPLOAD_PORT`.

Please note that you can use Unix shell-style wildcards:

```ini
[env:uno]
platform = atmelavr
framework = arduino
; any port that starts with /dev/ttyUSB
upload_port = /dev/ttyUSB*

; COM1 or COM3
upload_port = COM[13]
```

**Make sure that the platform is set to atmelavr and framework is set to arduino**

<h2>Authors</h2>

* **Omar Ben Brahim** - *Initial work*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.