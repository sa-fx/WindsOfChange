#pragma once

#include "WindsOfChange.h"

namespace WindsOfChange {
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
}  // namespace WindsOfChange