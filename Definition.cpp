#include "Main.h"


bool leakStatus = false;

LeakSensor *arrLeakSensor[NUMBER_LEAK_SENSOR];
Valve *valve;

#ifdef WDT_ACTIVE
GyverWDT Watchdog;
#endif
