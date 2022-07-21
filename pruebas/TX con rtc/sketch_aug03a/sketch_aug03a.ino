


#include <Wire.h> 
#include "RTClib.h"
#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
RTC_DS1307 RTC; 

int segundo;
int minuto;
int hora;
String data = "";



void setup() {

  Wire.begin();                               
  RTC.begin();
  Serial.begin(1200);
  HC12.begin(1200);               // Serial port to HC12
  //RTC.adjust(DateTime(__DATE__, __TIME__));

}

void loop() {

  DateTime now = RTC.now();          // Obtiene la fecha y hora del RTC

  Serial.print(now.year(), DEC);  // A§o
  Serial.print('/');
  Serial.print(now.month(), DEC); // Mes
  Serial.print('/');
  Serial.print(now.day(), DEC);   // Dia
  Serial.print(' ');
  Serial.print(now.hour(), DEC);  // Horas
  Serial.print(':');
  Serial.print(now.minute(), DEC); // Minutos
  Serial.print(':');
  Serial.print(now.second(), DEC); // Segundos
  Serial.println();

}
