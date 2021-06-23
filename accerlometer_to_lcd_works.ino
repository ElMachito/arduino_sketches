

#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

int backLight = 13;

const int xPin = 3;                   // x-axis
const int yPin = 2;                   // y-axis
const int zPin = 1;                   // z-axis

void setup()
{
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);
  Serial.begin(9600);
  
}

void loop()



{
  //Uncomment the lines below for Serial output
  
  //Serial.print("X=");
  //Serial.print(analogRead(xPin));  
  //Serial.print("\t");
  //Serial.print("Y=");
  //Serial.print(analogRead(yPin));  
  //Serial.print("\t");
  //Serial.print("Z=");
  //Serial.print(analogRead(zPin));  
  //delay(100);
  
  //Comment if not using a LCD.
  
  lcd.begin(2,16);              
  lcd.clear();                
  lcd.setCursor(0,0);  
  lcd.print("X= ");
  lcd.print(analogRead(xPin));  
  lcd.setCursor(10,0);          
  lcd.print("Y= ");
  lcd.print(analogRead(yPin));
  lcd.setCursor(5,1);          
  lcd.print("Z= ");
  lcd.print(analogRead(zPin));
  delay(300);
} 

 





   



