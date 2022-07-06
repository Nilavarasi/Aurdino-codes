//#include <Servo.h>
//
//int sensorPin = A0;
//int servoPin  = 9;
//
//int sensorValue = 0;
//int servoGrad = 90;
//int tolerance = 40;
//
//Servo myservo;
//
//void setup() {
//  pinMode( sensorPin, INPUT);
//  myservo.attach( servoPin );
//  myservo.write( servoGrad );
//    Serial.println("my output");
//
//}
//
//void loop() {
//  sensorValue = analogRead(sensorPin);
//  Serial.begin(9600);
//  Serial.println("my output");
//  Serial.println(sensorValue);
//   Serial.println(512-tolerance);
//   Serial.println(servoGrad);
//  if ( sensorValue < (512-tolerance) )
//  {
//    if (servoGrad < 180) servoGrad++;
//  }
//
//  if ( sensorValue > (512+tolerance) )
//  {
//    if (servoGrad > 0) servoGrad--;
//  }
//
//  myservo.write( servoGrad ); 
//
//  delay(100);
//}


#include <Servo.h>

int sensorPin = A0;
int servoPin  = 9;

int sensorValue = 0;
int servoGrad = 90;
int tolerance = 40;

Servo myservo;

void setup() {
  pinMode( sensorPin, INPUT);
  myservo.attach( servoPin );
  myservo.write( servoGrad );
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
   Serial.println(sensorValue);
   Serial.println(512-tolerance);
   Serial.println(servoGrad);
  if ( sensorValue < (512-tolerance) )
  {
    if (servoGrad < 180) servoGrad++;
  }

  if ( sensorValue > (512+tolerance) )
  {
    if (servoGrad > 0) servoGrad--;
  }

  myservo.write( servoGrad ); 

  delay(100);
}
