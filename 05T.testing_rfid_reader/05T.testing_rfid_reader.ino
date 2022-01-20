/*
RFID TEST SKETCH:
Upload the following test sketch for the RFID reader.
Keep the USB cable from your PC connected to the Arduino.
---------------------------------------------------------
*/

//RFID Library Created by Miguel Balboa (circuitito.com)
#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10 //arduino and module share data and communicate.
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

//Setup variables
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin(); //Start serial communication between the RFID and PC
  rfid.init(); //Initialize the RFID
  Serial.println("Testing RFID...");
}

void loop() {  //This loop looks for a card(s) to read
  // put your main code here, to run repeatedly:
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      if (rfid.serNum[0] != serNum0
          && rfid.serNum[1] != serNum1
          && rfid.serNum[2] != serNum2
          && rfid.serNum[3] != serNum3
          && rfid.serNum[4] != serNum4
           ) {
            //When a card is found, the following code will run
            Serial.println(" ");
            Serial.println("Card found");
            serNum0 = rfid.serNum[0];
            serNum1 = rfid.serNum[1];
            serNum2 = rfid.serNum[2];
            serNum3 = rfid.serNum[3];
            serNum4 = rfid.serNum[4];

            //Print the card ID to the Serial Monitor of the IDE
            Serial.println("Cardnumber:");
            Serial.print("Dec: ");
            Serial.print(rfid.serNum[0], DEC);
            Serial.print(",");
            Serial.print(rfid.serNum[2], DEC);
            Serial.print(",");
            Serial.print(rfid.serNum[1], DEC);
            Serial.print(",");
            Serial.print(rfid.serNum[3], DEC);
            Serial.print(",");
            Serial.print(rfid.serNum[4], DEC);
            Serial.println(" ");
            Serial.print("Hex: ");
            Serial.print(rfid.serNum[0], HEX);
            Serial.print(",");
            Serial.print(rfid.serNum[1], HEX);
            Serial.print(",");
            Serial.print(rfid.serNum[2], HEX);
            Serial.print(",");
            Serial.print(rfid.serNum[3], HEX);
            Serial.print(",");
            Serial.print(rfid.serNum[4], HEX);
            Serial.print(" ");
            
            } else {
              //If the ID matches, write a dot to the Serial Monitor
              Serial.print(".");
              }
           
      }
    }
    rfid.halt();
}
