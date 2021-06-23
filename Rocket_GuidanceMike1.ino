#include <Servo.h>

int xaccPin = 7;
int yaccPin = 6;
long xacc = 0;
long yacc = 0;
int anglex;
int angley;
int servoposx, servoposy;
int duration, inches;
long xacc1 = 0;
long yacc1 = 0;
long xacc2 = 0;
long yacc2 = 0;
long xacc3 = 0;
long yacc3 = 0;
long xaccs = 0;
long yaccs = 0;
long xaccd = 0;
long yaccd = 0;
int counter = 0;
Servo x1servo;
Servo x2servo;
Servo y1servo;
Servo y2servo;

void setup() 
{
  Serial.begin(9600);
  x1servo.attach(8);
  x2servo.attach(9);
  y1servo.attach(10);
  y2servo.attach(11);
  pinMode(xaccPin, INPUT);
  pinMode(yaccPin, INPUT);
  delay(1000);
  if (counter <= 1)
  {
      // starting values
      xacc1 = readAcceleration(xaccPin); 
      yacc1 = readAcceleration(yaccPin); 
      xacc2 = readAcceleration(xaccPin); 
      yacc2 = readAcceleration(yaccPin); 
      xacc3 = readAcceleration(xaccPin); 
      yacc3 = readAcceleration(yaccPin); 
      // stable position
      xaccs = (xacc1 + xacc2 + xacc3)/3;
      yaccs = (yacc1 + yacc2 + yacc3)/3;
  }
}





void loop() 
{
  xacc = readAcceleration(xaccPin);
  yacc = readAcceleration(yaccPin);
  xaccd = xacc - xaccs;
  yaccd = yacc - yaccs;
  anglex = map(xaccd, 280, -280, -90, 90);
  angley = map(yaccd, 280, -280, -90, 90);
  servoposx = map(anglex, -90, 90, 20, 160);
  servoposy = map(angley, -90, 90, 20, 160);
  x1servo.write(servoposx);
  x2servo.write(160 - servoposx);
  y1servo.write(servoposy);
  y2servo.write(160 - servoposy);
/*
  // Uncomment for testing purposes
  
  
  Serial.print("X1: ");
  Serial.print(servoposx);
  Serial.print("  X2: ");
  Serial.println(160 - servoposx);
  Serial.print("Y1: ");
  Serial.print(servoposy);
  Serial.print(  Y2: ");
  Serial.println(160 - servoposy);
  Serial.println();
*/
  delay(100);
}



long readAcceleration(int axe)
{
  int count = 0;
  long accel = 0;
  int value = 0;
  value = digitalRead(axe);
  while(value == HIGH) 
  {
     value = digitalRead(axe);
  }
  while(value == LOW) 
  {
    value = digitalRead(axe);
  }
  while(value == HIGH) 
  {
    value = digitalRead(axe);
    count = count + 1;
  }
  //accel = abs(8 * (count * 18 / 10 - 500)); //this was the original function
  accel = count;
  return accel;
}

