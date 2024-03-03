# Winds of Change

![Compile Examples](https://github.com/sa-fx/WindsOfChange/actions/workflows/compile-examples.yml/badge.svg)
![Arduino Lint](https://github.com/sa-fx/WindsOfChange/actions/workflows/lint.yml/badge.svg)

This library is designed to interface with the Winds of Change wind turbines for monitoring and control.

### Dependencies
- [SD](https://github.com/arduino-libraries/SD)
- [OneWire: v2.3.0](https://github.com/PaulStoffregen/OneWire) 

### Contribution
To add an additional sensor:
- Create a new pair of `.cpp/.h` files with your sensor's name (eg `sensor_name.cpp`, `sensor_name.h`) in `src`, following the style of previously implemented sensors
- Implement the driver code required for your sensor
- Add `#include "sensor_name.h"` to `WindsOfChange.h`

After compilation, the sensor should be ready for use

### References
With thanks for sample code:
- https://forum.arduino.cc/t/reading-a-pwm-signal/603967/5
- https://learn.parallax.com/KickStart
- https://www.dfrobot.com/product-689.html