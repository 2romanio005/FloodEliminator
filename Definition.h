// ================================================= ПРЕДВАРИТЕЛЬНОЕ ОБЪЯВЛЕНИЕ ГЛОБАЛЬНЫХ ПЕРЕМЕННЫХ (EXTERN) =================================================
#pragma once

#include "1Connection.h"

extern bool leakStatus;
extern bool speakerStatus;

extern LeakSensor *arrLeakSensor[NUMBER_LEAK_SENSOR];
extern Valve *valve;

#ifdef WDT_ACTIVE
extern GyverWDT Watchdog;
#endif
