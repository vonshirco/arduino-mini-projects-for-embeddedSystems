/*
Beginner kit for Arduino Tutorial: Sample Code 15-2: Displaying numbers on a 8 segment
LED display 
In this sketch, we will introduce an even simpler way to manipulate the loops for number 
0 to 9 in the 8segment LED. In the previous sketch, we created 10 arrays to display 0 to 9. 
That was a one-dimensional array.
In the following sketch (below) we create a two-dimensional array to make it simpler.
*/

int number[10][8] = {  //int number[i][j]
  {1,1,1,0,1,1,1,0},  //display 0
  {1,0,0,0,0,0,1,0},  //display 1
  {1,1,0,1,1,1,0,0},  //display 2
  {1,1,0,1,0,1,1,0},  //display 3
  {1,0,1,1,0,0,1,0},  //display 4
  {0,1,1,1,0,1,1,0},  //display 5
  {0,1,1,1,1,1,1,0},  //display 6
  {1,1,0,0,0,0,1,0},  //display 7
  {1,1,1,1,1,1,1,0},  //display 8
  {1,1,1,1,0,0,1,0},  //display 9
  };

//call this fuction to display numbers
void numberShow(int i) {
  for (int pin = 2; pin <= 9; pin++) {
    digitalWrite(pin, number[i][pin-2]);
    }
  }

void setup() {
  // put your setup code here, to run once:
  for (int pin = 2; pin <= 9; pin++) {
    pinMode(pin, OUTPUT);  //define digital pins 2 to 9 as output
    digitalWrite(pin, LOW);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j <= 9; j++) {
    numberShow(j);  //call numberShow() function to display 0 - 9
    delay(500);
    }
}
