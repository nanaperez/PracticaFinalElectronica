#include <Keypad.h>
#include <LiquidCrystal.h>               //agrega la libreria del LCD
const byte filas = 4;                    //define las 4 filas del teclado 
const byte columnas = 3;                 //define las 3 columnas del teclado
char teclas[filas][columnas] =           //inicializa filas y columnas
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

#define sw1 PINC, 0
#define sw2 PINC, 1
#define sw3 PINC, 2
#define sw4 PINC, 3


byte pinesfilas[filas] = {21,20,19,18};    //define los pines digitales de las cuatro filas
byte pinescolumnas[columnas] = {17,16,15}; //define los pines digitales de las tres columnas
Keypad teclado = Keypad( makeKeymap(teclas), pinesfilas,  pinescolumnas, filas, columnas ); //lectura del teclado      
Keypad teclado2 = Keypad( makeKeymap(teclas), pinesfilas,  pinescolumnas, filas, columnas ); //lectura del teclado          


LiquidCrystal lcd(48,49,45,44,43,42);    //inicializa la libreria y define los pines digitales para el LCD

char* almacen[10][3]; //matriz donde se guardan los productos, las secciones y cuantos hay en stock
int cantidad[10]; //arreglo de la cantidad de productos
char* secciones[5]; //arreglo de secciones
char pp;
char cp;
  
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
        lcd.print(cantidad[i]);
        lcd.setCursor(5,1);
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
     lcd.print("COMPRAR?       ");
     lcd.setCursor(1,1);
     lcd.print("SI[]    NO[]");
     while (bitRead(PINC, sw3)==HIGH){
       lcd.clear();
       if (compra()){
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Gracias por su compra");
          delay(1000);
       }
     }
  }
  else if (bitRead(PINC, sw1)==LOW && bitRead(PINC, sw2)==LOW && bitRead(PINC, sw3)==LOW){
    lcd.clear();
  }
}

boolean compra(){
    lcd.clear();
    //delay(1000);
    lcd.setCursor(1,0); 
    lcd.print("Digite el producto 0-9");
    pp = teclado.getKey();
    while(pp == '\0') {
      pp = teclado.getKey();
    }
    lcd.setCursor(1,1); 
    lcd.print(pp);
    delay(1000); 	
      lcd.clear();
      delay(1000);
      lcd.setCursor(1,0); 
      lcd.print("Digite cantidad");
      cp = teclado2.getKey();
      while(cp == '\0') {
        cp = teclado2.getKey();
      }
       	
      int valor = cp-48;
      
      cantidad[pp-48] = cantidad[pp-48] - valor;
        return true;
}

void stock() {
  secciones[0] = "s1 - lacteos    ";
  secciones[1] = "s2 - congelados ";
  secciones[2] = "s3 - granos     ";
  secciones[3] = "s4 - aseo       ";
  secciones[4] = "s5 - frutas     ";
  
  cantidad[0] = 10; //leche
  cantidad[1] = 15; //huevos
  cantidad[2] = 19; //carne
  cantidad[3] = 16; //pollo
  cantidad[4] = 45; //arroz
  cantidad[5] = 34; //maiz
  cantidad[6] = 22; //escoba
  cantidad[7] = 29; //jabon
  cantidad[8] = 12; //papaya
  cantidad[9] = 8;  //sandia
  
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
