// ================================================= НОМЕРАЦИЯ ПИНОВ =================================================

#define NUMBER_LEAK_SENSOR 4             // количество датчиков протечки
#define DPIN_FIRST_LEAK_SENSOR A1        // пин первого датчика воды, остальные будут подключаться в последующие пины, т.е. в DPIN_FIRST_LEAK_SENSOR + 1, DPIN_FIRST_LEAK_SENSOR + 2 ... DPIN_FIRST_LEAK_SENSOR + NUMBER_LEAK_SENSOR - 1
#define DPIN_FIRST_LED_LEAK_SENSOR 8     // пин первого светодиода для датчиков воды, остальные будут подключаться в последующие пины, т.е. в DPIN_FIRST_LED_LEAK_SENSOR + 1, DPIN_FIRST_LED_LEAK_SENSOR + 2 ... DPIN_FIRST_LED_LEAK_SENSOR + NUMBER_LEAK_SENSOR - 1

#define DPIN_VALVE 2                     // реле
#define DPIN_LED_ON 4                    // светодиод включённой воды
#define DPIN_LED_OFF 6                   // светодиод отключённой воды
#define DPIN_SPEAKER 12                  // пищалка

#define DPIN_BUTTON 5                    // кнопка
