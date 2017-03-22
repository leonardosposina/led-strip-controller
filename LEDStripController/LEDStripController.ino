//#################################
//# 5 Levels Led Strip Controller #
//#################################

const byte SENSOR_PIN = 2;
const byte TRANSISTOR_PIN = 4;
const byte MAX_LEVELS = 5;
const byte LED_STEP = 255 / MAX_LEVELS;
byte ledLevel = 0;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(TRANSISTOR_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(SENSOR_PIN)) {
    if (ledLevel < MAX_LEVELS) {
      ledLevel++;
    } else {
      ledLevel = 0;  
    }
  analogWrite(TRANSISTOR_PIN, LED_STEP * ledLevel);
  }
  delay(500);
}
