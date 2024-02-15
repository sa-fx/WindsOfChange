#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include <OneWire.h>

#include "WindsOfChange.h"

// Part number: DS18S20
class Temperature {
 public:
  Temperature(int pin);

  /**
   * @brief Reads the current temperature
   * @returns Temperature in Degrees Celsius
   */
  float read();

 private:
  int pin_;
  OneWire *wire;
  // TODOLater - Add constants for registers from datasheet
};

#endif
