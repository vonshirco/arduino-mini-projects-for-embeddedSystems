/*
  Make sure you use the values that you decoded in step 3 of “The Setup” on page 96 
in place of the values included here when completing the sketch. When you’re 
changing the value in the sketch to match your own codes, keep the 0x and add your
HEX code after it. For example, for the first button I decoded, the HEX code is FFA05F,
which looks like this in the sketch:
-------------------------------------
unsigned long Value1 = 0xFFA05F;
-------------------------------------
  In this project we’re controlling servos, but you could adapt the code slightly to 
remotely control anything that needs to be set to HIGH, such as an LED or piezo buzzer.
  The sketch calls on the IRremote library to read from the receiver and the Servo library 
to move the motors. The first two buttons are assigned to the x-axis servo to move the 
angle to a maximum of 70 degrees for left pan or 160 degrees for right. The third and 
fourth buttons are assigned to the y-axis servo to control the up and down tilt movement.

  If you want to adapt this to other output, change the code:
-------------------------------------------------------------
servo.write
-------------------------------------------------------------
to:
-------------------------------------------------------------
digitalWrite(pin, HIGH)
-------------------------------------------------------------
IR Library Copyright Ken Shirriff 
Used with kind permission
http://arcfn.com
-------------------------------------------------------------
*/

// WHEN THE GOING GET TOUGH - THE TOUGH GET GOING

#include <Servo.h> //Include the Servo library
#include <IRremote.h> //Include the IRremote library

unsigned long Value1 = 0xFFA05F; //Change this to your value
unsigned long Value2 = 0xFF50AF; //Change this to your value
unsigned long Value3 = 0xFF807F; //Change this to your value
unsigned long Value4 = 0xFF607F; //Change this to your value

int RECV_PIN = 11; // Pin connected to receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

Servo servo1;
Servo servo2; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn(); //Start the IR receiver
  servo1.attach(10); //Pin connected to servo 1
  servo2.attach(9); //Pin conneceted to servo 2
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) { //If there is an input, decode value
    Serial.println(results.value, HEX); //Display button value on Serial Monitor in hexadecimal format
    irrecv.resume(); //Receive the next value
    } 
    
    if (results.value == Value1) { //if remote code matches value 1, then move the servo
      servo1.write(160);
      
      } else if (results.value == Value2) { //if remote code matches value 2, then move the servo
        servo1.write(70);
        
        } else if (results.value == Value3) { //if remote code matches value 3, then move the servo
          servo2.write(70);
          
          } else if (results.value == Value4) { //if remote code matches value 4, then move the servo
            servo2.write(160);
            
            }
}
