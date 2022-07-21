
#include <SoftwareSerial.h>
SoftwareSerial HC12(A2, A3); // HC-12 TX Pin, HC-12 RX Pin

String data = "";
int caca = 27;
char c = 0;
boolean newline = false;

void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(13,OUTPUT);
}
void loop() {
  while (HC12.available()>0) {        // If HC-12 has data
    c = HC12.read();

    if(c == '\r'){
      continue;
    }
    else if(c == '\n'){
      newline = true;
      break;
    }
    else{
      data = data + c;
    }
    
  }
  
    if(newline == true){
      if(data.equals("hola")){
        Serial.println(data);
        digitalWrite(13,HIGH);
      }else if(data.equals("adios")){
        Serial.println(data);
        digitalWrite(13,LOW);
      }
      else{
      }
      data = "";
      newline = false;
    }


    
    
}
