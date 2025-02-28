//Include the SoftwareSerial library
#include "SoftwareSerial.h"

//Create a new software  serial
SoftwareSerial bt(1,0);

void setup() {
  //Initialize the hardware serial
  Serial.begin(38400);
  Serial.println("Digite os comandos AT:");
  bt.begin (38400);
  pinMode(1, INPUT);
  pinMode(0, OUTPUT);
}
 
void loop() {
  {
    if (bt.available())
    {
      int inByte = bt.read();
      Serial.write((char)inByte);
    }
    if (Serial.available())
      {
        int inByte = bt.read();
        bt.write((char)inByte);
      }
}
}
