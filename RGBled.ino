//String msg="Which Colour do you want to Blink: ";
//String Mycolor;
#include<LiquidCrystal.h>
LiquidCrystal lcd(10,9,5,4,3,2);
int Mycolor;
int redpin=8; //yellow
int greenpin=11; //red
int bluepin=12;
int potPin1=A1;
int potPin2=A2;
int RVal,GVal,BVal;
int potPin3=A3;
#include<LiquidCrystal.h>
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("colorCode:");
Serial.begin(9600);
pinMode(redpin,OUTPUT);
pinMode(greenpin,OUTPUT);
pinMode(bluepin,OUTPUT);
pinMode(potPin1,INPUT);
pinMode(potPin2,INPUT);
pinMode(potPin3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
/*Serial.println(msg);
while(Serial.available()==0)
{
    
}*/
int potVal1=analogRead(potPin1);
int potVal2=analogRead(potPin2);
int potVal3=analogRead(potPin3);
RVal=(255./1023.)*potVal1;
GVal=(255./1023.)*potVal2;
BVal=(255./1023.)*potVal3;
lcd.setCursor(11,0);
lcd.print("R=");
lcd.print(RVal);
lcd.setCursor(0,1);
lcd.print("G=");
lcd.print(GVal);
lcd.setCursor(7,1);
lcd.print("B=");
lcd.print(BVal);
//Mycolor=Serial.readString();
  analogWrite(redpin,RVal);
  analogWrite(greenpin,GVal);
  analogWrite(bluepin,BVal);
}
