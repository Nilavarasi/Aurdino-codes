#include <LiquidCrystal.h>
//#define echoPin 11 // attach pin D2 Arduino to pin Echo of HC-SR04
//#define trigPin 12 //attach pin D3 Arduino to pin Trig of HC-SR04

const int echoPin = 5;
const int trigPin = 6;
// defines variables
long duration; // variable for the duration of sound wave travel

int buzzer = A0;//the pin of the active buzzer
int red = 2;
int distance; // variable for the distance measurement
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
  pinMode(red, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("DistanceComplted");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);



  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  lcd.setCursor(0, 1);
  lcd.clear();
  lcd.print(String("DistanceDone:")+String(distance));
  if(distance<=3){
    digitalWrite(buzzer,HIGH);
    delay(10);
    digitalWrite(red, HIGH); 
    delay(10);
    }

  else if(distance > 3)
  {
     digitalWrite(buzzer,LOW);
     digitalWrite(red, LOW);
   }
}
