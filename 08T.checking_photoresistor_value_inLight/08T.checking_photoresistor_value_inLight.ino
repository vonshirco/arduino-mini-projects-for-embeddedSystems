/*
check the photoresistor’s value in ambient light.
-------------------------------------------------
  Insert your photoresistor into the breadboard. Connect one leg to the +5V rail 
using a jumper wire. Connect a 10k-ohm resistor to the other leg, and connect 
the other side of this resistor to Arduino A0 and GND on the breadboard.
  Open the Serial Monitor in the Arduino IDE. It will show the value being read 
from the light resistor in normal lighting conditions. Take note of your number,
which will be different depending on your lighting conditions.
  Now shine the laser on the resistor’s cell, and also note this number
  *This might seem counterintuitive, as you would expect more light to provide 
  a higher number, but the figure is actually translating the resistance—more 
  light, less resistance. Your values will differ from those shown here, so 
  make sure to record your two readings.
*/

void setup() { 
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Photoresistor Values...");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4, HIGH);
  Serial.println(analogRead(0));
}
