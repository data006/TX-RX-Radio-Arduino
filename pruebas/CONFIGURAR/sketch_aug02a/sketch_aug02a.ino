
#include <SoftwareSerial.h>

SoftwareSerial HC12(A2, A3);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  HC12.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(HC12.available()){
    Serial.write(HC12.read());
  }
  if(Serial.available()){
    HC12.write(Serial.read());
  }

}
