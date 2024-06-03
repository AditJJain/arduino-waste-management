#include <Servo.h>   //servo library

Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = 7;
int led= 10;
long duration, dist, average; //creating variables
long aver[3];   //array with 3 elements for average

void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close on power on
    delay(100);
    servo.detach(); //to save power
} 

void measure() {  
digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15); //sequence generates an short trigger pulse
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT); //sets echo to input, to listen for the pulse
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance, loop repeats thrice
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist<30 ) {
//Change distance as per your need
 servo.attach(servoPin);
 delay(1000);
 servo.write(0);  
 delay(5000);       
 servo.write(180);    
 delay(2000);
 servo.detach();      
}
Serial.print(dist);
}
