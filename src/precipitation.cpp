#include "precipitation.h"

namespace WindsOfChange {

Precipitation::Precipitation(int pin_analog, int pin_digital)
    : pin_analog_(pin_analog), pin_digital_(pin_digital) {}

int Precipitation::readAnalog() { return analogRead(pin_analog_); }

// Implemented assuming analogue is the preferred means of reading precipitation
// TODOLater - Confirm if digital is preferred over analogue
bool Precipitation::readDigital() {
  if (pin_digital_ == kDigitalDisconnected) {
    log("Warning: Precipitation digital pin not connected. Returning false");
    return false;
  } else {
    return digitalRead(pin_digital_);
  }
}

}  // namespace WindsOfChange