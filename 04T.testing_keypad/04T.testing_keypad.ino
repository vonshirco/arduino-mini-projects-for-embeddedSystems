
//Testing the keypad

#include <Keypad.h>

const byte ROWS = 4; //set four rows
const byte COLS = 4; //set four columns
char keys[ROWS][COLS] = {  //Definig Keymap
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
  byte rowPins[ROWS] = {2,3,4,5}; //Pins connected to the keypad ROW0, ROW1, ROW2, ROW3
  byte colPins[COLS] = {6,7,8,9}; //Pins connected to the keypad COL0, COL1, COL2, COL3

  //Create the keypad
  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);  
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();  //get the key you press
  if (key != NO_KEY){
    Serial.println(key);  //printing the pressed key on the serial monitor
    }
}
