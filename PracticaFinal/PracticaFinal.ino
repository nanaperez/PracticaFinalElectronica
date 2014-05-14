#define sw1 PINC, 0
#define sw2 PINC, 1
#define sw3 PINC, 2
#define sw4 PINC, 3
#include <LiquidCrystal.h>
LiquidCrystal lcd(48, 49, 45, 44, 43, 42);

void setup() {
  pinMode(47, OUPUT);
  digitalWrite(47,0);
  lcd.begin(16,2);
}

void loop() {
  if(bitRead(PINC, sw1) == HIGH){
    
  }
}
