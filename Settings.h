// ================================================= КОНСТАНТЫ НАСТРОЙКИ =================================================

#define TIMER_DURATION_OF_LEAK_SENSOR 2000 // время, в течении которого датчик должен сигнализировать о протечке, чтобы этот сигнал учитывался

#define NORMAL_OPEN true                   // поставить true если НОРМАЛЬНО-ОТКРЫТЫЙ, и false если НОРМАЛЬНО-ЗАКРЫТЫЙ

#define WDT_ACTIVE                         // если закоментировать то WatchDog будет вырезан из кода

#ifdef WDT_ACTIVE
#define WDT_PRESCALER WDT_PRESCALER_256    // максимальное время прохождения loop цикла (при привышении автоматическая перезагрузка)    (256 = ~1c)
/*
  #define WDT_PRESCALER_2     0x00  // (16 ± 1.6) ms
  #define WDT_PRESCALER_4     0x01  // (32 ± 3.2) ms
  #define WDT_PRESCALER_8     0x02  // (64 ± 6.4) ms
  #define WDT_PRESCALER_16    0x03  // (128 ± 12.8) ms
  #define WDT_PRESCALER_32    0x04  // (256 ± 25.6) ms
  #define WDT_PRESCALER_64    0x05  // (512 ± 51.2) ms
  #define WDT_PRESCALER_128   0x06  // (1024 ± 102.4) ms
  #define WDT_PRESCALER_256   0x07  // (2048 ± 204.8) ms
  #define WDT_PRESCALER_512   0x08  // (4096 ± 409.6) ms
  #define WDT_PRESCALER_1024  0x09  // (8192 ± 819.2) ms
*/
#endif
