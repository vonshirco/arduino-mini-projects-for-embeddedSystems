/*
When an object is within the trigger distance, the red LED will light 
and the servo will move 45 degrees. You can change the distance of the 
sensor field in the following line of the sketch:
----------------------------------------------------------------------------
if (distance <= 15)
----------------------------------------------------------------------------
In this example, if something is sensed within a distance of 15 centimeters, 
the next block of code will run.
The Trig pin on the sensor is connected to Arduino pin 12 and emits an 
ultrasonic signal or ping. When the signal reaches an object, it bounces 
back to the module, and this echo is sent to Arduino pin 13. The time difference 
between the two signals gives us our distance reading. If the distance is more 
than our set minimum, the green LED stays on; if not, the red LED lights and the 
servo moves.
---------------------------------------------------------
NewPing Library created by Tim Eckel teckel@leethost.com.
Copyright 2012 License: GNU GPL v3
http://www.gnu.org/licenses/gpl-3.0.html
---------------------------------------------------------
*/

#include <NewPing.h> //call NewPing Library 
#include <Servo.h>   //call Servo library
#define trigPin 12 //Trig pin connected to Arduino 12
#define echoPin 13 //Echo pin connected to Arduino 13
#define MAX_DISTANCE 500
NewPing sonar(trigPin, echoPin, MAX_DISTANCE); //Library setting
int greenLed = 3, redLed = 2; //Set green LED to pin 3, red to pin 2
int pos = 20;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  myservo.attach(9); //Servo attached to pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  int duration, distance, pos = 0, i;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Trig pin sends a ping
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Echo receives the ping
  //distance = (duration/2) / 29.1; or
  distance = duration * 0.034/2; //0.034 = speed of sound in air
  Serial.print(distance);
  Serial.println(" cm");

  //If sensor detects object within 15 cm
  if (distance <= 15){
    digitalWrite(greenLed, LOW); //Turn off green LED
    digitalWrite(redLed, HIGH); //Turn on red LED
    myservo.write(180);   //Move servo arm 180 degree
    delay(450);
    digitalWrite(redLed, LOW);
    myservo.write(90);
    delay(450);
    digitalWrite(redLed, HIGH);
    myservo.write(0);
    delay(450);
    digitalWrite(redLed, LOW);
    myservo.write(90);
    
    }else{  //Otherwise
        digitalWrite(redLed, LOW);  //Turn off red LED
        digitalWrite(greenLed, HIGH);  //Turn on green LED
        myservo.write(90);
      }
      delay(450);
}
