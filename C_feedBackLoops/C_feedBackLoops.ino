#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;
void setup() {
  // setup the buzzer on digital pin 6 (D6)
  pinMode(6, OUTPUT);
  accelemeter.init();  
  Serial.begin(9600);
}
void loop()
{
  int8_t x;
  int8_t y;
  int8_t z;
  float ax,ay,az;
  
  accelemeter.getXYZ(&x,&y,&z);

  Serial.println("Sensor values:");
  Serial.println("x = " + String(x) + " y = " + String(y) + " z = " + String(z));
  
  accelemeter.getAcceleration(&ax,&ay,&az);
  
  Serial.println("Accleration values:");
  char accelerationMsg[20];
  sprintf(accelerationMsg, "x = %f y = %f z = %f", ax, ay, az);
  Serial.println(accelerationMsg);
  
  Serial.println("*************");

  if (y <= 0 && z <= 0) {
    // the accelerometer is upside down!
    Serial.println("!!! AAAH !!!");
    Serial.println("!!! AAAH !!!");
    Serial.println("!!! AAAH !!!");
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }
  
  delay(1000);
}


