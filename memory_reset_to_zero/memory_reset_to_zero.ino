#include <avr/eeprom.h>
void setup() {
  for(uint8_t i = 0; i < 4; ++i){
    eeprom_update_byte(i, 0); 
  }

}

void loop() {
  

}
