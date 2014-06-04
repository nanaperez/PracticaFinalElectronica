#define sw1 PINC, 0
#define sw2 PINC, 1
#define sw3 PINC, 2
#define sw4 PINC, 3

#include <LiquidCrystal.h> //agrega la libreria del LCD

LiquidCrystal lcd(48,49,45,44,43,42);    //inicializa la libreria y define los pines digitales para el LCD

char* almacen[10][3]; //matriz donde se guardan los productos, las secciones y cuantos hay en stock
int stock[10]; //arreglo de la cantidad de productos
char* secciones[5]; //arreglo de secciones
  
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
    lcd.print("Gracias por su compra");
  }
  else if (bitRead(PINC, sw2)==LOW && bitRead(PINC, sw3)==LOW && bitRead(PINC, sw4)==LOW){
    lcd.clear();
  }
  
  if (bitRead(PINC, sw2)==HIGH){
    for(int i = 0; i < 10; i++){  
      for(int j = 0; j < 2; j++){ //creo que este no se necesita
        lcd.setCursor(1,0);
        lcd.print(almacen[i][0]);
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
     for(int i = 0; i < 10; i++){  
      for(int j = 0; j < 3; j++){ //creo q este no se necesita
        lcd.setCursor(1,0);
        lcd.print(almacen[i][1]);
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
     lcd.print("SI[]    NO[]");
  }
  else if (bitRead(PINC, sw1)==LOW && bitRead(PINC, sw2)==LOW && bitRead(PINC, sw3)==LOW){
    lcd.clear();
  }
}

void stock() {
  secciones[0] = "s1 - lacteos    ";
  secciones[1] = "s2 - congelados ";
  secciones[2] = "s3 - granos     ";
  secciones[3] = "s4 - aseo       ";
  secciones[4] = "s5 - frutas     ";
  
  producto[0] = 10;
  producto[1] = 15;
  producto[2] = 19;
  producto[3] = 16;
  producto[4] = 45;
  producto[5] = 34;
  producto[6] = 22;
  producto[7] = 29;
  producto[8] = 12;
  producto[9] = 8;
  
  almacen[0][0] = "s1 - lacteos   ";
  almacen[0][1] = "leche          ";
  almacen[0][2] = "10 unidades    ";
  almacen[1][0] = "s1 - lacteos   ";
  almacen[1][1] = "huevos         ";
  almacen[1][2] = "15 unidades    ";
  almacen[2][0] = "s2 - congelados";
  almacen[2][1] = "carne          ";
  almacen[2][2] = "19 unidades    ";
  almacen[3][0] = "s2 - congelados";
  almacen[3][1] = "pollo          ";
  almacen[3][2] = "16 unidades    ";
  almacen[4][0] = "s3 - granos    ";
  almacen[4][1] = "arroz          ";
  almacen[4][2] = "45 unidades    ";
  almacen[5][0] = "s3 - granos    ";
  almacen[5][1] = "maiz           ";
  almacen[5][2] = "34 unidades    ";
  almacen[6][0] = "s4 - aseo      ";
  almacen[6][1] = "escoba         ";
  almacen[6][2] = "22 unidades    ";
  almacen[7][0] = "s4 - aseo      ";
  almacen[7][1] = "jabon          ";
  almacen[7][2] = "29 unidades    ";
  almacen[8][0] = "s5 - frutas    ";
  almacen[8][1] = "papaya         ";
  almacen[8][2] = "12 unidades    ";
  almacen[9][0] = "s5 - frutas    ";
  almacen[9][1] = "sandia         ";
  almacen[9][2] = "8 unidades     ";
}
