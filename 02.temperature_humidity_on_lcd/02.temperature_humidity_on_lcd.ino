/*
This sketch uses the LiquidCrystal library, which comes with the Arduino IDE, 
and the DHT library, which you will need to download and install 
from http://nostarch.com/arduinohandbook/ (see “Libraries” on page 7). 
The DHT library controls the function of the sensor, and the LCD library 
displays the readings on the screen.
--------------------------------------------------------------------
Example testing sketch for various DHT humidity/temperature sensors. 
Written by ladyada, public domain.
--------------------------------------------------------------------
*/

#include <LiquidCrystal.h>
#include "DHT.h" //call the DHT library

//#define DHTPIN 8 //Pin connected to DHT
#define DHTPIN 4 //Pin connected to DHT

//LiquidCrystal lcd(12,11,5,4,3,2);
LiquidCrystal lcd(7,8,9,10,11,12); //(RS,E,D4,D5,D6,D7) -- (A-5V, K-GND) -- (VSS-GND, VDD-5V) -- (V0-potentiometer) -- (RW-GND)

#define DHTTYPE DHT11 //Define the type of DHT module
DHT dht(DHTPIN, DHTTYPE); //Command to the DHT.h library

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin(); //Start the sensor
  lcd.begin(16,2); //LCD Screen is 16 character by 2 lines
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity(); //Value for humidity
  float t = dht.readTemperature(); //Value for temperature
  t = t * 9/5 + 32; //Change reading from Celcius to Fahrenheit

   if (isnan(t) || isnan(h)){  //Check that DHT sensor is working
      lcd.setCursor(0,0);
      lcd.print("Failed to Read from DHT"); //if it's not working display this
      Serial.println("Failed to Read From DHT");
    }else{  //otherwise show the readings on the screen
      Serial.println("Humidity: " + (String)h + " %" );
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Humidity: ");
      lcd.print(h);
      lcd.print("%");
      Serial.println("Temp: " + (String)t + " f" );
      lcd.setCursor(0,1);
      lcd.print("Temp: ");
      lcd.print(t);
      lcd.print("f");
      }
}
