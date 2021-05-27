#include <Arduino.h>
int tiempo;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(17, INPUT);
  Serial.begin(115200);
  tiempo=500;
}

void loop() {
  if(digitalRead(17))
  tiempo=1200;
  else 
  tiempo=400;
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(21,LOW);
  digitalWrite(22,HIGH);
  digitalWrite(23,LOW);
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
  Serial.println("1");
  delay(tiempo);
}
// Per utilitzar un potenciòmetre: 
// int posicio;
// void setup() { Serial.begin(115200);
// pinMode(15,INPUT);}
// void loop() { posicio=analogRead(15);
// Serial.println(posicio);}