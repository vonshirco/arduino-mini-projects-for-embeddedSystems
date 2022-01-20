/*
The sketch first calls on the Servo library and then defines the two servos as tilt 
and pan. The joystick x-axis is attached to Arduino pin A0 and the y-axis to Arduino A1, 
and these are our INPUT. The x- and y-axes are then set as variables for movement. 
The tilt servo is attached to Arduino pin 9 and pan is attached to Arduino pin 10, 
and these are our OUTPUT. The Arduino then reads the INPUT from the joystick and changes 
this voltage to OUTPUT, moving the servos according to which direction is chosen.
-----------------------------------------------------------------------------------------
Used with kind permission from http://learn.explorelabs.com/ 
Creative Commons 4.0 Share Alike (CC by SA 4.0) license
*/

#include <Servo.h>
Servo tilt, pan; //Create servo object
int joyX = A0; //Analog pin connected to x-axis servo
int joyY = A1; //Analog pin connected to y-axis servo
int x, y; //Variables to read values

void setup() {
  // put your setup code here, to run once:
  tilt.attach(9); //Attach tilt servo on pin 9 to the servo object
  pan.attach(10); //Attach pan servo on pin 10 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  x = joyX; //Read value of x-axis (between 0 and 1023)
  y = joyY; //Read value of y-axis (between 0 and 1023)
  
  x = map(analogRead(joyX), 0, 1023, 900, 2100); //Scale it to use with servo between 900 to 2100 microseconds 
  y = map(analogRead(joyY), 0, 1023, 900, 2100); 
  //Meaning - map(analogRead(joyY), 0, 1023, 900, 2100); = map(analogRead(Number to be scaled), min-input_value, max-input, min-output, max-output);

  tilt.write(x); //Set servo position according to scaled value
  pan.write(y); //Set servo position according to scaled value

  delay(15); //wait for servos to get to new position
}
