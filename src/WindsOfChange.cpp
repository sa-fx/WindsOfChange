#include "WindsOfChange.h"

namespace WindsOfChange {

void log(String message) {
  // Add timestamp: time from last reset
  // Note real time clock (RTC) required for real time
  String log = "[" + String(micros()) + "] ";
  log += message;
  Serial.println(log);

  // Open the file
  // Note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // If the file is available, write to it:
  if (dataFile) {
    dataFile.println(log);
    dataFile.close();
    Serial.println(log);
  } else {
    Serial.println("error opening datalog.txt");
  }
}
}  // namespace WindsOfChange
