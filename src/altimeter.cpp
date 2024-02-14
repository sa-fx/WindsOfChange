#include "altimeter.h"

namespace WindsOfChange {
Altimeter::Altimeter() {
  sensor = new Intersema::BaroPressure_MS5607B();
  sensor->init();
}

// TODOLater - Confirm if this is what we want the sensor to read
float Altimeter::read() { return sensor->getHeightCentiMeters(); };
}  // namespace WindsOfChange