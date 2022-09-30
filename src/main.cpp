/**
  I, Alec Pasion, 000811377 certify that this material is my original work. No other person's work has been used
  without due acknowledgement.
**/
#include <Arduino.h> 
boolean isOff = true;
int buttonStateCheck = 0;
void setup() { 
  Serial.begin(115200); 
 
  pinMode(D5, INPUT_PULLUP); 
  pinMode(D4, OUTPUT); 
  analogWriteRange(1023); 
} 
 
 
void loop() { 
  int iButton = digitalRead(D5);
  int iVal = analogRead(A0);
  int brightness = map(iVal,0,pow(2,10),1023,0);
  if (iButton == buttonStateCheck)
  {
    if(!isOff){
      isOff = true;
    }else{
      isOff = false;
    }
    delay(500);
  }
  if(!isOff){
    analogWrite(D4, brightness);
  }
  digitalWrite(D4,isOff);
}