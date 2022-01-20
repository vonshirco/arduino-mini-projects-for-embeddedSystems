/*
The sketch works by setting Arduino pin 13 as output for the LED, 
pin 2 as input for the PIR sensor, and pin 10 as output for the piezo buzzer. 
When the PIR sensor is triggered, a HIGH signal is sent to the Arduino, 
which will in turn light the LED and play a tone on the piezo buzzer.
*/

int ledPin = 13;  //Pin connected to LED
int inputPin = 2;  //Pin connected to PIR sensor
int pirState = LOW;  //Start PIR state LOW with no motion
int val = 0;  //Variable for reading the pin status
int pinSpeaker = 10;  //Pin connected to piezo

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //Set LED as output
  pinMode(inputPin, INPUT); //Set sensor as input
  pinMode(pinSpeaker, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);  //Read PIR input value

  if (val == HIGH) { //If Motion is detected (input is HIGH)
    digitalWrite(ledPin, HIGH); //turn on LED
    playTone(300, 160);
    delay(150);
    if (pirState == LOW) {
      Serial.println("Motion Detected!"); //Print to the serial monitor if motion is detected
      pirState == HIGH;
      }
      
    } else {  //If Motion is not detected (input is LOW)
      digitalWrite(ledPin, LOW); //turn off LED
      playTone(0, 0);
      delay(300);
      if (pirState == HIGH) {
        Serial.println("Motion Ended!");
        pirState == LOW;
        }
        
      }
}

void playTone (long duration, int freq) { //Duration in ms, Frequency in Hz
  duration *= 1000;  //same as (duration * 1000 = duration2), (duration2 * 1000 = duration3), (duration3 * 1000 = duration4), ...
  int period = (1.0 / freq) * 1000000;
  long elapsed_time = 0;
  while (elapsed_time < duration) {
    digitalWrite(pinSpeaker, HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(pinSpeaker, LOW);
    delayMicroseconds(period / 2);
    elapsed_time += (period);
    }
  }
