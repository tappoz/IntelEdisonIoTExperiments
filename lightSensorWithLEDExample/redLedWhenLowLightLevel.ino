
// the LED needs to be plugged on digital port 2
int WARNING_LED_PIN = 2;

// light sensor warning threshold
int WARNING_THRESHOLD = 700;

void setup() {
  // initialize the LED output
  pinMode(WARNING_LED_PIN, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // turn the LED off by making the voltage LOW 
  digitalWrite(WARNING_LED_PIN, LOW);

  // reading the value of the light sensor from analog port 1 
  int lightSensorValue = analogRead(A1);

  // this is the line that will be printed on the Serial Port (COM)
  String lineToPrint;
  
  if (lightSensorValue < WARNING_THRESHOLD) {
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(WARNING_LED_PIN, HIGH);
    lineToPrint = "Low light level! " + String(lightSensorValue);
  } else {
    lineToPrint = "Light level is fine: " + String(lightSensorValue);
  }

  // printing the relevant information on the Serial Port
  Serial.println(lineToPrint);
  // every 500 milliseconds
  delay(500);
}
