// ================================================= НОМЕРАЦИЯ ПИНОВ =================================================

#define DPIN_FIRST_LEAK_SENSOR 5         // пин первого датчика воды, остальные будут подключаться в последующие пины, т.е. в DPIN_FIRST_LEAK_SENSOR + 1, DPIN_FIRST_LEAK_SENSOR + 2 ... DPIN_FIRST_LEAK_SENSOR + numberLeakSensor - 1
#define DPIN_FIRST_LED_LEAK_SENSOR 8     // пин первого светодиода для датчиков воды, остальные будут подключаться в последующие пины, т.е. в DPIN_FIRST_LED_LEAK_SENSOR + 1, DPIN_FIRST_LED_LEAK_SENSOR + 2 ... DPIN_FIRST_LED_LEAK_SENSOR + numberLeakSensor - 1

#define DPIN_VALVE 13
#define DPIN_LED_ON 12
#define DPIN_LED_OFF 11
#define DPIN_SQUEAKER 10 
