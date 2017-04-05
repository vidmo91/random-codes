void setup() {
  Serial.begin(9600);
}
void loop() {
  uint8_t value[10];
  for (int i = 0; i < 10; i++) {
    Serial.write('a' + i);
    if (Serial.available())
    {
      value[i] = Serial.read();
      while (Serial.available())
        Serial.read();
    }
  }
}



