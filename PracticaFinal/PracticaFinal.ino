#define sw1 PINC, 0
#define sw2 PINC, 1
#define sw3 PINC, 2
#define sw4 PINC, 3

#include <LiquidCrystal.h>//agrega la libreria del LCD
#include <stock.h>

LiquidCrystal lcd(48,49,45,44,43,42);    //inicializa la libreria y define los pines digitales para el LCD

char* almacen[10][2];
char* secciones[5];
  
void setup() {
  pinMode(47,OUTPUT);
  digitalWrite(47,0);
  lcd.begin(16,2);
  stock();
}

void loop() {
  if(bitRead(PINC, sw1)==HIGH){
    lcd.setCursor(1,0);
    lcd.print("Bienvenido!!");
    lcd.setCursor(1,1);
    lcd.print("Gracias");
  }
  else if (bitRead(PINC, sw2)==LOW && bitRead(PINC, sw3)==LOW && bitRead(PINC, sw4)==LOW){
    lcd.clear();
  }
  
  if (bitRead(PINC, sw2)==HIGH){
      lcd.setCursor(1,0);
      lcd.print("SECCION #");
      lcd.setCursor(1,1);
      lcd.print(secciones[0]);
  }

  else if (bitRead(PINC, sw1)==LOW && bitRead(PINC, sw3)==LOW && bitRead(PINC, sw4)==LOW){
    lcd.clear();
  }
  
  if(bitRead(PINC, sw3)==HIGH){
     lcd.setCursor(1,0);
     lcd.print("CANTIDAD 10");
     lcd.setCursor(1,1);
     lcd.print("EN STOCK");
  }
  else if (bitRead(PINC, sw1)==LOW && bitRead(PINC, sw2)==LOW && bitRead(PINC, sw4)==LOW){
    lcd.clear();
  }
  
  if(bitRead(PINC, sw4)==HIGH){
     lcd.setCursor(1,0);
     lcd.print("COMPRAR?");
     lcd.setCursor(1,1);
     lcd.print("SI    NO");
  }
  else if (bitRead(PINC, sw1)==LOW && bitRead(PINC, sw2)==LOW && bitRead(PINC, sw3)==LOW){
    lcd.clear();
  }
}

void stock() {
  
  secciones[0] = "s1 - ";
  secciones[1] = "s2";
  secciones[2] = "s3";
  secciones[3] = "s4";
  secciones[4] = "s5";
  
  almacen[0][0] = "papas";
  almacen[0][1] = "s1";
  almacen[1][0] = "huevos";
  almacen[1][1] = "s1";
  almacen[2][0] = "arroz";
  almacen[2][1] = "s2";
  almacen[3][0] = "maiz";
  almacen[3][1] = "s2";
  almacen[4][0] = "carne";
  almacen[4][1] = "s3";
  almacen[5][0] = "pollo";
  almacen[5][1] = "s3";
  almacen[6][0] = "pescado";
  almacen[6][1] = "s4";
  almacen[7][0] = "arepa";
  almacen[7][1] = "s4";
  almacen[8][0] = "frutas";
  almacen[8][1] = "s5";
  almacen[9][0] = "verduras";
  almacen[9][1] = "s5";  
}
