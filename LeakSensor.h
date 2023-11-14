// ================================================= КЛАСС ДАТЧИК ПРОТЕЧКИ =================================================
#pragma once

#include "0Include.h"

class LeakSensor {
  public:
    LeakSensor(const uint8_t dPinSensor, const uint8_t dPinLed, const uint16_t eepromCell);
    //~LeakSensor();

    bool handler();

    bool setSensorStatus(const bool sensorStatus);
  private:
    const uint8_t dPinSensor;
    const uint8_t dPinLed;
    const uint16_t eepromCell;

    bool sensorStatus;
};
