#define LMF 5      //left motor forward
#define LMB 4      //left motor backward
#define RMF 6      //right motor forward
#define RMB 7      //right motor backward
int xPin=A2;       //x-axis(horizontal) potentiometer analog pin
int yPin=A3;       //Y-axis(vertical) potentiometer analog pin
int SwitchVal;     //switching action of joystick(on press joystick will off)
int SwitchPin=2;    
int ENA=3;          //left motor enabler
int ENB=9;          //right motor enabler
int Speedl;         //speed of left motor
int Speedr;         //speed of right motor
int xVal,yVal;      //value of horizontal and vertical pot in joystick(0-1023)
void setup() { 
  //put your setup code here, to run once:
pinMode(xPin,INPUT); 
pinMode(yPin,INPUT);
pinMode(SwitchPin,INPUT);
digitalWrite(SwitchPin,HIGH);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(LMF, OUTPUT);
pinMode(LMB, OUTPUT);
pinMode(RMF, OUTPUT);
pinMode(RMB, OUTPUT);
Serial.begin(9600);    //for serial moniter
}

void loop() {
  // put your main code here, to run repeatedly
//at mid of joystick xval show 532 and yval show 517  

SwitchVal=digitalRead(SwitchPin);  // read switch postion of joystick (0,1)
xVal=analogRead(xPin);              //x axis pot values(0,1023)
yVal=analogRead(yPin);              //x axis pot values(0,1023)
if(xVal<531 )    // move forward
{  
  Speedl=map(xVal,532,0,0,255);
  Speedr=map(xVal,532,0,0,255);
  forward(Speedl,Speedr);
}
else if(xVal>533 )   //move backward
{
  Speedl=map(xVal,532,1023,0,255);
  Speedr=map(xVal,532,1023,0,255);
  backward(Speedl,Speedr);
}
 else if(yVal>518)   //move right
{
  Speedr=map(yVal,517,1023,0,255);
  right(Speedr);
}
else if(yVal<517)   //move left
{
  Speedl=map(yVal,517,0,0,255);
  left(Speedl);
}    
else          //stop  
{
  Stop();
}
delay(100);
Serial.print(xVal);Serial.print(" "); //for print values of left values
Serial.println(yVal);                //for print values of left values
}
void forward(int Speedl,int Speedr)  //function to move forward 
{
   digitalWrite(LMF,HIGH);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,HIGH);
   digitalWrite(RMB,LOW);
   analogWrite(ENA,Speedl);
   analogWrite(ENB,Speedr);
}
void left(int Speedl)   //function to move left
{
   digitalWrite(LMF,HIGH);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,LOW);
   digitalWrite(RMB,LOW);
   analogWrite(ENB,Speedl);
}
void right(int Speedr)        //function to turn right 
{
   digitalWrite(LMF,LOW);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,HIGH);
   digitalWrite(RMB,LOW);
   analogWrite(ENA,Speedr);
}
void backward(int Speedl,int Speedr)  //function to move backward 
{  
   digitalWrite(LMF,LOW);
   digitalWrite(LMB,HIGH);
   digitalWrite(RMF,LOW);
   digitalWrite(RMB,HIGH);
   analogWrite(ENA,Speedl);    
   analogWrite(ENB,Speedr);    
}
void Stop()                    //function to stop 
{
   digitalWrite(LMF,LOW);
   digitalWrite(LMB,LOW);
   digitalWrite(RMF,LOW);
   digitalWrite(RMB,LOW);
   analogWrite(ENA,0);
   analogWrite(ENB,0);
}
