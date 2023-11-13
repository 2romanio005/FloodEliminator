#include "Main.h"

LeakSensor::LeakSensor(const uint8_t dPidSensor, const uint8_t dPidLed, const uint16_t eepromCell): dPidSensor(dPidSensor), dPidLed(dPidLed), eepromCell(eepromCell){
  pinMode(this->dPidSensor, INPUT_PULLUP);
  pinMode(this->dPidLed, OUTPUT);
  this->setFlagStatus(eeprom_read_byte(this->eepromCell));
}

bool LeakSensor::handler(){
  if(digitalRead(this->dPidSensor)){
    this->setFlagStatus(true);
  }
  return this->flagStatus;
}

bool LeakSensor::setFlagStatus(bool flagStatus){
  eeprom_update_byte(this->eepromCell, uint8_t(flagStatus) * MaxByte);
  digitalWrite(this->dPidLed, this->flagStatus = flagStatus);
  return this->flagStatus;
}
