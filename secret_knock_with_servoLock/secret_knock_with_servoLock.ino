/*
We first call on the Servo library and set Arduino pin 9 to control the servo.
LEDs are attached to Arduino pins 3, 4, and 5, and these will light depending 
on the validity of a knock. The piezo acts as a sensor rather than a buzzer in
this project and is attached to Arduino pin A0. When someone knocks, the knock
is sensed by the piezo and a voltage value is sent to the A0 analog pin of the 
Arduino depending on the strength of the knock—the harder the knock, the higher
the value. A knock with a value below 10 is considered too quiet, and one with 
a value above 100 too loud, so neither will be accepted as a valid knock. 
The red LED lights if the knock is not accepted, and the yellow LED lights 
if it is. Any knock value between 10 and 100 is accepted as a valid knock and 
counted, and if three valid knocks are received, the servomotor moves and the 
green LED lights. 
As mentioned earlier, these are the two lines of code that set the parameters 
for measuring the voltage:
-----------------------------------------------------------------------------
const int quietKnock = 10; 
const int loudKnock = 100;
-----------------------------------------------------------------------------
If you were feeling particularly secretive, you could set this range even 
tighter to make the code harder to crack. Here’s the sketch:

------------------------------------------------
Created 18 September 2012 by Scott Fitzgerald 
Thanks to Federico Vanzati for improvements 
http://arduino.cc/starterKit 
This example code is part of the public domain.
------------------------------------------------

*/

#include <Servo.h>
Servo servo9; //Pin connected to the servo mpo

const int piezo = A0; //Pin connected to piezo
const int switchPin = 2; //Pin connected to servo
const int yellowLed = 3; //Pin connected to yellow LED
const int greenLed = 4; //Pin connected to green LED
const int redLed = 5; //Pin connected to red LED

int knockVal; //value for knock strength
int switchVal;

const int quiteKnock = 10; //set min value that will be accepted
const int loudKnock = 100; //set max value that will be accepted
boolean locked = false; //A true or false variable
int numberOfKnocks = 0; //value for number of knocks

void setup() {
  // put your setup code here, to run once:
  servo9.attach(9);
  pinMode(yellowLed, OUTPUT); //set LED pins as outputs
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(switchPin, INPUT); //set servo as input
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH); //Green LED is lit when the sequence is correct
  
  servo9.write(0);
  Serial.begin("The Door is Unlocked!");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (locked == false){ //if servo/door is unlocked or open
      switchVal = digitalRead(switchPin);
      if (switchVal == HIGH){  //if servo/door is locked or closed
          locked = true;
          digitalWrite(greenLed, LOW);
          digitalWrite(redLed, HIGH);
          servo9.write(90); //locked or closed
          Serial.println("The Door is Locked");
          delay(1000);
        }
    }

  if (locked == true){ //if servo/door is locked or closed
      knockVal = analogRead(piezo); //knock value is read by the analog pin (from the piezo)
      if(numberOfKnocks < 3 && knockVal > 0){
        if (checkForKnock(knockVal) == true){ //checks for correct number of Knocks
            numberOfKnocks ++;
          }
          Serial.print(3 - numberOfKnocks);
          Serial.println(" more knocks to go");
        }
        if (numberOfKnocks >= 3){  //if 3 valid knocks are detected the servo move or unlocks/opens
            locked = false;
            servo9.write(0);
            delay(20);
            digitalWrite(greenLed, HIGH);
            digitalWrite(redLed, LOW);
            Serial.println("The Door is Unlocked");
          }
    }

}

boolean checkForKnock(int value) { //checks knock value
  if (value > quiteKnock && value < loudKnock){ //value needs to be between these
     digitalWrite(yellowLed, HIGH);
     delay(50);
     digitalWrite(yellowLed, LOW);
     Serial.print("Valid Knock of Value: ");
     Serial.print(value);
     return true;
    }else{
      Serial.print("Bad Knock value: ");
      Serial.println(value);
      return false;
      }
  }
