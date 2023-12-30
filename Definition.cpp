#include "Main.h"


bool leakStatus = false;                        // флажок протечки
bool speakerStatus = true;                      // флажок что человек ещё не пришёл, значит надо продолжать пищать (true - пищать)

LeakSensor *arrLeakSensor[NUMBER_LEAK_SENSOR];
Valve *valve;

#ifdef WDT_ACTIVE
GyverWDT Watchdog;
#endif
