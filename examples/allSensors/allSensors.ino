/**
 * allSensors.ino
 * Example showing all sensors implemented in current revision in a single file
 * Author: S Alexander
 * Last Updated: 14/02/2024
 */

#include <WindsOfChange.h>

using namespace WindsOfChange;

// Analogue pins connected to analogue read sensors
const int PIN_SD_CHIP_SELECT = 4;
const int PIN_TEMPERATURE = 5;
const int PIN_STRAIN_GAUGE = A0;
const int PIN_HUMIDITY = A1;
const int PIN_PRECIPITATION = A2;
const int PIN_ANEMOMETER = 6;

Altimeter altimeter();
Anemometer anemometer(PIN_ANEMOMETER);
Humidity humidity(PIN_HUMIDITY);
Precipitation precipitation(PIN_PRECIPITATION);
StrainGauge strain_gauge(PIN_STRAIN_GAUGE);
Temperature temperature(PIN_TEMPERATURE);

void setup() {
  Serial.begin(9600);
  if (!SD.begin(PIN_SD_CHIP_SELECT)) {
    Serial.println("Card failed, or not present");
    while (1)
      ;
  }

  pinMode(PIN_ANEMOMETER, INPUT);
  pinMode(PIN_TEMPERATURE, INPUT);
  pinMode(PIN_STRAIN_GAUGE, INPUT);
  pinMode(PIN_HUMIDITY, INPUT);
  pinMode(PIN_PRECIPITATION, INPUT);
}

void loop() {
  float result = temperature.read();
  String message = String(result);
  log(message);
}
