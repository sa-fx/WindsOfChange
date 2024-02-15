#include "altimeter.h"

Altimeter::Altimeter() {
  Wire.begin();
  // Reset registers
  Wire.beginTransmission(kAltimeterDeviceAddress);
  Wire.write(kAltimeterCommandReset);
  Wire.endTransmission();
}

float Altimeter::read() { return 0.0; };
