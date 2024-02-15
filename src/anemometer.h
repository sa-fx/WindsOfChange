#ifndef _ANEMOMETER_H_
#define _ANEMOMETER_H_

#include "WindsOfChange.h"

class Anemometer {
 public:
  Anemometer(int pin);

  /**
   * @brief Read the current wind speed
   * @returns Integer value of wind speed (units unknown)
   */
  // TODOLater - Determine units of sensor output
  int read();

 private:
  int pin_;
};

#endif
