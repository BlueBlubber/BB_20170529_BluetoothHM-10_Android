#include <SoftwareSerial.h>

#define ledPin 13
#define rxPin 1
#define txPin 0

SoftwareSerial btSerial(rxPin, txPin);
String btData;
String btData1;

void setup() {
  btSerial.begin(9600);
  Serial.begin(9600);
  btSerial.println("bluetooth available");
  Serial.println("bluetooth available");
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if (btSerial.available() || Serial.available()) {
    btData1 = Serial.readString();
    btData = btSerial.readString();
    if (btData == "on" || btData1 == "on") {
      digitalWrite(ledPin, 1);
      btSerial.println("LED on Pin 13 is on_Bluetooth");
      Serial.println("LED on Pin 13 is on_Serial");
    }
    if (btData == "off" || btData1 == "off") {
      digitalWrite(ledPin, 0);
      btSerial.println("LED on Pin 13 is off_Bluetooth");
      Serial.println("LED on Pin 13 is off_Serial");
    }
  }
  delay(100);
}
