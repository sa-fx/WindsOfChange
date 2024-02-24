#include "power_meter.h"

PowerMeter::PowerMeter(uint8_t device_address = 0x01, int pin_de, int pin_re)
    : device_address_(device_address), pin_de_(pin_de), pin_re_(pin_re) {
  node.begin(device_address_, Serial);
  pinMode(pin_re_, OUTPUT);
  pinMode(pin_de_, OUTPUT);
  digitalWrite(pin_re_, 0);
  digitalWrite(pin_de_, 0);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
  // TODOLater - Determine if this is needed
  // changeAddress(0XF8, 0x01);
}

PowerMeter::~PowerMeter() {}

uint32_t PowerMeter::getVoltage() {
  uint8_t result = node.readInputRegisters(kRegisterVOltage, 1);
  if (result == node.ku8MBSuccess) {
    // Divide by 10, as per manual
    return (node.getResponseBuffer(kRegisterVOltage)) / 10;
  } else {
    return 0xFFFFFFFF;
  }
}

uint32_t PowerMeter::getCurrent() {
  uint8_t result = node.readInputRegisters(kRegisterCurrentLo, 2);
  if (result == node.ku8MBSuccess) {
    // Combine both halves of value and divide by 1000, as per manual
    return ((node.getResponseBuffer(kRegisterCurrentHi) << 16) +
            node.getResponseBuffer(kRegisterCurrentLo)) /
           1000;
  } else {
    return 0xFFFFFFFF;
  }
}

uint32_t PowerMeter::getPower() {
  uint8_t result = node.readInputRegisters(kRegisterPowerLo, 2);
  if (result == node.ku8MBSuccess) {
    // Combine both halves of value and divide by 10, as per manual
    return ((node.getResponseBuffer(kRegisterPowerHi) << 16) +
            node.getResponseBuffer(kRegisterPowerLo)) /
           10;
  } else {
    return 0xFFFFFFFF;
  }
}

uint32_t PowerMeter::getEnergy() {
  uint8_t result = node.readInputRegisters(kRegisterEnergyLo, 2);
  if (result == node.ku8MBSuccess) {
    // Combine both halves of value
    return (node.getResponseBuffer(kRegisterEnergyHi) << 16) +
           node.getResponseBuffer(kRegisterEnergyLo);
  } else {
    return 0xFFFFFFFF;
  }
}

uint32_t PowerMeter::getFrequency() {
  uint8_t result = node.readInputRegisters(kRegisterFrequency, 1);
  if (result == node.ku8MBSuccess) {
    // Divide by 10, as per manual
    return (node.getResponseBuffer(kRegisterFrequency)) / 10;
  } else {
    return 0xFFFFFFFF;
  }
}

uint32_t PowerMeter::getPowerFactor() {
  uint8_t result = node.readInputRegisters(kRegisterPowerFactor, 1);
  if (result == node.ku8MBSuccess) {
    // Divide by 10, as per manual
    return (node.getResponseBuffer(kRegisterPowerFactor)) / 100;
  } else {
    return 0xFFFFFFFF;
  }
}

uint32_t PowerMeter::getAlarmStatus() {
  uint8_t result = node.readInputRegisters(kRegisterVOltage, 1);
  if (result == node.ku8MBSuccess) {
    return node.getResponseBuffer(kRegisterVOltage);
  } else {
    return 0x0001;
  }
}

void PowerMeter::preTransmission() {
  digitalWrite(pin_re, HIGH);
  digitalWrite(pin_de, HIGH);
  delay(1);
}

void PowerMeter::postTransmission() {
  digitalWrite(pin_re, LOW);
  digitalWrite(pin_de, LOW);
  delay(1);
}