//const int button1Pin = 11;
//const int button2Pin = 10;
//
//const int led1Pin = 13;
//const int led2Pin = 12;
//
//const uint8_t potentiometerPin = A0;
//const uint8_t buttonArrayPin   = A1;
//
//void setup() {
//  pinMode(button1Pin, INPUT);
//  pinMode(button2Pin, INPUT);
//  pinMode(led1Pin, OUTPUT);
//  pinMode(led2Pin, OUTPUT);
//  
//  Serial.begin(9600);
//}
//
//void loop() {
//  int button1 = 1-digitalRead(button1Pin);
//  int button2 = 1-digitalRead(button2Pin);
//  float potentiometer = analogRead(potentiometerPin)/1024.0f;
//  int buttonArray = analogRead(buttonArrayPin);
//
//  //Serial.println(buttonArray);
//
//  if(buttonArray < 256) {        // 0
//    Serial.println("Button 1");
//  } else if(buttonArray < 598) { //512
//    Serial.println("Button 2");
//  } else if(buttonArray < 726) { //683
//    Serial.println("Button 3");
//  } else if(buttonArray < 794) { //768
//    Serial.println("Button 4");
//  } else if(buttonArray < 837) { //820
//    Serial.println("Button 5");
//  } else if(buttonArray < 866) { //853
//    Serial.println("Button 6");
//  } else if(buttonArray < 951) { //878
//    Serial.println("Button 7");
//  } else {
//    Serial.println("");
//  }
//
////  if(button1 > 0) {
////    digitalWrite(led1Pin, HIGH);
////  } else {
////    digitalWrite(led1Pin, LOW);
////  }
////  if(button2 > 0) {
////    digitalWrite(led2Pin, HIGH);
////  } else {
////    digitalWrite(led2Pin, LOW);
////  }
//}
