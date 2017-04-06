#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4);
volatile uint8_t lastEncoded = 0;
uint8_t encoded;
volatile uint8_t encoderValue = 0;
uint8_t lastencoderValue = 0;
uint8_t MSB;
uint8_t LSB;
uint8_t sum;
uint8_t button=97;

void setup()
{
  mySerial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}
void loop()
{

  while (mySerial.available()) {
    uint8_t inc=mySerial.read();
    if ( inc == 'a') {
      mySerial.write(encoderValue);
      mySerial.write(button);
      button=97;
    }
  }
  encoded = (digitalRead(0) << 1) | digitalRead(1); 
  sum  = (lastEncoded << 2) | encoded;
  if (sum == 0b0100 || sum == 0b0010)
    encoderValue ++;
  if (sum == 0b1110 || sum == 0b0111)
    encoderValue --;
  lastEncoded = encoded;
  if(digitalRead(2)==0)
    button=99;
  
}
