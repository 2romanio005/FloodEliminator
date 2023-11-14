#include "Main.h"

LeakSensor::LeakSensor(const uint8_t dPidSensor, const uint8_t dPidLed, const uint16_t eepromCell): dPidSensor(dPidSensor), dPidLed(dPidLed), eepromCell(eepromCell){
  pinMode(this->dPidSensor, INPUT_PULLUP);
  pinMode(this->dPidLed, OUTPUT);
  this->setSensorStatus(eeprom_read_byte(this->eepromCell));
}

bool LeakSensor::handler(){
  if(digitalRead(this->dPidSensor) && !this->sensorStatus){
    this->setSensorStatus(true);
  }
  return this->sensorStatus;
}

bool LeakSensor::setSensorStatus(const bool sensorStatus){
  eeprom_update_byte(this->eepromCell, uint8_t(sensorStatus) * MaxByte);
  digitalWrite(this->dPidLed, this->sensorStatus = sensorStatus);
  return this->sensorStatus;
}
