#include "Main.h"

Valve::Valve(const uint8_t dPinValve, const uint8_t dPinLedOn, const uint8_t dPinLedOff): dPinValve(dPinValve), dPinLedOn(dPinLedOn), dPinLedOff(dPinLedOff){
  pinMode(this->dPinValve, OUTPUT);
  pinMode(this->dPinLedOn, OUTPUT);
  pinMode(this->dPinLedOff, OUTPUT);
  this->valveStatus = false;
}

void Valve::handler(){
  digitalWrite(this->dPinValve, this->valveStatus ^ normalClose);

  digitalWrite(this->dPinLedOn, valveStatus);
  digitalWrite(this->dPinLedOff, !valveStatus);
}

void Valve::setValveStatus(const bool valveStatus){
  if(this->valveStatus != valveStatus){
    this->changeValveStatus();
  }
}

bool Valve::changeValveStatus(){
  this->flagChangingStatus = true;
  return this->valveStatus = !this->valveStatus;
}

bool Valve::getValveStatus(){
  return this->valveStatus;
}
