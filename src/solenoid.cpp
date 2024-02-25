#include "solenoid.h"

Solenoid::Solenoid(int pin) : pin_(pin) { plunger_state_ = kRetracted; }

Solenoid::~Solenoid() {
  // Retract solenoid upon destruction
  retract();
}

void Solenoid::extend() {
  if (plunger_state_ != kExtended) {
    // TODOLater - implement actuating solenoid
    plunger_state_ = kExtended;
  }
}

void Solenoid::retract() {
  if (plunger_state_ != kRetracted) {
    // TODOLater - implement actuating solenoid
    plunger_state_ = kRetracted;
  }
}
