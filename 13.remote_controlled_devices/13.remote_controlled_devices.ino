/*
Beginner kit for Arduino kit Tutorial Sample Code 14-2 (Remote control led/relays)
*/

#include <IRremote.h> //Include IRremote library
int RECV_PIN = 11;  //pin connected to receiver

int device1 = 10;  //pin connected to device1
int device2 = 9;
int device3 = 8;
boolean device1State = LOW;  //device1State to store the state of device
boolean device2State = LOW;
boolean device3State = LOW;

IRrecv irrecv(RECV_PIN); //define RECV_PIN as infrared receiver
decode_results results;  //define variable results to save the result of infrared receiver

unsigned long Value1 = 0xFFA05F;  //change this value to your remote button value
unsigned long Value2 = 0xFD00FF;
unsigned long Value3 = 0xFFBA1F;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();  //Start the IR receiver
  pinMode(device1, OUTPUT);  //define device1 as output signal
  pinMode(device2, OUTPUT);
  pinMode(device3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);  //Display button value on Serial Monitor in hexadecimal format

    //Once receive code from button, the state of the device is changed from HIGH to LOW or from LOW to HIGH
    if (results.value == Value1) {  //if remove code matches value1
      device1State = !device1State;  //reverse
      digitalWrite(device1, device1State);  //Change the state of device one
      }

      if (results.value == Value2) {
        device2State = !device2State;
        digitalWrite(device2, device2State);
        }

        if (results.value == Value3) {
          device3State = !device3State;
          digitalWrite(device3, device3State);
          }
    
    irrecv.resume();  //Receive the next value
    
    }
}
