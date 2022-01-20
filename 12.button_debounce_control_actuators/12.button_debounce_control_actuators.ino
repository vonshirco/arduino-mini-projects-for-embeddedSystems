/*
beginner Kit for arduino tutorials Sample code 13
Button to control relays LEDs etc
*/

int buttonPin = 2; 
int relayOrLED = 3;
int relayOrLEDState = HIGH;
int buttonState;  //record current button state
int lastButtonState = LOW; //record the last button state
long lastDebounceTime = 0;
long debounceDelay = 50; //eliminate debounce time

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(relayOrLED, OUTPUT);

  digitalWrite(relayOrLED, relayOrLEDState);  //Configure the initial state of relayOrLED
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);  //read the value of the button
  
  //Once detects change of state record time
  if (reading != lastButtonState) {  //testing for correct signal, this is due to button debounce (to avoid incorrect signal)
    lastDebounceTime = mills();
    }

    //wait for 50ms to evaluate if it is the same state as last state
    //if different change the button state
    //if the state of the button is high(pressed), change the state of relayOrLED
    if ((mills() - lastDebounceTime) > debounceDelay) {
      if (reading != buttonState) {
        buttonState = reading;
        if (buttonState == HIGH) {
          relayOrLEDState = !relayOrLEDState;
          }
        }
     }

      digitalWrite(relayOrLED, relayOrLEDState);
      //Change the last state of button
      lastButtonState = reading;
}
