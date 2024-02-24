#include "power_meter.h"

// TODOLater - Test with hardware
PowerMeter::PowerMeter(uint8_t device_address, int pin_de, int pin_re)
    : device_address_(device_address), pin_de_(pin_de), pin_re_(pin_re) {
  node_.begin(device_address_, Serial);
  pinMode(pin_re_, OUTPUT);
  pinMode(pin_de_, OUTPUT);
  digitalWrite(pin_re_, 0);
  digitalWrite(pin_de_, 0);
  // TODOLater - Decide if removing this is okay
  //   node_.preTransmission(preTransmission);
  //   node_.postTransmission(postTransmission);
  // TODOLater - Determine if this is needed
  // changeAddress(0XF8, 0x01);
}

PowerMeter::~PowerMeter() {}

// TODOLater - Refactor getters to remove code duplication
uint32_t PowerMeter::getVoltage() {
  uint32_t measurement;
  preTransmission();
  uint8_t result = node_.readInputRegisters(kRegisterVoltage, 1);
  if (result == node_.ku8MBSuccess) {
    // Divide by 10, as per manual
    measurement = (node_.getResponseBuffer(kRegisterVoltage)) / 10;
  } else {
    measurement = 0xFFFFFFFF;
  }
  postTransmission();
  return measurement;
}

uint32_t PowerMeter::getCurrent() {
  uint32_t measurement;
  preTransmission();
  uint8_t result = node_.readInputRegisters(kRegisterCurrentLo, 2);
  if (result == node_.ku8MBSuccess) {
    // Combine both halves of value and divide by 1000, as per manual
    measurement = ((node_.getResponseBuffer(kRegisterCurrentHi) << 16) +
                   node_.getResponseBuffer(kRegisterCurrentLo)) /
                  1000;
  } else {
    measurement = 0xFFFFFFFF;
  }
  postTransmission();
  return measurement;
}

uint32_t PowerMeter::getPower() {
  uint32_t measurement;
  preTransmission();
  uint8_t result = node_.readInputRegisters(kRegisterPowerLo, 2);
  if (result == node_.ku8MBSuccess) {
    // Combine both halves of value and divide by 10, as per manual
    measurement = ((node_.getResponseBuffer(kRegisterPowerHi) << 16) +
                   node_.getResponseBuffer(kRegisterPowerLo)) /
                  10;
  } else {
    measurement = 0xFFFFFFFF;
  }
  postTransmission();
  return measurement;
}

uint32_t PowerMeter::getEnergy() {
  uint32_t measurement;
  preTransmission();
  uint8_t result = node_.readInputRegisters(kRegisterEnergyLo, 2);
  if (result == node_.ku8MBSuccess) {
    // Combine both halves of value
    measurement = (node_.getResponseBuffer(kRegisterEnergyHi) << 16) +
                  node_.getResponseBuffer(kRegisterEnergyLo);
  } else {
    measurement = 0xFFFFFFFF;
  }
  postTransmission();
  return measurement;
}

uint32_t PowerMeter::getFrequency() {
  uint32_t measurement;
  preTransmission();
  uint8_t result = node_.readInputRegisters(kRegisterFrequency, 1);
  if (result == node_.ku8MBSuccess) {
    // Divide by 10, as per manual
    measurement = (node_.getResponseBuffer(kRegisterFrequency)) / 10;
  } else {
    measurement = 0xFFFFFFFF;
  }
  postTransmission();
  return measurement;
}

uint32_t PowerMeter::getPowerFactor() {
  uint32_t measurement;
  preTransmission();
  uint8_t result = node_.readInputRegisters(kRegisterPowerFactor, 1);
  if (result == node_.ku8MBSuccess) {
    // Divide by 10, as per manual
    measurement = (node_.getResponseBuffer(kRegisterPowerFactor)) / 100;
  } else {
    measurement = 0xFFFFFFFF;
  }
  postTransmission();
  return measurement;
}

uint32_t PowerMeter::getAlarmStatus() {
  uint32_t measurement;
  preTransmission();
  uint8_t result = node_.readInputRegisters(kRegisterAlarmStatus, 1);
  if (result == node_.ku8MBSuccess) {
    measurement = node_.getResponseBuffer(kRegisterAlarmStatus);
  } else {
    measurement = 0x0001;
  }
  postTransmission();
  return measurement;
}

void PowerMeter::preTransmission() {
  digitalWrite(pin_re_, HIGH);
  digitalWrite(pin_de_, HIGH);
  delay(1);
}

void PowerMeter::postTransmission() {
  digitalWrite(pin_re_, LOW);
  digitalWrite(pin_de_, LOW);
  delay(1);
}