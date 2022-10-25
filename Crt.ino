// CRT Driver
//   Author  - Cole Barach
//   Created - 22.06.18
//   Updated - 22.07.16

// Libraries
#include <TimerOne.h>

// Pin Assignments
  // Output
    const int horizontalPwmPin      = 9;
    const int horizontalPolarityPin = 7;
    const int verticalPwmPin        = 10;
    const int verticalPolarityPin   = 8;
  // Input
    const int potentiometerPin      = A0;
    const int buttonPin             = 3;

// Control Variables
  // Potentiometer
    long frequencyMax = 262144;
    long frequencyMin = 0;
    long frequencyDelta;
    int  frequencyStep;
    int  period = 16;
    bool startUp = true;
  //Cursor
    int xCursor;
    int yCursor;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(period);
  pinMode(horizontalPwmPin,      OUTPUT);
  pinMode(horizontalPolarityPin, OUTPUT);
  pinMode(verticalPwmPin,        OUTPUT);
  pinMode(verticalPolarityPin,   OUTPUT);
  frequencyDelta = frequencyMax-frequencyMin;
  frequencyStep  = frequencyDelta/1024;
}

void loop() {
//  DemoGrid();
  DemoQuarterGrid();
//  int fontSize = 32;
//  JumpCursor(-256,512);
//  FontA(fontSize);
//  FontB(fontSize);
//  FontC(fontSize);
//  JumpCursor(-256,0);
//  FontD(fontSize);
//  FontE(fontSize);
//  FontF(fontSize);
}

// --------------------------------------------------------------------------------------Cursor
void WriteCursor(int x, int y) {
  SetFrequency(); //Temporary
  xCursor = x;
  yCursor = y;
  digitalWrite(horizontalPolarityPin,GetPolarity(x));
  digitalWrite(verticalPolarityPin,  GetPolarity(y));
  Timer1.pwm(horizontalPwmPin,abs(x),period);
  Timer1.pwm(verticalPwmPin,  abs(y),period);
  delayMicroseconds(32);
  //PrintCursor();
}
void StepCursor(int x, int y) {
  WriteCursor(xCursor+x, yCursor+y);
}
void DelayCursor() {
  StepCursor(0,0);
  delayMicroseconds(128);
}
void JumpCursor(int x, int y) {
  WriteCursor(x,y);
  DelayCursor();
}
void JumpLocalCursor(int x, int y) {
  JumpCursor(xCursor + x, yCursor + y);
}
void PrintCursor() {
  Serial.println("");
  Serial.print(xCursor);
  Serial.print("x - ");
  Serial.print(yCursor);
  Serial.print("y");
}

// --------------------------------------------------------------------------------------Primatives
void DrawPoint(int iterations) {
  for(int n = 0; n < iterations; n++) {
    DelayCursor();
  }
}
void DrawVector(int xStep, int yStep, int iterations) {
  for(int n = 0; n < iterations; n++) {
    StepCursor(xStep,yStep);
  }
}
void DrawRectangle(int xStep, int yStep, int xIterations, int yIterations) {
  DrawVector( xStep, 0,     xIterations);
  DrawVector( 0,     yStep, yIterations);
  DrawVector(-xStep, 0,     xIterations);
  DrawVector( 0,    -yStep, yIterations);
}
void DrawArc(float theta, int radius, float thetaStep, int iterations) {
  int xPrime = cos(theta)*radius;
  int yPrime = sin(theta)*radius;
  for(int n = 0; n < iterations; n++) {
    theta += thetaStep;
    int x = cos(theta)*radius;
    int y = sin(theta)*radius;
    StepCursor(x-xPrime,y-yPrime);
    xPrime = x;
    yPrime = y;
  }
}
// --------------------------------------------------------------------------------------Font
void FontBlock(int scale) {
  DrawVector( 0,-12,scale);
  DrawVector( 8, 0, scale);
  DrawVector( 0, 12,scale);
  DrawVector(-8, 0, scale);
  JumpLocalCursor(8*scale,0);
}
void FontSpace(int scale) {
  JumpLocalCursor(8*scale,0);
}
void FontA(int scale) {
  JumpLocalCursor(0,-12*scale);
  DrawVector( 4, 12,scale);
  DrawVector( 4,-12,scale);
  JumpLocalCursor(-6*scale,6*scale);
  DrawVector( 4,  0,scale);
  JumpLocalCursor(2*scale,6*scale);
}
void FontB(int scale) {
  DrawVector( 0,-12,scale);
  DrawVector( 3, 3, scale);
  DrawVector(-3, 3, scale);
  DrawVector( 3, 3, scale);
  DrawVector(-3, 3, scale);
  JumpLocalCursor(8*scale,0);
}
void FontC(int scale) {
  JumpLocalCursor(6*scale,-12*scale);
  DrawVector(-6, 6,scale);
  DrawVector( 6, 6,scale);
  JumpLocalCursor(2*scale,0);
}
void FontD(int scale) {
  DrawVector( 0,-12,scale);
  DrawVector( 6, 6, scale);
  DrawVector(-6, 6, scale);
  JumpLocalCursor(8*scale,0);
}
void FontE(int scale) {
  DrawVector( 0,-12,scale);
  DrawVector( 6, 0, scale);
  JumpLocalCursor(-6*scale,6*scale);
  DrawVector( 6, 0, scale);
  JumpLocalCursor(-6*scale,6*scale);
  DrawVector( 6, 0, scale);
  JumpLocalCursor(2*scale,0);
}
void FontF(int scale) {
  JumpLocalCursor(0,-12*scale);
  DrawVector( 0,12,scale);
  DrawVector( 6, 0, scale);
  JumpLocalCursor(-6*scale,-6*scale);
  DrawVector( 6, 0, scale);
  JumpLocalCursor(2*scale,6*scale);
}

// --------------------------------------------------------------------------------------Demos
void DemoSquare() {
  JumpCursor(-768,-768);
  DrawRectangle(16,16,96,96);
}
void DemoDiamond() {
  JumpCursor(-768,0);
  DrawVector( 16,-16,48);
  DrawVector( 16, 16,48);
  DrawVector(-16, 16,48);
  DrawVector(-16,-16,48);
}
void DemoGrid() {
  for(int xIteration = -4; xIteration <= 4; xIteration++) {
    int polarity = ParityToPolarity(xIteration);
    int x = 1024*polarity;
    int y = 256*xIteration;
    JumpCursor(x,y);
    DrawVector(-64*polarity,0,32);
    DelayCursor();
  }
  for(int yIteration = 4; yIteration >= -4; yIteration--) {
    int polarity = ParityToPolarity(yIteration);
    int x = 256*yIteration;
    int y = 1024*polarity;
    JumpCursor(x,y);
    DrawVector(0,-64*polarity,32);
    DelayCursor();
  }
}
void DemoQuarterGrid() {
  for(int xIteration = 0; xIteration <= 4; xIteration++) {
    int polarity = ParityToPolarity(xIteration);
    int x = 1024*polarity;
    int y = 256*xIteration;
    JumpCursor(x,y);
    DrawVector(-64*polarity,0,32);
    DelayCursor();
  }
  for(int yIteration = 0; yIteration >= -4; yIteration--) {
    int polarity = ParityToPolarity(yIteration);
    int x = 256*yIteration;
    int y = 1024*polarity;
    JumpCursor(x,y);
    DrawVector(0,-64*polarity,32);
    DelayCursor();
  }
}

// --------------------------------------------------------------------------------------Math
bool GetPolarity(int n) {
  return n < 0;
}
bool GetParity(int n) {
  while(n < 0) {
    n += 1024;
  }
  return n % 2;
}
int ParityToPolarity(int n) {
  return 1 - 2*GetParity(n);
}
void SetFrequency() {
  if(digitalRead(buttonPin) || startUp) {
    startUp = false;
    long frequency = (long)analogRead(potentiometerPin)*frequencyStep + frequencyMin;
    period = 1000000/frequency;
    Serial.print(frequency);
    Serial.print("Hz - ");
    Serial.print(period);
    Serial.println("μs");
  }
}
