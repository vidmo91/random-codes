
#include <SoftwareSerial.h>
#define timetrsh 500
SoftwareSerial mySerial(2, 3);
void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
}
void loop() {
  uint8_t value[10];
  uint8_t button[10];
  uint8_t timeout = 0;

  mySerial.write('a');
  for (uint8_t i = 0; i < 10; i++) {
    while (mySerial.available() == 0);
    if (mySerial.available())
      value[i] = mySerial.read();
    while (mySerial.available() == 0);
    if (mySerial.available())
      button[i] = mySerial.read();
  }
  while (mySerial.available())
    mySerial.read();


  for (uint8_t i = 0; i < 10; i++) {
    Serial.print(value[i], DEC);
    Serial.print(" ");
  }
  Serial.println("");

  for (uint8_t i = 0; i < 10; i++) {

    Serial.print(button[i], DEC);
    Serial.print(" ");
  }
  Serial.println("");

  for (uint8_t i = 0; i < 10; i++) {

    Serial.print("enc ");
    Serial.write('a' + i);
    Serial.print(" val: ");
    Serial.print(value[i], DEC);
    Serial.print("\t but st: ");
    if (button[i] == 97)
      Serial.print("not pres\t");
    else if (button[i] == 99)
      Serial.print("pres\t");
    else
      Serial.print("err\t");
    while (mySerial.available())
      mySerial.read();
  }
  Serial.println();
  delay(2000);
}



