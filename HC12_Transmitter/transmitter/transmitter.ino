#include <SoftwareSerial.h>

SoftwareSerial HC12(11,12);

void setup()
{
   Serial.begin(9600);
   HC12.begin(9600);
}

void loop()
{
  HC12.write("Test");
  delay(1000);
}
