/* 
The sketch first reads the input from the potentiometer. It maps the input value 
to the output range, in this case nine LEDs. Then it sets up a for loop over the 
outputs. If the output number of the LED in the series is lower than the mapped 
input range, the LED turns on; if not, it turns off. See? Simple! If you turn 
the potentiometer to the right, the LEDs light up in sequence. Turn it to the 
left, and they turn off in sequence.
*/

const int analogPin = A0; //Pin connected to the potentiometer
const int ledCount = 9; //Number of LEDs
int ledPins[] = {2,3,4,5,6,7,8,9,10}; //an array of pin numbers to which LEDs are attached

void setup() {
  // put your setup code here, to run once:
  //loop over the pin array and set them all to the output
  for (int thisLed = 0; thisLed < ledCount; thisLed++){
    pinMode(ledPins[thisLed], OUTPUT); //Sets the LED pins as output
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading = analogRead(analogPin); //Analog input (to get the analog input signal from pin A0) or read the potentiometer
  //map the result to range from 0 to the number of LEDs 
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
  //loop over the LED array
  for (int thisLed = 0; thisLed < ledCount; thisLed++){
    //if the array element's index is less than ledLevel,
    //turn the pin for this element on
    if(thisLed < ledLevel){
      digitalWrite(ledPins[thisLed], HIGH); //turn ON LEDs in sequence
      }else{ //turn off all pins higher than the ledLevel
        digitalWrite(ledPins[thisLed], LOW); //turn OFF LEDs in sequence
        }
    }
}
