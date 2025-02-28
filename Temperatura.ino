/*
Projeto Arduino com LCD, sensor de luz e de temperatura. 
Por Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/
#include "LiquidCrystal.h"
#include "Limits.h"
#include <Thermistor.h>

 
//Variáveis
int valorSensorTemp = 0;
Thermistor temp(0);
Thermistor frio(4);
 
//Criando um objeto da classe LiquidCrystal e 
//inicializando com os pinos da interface.
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);
 
void setup() {
  //Inicializando o LCD e informando o tamanho de 16 colunas e 2 linhas
  //que é o tamanho do LCD JHD 162A usado neste projeto.
  lcd.begin(16, 2);    
  pinMode(13, OUTPUT);
}
 
void loop() { 
     
      //Lendo o valor do sensor de temperatura.
    valorSensorTemp = temp.getTemp();   
  
       
   if (valorSensorTemp < 60){
    digitalWrite(13, HIGH); 
   }
else{
  digitalWrite(13, LOW); 
   }
   delay(150); 
    
     
  //Exibindo valor da leitura do sensor de temperatura no display LCD.
  lcd.clear();  //limpa o display do LCD.     
  lcd.print("Temp cooler: ");  //imprime a string no display do LCD.                 
  lcd.print(valorSensorTemp);
  lcd.write(B11011111); //Simbolo de graus celsius
  lcd.print("C");
   
  
  delay(1000); //aguarda 1 segundos
}
