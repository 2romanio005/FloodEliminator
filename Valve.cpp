#include "Main.h"

Valve::Valve(const uint8_t dPinValve, const uint8_t dPinLedOn, const uint8_t dPinLedOff, const uint16_t eepromCell): dPinValve(dPinValve), dPinLedOn(dPinLedOn), dPinLedOff(dPinLedOff), eepromCell(eepromCell) {
  pinMode(this->dPinValve, OUTPUT);
  pinMode(this->dPinLedOn, OUTPUT);
  pinMode(this->dPinLedOff, OUTPUT);
  
  this->valveStatus = eeprom_read_byte(this->eepromCell);
}

void Valve::handler() {
  digitalWrite(this->dPinValve, this->valveStatus ^ NORMAL_OPEN);

  digitalWrite(this->dPinLedOn, valveStatus);
  digitalWrite(this->dPinLedOff, !valveStatus);
}

void Valve::setValveStatus(const bool valveStatus) {
  if (this->valveStatus != valveStatus) {
    this->changeValveStatus();
  }
}

bool Valve::changeValveStatus() {
  this->valveStatus = !this->valveStatus;
  eeprom_write_byte(this->eepromCell, uint8_t(this->valveStatus) * MAX_BYTE);
  //this->flagChangingStatus = true;
  return this->valveStatus;
}

bool Valve::getValveStatus() {
  return this->valveStatus;
}
