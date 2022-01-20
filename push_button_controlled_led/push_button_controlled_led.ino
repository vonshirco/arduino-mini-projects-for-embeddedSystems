
const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0; //Gives pushbutton a value

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //set ledpin as output
  pinMode(buttonPin, INPUT); //set buttonPin as input
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin); //Read input from pin 2
  if(buttonState == HIGH){ //if pushbutton is pressed
      digitalWrite(ledPin, HIGH); //turn on led
    }else{
      digitalWrite(ledPin, LOW);
      }
 
}
