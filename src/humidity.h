#ifndef _HUMIDITY_H_
#define _HUMIDITY_H_

#include "WindsOfChange.h"

class Humidity {
 public:
  Humidity(int pin);

  /**
   * @brief Read the current humidity
   * @returns Integer value of humidity (units unknown)
   */
  // TODOLater - Determine units of sensor output
  int read();

 private:
  int pin_;
};

#endif
