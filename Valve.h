// ================================================= КЛАСС ВЕНТИЛЬ =================================================
#pragma once

#include "0Include.h"

class Valve {
  public:
    Valve(const uint8_t dPinValve, const uint8_t dPinLedOn, const uint8_t dPinLedOff, const uint16_t eepromCell);

    void handler();

    void setValveStatus(const bool valveStatus);
    bool changeValveStatus();
    bool getValveStatus();
  private:
    const uint8_t dPinValve;
    const uint8_t dPinLedOn;
    const uint8_t dPinLedOff;
    const uint16_t eepromCell;

    bool valveStatus;             // false - закрытый, true - открытый
    //bool flagChangingStatus;
};
