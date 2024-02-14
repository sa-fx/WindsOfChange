#pragma once

#include "IntersemaBaro.h"
#include "WindsOfChange.h"

namespace WindsOfChange {
class Altimeter {
 public:
  Altimeter();

  /**
   * @brief Read the current height of the sensor
   * @returns Float representing height in centimetres
   */
  float read();

 private:
  Intersema::BaroPressure_MS5607B *sensor;
};

}  // namespace WindsOfChange