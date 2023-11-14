// ================================================= КЛАСС ДАТЧИК ПРОТЕЧКИ =================================================
#pragma once

#include "0Include.h"

class LeakSensor{
  public:
    LeakSensor(const uint8_t dPidSensor, const uint8_t dPidLed, const uint16_t eepromCell);
    //~LeakSensor();
  
    bool handler();

    bool setSensorStatus(const bool sensorStatus);
  private:
    const uint8_t dPidSensor;
    const uint8_t dPidLed;
    const uint16_t eepromCell;
    
    bool sensorStatus;
};
