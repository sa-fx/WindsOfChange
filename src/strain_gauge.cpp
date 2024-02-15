#include "strain_gauge.h"

StrainGauge::StrainGauge(int pin) : pin_(pin) {}
int StrainGauge::read() { return analogRead(pin_); }
