/*
from beginner kit for arduino tutorial Project 11 Controllable Servo

You can also modify this circuit by swapping the potentiometer for 
a sensor such as a tilt switch, or changing the actuator to an LED.
Get tinkering and use your imagination!

Servo turns according to the position of the potentiometer.
*/

#include <Servo.h>  //Insert the Servo Library
Servo myservo;  //Create servo object to control servo 

int potPin = 0;  //connect potentiometer to analog pin 0
int val;  //variables value to read value from analog pin

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);  //Attach the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potPin);  //reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 179); //Scale it to use it with servo (value between 0 and 179)
  //The format of map function is: map(value, fromLow(input), fromHigh(input), toLow(output), toHigh(output))

  myservo.write(val);  //Sets the servo position according to the scaled value
  delay(15);  //wait for 15ms to turn to certain position
}
