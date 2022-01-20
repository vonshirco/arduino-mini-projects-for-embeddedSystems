/*
Library originally added 18 Apr 2008 by David A. Mellis
library modified 5 Jul 2009 by Limor Fried (http://www.ladyada.net) 
example added 9 Jul 2009 by Tom Igoe modified 22 Nov 2010 by Tom Igoe 
This example code is in the public domain. http://www.arduino.cc/en/Tutorial/LiquidCrystal
LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()
Demonstrates the use of a 16x2 LCD display. The LiquidCrystal library works with 
all LCD displays that are compatible with the Hitachi HD44780 driver. There are many
of them out there, and you can usually tell them by the 16-pin interface.
This sketch prints "Arduino Sketch" to the LCD and uses the scrollDisplayLeft() 
and scrollDisplayRight() methods to scroll the text.
*/

//include the library
#include <LiquidCrystal.h>

//Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12); //(RS,E,D4,D5,D6,D7) -- (A-5V, K-GND) -- (VSS-GND, VDD-5V) -- (V0-potentiometer) -- (RW-GND)

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); //Set up the LCD's number of columns and rows
  lcd.print("Von Embedded Programming"); //Print a message to the LCD
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Scroll 13 positions (string length) to the left to move it offscreen left
  for (int positionCounter = 0; positionCounter < 13; positionCounter++){
      lcd.scrollDisplayLeft(); //Scroll one position left
      delay(150); //wait a bit
    }

    //Scroll 29 positions (string length + display length) to the right to move it offscreen right
    for (int positionCounter = 0; positionCounter < 29; positionCounter++){
        lcd.scrollDisplayRight(); //Scroll one position right
        delay(150); //wait a bit
      }

      //Scroll 16 positiond (display length + string length) to the left to move it back to the center
      for (int positionCounter = 0; positionCounter < 16; positionCounter++){
          lcd.scrollDisplayLeft(); //Scroll one position left
          delay(150); //wait a bit
        }

        delay(1000); //Delay at the end of the full loop

}
