#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;
void setup()
{
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
  delay(500);
}


