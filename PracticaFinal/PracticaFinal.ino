#define sw1 PINC, 0
#define sw2 PINC, 1

#include <LiquidCrystal.h>    //agrega la libreria del LCD

LiquidCrystal lcd(48,49,45,44,43,42);    //inicializa la libreria y define los pines digitales para el LCD

void setup() {
  pinMode(47,OUTPUT);
  digitalWrite(47,0);
  lcd.begin(16,2);
}

void loop() {
  if(bitRead(PINC, sw1)==HIGH){
    lcd.setCursor(1,0);
    lcd.print("Bienvenido!!");
    lcd.setCursor(1,1);
     lcd.print("Gracias");
  }
  else if (bitRead(PINC, sw2)==LOW){
    lcd.clear();
  }
  
  if (bitRead(PINC, sw2)==HIGH){
    lcd.setCursor(1,0);
    lcd.print("FACEBOOK");
     lcd.setCursor(1,1);
     lcd.print("JESSECOGOLLO");
  }

  else if (bitRead(PINC, sw1)==LOW){
    lcd.clear();
  }
  //lcd.setCursor(1,0);
  //lcd.print("TWITTER");
  //lcd.setCursor(1,1);
  //lcd.print("@JESSECOGOLLO");
}
