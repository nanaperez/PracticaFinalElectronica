#define sw1 PINC, 0
#define sw2 PINC, 1
#define sw3 PINC, 2
#define sw4 PINC, 3

#include <LiquidCrystal.h>//agrega la libreria del LCD
#include <stock.h>

LiquidCrystal lcd(48,49,45,44,43,42);    //inicializa la libreria y define los pines digitales para el LCD

char* almacen[10][3];
char* producto[10];
char* secciones[4];
  
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
    for(int i = 0; i < 9; i++){  
      for(int j = 0; j < 2; j++){
        lcd.setCursor(1,0);
        lcd.print(almacen[i][0]);
        //delay(3000);
        lcd.setCursor(1,1);
        lcd.print(almacen[i][1]);
        delay(2000);
      }
    }
  }

  else if (bitRead(PINC, sw1)==LOW && bitRead(PINC, sw3)==LOW && bitRead(PINC, sw4)==LOW){
    lcd.clear();
  }
  
  if(bitRead(PINC, sw3)==HIGH){
     for(int i = 0; i < 9; i++){  
      for(int j = 0; j < 2; j++){
        lcd.setCursor(1,0);
        lcd.print(almacen[i][1]);
        //delay(3000);
        lcd.setCursor(1,1);
        lcd.print(almacen[i][2]);
        delay(2000);
      }
    }
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
  
  secciones[0] = "s1 - lacteos    ";
  secciones[1] = "s2 - congelados ";
  secciones[2] = "s3 - granos     ";
  secciones[3] = "s4 - legumbreria";
  
  producto[0] = "leche   ";
  producto[1] = "huevos  ";
  producto[2] = "carne   ";
  producto[3] = "pollo   ";
  producto[4] = "arroz   ";
  producto[5] = "maiz    ";
  producto[6] = "trapo   ";
  producto[7] = "escoba  ";
  producto[8] = "frutas  ";
  producto[9] = "verduras";
  
  almacen[0][0] = "s1";
  almacen[0][1] = "leche ";
  almacen[0][2] = "10    ";
  almacen[1][0] = "s1";
  almacen[1][1] = "huevos";
  almacen[1][2] = "15    ";
  almacen[2][0] = "s2";
  almacen[2][1] = "carne ";
  almacen[2][2] = "19    ";
  almacen[3][0] = "s2";
  almacen[3][1] = "pollo ";
  almacen[3][2] = "1    ";
  almacen[4][0] = "s3";
  almacen[4][1] = "arroz ";
  almacen[4][2] = "99    ";
  almacen[5][0] = "s3";
  almacen[5][1] = "maiz  ";
  almacen[5][2] = "34    ";
  almacen[6][0] = "s4";
  almacen[6][1] = "trapo ";
  almacen[6][2] = "43    ";
  almacen[7][0] = "s4";
  almacen[7][1] = "jabon ";
  almacen[7][2] = "29    ";
}
