# Keypad-Arduino-1-wire
Allows an Arduino/Genuino board to deal with keypad 3 * 4 with 1 wire. 

must create Network of resistors as in image:
https://hackster.imgix.net/uploads/attachments/946330/blob_ttPMwKopJq.blob?auto=compress%2Cformat&w=900&h=675&fit=min

you can put 5Ks and 2Ks or put what you want but declare it in constructor.
 The function: char button_content(float analog) will return character was pressed , take analogRead as paramter.


example:
#include <Streaming.h>
#include <Keypad34.h>

#define key_pin A0

Keypad34 keypad;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sig = analogRead(key_pin);
  Serial<< "signal coming = "<<sig<< " & Key " <<keypad.button_content(sig) << " is pressed" << endl;
  delay(100);
}
