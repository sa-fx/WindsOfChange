#ifndef _PRECIPITATION_H_
#define _PRECIPITATION_H_

#include "WindsOfChange.h"

const int kDigitalDisconnected = 999;

class Precipitation {
 public:
  // If digital pin not specified for use, default to impossible value
  Precipitation(int pin_analog, int pin_digital = kDigitalDisconnected);

  /**
   * @brief Read the current amount of rain on the sensor
   * @returns Integer value of sensor's dampness (units unknown)
   */
  // TODOLater - Determine units of sensor output
  int readAnalog();

  /**
   * @brief Read if the dampness of the sensor has passed a hardware-defined
   * threshold
   * @returns true if too damp; false otherwise
   */
  bool readDigital();

 private:
  int pin_analog_;
  int pin_digital_;
};

#endif
