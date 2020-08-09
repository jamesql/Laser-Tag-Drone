#include <SoftwareSerial.h>

SoftwareSerial HC12(11,12);
int ir_time = 1000;

int IRPin = 10;

void setup()
{
   Serial.begin(9600);
   HC12.begin(9600);
}

void loop()
{
  if (HC12.available())
    AttemptTase();   
}

void AttemptTase()
{
  enable_ir();
  delay(ir_time);
  disable_ir();
}

/* send 38khz raw ir signal. */
void sendIr()
{
  
}
