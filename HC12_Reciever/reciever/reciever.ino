#include <SoftwareSerial.h>

/* HC12 Objects */
SoftwareSerial HC12(11,12);

/* IR Variables */
int ir_time = 1000;
int IRPin = 10;

/* Constructor. */
void setup()
{
   Serial.begin(9600);
   HC12.begin(9600);
}

/* Program Loop */
void loop()
{
  if (HC12.available())
    sendIr();   
}

/* send 38khz raw ir signal. */
void sendIr()
{
  
}
