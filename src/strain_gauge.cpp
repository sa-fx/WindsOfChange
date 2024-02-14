#include "strain_gauge.h"

namespace WindsOfChange {

StrainGauge::StrainGauge(int pin) : pin_(pin) {}
int StrainGauge::read() { return analogRead(pin_); }

}  // namespace WindsOfChange
