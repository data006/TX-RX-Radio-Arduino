
#include <SoftwareSerial.h>
SoftwareSerial HC12(A2, A3); // HC-12 TX Pin, HC-12 RX Pin

String data = "";

void setup() {
  HC12.begin(1200);               // Serial port to HC12
}
void loop() {  

  data = "Valvula1\n";
  HC12.println(data);      // Send that data to HC-12 

  delay(250);

  data = "Valvula2\n";
  HC12.println(data);      // Send that data to HC-12 

  delay(250);

  data = "Valvula3\n";
  HC12.println(data);      // Send that data to HC-12 

  delay(250);
  
  data = "Valvula4\n";
  HC12.println(data);      // Send that data to HC-12 

  delay(250);
  
}
