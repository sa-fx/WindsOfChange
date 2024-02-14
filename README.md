# Winds of Change

This code is designed to interface with the Winds of Change wind turbines for monitoring and control.

### Dependencies
Compilation is achieved with either the [Arduino IDE](https://www.arduino.cc/en/software) or [Arduino CLI](https://github.com/arduino/arduino-cli). Target board: TBD

The following libraries are required:
- [SD](https://github.com/arduino-libraries/SD)
- [OneWire](https://github.com/PaulStoffregen/OneWire) 

### Contribution
To add an additional sensor:
- Create a new pair of .cpp/.hpp files with your sensor's name (eg `sensor_name.cpp`, `sensor_name.hpp`)
- Use the templates shown below for these files
- Implement the driver code required for your sensor
- Add `#include "sensor_name.hpp"` to winds_of_change.hpp
- Instantiate your new sensor in `WindsOfChange.ino`

After compilation, the sensor should be ready for use

### References
With thanks for sample code:
- https://forum.arduino.cc/t/reading-a-pwm-signal/603967/5
- https://learn.parallax.com/KickStart
- https://www.dfrobot.com/product-689.html