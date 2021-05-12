/*
  ╔------------------------------------------------------------╗
  ║               5 Levels LED strip controller                ║
  ╠------------------------------------------------------------╣
  ║ A simple LED strip controller project based on Digispark   ║
  ║ ATtiny85, also using a capacitive touch sensor and a MOSFET║
  ║ transistor.                                                ║
  ╠------------------------------------------------------------╣
  ║ Filename: LEDStripController.ino                           ║
  ║ Last modified: 22 March 2017 by Leonardo Sposina.          ║
  ╚------------------------------------------------------------╝
*/

const byte SENSOR_PIN = 2;
const byte TRANSISTOR_PIN = 4;
const byte INTENSITY_LEVELS = 5;
const byte MIN_INTENSITY = 255 / INTENSITY_LEVELS;

byte touchCount = 0;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(TRANSISTOR_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(SENSOR_PIN)) {
    if (touchCount < INTENSITY_LEVELS) {
      touchCount++;
    } else {
      touchCount = 0;
    }
    byte ledIntensity = MIN_INTENSITY * touchCount;
    analogWrite(TRANSISTOR_PIN, ledIntensity);
  }
  delay(500);
}
