#include "humidity.h"

namespace WindsOfChange {

Humidity::Humidity(int pin) : pin_(pin) {}
int Humidity::read() { return analogRead(pin_); }

}  // namespace WindsOfChange