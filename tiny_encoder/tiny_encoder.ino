#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4);
volatile uint8_t lastEncoded = 0;
uint8_t encoded;
volatile uint8_t encoderValue = 0;
uint8_t lastencoderValue = 0;
uint8_t MSB;
uint8_t LSB;
uint8_t sum;

void setup()
{
  mySerial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}
void loop()
{
  if (digitalRead(2) == 0){
    mySerial.println(encoderValue, DEC);
    while(digitalRead(2) == 0);
  }
  encoded = (digitalRead(0) << 1) | digitalRead(1); //converting the 2 pin value to single number
  sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value
  if (sum == 0b0100 || sum == 0b0010)
    encoderValue ++;
  if (sum == 0b1110 || sum == 0b0111)
    encoderValue --;
  lastEncoded = encoded; //store this value for next time
}
