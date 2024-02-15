#include "temperature.h"

Temperature::Temperature(int pin) : pin_(pin) {
  wire = new OneWire(pin_);
  // TODOLater - Add debug log to confirm creation
};

// Based on manufacturer's example code
float Temperature::read() {
  byte data[12];
  byte addr[8];

  if (!wire->search(addr)) {
    // no more sensors on chain, reset search
    wire->reset_search();
    return -1000;
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if (addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Device is not recognized");
    return -1000;
  }

  wire->reset();
  wire->select(addr);
  wire->write(0x44, 1);  // start conversion, with parasite power on at the end

  byte present = wire->reset();
  wire->select(addr);
  wire->write(0xBE);  // Read Scratchpad

  for (int i = 0; i < 9; i++) {  // we need 9 bytes
    data[i] = wire->read();
  }

  wire->reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB);  // using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;
};
