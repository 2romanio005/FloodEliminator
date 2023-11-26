#pragma once

#include "Main.h"

void setup() {
// НАСТРОЙКА ОСНОВНОГО ФУНКЦИОНАЛА РАБОТЫ, ДОЛЖНА ПРОХОДИТЬ БЫСТРО, ЧТОБЫ СРАЗУ ПЕРЕВЕСТИ УПРАВЛЯЮЩИЕ ПИНЫ В ПРАВИЛЬНОЕ ПОЛОЖЕНИЕ
  valve = new Valve(DPIN_VALVE, DPIN_LED_ON, DPIN_LED_OFF, EEPROM_CELL_VALVE);    // создание крана
  valve->handler();
  
  for (uint8_t i = 0; i < NUMBER_LEAK_SENSOR; ++i) {                              // создание датчиков
    arrLeakSensor[i] = new LeakSensor(DPIN_FIRST_LEAK_SENSOR + i, DPIN_FIRST_LED_LEAK_SENSOR + i, uint16_t(EEPROM_CELL_FIRST_LEAK_SENSOR + i));
  }

// НАСТРОЙКА ВСЯКОГО БАРАХЛА, ЗАДЕЖКИ НЕ КРИТИЧНЫ
  //Serial.begin(9600);
  pinMode(DPIN_BUTTON, INPUT_PULLUP);                 // кнопка

  pinMode(DPIN_SPEAKER, OUTPUT);                      // пищалка
  delay(200);
  digitalWrite(DPIN_SPEAKER, true);                   // пискнуть в начале
  do {
    delay(200);
  } while (!digitalRead(DPIN_BUTTON));                // пока кнопка не будет отпущенна
  digitalWrite(DPIN_SPEAKER, false);

#ifdef WDT_ACTIVE
  Watchdog.enable(RESET_MODE, WDT_PRESCALER);           // Режим сторжевого сброса
#endif
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
    //Serial.println("Clicked AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    digitalWrite(DPIN_SPEAKER, !leakStatus);
    do {
      delay(50);
    } while (!digitalRead(DPIN_BUTTON));

    if (valve->changeValveStatus()) {
      leakStatus = false;
      for (uint8_t i = 0; i < NUMBER_LEAK_SENSOR; ++i) {
        leakStatus |= arrLeakSensor[i]->resetSensorStatus();          // сброс показаний датчиков (тех которые уже не активны)
      }

      if (!leakStatus) {
        delay(100);                                                   // на случай коротко-временного пропадания сигнала сдатчика с последующим возвращением
      }
    }
  }

#ifdef WDT_ACTIVE
  Watchdog.reset(); // Переодический сброс watchdog, означающий, что устройство не зависло
#endif
}



// ;D
