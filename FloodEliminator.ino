#pragma once

#include "Main.h"

void setup() { 
  for(uint8_t i = 0; i < numberLeakSensor; ++i){
    arrLeakSensor[i] = new LeakSensor(DPIN_FIRST_LEAK_SENSOR + i, DPIN_FIRST_LED_LEAK_SENSOR + 1, uint16_t(i));
  }
  valve = new Valve(DPIN_VALVE, DPIN_LED_ON, DPIN_LED_OFF);
  pinMode(DPIN_SQUEAKER, OUTPUT);
}

void loop() {
  for(uint8_t i = 0; i < numberLeakSensor; ++i){
    leakStatus |= arrLeakSensor[i]->handler();
  }
  if(leakStatus){
    valve->setValveStatus(false);           // перекрыть воду при протечке
  }
  valve->handler();

  digitalWrite(DPIN_SQUEAKER, leakStatus);
}
