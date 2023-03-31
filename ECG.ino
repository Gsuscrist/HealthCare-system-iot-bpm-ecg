
/******************************************************************************
Heart_Rate_Display.ino
Publisher: https://www.circuitschools.com
******************************************************************************/
int hearthBeat =0;

 
void setup() {
  // initialize the serial communication:
  Serial.begin(115200);
  pinMode(34, INPUT); // Setup for leads off detection LO +
  pinMode(35, INPUT); // Setup for leads off detection LO -
 
}
 
void loop() {
  
  if((digitalRead(34) == 1)||(digitalRead(35) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
    hearthBeat = ((analogRead(A0)*100)/3000);
   String msg = "your heart Beat is: " + String(hearthBeat);
      Serial.println(msg);
  }
  //Wait for a bit to keep serial data from saturating
  delay(1500);
}
