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
#ifdef WDT_ACTIVE
  Watchdog.enable(RESET_MODE, WDT_PRESCALER);         // Режим сторжевого сброса
  Watchdog.reset();                                   // Переодический сброс watchdog, означающий, что устройство не зависло
#endif

  digitalWrite(DPIN_SPEAKER, true);                   // пискнуть в начале
  do {
    delay(50);
  } while (!digitalRead(DPIN_BUTTON));                // пока кнопка не будет отпущенна
  digitalWrite(DPIN_SPEAKER, false);
}

void loop() {
  for (uint8_t i = 0; i < NUMBER_LEAK_SENSOR; ++i) {    // проверка датчиков
    leakStatus |= arrLeakSensor[i]->handler();
  }
  digitalWrite(DPIN_SPEAKER, leakStatus && speakerStatus);  // включить пищалку если человек ещё не прищёл


  if (leakStatus) {
    valve->setValveStatus(false);                       // перекрыть воду при протечке
  }
  valve->handler();

  if (!digitalRead(DPIN_BUTTON)) {                      // обработка нажатий кнопки
    digitalWrite(DPIN_SPEAKER, (!leakStatus) || (!speakerStatus));
    do {
      delay(50);
    } while (!digitalRead(DPIN_BUTTON));

    if (valve->changeValveStatus()) {                                 // если кран должен быть переведён в положение открыт
      leakStatus = false;                                             // сброс всего... и заново проверить черех 100
      for (uint8_t i = 0; i < NUMBER_LEAK_SENSOR; ++i) {
        leakStatus |= arrLeakSensor[i]->resetSensorStatus();          // сброс показаний датчиков (тех которые уже не активны)
      }
      speakerStatus = !leakStatus;                                    // пометить что человек уже прищёл и надо перестать пищать или если протечка устранена то вернуть в значение по умолчанию

      if (!leakStatus) {                                              // если все датчики показали нет
        delay(100);                                                   // сдвинуть перепроверке значений с датчиков на 100 милисекунд
      }
    }
  }

#ifdef WDT_ACTIVE
  Watchdog.reset();                                                   // Переодический сброс watchdog, означающий, что устройство не зависло
#endif
}



// ;D
