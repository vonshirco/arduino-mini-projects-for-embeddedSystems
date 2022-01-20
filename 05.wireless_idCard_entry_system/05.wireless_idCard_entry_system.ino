/*
The sketch begins by calling on the SPI, RFID, Servo, Pitches, 
and Wire libraries to control communication between the Arduino, 
RFID module, and servo. Two melodies are defined, one for a positive 
reading on your card and the other for a negative reading. The green 
LED is set to Arduino pin 2, the red LED to pin 3, the piezo buzzer 
to pin 8, and the servo to pin 9.
The following line is where you add your card’s hex value:
----------------------------------------------------------
byte card[5] = {0x4D,0x55,0xAD,0xD3,0x66};
----------------------------------------------------------
Pass your card in front of the reader. If the hex code on the card 
matches that in your sketch, the green LED lights up, a tune plays, 
and the servo moves. The reader rejects all other cards unless you 
add their number to the code at 1. If a card is rejected, the red LED 
lights up and a different tune plays, but the servo does not move.
*/

#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#include "pitches.h"
#include <Wire.h>

RFID rfid(10,5); //Define the RFID

//Replace this with the code from your card in hex form
byte card [5] = {0x4D,0x55,0xAD,0xD3,0X66};
//List any other codes for cards with access here

byte serNum[5];
byte data[5];

//Define the melodies for successful access and denied access
int access_melody[] = {NOTE_G4, 0, NOTE_A4, 0, NOTE_B4, 0, NOTE_A4, 0, NOTE_B4, 0, NOTE_C5, 0};
int access_noteDurations[] = {8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4};
int fail_melody[] = {NOTE_G2, 0, NOTE_F2, 0, NOTE_D2, 0};
int fail_noteDurations[] = {8, 8, 8, 8, 8, 4};

int LED_access = 2; //Pin connected to green LED
int LED_intruder = 3; //Pin connected to red LED
int speaker_pin = 8; //Pin connected to piezo buzzer
int servoPin = 9; //Pin connected to servo

Servo doorLock; //Define the servomotor

void setup() {
  // put your setup code here, to run once:
  doorLock.attach(servoPin); //set servo as a pin
  Serial.begin(9600); //Start serial communication
  SPI.begin(); //start serial communication between the RFID and the PC
  rfid.init(); //Initialize the RFID
  Serial.println("Arduino card reader");
  delay(1000);
  pinMode(LED_access, OUTPUT);
  pinMode(LED_intruder, OUTPUT);
  pinMode(speaker_pin, OUTPUT);
  pinMode(servoPin, OUTPUT);
}

void loop() { //Create a variable for each user
  // put your main code here, to run repeatedly:
  boolean card_card = true; //Define your card
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      delay(1000);
      data[0] = rfid.serNum[0];
      data[1] = rfid.serNum[1];
      data[2] = rfid.serNum[2];
      data[3] = rfid.serNum[3];
      data[4] = rfid.serNum[4];
      }
      Serial.print("Card found - code:");
      for (int i = 0; i < 5; i++) {
        //If it is not your, the card is considered false
        if (data[i] != card[i]) card_card = false;
        }
        Serial.println();
        if (card_card) { //A card with access permission is found
          Serial.print("Hello"); //Print to the Seril Monitor
          for (int i = 0; i < 12; i++) { //Play welcome music
            int access_noteDuration = 1000 / access_noteDurations[i];
            tone(speaker_pin, access_melody[i], access_noteDuration);
            int access_pauseBetweenNotes = access_noteDuration * 1.30;
            delay(access_pauseBetweenNotes);
            noTone(speaker_pin);
            }
          } else { //If the card is not recognized
            //Print message to Serial Monitor
            Serial.println("card not Recognized! Contact the Administrator!");
            digitalWrite(LED_intruder, HIGH); //Turn on red LED
            for (int i = 0; i < 6; i++) { //Play intruder melody
              int fail_noteDuration = 1000 / fail_noteDurations[i];
              tone(speaker_pin, fail_melody[i], fail_noteDuration);
              int fail_pauseBetweenNotes = fail_noteDuration * 1.30;
              delay(fail_pauseBetweenNotes);
              noTone(speaker_pin);
              }
              delay(1000);
              digitalWrite(LED_intruder, LOW); //Turn off red LED
            }

            if (card_card) { //Add other users with access here
              Serial.println("Access Granted...........Welcome!");
              digitalWrite(LED_access, HIGH); //Turn on green LED
              doorLock.write(180); //Turn servo 180 degrees
              delay(5000); //Wait for 5 seconds
              doorLock.write(0); //Turn servo back to 0 degrees
              digitalWrite(LED_access, LOW); //Turn off green LED
              }
              Serial.println();
              delay(500);
              rfid.halt();
    }
}
