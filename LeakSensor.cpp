#include "Main.h"

LeakSensor::LeakSensor(const uint8_t dPinSensor, const uint8_t dPinLed, const uint16_t eepromCell): dPinSensor(dPinSensor), dPinLed(dPinLed), eepromCell(eepromCell) {
  pinMode(this->dPinSensor, INPUT_PULLUP);
  pinMode(this->dPinLed, OUTPUT);
  this->setSensorStatus(eeprom_read_byte(this->eepromCell));
}

bool LeakSensor::handler() {
  if (digitalRead(this->dPinSensor) && !this->sensorStatus) {
    this->setSensorStatus(true);
  }
  digitalWrite(this->dPinLed, this->sensorStatus);
//  Serial.print(this->dPinSensor);
//  Serial.print('\t');
//  Serial.println(this->sensorStatus);
  return this->sensorStatus;
}

bool LeakSensor::setSensorStatus(const bool sensorStatus) {
  eeprom_update_byte(this->eepromCell, uint8_t(sensorStatus) * MAX_BYTE);
  return this->sensorStatus = sensorStatus;
}
