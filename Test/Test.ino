#include "lib14Seg.h"
#include <SPI.h>

int a=0;

#define RCK 9
#define SCK 13
#define MOSI 11

void setup(){
  pinMode(RCK, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(14, OUTPUT);
  
  LED14Seg.init(RCK, 0x04, 8);  
}


void loop(){
//    LED14Seg.setChar("    Arduino..    ARDUINO");
    LED14Seg.setChar("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    LED14Seg.showStop();
    LED14Seg.setScrollSpeed(300);
    
    delay(100000);
}
