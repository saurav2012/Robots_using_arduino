#include <Servo.h>
#include<NewPing.h>
int trigPin=13;
int echoPin=12;
float timeTaken=0;
int Servopin=11;
const int LMF = 4;
const int LMB = 5;
const int RMF= 6;
const int RMB = 7;
int ENA=3;
int ENB=9;
#define maximum_distance 200 //cm
boolean goesForward = false;
int distance=100;
int Speed=75;
//NewPing sonar(trigpin, echopin, maximum_distance); //sensor function
Servo servomotor; //our servo name


void setup(){
  Serial.begin(9600);
  pinMode(RMF, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  analogWrite(ENA,Speed);
  analogWrite(ENB,Speed);
  servomotor.attach(Servopin); //our servo pin
  servomotor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
    
}

void loop(){
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  if (distance <= 20){
    moveStop();
    delay(200);
    moveBackward();
    delay(200);
    moveStop();
    delay(200);
    distanceRight = lookRight();
     Serial.print(distanceRight);
     Serial.print(" ");
    delay(200);
    distanceLeft = lookLeft();
     Serial.print(distanceLeft);Serial.print(" ");
    delay(200);
    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
   distance = readPing();
   Serial.println(distance);
}

int lookRight(){  
  servomotor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servomotor.write(90);
  return distance;
}
int lookLeft(){
  servomotor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servomotor.write(90);
  return distance;
  delay(100);
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop()
{  
  digitalWrite(RMF, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void moveForward()
{
  if(!goesForward){
    goesForward=true;
    digitalWrite(LMF, LOW);
    digitalWrite(RMF, HIGH);
    digitalWrite(LMB, HIGH);
    digitalWrite(RMB, LOW); 
  }
}
void moveBackward()
{
  goesForward=false;
  digitalWrite(LMB, HIGH);
  digitalWrite(RMB, HIGH);
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW);
}
void turnRight(){
  digitalWrite(LMF, HIGH);
  digitalWrite(RMB, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMF, LOW);
  delay(500);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
}

void turnLeft()
{
  digitalWrite(LMB, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  delay(500);
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
}
