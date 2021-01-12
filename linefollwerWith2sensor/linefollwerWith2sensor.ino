int pin1=8;
int pin2=10;
#define LMF 5       // left motor
#define LMB 4       // left motor
#define RMF 7       // right motor
#define RMB 6       // right motor
int ENA=3;
int ENB=9;
int Speed=255;
void setup() {
  // put your setup code here, to run once:
pinMode(pin1,INPUT);
pinMode(pin2,INPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(LMF, OUTPUT);
pinMode(LMB, OUTPUT);
pinMode(RMF, OUTPUT);
pinMode(RMB, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
boolean IR1= digitalRead(pin1);  //left
boolean IR2= digitalRead(pin2);  //right
Serial.print(IR1);
Serial.println(IR2);
if(IR1==LOW && IR2==LOW)
{
  forward();
}
if(IR1==LOW && IR2==HIGH)
{
  left();
}
if(IR1==HIGH && IR2==LOW)
{
  right();
}
if(IR1==HIGH && IR2==HIGH)
{
  turn();
}

}
void forward()
{
   digitalWrite(LMF,HIGH);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,HIGH);
   digitalWrite(RMB,LOW);
   analogWrite(ENA,Speed);
   analogWrite(ENB,Speed);
}
void left()
{ 
   digitalWrite(LMF,HIGH);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,LOW);
   digitalWrite(RMB,LOW);
   analogWrite(ENB,Speed);
}
void right()
{
   digitalWrite(LMF,LOW);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,HIGH);
   digitalWrite(RMB,LOW);
   analogWrite(ENA,Speed);
}
void turn()
{  
   digitalWrite(LMF,HIGH);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,LOW);
   digitalWrite(RMB,HIGH);
   analogWrite(ENA,Speed);
   analogWrite(ENB,Speed);
}
