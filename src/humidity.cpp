#include "humidity.h"

Humidity::Humidity(int pin) : pin_(pin) {}
int Humidity::read() { return analogRead(pin_); }
