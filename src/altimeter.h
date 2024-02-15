#ifndef _ALTIMETER_H_
#define _ALTIMETER_H_

#include "IntersemaBaro.h"
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
  Intersema::BaroPressure_MS5607B *sensor;
};

#endif
