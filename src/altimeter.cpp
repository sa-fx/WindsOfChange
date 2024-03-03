#include "altimeter.h"

Altimeter::Altimeter(byte device_address) : device_address_(device_address) {
  Wire.begin();
  // Reset registers
  Wire.beginTransmission(device_address_);
  Wire.write(kAltimeterCommandReset);
  Wire.endTransmission();
  // Read all coefficients
  for (int i = 0; i < 8; i++) {
    calibrationCoefficient[i] = readPROM(i);
  }
  // TODOLater - Implement crc4();
}

unsigned long Altimeter::readADC(byte command) {
  Wire.beginTransmission(device_address_);
  Wire.write(command);
  Wire.endTransmission();
  delay(9);  // ADC conversion time (9 ms for MS5607)
  Wire.beginTransmission(device_address_);
  Wire.write(kAltimeterCommandAdcRead);
  Wire.endTransmission();
  Wire.requestFrom(device_address_, 3);
  return (Wire.read() << 16) | (Wire.read() << 8) | Wire.read();
}

byte Altimeter::readPROM(byte index) {
  Wire.beginTransmission(device_address_);
  Wire.write(kAltimeterCommandPromRd | (index << 1));
  Wire.endTransmission();
  Wire.requestFrom(device_address_, 2);
  // Read MSB, and OR with LSB
  return (Wire.read() << 8) | Wire.read();
}
