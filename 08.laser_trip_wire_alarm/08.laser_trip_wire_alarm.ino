/*
The sketch first sets Arduino pin 11 as an OUTPUT for the piezo buzzer and 
pin 13 as an OUTPUT for the LED. The photoresistor is connected to Arduino pinA0.
If the analog reading from A0 is more than 850 (meaning that there is less light 
and the laser beam has been broken), the buzzer will be set to HIGH and turn on 
and the LED will turn off. Remember to change the resistance value depending on 
your calibration on this line:
------------------------------
if (analogRead(0) > 850) {
------------------------------
As noted earlier, when the laser is shining on the resistor it reads about 620, 
so in the sketch I’ve set the buzzer to sound only if the value is more than 850.
This value is between our laser value and our nonlaser value, so we know the laser
beam to the resistor has been broken if the value reaches 850.
*/

int buzzPin = 11; //Pin connected to the piezo
int LED = 13; //Pin connected to the LED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT); //Set pin as output
  pinMode(LED, OUTPUT); //Set pin as output
  Serial.println("Photoresistor Value");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(0));
  if (analogRead(0) > 1022) { //Set this value depending on the values of your photoresistor //(analogRead(0) > 850)
    digitalWrite(buzzPin, HIGH); //If value is above 850, turn piezo ON
    digitalWrite(LED, LOW); //If value is above 850, turn the LED OFF
    delay(1000); //wait for 1 second
    digitalWrite(buzzPin, LOW);
    digitalWrite(LED, LOW); //LED remains OFF
    
    } else { //If value is 850 or below
      digitalWrite(buzzPin, LOW); //Light shining on photoresistor the piezo is OFF
      digitalWrite(LED, HIGH); //Light shining on photoresistor the LED is ON
      }
}
