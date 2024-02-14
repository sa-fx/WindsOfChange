#pragma once

#include "WindsOfChange.h"

namespace WindsOfChange {
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

}  // namespace WindsOfChange
