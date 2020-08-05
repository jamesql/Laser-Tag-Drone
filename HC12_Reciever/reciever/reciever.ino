#include <SoftwareSerial.h>

SoftwareSerial HC12(11,12);
int ir_time = 1000;

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

void enable_ir()
{
  
}

void disable_ir()
{
  
}
