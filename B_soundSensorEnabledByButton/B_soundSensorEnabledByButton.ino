#include <Wire.h>
#include "rgb_lcd.h"

// the LCD needs to be plugged on to a I2C port
rgb_lcd lcd;
// the pushbutton pin is in the digital port 3 (D3)
const int BUTTON_PIN = 3;
// the LED needs to be plugged on digital port 2 (D2)
const int WARNING_LED_PIN = 2;
// variable for reading the pushbutton
int buttonState = 0;

const int BG_RED = 0;
const int BG_GREEN = 1;
const int BG_BLUE = 2;

void setLcdBackground(rgb_lcd inLcd, int backgroundType) {
  switch (backgroundType) {
    case BG_RED:
      inLcd.setRGB(255, 0, 0);
      break;
    case BG_GREEN:
      inLcd.setRGB(0, 255, 0);
      break;
    case BG_BLUE:
      inLcd.setRGB(0, 0, 255);
      break;
    default:
      // kind of white background light
      inLcd.setRGB(255, 255, 255);
    break;
  }
}

void setup() {

  // set up the LCD's number of columns and rows:
  uint8_t numOfColumns = 16;
  uint8_t numOfLines = 2;
  lcd.begin(numOfColumns, numOfLines);

  // set the LCD display background colour
  setLcdBackground(lcd, BG_BLUE);
    
  // initialize the pushbutton pin as an input
  pinMode(BUTTON_PIN, INPUT);

  // initialize the LED pin as an output
  pinMode(WARNING_LED_PIN, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {

  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);
    
  // this is the line that will be printed on the Serial Port (COM)
  String lineToPrint;
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    setLcdBackground(lcd, BG_GREEN);
    // turn WARNING LED off
    digitalWrite(WARNING_LED_PIN, LOW);
    // reading the value of the sound sensor from analog port 2 (A2)
    int soundSensorValue = analogRead(A2);
    lineToPrint = "Level: " + String(soundSensorValue) + " ";
  }
  else {
    setLcdBackground(lcd, BG_RED);
    // turn WARNING LED on:
    digitalWrite(WARNING_LED_PIN, HIGH);
    lineToPrint = "No reading! ";
  }

  // printing the relevant information on the Serial Port
  Serial.println(lineToPrint);
  // Print a message to the LCD.
  lcd.print(lineToPrint);
  
  // sampling every 100 milliseconds
  delay(100);
}
