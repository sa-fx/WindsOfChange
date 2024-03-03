#ifndef _WINDSOFCHANGE_H_
#define _WINDSOFCHANGE_H_

#include <SD.h>
#include <SPI.h>

#include "Arduino.h"
#include "altimeter.h"
#include "anemometer.h"
#include "humidity.h"
#include "precipitation.h"
#include "solenoid.h"
#include "strain_gauge.h"
#include "temperature.h"

namespace WindsOfChange {

/**
 * Save a string as a log to file on an SD card
 * @param message   The string to be saved to the SD card
 */
void log(String message);

}  // namespace WindsOfChange

#endif
