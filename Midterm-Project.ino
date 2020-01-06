const int port1 = A1; 
const int port2 = A2; 
const int port3 = A3;
 int portValue1 = 0; 
 int portValue2 = 0;
 int portValue3 = 0; 
 float Vltin = 5; 
 float Vltout1 = 0; 
 float Vltout2 = 0; 
 float Vltout3 = 0; 
 float Rref1 = 1000; 
 float Rref2 = 1000; 
 float Rref3 = 1000; 
 float r1 = 0; 
 float r2 = 0; 
 float r3 = 0; 
 float ra=0,rb=0,rc=0; 

 void setup ()
  { 
 Serial.begin(9600); 
  } 
         void getRes1()
     { 
    portValue1 = analogRead(port1);
    Vltout1 = (Vltin * portValue1) / 1023; 
 r1 = Rref1 * (1 / ((Vltin / Vltout1) - 1));      
            Serial.print("Resistor 1: "); 
            Serial.println(r1);
            delay(1000); 
      } 
      
          void getRes2()
     { 
            portValue2 = analogRead(port2);
            Vltout2 = (Vltin * portValue2) / 1023;
            r2 = Rref2 * (1 / ((Vltin / Vltout2) - 1));  
            Serial.print("Resistor 2: "); 
            Serial.println(r2); 
            delay(1000); 
     } 
     
          void getRes3()
     { 
            portValue3 = analogRead(port3);
            Vltout3 = (Vltin * portValue3) / 1023;
            r3 = Rref3 * (1 / ((Vltin / Vltout3) - 1)); 
            Serial.print("Resistor 3: "); 
            Serial.println(r3); 
            delay(1000);
     } 
     
         void loop ()
 {
    Serial.println("------------------------------------------");  
    Serial.println("Delta to WYE");   
    Serial.println("Analyzing Resistors. . . . ");    
        getRes1(); 
        getRes2(); 
        getRes3();
    Serial.println("Calculating....."); 
    delay(2000); 
  ra=(r2*r3)/(r1+r2+r3); 
  rb=(r3*r1)/(r1+r2+r3);
  rc=(r1*r2)/(r1+r2+r3); 
    Serial.print("Resistor 1:"); 
    Serial.println(ra);    
    Serial.print("Resistor 2:"); 
    Serial.println(rb);  
    Serial.print("Resistor 3:"); 
    Serial.println(rc); Serial.println("------------------------------------------"); delay(2000);
 }
