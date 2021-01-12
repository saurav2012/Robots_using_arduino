#include <Servo.h>
#include<NewPing.h>
int distance=0;
int trigPin=10;  
int echoPin=11;  
#define MAX_DISTANCE 400
NewPing sonar(trigPin,echoPin,MAX_DISTANCE);
Servo myServo;
void setup(){
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); 
}
void loop() 
{
  for(int i=5;i<=175;i++)
  {  
  myServo.write(i);
  delay(30);
  distance =sonar.ping_cm();
  Serial.print(i); 
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
  for(int i=175;i>5;i--)
  {  
  myServo.write(i);
  delay(30);
  distance = sonar.ping_cm();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
