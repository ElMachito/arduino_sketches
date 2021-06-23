#include <LiquidCrystal.h>
 
#define trigPin 13
#define echoPin 12
 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 

void setup() {
 lcd.begin(16, 2);
 lcd.print("Distance (cm):");
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 }
 
void loop() {
 lcd.setCursor(0, 1);
 int duration, distance;
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 if (distance >= 200 || distance <= 0){
 lcd.print("Out of range");
 }
 else {
 lcd.print(distance);
 }
 delay(500);
 }
