// ================================================= НОМЕРАЦИЯ ПИНОВ =================================================

#define DPIN_FIRST_LEAK_SENSOR 3         // пин первого датчика воды, остальные будут подключаться в последующие пины, т.е. в DPIN_FIRST_LEAK_SENSOR + 1, DPIN_FIRST_LEAK_SENSOR + 2 ... DPIN_FIRST_LEAK_SENSOR + NUMBER_LEAK_SENSOR - 1
#define DPIN_FIRST_LED_LEAK_SENSOR 6     // пин первого светодиода для датчиков воды, остальные будут подключаться в последующие пины, т.е. в DPIN_FIRST_LED_LEAK_SENSOR + 1, DPIN_FIRST_LED_LEAK_SENSOR + 2 ... DPIN_FIRST_LED_LEAK_SENSOR + NUMBER_LEAK_SENSOR - 1

#define DPIN_VALVE A0                    // реле
#define DPIN_LED_ON 12                   // светодиод включённой воды
#define DPIN_LED_OFF 2                  // светодиод отключённой воды
#define DPIN_SPEAKER 10                 // пищалка

#define DPIN_BUTTON 9                    // кнопка
