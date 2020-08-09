#include <SoftwareSerial.h>

/* HC12 Object. */
SoftwareSerial HC12(11,12);
int ButtonPin = 13;

/* Sequencing Variabels (kinda like aim assist). */
int sequence = 0;
int seqMax = 2500;

/* Constructor. */
void setup()
{
   HC12.begin(9600);
   pinMode(ButtonPin, INPUT);
}

/* Program Loop */
void loop()
{
  /* Check if we are making a tasing attempt. */
  if (isGateOpened() || sequence > seqMax)
  {
    /* Alert drone that someone needs to be tased. */
    HC12.write("Tase Attempted.\n");
    /* Reset Sequence */
    sequence = 0;
  }
  /* Set to next sequence. */
  sequence++;
}

/* Check if button is pressed down. */
bool isGateOpened()
{
  
}

/* send 38khz raw ir signal. */
void sendIr()
{
  
}
