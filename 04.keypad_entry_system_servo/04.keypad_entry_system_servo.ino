/*
First, the sketch calls on the Keypad, Servo, and Password libraries. 
The Servo library is included in the IDE, but you’ll have to download 
the Keypad and Password libraries (http://nostarch.com/ arduinohandbook/). 
We then set the eight pins that will determine the input from the keypad, 
and set Arduino pins 11 and 12 to control the LEDs and pin 13 to control the servomotor. 
The Arduino waits for your code input from the keypad and for you to confirm your input with *.
Once you’ve pressed the asterisk key, the sketch will check the entry against the password in the code. 
If the entry doesn’t match the password, the red LED will be set to HIGH and light; 
if the entry does match the password, the green LED will be set to HIGH and light, 
and the servomotor will turn. Pressing # will reset the sketch so it’s ready for another entry.
***With the keypad face up, the wires are numbered 1–8 from left to right. The first four wires 
correspond to the rows, and the latter four to the columns.

To alter the password, change the number in quotation marks in the following line.
----------------------------------------------------------------------------------
Password password = Password("2468");
----------------------------------------------------------------------------------
Keypad Library for Arduino 
Authors: Mark Stanley, Alexander Brevig
http://playground.arduino.cc/Main/KeypadTutorial 
*/

#include <Password.h>
#include <Keypad.h>
#include <Servo.h>

Servo myservo;
Password password = Password("2468"); //Set Password

const byte ROWS = 4; //Set four rows
const byte COLS = 4; //Set four columns

char keys[ROWS][COLS] = {  //Define the keymap
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
  byte rowPins[ROWS] = {9,8,7,6}; //Pins connected to the keypad ROW0, ROW1, ROW2, and ROW3
  byte colPins[COLS] = {5,4,3,2}; //Pins connected to the keypad COL0, COL1, COL2, and COL3

  //Create the keypad
  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(200);
  pinMode(11, OUTPUT); //Set green LED as output
  pinMode(12, OUTPUT); //Set red LED  as output
  myservo.attach(13); //Pin connected to servo
  keypad.addEventListener(keypadEvent); //Add an event listener to detech key presses
}

void loop() {
  // put your main code here, to run repeatedly:
  keypad.getKey();
  myservo.write(0);
}

void keypadEvent(KeypadEvent eKey) {
  switch (keypad.getState()) {
    case PRESSED:
    Serial.print("Pressed: ");
    Serial.println(eKey);
    switch (eKey) {
      case '*': checkPassword();
      break;
      case '#': password.reset();
      break;
      default: password.append(eKey);
      }
    }
  }

void checkPassword() {
  if (password.evaluate()) {  //If Password is correct...
    Serial.println("Success");
    myservo.write(90); //Move servo arm 90 degrees
    digitalWrite(11, HIGH); //Turn on green LED
    delay(500);
    digitalWrite(11, LOW); //Turn off green LED
    } else {   //If the Password is incorrect...
      Serial.println("Wrong");
      myservo.write(0);
      digitalWrite(12, HIGH); //Turn on red LED 
      delay(500); //Wait 5 second
      digitalWrite(12, LOW); //Turn off red LED
      }
  }
