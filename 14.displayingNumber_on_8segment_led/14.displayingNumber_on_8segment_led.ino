/*
Beginner kit for Arduino Tutorial: Sample Code 15-1: Displaying numbers on a 8 segment
LED display 
 
An 8-segment LED is a formed of electronic display device for displaying decimal numerals.
It is an alternative to more complex dot matrix displays. By controlling each LED in each 
segment connected to a digital pin, numbers can be displayed on this LED.

The 8 segment LED has 10 pins. The 5 pins on the upper position are connected to digital 
pin 2 to digital pin 5. The other 5 pins on the lower position with decimal point are 
connected to digital pin 6 to 9. 8 resistors are included to limit the current for the LEDs.

nA[8] = {b,a,f,g,e,d,c,DP} -> nN[8]

The sketch below, we created 10 arrays to display 0 to 9. This is a one-dimensional array.
*/
void setup() {
  // put your setup code here, to run once:
  for (int pin = 2; pin <= 9; pin++) {  //define digital pin 2 - 9 as output
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

  //display number 0
  int n0[8] = {1,1,1,0,1,1,1,0};
  //display the array of n0[8] in digital pin 2 - 9
  for (int pin = 2; pin <= 9; pin++) {
    digitalWrite(pin, n0[pin-2]);    //n0[pin-2] because index in array starts from 0... and our pins have started with 2 to 9
    }
    delay(500);

    //display number 1
    int n1[8] = {1,0,0,0,0,0,1,0};
    //display the array of n1[8] in digital pin 2 - 9
    for (int pin = 2; pin <= 9; pin++) {
      digitalWrite(pin, n1[pin-2]);
      }
      delay(500);

      //display number 2
      int n2[8] = {1,1,0,1,1,1,0,0};
      //display the array of n2[8] in digital pin 2 - 9
      for (int pin = 2; pin <= 9; pin++) {
        digitalWrite(pin, n2[pin-2]);
        }
        delay(500);

        //display number 3
        int n3[8] = {1,1,0,1,0,1,1,0};
        //display the array of n3[8] in digital pin 2 - 9
        for (int pin = 2; pin <= 9; pin++) {
          digitalWrite(pin, n3[pin-2]);
          }
          delay(500);

          //display number 4
          int n4[8] = {1,0,1,1,0,0,1,0};
          //display the array of n4[8] in digital pin 2 - 9
          for (int pin = 2; pin <= 9; pin++) {
            digitalWrite(pin, n4[pin-2]);
            }
            delay(500);
            
            //display number 5
            int n5[8] = {0,1,1,1,0,1,1,0};
            //display the array of n5[8] in digital pin 2 - 9
            for (int pin = 2; pin <= 9; pin++) {
              digitalWrite(pin, n5[pin-2]);
              }
              delay(500);

              //display number 6
              int n6[8] = {0,1,1,1,1,1,1,0};
              //display the array of n6[8] in digital pin 2 - 9
              for (int pin = 2; pin <= 9; pin++) {
                digitalWrite(pin, n6[pin-2]);
                }
                delay(500);

                //display number 7
                int n7[8] = {1,1,0,0,0,0,1,0};
                //display the array of n7[8] in digital pin 2 - 9
                for (int pin = 2; pin <= 9; pin++) {
                  digitalWrite(pin, n7[pin-2]);
                  }
                  delay(500);

                  //display number 8
                  int n8[8] = {1,1,1,1,1,1,1,0};
                  //display the array of n8[8] in digital pin 2 - 9
                  for (int pin = 2; pin <= 9; pin++) {
                    digitalWrite(pin, n8[pin-2]);
                    }
                    delay(500);

                    //display number 9
                    int n9[8] = {1,1,1,1,0,0,1,0};
                    //display the array of n9[8] in digital pin 2 - 9
                    for (int pin = 2; pin <= 9; pin++) {
                      digitalWrite(pin, n9[pin-2]);
                      }
                      delay(500);
                      
}
