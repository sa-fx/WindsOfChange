#ifndef _ALTIMETER_H_
#define _ALTIMETER_H_

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
};

#endif
