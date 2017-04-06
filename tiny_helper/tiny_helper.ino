#include <SoftwareSerial.h>
#define timetrsh 100

SoftwareSerial aSerial(2, 3);
SoftwareSerial bSerial(5, 6);
SoftwareSerial cSerial(7, 8);
void setup() {
  Serial.begin(115200);
  aSerial.begin(9600);
    bSerial.begin(9600);
    cSerial.begin(9600);
}
  uint8_t value[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t button[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void loop() {

  uint8_t timeout = 0;
  uint8_t inc = 0;
  long prev ;
    while (Serial.available()) {
      if ( Serial.read() == 'a') {
        for (uint8_t i = 0; i < 10; i++) {
          Serial.write(value[i]);
          //delay(1);
          Serial.write(button[i]);
          //delay(1);
        }  
      }
    }


  //////////////////////////////////////////////////////////////////////////////  //reading one tiny enc
  aSerial.listen();
  aSerial.write('a');
  ///////////////////////////////////////////////////////////////  //reading one val
  prev = millis();
  while ((aSerial.available() == 0) && ((millis() - prev ) < timetrsh));
  if (aSerial.available())
    value[0] = aSerial.read();
  else if ((millis() - prev) >= timetrsh)
  {
    value[0] = 0;
    timeout = 1;
  }
  else
    timeout = 2;

  ///////////////////////////////////////////////////////////////  //reading one val
  prev = millis();
  while ((aSerial.available() == 0) && ((millis() - prev ) < timetrsh));
  if (aSerial.available())
    button[0] = aSerial.read();
  else if ((millis() - prev) >= timetrsh)
  {
    button[0] = 0;
    timeout = 1;
  }
  else
    timeout = 2 ;

  ////////////////////////////////////////////////////////////////////////////  //reading one tiny enc
    bSerial.listen();
    bSerial.write('b');
    ///////////////////////////////////////////////////////////////  //reading one val
    prev = millis();
    while ((bSerial.available() == 0) && ((millis() - prev ) < timetrsh));
    if (bSerial.available())
      value[1] = bSerial.read();
    else if ((millis() - prev) >= timetrsh)
    {
      value[1] = 0;
      timeout = 1;
    }
    else
      timeout = 2 ;
    ///////////////////////////////////////////////////////////////  //reading one val
    prev = millis();
    while ((bSerial.available() == 0) && ((millis() - prev ) < timetrsh));
    if (bSerial.available())
      button[1] = bSerial.read();
    else if ((millis() - prev) >= timetrsh)
    {
      button[1] = 0;
      timeout = 1;
    }
    else
      timeout = 2 ;
    //////////////////////////////////////////////////////////////////////////////  //reading one tiny enc
    cSerial.listen();
    cSerial.write('c');
    ///////////////////////////////////////////////////////////////  //reading one val
    prev = millis();
    while ((cSerial.available() == 0) && ((millis() - prev ) < timetrsh));
    if (cSerial.available())
      value[2] = cSerial.read();
    else if ((millis() - prev) >= timetrsh)
    {
      value[2] = 0;
      timeout = 1;
    }
    else
      timeout = 2 ;
    ///////////////////////////////////////////////////////////////  //reading one val
    prev = millis();
    while ((cSerial.available() == 0) && ((millis() - prev ) < timetrsh));
    if (cSerial.available())
      button[2] = cSerial.read();
    else if ((millis() - prev) >= timetrsh)
    {
      button[2] = 0;
      timeout = 1;
    }
    else
      timeout = 2 ;



}

