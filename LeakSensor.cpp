#include "Main.h"

LeakSensor::LeakSensor(const uint8_t dPinSensor, const uint8_t dPinLed, const uint16_t eepromCell): dPinSensor(dPinSensor), dPinLed(dPinLed), eepromCell(eepromCell) {
  pinMode(this->dPinSensor, INPUT_PULLUP);
  pinMode(this->dPinLed, OUTPUT);
  this->setSensorStatus(eeprom_read_byte(this->eepromCell));
}

bool LeakSensor::handler() {
  if (this->getSensorValue() && !this->sensorStatus) {
    if (!this->flagChangingStatus) {
      this->flagChangingStatus = true;
      this->timerChangingStatus = millis();
    }
    if (millis() - this->timerChangingStatus >= TIMER_DURATION_OF_LEAK_SENSOR) {
      this->setSensorStatus(true);
      this->flagChangingStatus = false;
    }
  } else {
    flagChangingStatus = false;
  }
  
  digitalWrite(this->dPinLed, this->sensorStatus);
  return this->sensorStatus;
}

bool LeakSensor::setSensorStatus(const bool sensorStatus) {
  eeprom_update_byte(this->eepromCell, uint8_t(sensorStatus) * MAX_BYTE);
  return this->sensorStatus = sensorStatus;
}

bool LeakSensor::resetSensorStatus() {
  if (!this->getSensorValue()) {
    this->setSensorStatus(false);
  }
  return this->sensorStatus;
}


bool LeakSensor::getSensorValue() {
  return !digitalRead(this->dPinSensor);
}
