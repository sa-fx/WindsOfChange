#pragma once

#include "WindsOfChange.h"

namespace WindsOfChange {
class StrainGauge {
 public:
  StrainGauge(int pin);

  /**
   * @brief Read the current strain on the strain gauge
   * @returns Integer value of gauge's strain (units unknown)
   */
  // TODOLater - Determine units of sensor output
  int read();

 private:
  int pin_;
};

}  // namespace WindsOfChange
