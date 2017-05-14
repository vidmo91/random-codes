#define sensorPin  A3    //input pin for the potentiometer - phisical pin 2
#define pwmPin  4      // select the pin for the fan driver - phisical pin 3
void setup() {
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  analogWrite(pwmPin, map(analogRead(sensorPin),0,1023,0,255));
  delay(10);
}
