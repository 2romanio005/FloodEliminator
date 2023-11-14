// ================================================= DEFINE-КОНСТАНТЫ ДЛЯ ПРОГРАММИСТА =================================================

#define MAX_BYTE 0b11111111                                                       // заполненный байт (его пищем в eeprom-память, чтобы все биты были подняты)

#define EEPROM_CELL_FIRST_LEAK_SENSOR 0                                           // адресс ячейки eeprom-памяти с которой начинать писать состояния датчиков. будет занято NUMBER_LEAK_SENSOR байт
#define EEPROM_CELL_VALVE (EEPROM_CELL_FIRST_LEAK_SENSOR + NUMBER_LEAK_SENSOR)    // адресс ячейки eeprom-памяти для записии положения вентиля
