#include <SoftwareSerial.h>

SoftwareSerial HC12(11,12);
int ButtonPin = 13;

int sequence = 0;
int seqMax = 500;

void setup()
{
   HC12.begin(9600);
   pinMode(ButtonPin, INPUT);
}

void loop()
{
  if (isGateOpened() || sequence > seqMax)
  {
    HC12.write("Go Fuck Yourself\n");
    sequence = 0;
  }
  sequence++;
}

bool isGateOpened()
{
  
}
