//Hall Effect Sensor
//Detects the presence of a magnetic field and turns on the led

int hallSensor = 4;
int ledPin = 13;
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(hallSensor, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(hallSensor);

  if(state == LOW){ //Default output of the module is high when there is no strong magnetic field around 
    //if we read the state as LOW we turn on the LED
      digitalWrite(ledPin, HIGH); 
    }else{
      digitalWrite(ledPin, LOW);
      }
}
