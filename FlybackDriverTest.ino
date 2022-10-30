#include <TimerOne.h>

const int flybackTriggerPin = 9;
      int flybackFrequency  = 16384;

const int potentiometerPin = A0;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000*1000/flybackFrequency);
  pinMode(flybackTriggerPin, OUTPUT);
  pinMode(potentiometerPin,  INPUT);
}

void loop() {
  int potentiometerValue = analogRead(potentiometerPin)*(flybackFrequency/1024)+1;
  Serial.println(potentiometerValue);
  
  Timer1.initialize(1000*1000/potentiometerValue);
  Timer1.pwm(flybackTriggerPin,512);
}
