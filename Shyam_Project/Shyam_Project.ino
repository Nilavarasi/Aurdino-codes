// Author: Shyam Rajasekaran
#include <Servo.h>
#define trigPin 3
#define echoPin 2
Servo servo1;
Servo servo2;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(4);
  servo2.attach(5);
  servo2.write(0);
  servo1.write(0);
}

void loop() {
  long duration, distance; 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration/2) / 29.1;
  if (distance < 10) {
  Serial.println("the distance is less than 5");
  servo1.write(90);
  servo2.write(90);
  delay(2000);
  servo2.write(0); servo1.write(0);
}
