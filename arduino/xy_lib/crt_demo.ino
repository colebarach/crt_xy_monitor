// CRT Demo
//   Author - Cole Barach
//   Date Created - 22.10.17
//   Date Updated - 22.10.17
//

// Pinout
const int horizontalPolarityPin = 7;
const int verticalPolarityPin   = 8;
const int horizontalPwmPin      = 9;
const int verticalPwmPin        = 10;

void setup() {
  pinMode(horizontalPolarityPin, OUTPUT);
  pinMode(verticalPolarityPin,   OUTPUT);
  pinMode(horizontalPwmPin,      OUTPUT);
  pinMode(verticalPwmPin,        OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int xPos = 480*cos(millis()/100) + 480;
  int yPos = 480*sin(millis()/100) + 480;
  //Serial.print(xPos);
  //Serial.print(" - ");
  //Serial.println(yPos);
  analogWrite(horizontalPwmPin, xPos);
  analogWrite(verticalPwmPin,   yPos);
}
