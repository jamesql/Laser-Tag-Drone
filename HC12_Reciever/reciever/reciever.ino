#include <SoftwareSerial.h>
#include <IRremote.h>

/* HC12 Objects */
SoftwareSerial HC12(11,12);

/* IR Variables */
int ir_time = 1000;

/* IR Send Object. */
IRsend o;

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
      unsigned int irSignal[] = { 9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560,
            1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560,
            1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560,
            1690, 560, 1690, 560, 39416, 9000, 2210, 560 };

      o.sendRaw(irSignal,sizeof(irSignal) / sizeof(irSignal[0]),38);
}
