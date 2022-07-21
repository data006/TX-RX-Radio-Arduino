/* 1byte HC12 TRANSMITTER example.
/* Tutorial link: http://electronoobs.com/eng_arduino_tut96.php
 * Code: http://electronoobs.com/eng_arduino_tut96_code1.php
 * Scheamtic: http://electronoobs.com/eng_arduino_tut96_sch1.php
 * Youtube Channel: http://www.youtube/c/electronoobs   
 * 
  Module // Arduino UNO/NANO    
    GND    ->   GND
    Vcc    ->   3.3V
    Tx     ->   D10
    Rx     ->   D11      
 */
#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
int pot = 2;
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(pot,INPUT);
}
void loop() {  
  int hola = 27;
  int val = digitalRead(pot);
  Serial.println(hola);
  HC12.write(hola);      // Send that data to HC-12  
}
