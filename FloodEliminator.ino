#pragma once

#include "Main.h"

void setup() {
  // Serial.begin(9600);
  
  for (uint8_t i = 0; i < NUMBER_LEAK_SENSOR; ++i) {     // создание датчиков
    arrLeakSensor[i] = new LeakSensor(DPIN_FIRST_LEAK_SENSOR + i, DPIN_FIRST_LED_LEAK_SENSOR + i, uint16_t(EEPROM_CELL_FIRST_LEAK_SENSOR + i));
  }
  
  valve = new Valve(DPIN_VALVE, DPIN_LED_ON, DPIN_LED_OFF, EEPROM_CELL_VALVE);    // создание крана
  valve->handler();
  
  pinMode(DPIN_BUTTON, INPUT_PULLUP);                  // кнопка

  pinMode(DPIN_SPEAKER, OUTPUT);                      // пищалка
  digitalWrite(DPIN_SPEAKER, true);                   // пискнуть в начале
  delay(200);
  digitalWrite(DPIN_SPEAKER, false);
}

void loop() {
  for (uint8_t i = 0; i < NUMBER_LEAK_SENSOR; ++i) {    // проверка датчиков
    leakStatus |= arrLeakSensor[i]->handler();
  }
  digitalWrite(DPIN_SPEAKER, leakStatus);
  
  if (leakStatus) {
    valve->setValveStatus(false);                       // перекрыть воду при протечке
  }
  valve->handler();
  
  if (!digitalRead(DPIN_BUTTON)) {                      // обработка нажатий кнопки
    digitalWrite(DPIN_SPEAKER, !leakStatus);
    if (valve->changeValveStatus()) {
      leakStatus = false;
      for (uint8_t i = 0; i < NUMBER_LEAK_SENSOR; ++i) {
        leakStatus |= arrLeakSensor[i]->resetSensorStatus();          // сброс показаний датчиков (тех которые уже не активны)
      }
      
      if(!leakStatus){
        delay(100);                                                   // на случай коротко-временного пропадания сигнала сдатчика с последующим возвращением
      }
    }
    
    do {
      delay(50);
    } while (!digitalRead(DPIN_BUTTON));
  }
}
