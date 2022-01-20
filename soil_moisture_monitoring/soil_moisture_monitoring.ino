/*
The sketch first defines Arduino pin A0 so that it reads the moisture sensor value. 
It then defines Arduino pin 11 as output for the buzzer, and pin 13 as output for the LED. 
Use the Serial.Println() function to send the reading from the sensor to the IDE, in order 
to see the value on the screen.

Change the value in the line

if(analogRead(0) > 900){

depending on the reading from the sensor when it is dry (here it’s 900). When the soil is 
moist, this value will be below 900, so the LED and buzzer will remain off. When the value 
rises above 900, it means the soil is drying out, and the buzzer and LED will alert you to 
water your plant.
*/

const int moistureA0 = 0; 
int pinA0 = 0; //pin connected to A0 of the controller
int tmp = 0; //value of the analog pin
int buzzPin = 11; //pin connected to the piezo buzzer
int LED = 13; //pin connected to the led

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Send arduino reading to IDE
  Serial.println("Soil Moisture Sensor");
  pinMode(moistureA0, INPUT); //set pin as input
  pinMode(buzzPin, OUTPUT); //set pin as output
  pinMode(LED, OUTPUT); //set pin as output

}

void loop() {
  // put your main code here, to run repeatedly:
  tmp = analogRead(moistureA0);
  if (tmp != pinA0){
      pinA0 = tmp;
      Serial.print("A = "); //Show the resistance value of the sensor in the IDE
      Serial.println(pinA0);
    }
  delay(1000);

  if(analogRead(0) > 900){  //if the resistance is high (in dry soil)
    Serial.println("Soil Too Dry Switch On Water Pump!");
    digitalWrite(buzzPin, HIGH); //buzzer will sound
    digitalWrite(LED, HIGH); //LED will light
    delay(1000); //wait for one second
    digitalWrite(buzzPin, LOW);
    digitalWrite(LED, LOW);
    
    }else{ //if resistance is not high or its low (in wet soil)
      Serial.println("Soil is Now Wet!");
      digitalWrite(buzzPin,LOW); //buzzer stays off
      digitalWrite(LED, LOW); //LED does not light
      }

}
