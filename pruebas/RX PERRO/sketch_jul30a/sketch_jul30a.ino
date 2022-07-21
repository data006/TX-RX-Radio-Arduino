
#include <SoftwareSerial.h>
SoftwareSerial HC12(A2, A3); // HC-12 TX Pin, HC-12 RX Pin

String data = "";
int caca = 27;
char c = 0;
boolean newline = false;

void setup() {
  Serial.begin(1200);             // Serial port to computer
  HC12.begin(1200);               // Serial port to HC12
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
      if(data.equals("Valvula1")){
        Serial.println(data);
        digitalWrite(13,LOW);
        HC12.println("Valvula1\n");
      }else if(data.equals("Valvula2")){
        Serial.println(data);
        digitalWrite(13,LOW);
        HC12.println("Valvula2\n");
      }else if(data.equals("Valvula3")){
        Serial.println(data);
        digitalWrite(13,HIGH);
      }else if(data.equals("Valvula4")){
        Serial.println(data);
        digitalWrite(13,LOW);
        HC12.println("Valvula4\n");
      }
      else{
      }
      data = "";
      newline = false;
    }


    
    
}
