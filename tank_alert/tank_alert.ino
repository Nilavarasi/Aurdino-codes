#define echoPin 5 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel

int buzzer = 6;//the pin of the active buzzer
int green = 10;
int yellow = 11;
int red = 5;
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(buzzer,LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
//    
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

  if(distance==2){
    digitalWrite(buzzer,HIGH);
    delay(10);
    digitalWrite(red, HIGH);
    delay(10);
//  }else if(distance <=3  && distance >2) {
    }else if(distance ==7) {
//    digitalWrite(buzzer,HIGH);
//    delay(10);
    digitalWrite(yellow, HIGH);
    delay(10);
    } else if(distance ==11) {
//   } else if(distance <=6 && distance >5) {
//    digitalWrite(buzzer,HIGH);
//    delay(10);
    digitalWrite(green, HIGH);
    delay(10);
   }

    else if(distance > 2)
    {
      digitalWrite(buzzer,LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
      }
}
