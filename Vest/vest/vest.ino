#include <IRremote.h>

// Pin that controlls both channels relay circuits
#define relay_pin 4

int rec_arry[] = {2};
const int rec_arry_length = sizeof(rec_arry);

IRrecv ir_arry[] = {NULL};

void setup() {
  Serial.begin(9600);

  Serial.println("Enabling Pins");
  enableIRPins();
  Serial.println("Enabled Pins");
  pinMode(relay_pin, OUTPUT);
}

// Just detect if any of the recievers have detected a IR light (15-20 ft) then open relay
void loop() {
  for (int p = 0; p < sizeof(ir_arry); p++) {
    if (detect(ir_arry[p]))
      digitalWrite(relay_pin, HIGH);
  }
  delay(1000);
  digitalWrite(relay_pin, LOW);
}

// Inits and enables / adds the pins to the IR Reciever lib and adds it to our array
void enableIRPins() {
  for (int p = 0; p < sizeof(rec_arry); p++) {
    IRrecv this_p(rec_arry[p]);
    ir_arry[p] = this_p;
    ir_arry[p].enableIRIn();
  }
}

// detect if a IR pin has been triggered
bool detect(IRrecv this_recv) {
  decode_results res;
  if (this_recv.decode( & res)) {
    this_recv.resume();
    return true;
  } else {
    this_recv.resume();
    return false;
  }
}
