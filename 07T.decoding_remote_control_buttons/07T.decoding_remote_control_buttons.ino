/*
--> The sketch first calls on the IRremote library, which reads from the IR receiver 
and sends the corresponding data to the Arduino. The IR receiver is assigned to 
pin 11 on the Arduino, and the sketch begins communicating with the Arduino IDE 
so that when a button is pressed the input is displayed in the Serial Monitor in 
real time. The sketch continues in a loop, looking for button presses, and shows 
the corresponding value to the IDE.
--> Open the Serial Monitor in your IDE.
--> Point your remote toward the receiver and try pressing different buttons. 
They will appear in the Serial Monitor decoded into letters and numbers in a 
format known as hexadecimal (HEX).
--> Try short, sharp presses to get the best results. If you press a button 
for too long, the Serial Monitor will show Fs for as long as you hold the button.
--> Write down the numbers that appear and the buttons they correspond to. 
You will need these numbers later.
--> Now that we’ve decoded the button signals from the remote control, we 
can use them in our projects.
------------------------------------------------------------------------------------
Copyright 2009 Ken Shirriff 
Used with kind permission
http://arcfn.com
------------------------------------------------------------------------------------
*/

#include <IRremote.h> //Use library
int receiver = 11; // Pin connected to receiver

IRrecv irrecv(receiver);
decode_results results;

int ledPin = 13;
int buzzPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Show keypresses in IDE
  irrecv.enableIRIn(); //Start up receiver
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.println("Decoding Remote Control...");
  Serial.println("....................................");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) { //If there is an input, decode value
    Serial.println(results.value,HEX); //Display button value on Serial Monitor in hexadecimal format
    irrecv.resume(); //Receive next value
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(500);
    } else{
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzPin, LOW);
      }
}
