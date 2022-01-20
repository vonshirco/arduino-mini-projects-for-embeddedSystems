/*
from beginner kit for arduino tutorial Project 10 Servo
*/

#include <Servo.h>  //Declare to insert Servo.h library
Servo myservo;  //Create servo object to control a servo
int pos = 0;  //Variable pos to store position of servo

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);  //attach the servo to digital pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos < 180; pos += 1) {  //servo turns from 0 to 180 in steps of 1 degree
    myservo.write(pos);  //tell servo to go to position in variable 'pos'
    delay(15);  //waits 15ms for the servo to reach the position
    }

    for (pos = 180; pos = 0; pos -= 1) {  //servo turns from 180 to 0 in steps
      myservo.write(pos);  //tell servo to go to position in variable 'pos'
      delay(15);  //waits 15ms for the servo to reach the position
      }
}
