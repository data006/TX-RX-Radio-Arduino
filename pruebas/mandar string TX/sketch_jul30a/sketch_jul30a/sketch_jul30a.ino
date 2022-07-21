
#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

String data = "";
int num = 27;

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(A1,INPUT);
}
void loop() {  
  
  if(digitalRead(A1) == HIGH){
    data = "hola\n";
    num = 1;
    Serial.println(data);
    HC12.println(data);      // Send that data to HC-12  
  }
  else{
    data = "adios\n";
    num = 0;
    Serial.println(data);
    HC12.println(data);      // Send that data to HC-12  
  }
  
}
