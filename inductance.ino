double pulse, frequency, capacitance, inductance;
void setup(){
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  delay(200);
}
void loop(){
  digitalWrite(9, HIGH);
  delay(5);//give some time to charge inductor.
  digitalWrite(9,LOW);
  delayMicroseconds(100); //make sure resination is measured
  pulse = pulseIn(8,HIGH,5000);//returns 0 if timeout
  if(pulse > 0.1){ //if a timeout did not occur and it took a reading:
  capacitance = 2.E-6; // - insert value here
  
  frequency = 1.E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);//one of my profs told me just do squares like this
  inductance *= 1E6; //note that this is the same as saying inductance = inductance*1E6

  //Serial print
  Serial.print("\tinductance uH:");
  Serial.println( inductance );
  delay(100);
  }
}
