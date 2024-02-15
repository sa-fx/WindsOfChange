#ifndef _ALTIMETER_H_
#define _ALTIMETER_H_

#include <Wire.h>

#include "WindsOfChange.h"

class Altimeter {
 public:
  Altimeter();

  /**
   * @brief Read the current height of the sensor
   * @returns Float representing height in centimetres
   */
  float read();

 private:
  const byte kAltimeterDeviceAddress = 0x76;
  const byte kAltimeterCommandReset = 0x1E;    // ADC reset command
  const byte kAltimeterCommandAdcRead = 0x00;  // ADC read command
  const byte kAltimeterCommandAdcConv = 0x40;  // ADC conversion command
  const byte kAltimeterCommandAdcD1 = 0x00;    // ADC D1 conversion
  const byte kAltimeterCommandAdcD2 = 0x10;    // ADC D2 conversion
  const byte kAltimeterCommandAdc256 = 0x00;   // ADC OSR=256
  const byte kAltimeterCommandAdc512 = 0x02;   // ADC OSR=512
  const byte kAltimeterCommandAdc1024 = 0x04;  // ADC OSR=1024
  const byte kAltimeterCommandAdc2048 = 0x06;  // ADC OSR=2048
  const byte kAltimeterCommandAdc4096 = 0x08;  // ADC OSR=4096
  const byte kAltimeterCommandPromRd = 0xA0;   // PROM read command

  byte calibrationCoefficient[8];
};

#endif
