#include "Capacitance.h"
void setup()
{
  pinMode(chargePin, OUTPUT);     
  digitalWrite(chargePin, LOW);  
  Serial.begin(9600); 
}
void loop()
{
  CapacitanceRay con;
  con.CAP();
}
