#include "solenoid.h"

Solenoid::Solenoid(int pin) : pin_(pin) { plunger_state_ = kRetracted; }

Solenoid::~Solenoid() {
  // Retract solenoid upon destruction
  retract();
}

void Solenoid::setDutyCycle(int duty_cycle) { duty_cycle_ = duty_cycle; }

void Solenoid::extend() {
  if (plunger_state_ != kExtended) {
    analogWrite(pin_, duty_cycle_);
    plunger_state_ = kExtended;
  }
}

void Solenoid::retract() {
  if (plunger_state_ != kRetracted) {
    // TODOLater - implement actuating solenoid
    plunger_state_ = kRetracted;
  }
}

bool Solenoid::getSolenoidStatus() { return (bool)plunger_state_; }
