

#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

String texto = "";

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(A0,INPUT);
}
void loop() {  
  Serial.println(hola);
  HC12.write(hola);      // Send that data to HC-12  

  if(digitalRead(A0) == HIGH){
    texto = "hola"
    Serial.println(texto);
    HC12.write(texto);      // Send that data to HC-12  
  }
  else{
    texto = "adios"
    Serial.println(texto);
    HC12.write(texto);      // Send that data to HC-12  
  }
  
}
