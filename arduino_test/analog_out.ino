#include <TimerOne.h>

const int xPin = 9;
const int yPin = 10;

int period = 64;

// 256
int distanceLookup[] =
{
  0,
  1501
};

void setup()
{
  Timer1.initialize(period);
  
  pinMode(xPin, OUTPUT);
  pinMode(yPin, OUTPUT);
}

void loop()
{
  demoSizeDelay2();
  
//  drawFontA(0, 0);
//  drawFontB(12, 0);
//  drawFontC(24, 0);
//  drawFontD(36, 0);
//  drawFontE(48, 0);
//  drawFontF(60, 0);
}

void drawFontNull(int x, int y)
{
  drawVector(x,   y);
  drawVector(x+8, y);
  drawVector(x+8, y+12);
  drawVector(x,   y+12);
  
  drawVector(x,   y);
  drawVector(x+8, y);
}

void drawFontA(int x, int y)
{
  drawVector(x,   y);
  drawVector(x+2, y+6);
  drawVector(x+6, y+6);
  drawVector(x+2, y+6);
  drawVector(x+4, y+12);
  drawVector(x+8, y);
}

void drawFontB(int x, int y)
{

  drawVector(x,   y);
  drawVector(x,   y+12);
  drawVector(x+8, y+12);
  drawVector(x+8, y+8);
  drawVector(x+6, y+6);
  drawVector(x,   y+6);
  drawVector(x+6, y+6);
  drawVector(x+8, y+4);
  drawVector(x+8, y);
  drawVector(x,   y);
}

void drawFontC(int x, int y)
{
  drawVector(x+8, y);
  drawVector(x+2, y);
  drawVector(x,   y+2);
  drawVector(x,   y+10);
  drawVector(x+2, y+12);
  drawVector(x+8, y+12);
}

void drawFontD(int x, int y)
{
  drawVector(x,   y);
  drawVector(x,   y+12);
  drawVector(x+6, y+12);
  drawVector(x+8, y+10);
  drawVector(x+8, y+2);
  drawVector(x+6, y);
  drawVector(x,   y);
}

void drawFontE(int x, int y)
{
  drawVector(x+8, y);
  drawVector(x,   y);
  drawVector(x,   y+6);
  drawVector(x+8, y+6);
  drawVector(x,   y+6);
  drawVector(x,   y+12);
  drawVector(x+8, y+12);
}

void drawFontF(int x, int y)
{
  drawVector(x,   y);
  drawVector(x,   y+6);
  drawVector(x+8, y+6);
  drawVector(x,   y+6);
  drawVector(x,   y+12);
  drawVector(x+8, y+12);
}

void drawPoint(int x, int y)
{
  Timer1.pwm(xPin, x, period);
  Timer1.pwm(yPin, y, period);
}

void drawVector(int x, int y)
{
  int distance = x;

  if(y > x) distance = y;

  delayMicroseconds(3200);

  Timer1.pwm(xPin, x, period);
  Timer1.pwm(yPin, y, period);
}

void demoSizeDelay()
{
  int step = 32;
  
  for(int x = step; x < 256; x += step)
  {
    drawVector(x,0);
    drawVector(x,x);
    drawVector(0,x);

    x += step;
    
    drawVector(0,x);
    drawVector(x,x);
    drawVector(x,0);
  }
}

void demoSizeDelay2()
{
  int step = 64;
  
  for(int x = step; x < 255; x += step)
  {
    drawVector(255-x,255);
    drawVector(255-x,255-x);
    drawVector(255,  255-x);

    x += step;
    
    drawVector(255,  255-x);
    drawVector(255-x,255-x);
    drawVector(255-x,255);
  }
}

void demoHilbertCurve(int depth)
{
  
}

void drawHilbertCurve(int x, int y, int rotation, int symmetry, int depth)
{
  if(depth == 0) return;
  
  // Scale LUT (1 / (2^x - 1))
  int scale = 255;
  if     (depth == 2) scale = 85;
  else if(depth == 3) scale = 36;
  else if(depth == 4) scale = 17;
  else if(depth == 5) scale = 8;
  else if(depth == 6) scale = 4;
  else if(depth == 7) scale = 2;
  else if(depth == 8) scale = 1;

  if(symmetry == 0)
  {
    if(rotation == 0)
    {
      drawHilbertCurve(x, y, 1, 1, depth-1);
      
      drawVector(x + scale + subscale, y);
      
      drawHilbertCurve(x, y, 0, 0, depth-1);
      
      drawVector(x + scale + subscale, y + scale + subscale);
      
      drawHilbertCurve(x, y + scale, 0, 0, depth-1);
      
      drawVector(x, y);
      
      drawHilbertCurve(x, y, 3, 1, depth-1);
    }
    else if(rotation == 1)
    {
      
    }
    else if(rotation == 2)
    {
      
    }
    else if(rotation == 3)
    {
      
    } 
  }
  else
  {
    if(rotation == 0)
    {
      
    }
    else if(rotation == 1)
    {
      
    }
    else if(rotation == 2)
    {
      
    }
    else if(rotation == 3)
    {
      
    }
  }
}

//
//void demoStar()
//{
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 255, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 225, period);
//  Timer1.pwm(yPin, 209, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 149, period);
//  Timer1.pwm(yPin, 253, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 63, period);
//  Timer1.pwm(yPin, 237, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 7, period);
//  Timer1.pwm(yPin, 171, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 7, period);
//  Timer1.pwm(yPin, 83, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 63, period);
//  Timer1.pwm(yPin, 17, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 149, period);
//  Timer1.pwm(yPin, 1, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 127, period);
//  Timer1.pwm(yPin, 127, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 225, period);
//  Timer1.pwm(yPin, 45, period);
//
//  delayMicroseconds(drawDelay);
//}
//
//void demoSquare()
//{
//  Timer1.pwm(xPin, 0, period);
//  Timer1.pwm(yPin, 0, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 255, period);
//  Timer1.pwm(yPin, 0,   period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 255, period);
//  Timer1.pwm(yPin, 255, period);
//
//  delayMicroseconds(drawDelay);
//  
//  Timer1.pwm(xPin, 0,   period);
//  Timer1.pwm(yPin, 255, period);
//
//  delayMicroseconds(drawDelay);
//}
//
//void demoDiamond()
//{
//  Timer1.pwm(xPin, 128, period);
//  Timer1.pwm(yPin, 0,   period);
//
//  delayMicroseconds(drawDelay);
//  
//  Timer1.pwm(xPin, 255, period);
//  Timer1.pwm(yPin, 128, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 128, period);
//  Timer1.pwm(yPin, 255, period);
//
//  delayMicroseconds(drawDelay);
//
//  Timer1.pwm(xPin, 0,   period);
//  Timer1.pwm(yPin, 128, period);
//
//  delayMicroseconds(drawDelay);
//}
