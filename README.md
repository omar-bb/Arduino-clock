| Build Status                                                                                                                              |
|-------------------------------------------------------------------------------------------------------------------------------------------|
| [![Build Status](https://travis-ci.org/omar-bb/Arduino-clock.svg?branch=master)](https://travis-ci.org/github/omar-bb/Arduino-clock)      |

# Arduino-clock

An arduino clock with a 16x64 matrix and a DS3231 For Pi

---

## Installation

To get started clone this repo or download zip and extract on your local machine. To clone using git

```
$ git clone https://github.com/omar-bb/Arduino-clock.git
```

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