
int potPin = A0; //Analog pin connected to potentiometer
int potValue = 0; //Value that will read from the potentiometer
int led = 9; // pin 9 (connected to the LED) is capable o PWM

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); //set pin 9 to output
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin); //Read potentiometer value from A0 pin
  
  analogWrite(led, potValue/4); //Send potentiometer value to LED to control brightness with PWM 

  delay(10); //delays for 10ms
  
}
