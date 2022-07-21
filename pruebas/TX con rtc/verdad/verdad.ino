

////////////////////////////////////INICIALIZACION DE LIBRERIAS NECESARIAS////////////////////////////////////////////////
#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h> 
#include "RTClib.h"
#include <SoftwareSerial.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   // Direccion Fisica MAC
byte ip[] = { 192, 168, 0, 69 };                      // IP Local que usted debe configurar 
byte gateway[] = { 192, 168, 0, 1 };                   // Puerta de enlace
byte subnet[] = { 255, 255, 255, 0 };                  // Mascara de Sub Red
EthernetServer server(80);

SoftwareSerial HC12(A2, A3); // HC-12 TX Pin, HC-12 RX Pin
RTC_DS1307 RTC;              // inicializa el modulo RTC




///////////////////////////////////INICIALIZACION DE VARIABLES NECESARIAS////////////////////////////////////////////////
bool automatico = true;
bool manual = false;

int segundo = 0;
int minuto = 0;
int hora = 0;

int segundoProgramado = 0;
int minutoProgramado = 36;
int horaProgramado = 21;

uint32_t tactual=0;      
uint32_t tanterior=0;        

String data = "";
String readString;



void setup() {

  Ethernet.begin(mac, ip, gateway, subnet);     // Inicializa la conexion Ethernet y el servidor
  server.begin();

  Wire.begin();                               
  RTC.begin();                                  // Inicia la comunicaci¢n con el RTC
  Serial.begin(1200);
  HC12.begin(1200);
  //RTC.adjust(DateTime(__DATE__, __TIME__));   //Linea de codigo que sirve para cargarle la fecha y hora al RTC, solo se carga la primera vex


  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
  }

  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Cable Ethernet no conectado");
  }


  

}



void loop() {

////////////////////////////////////////////////////////////////CONFIGURACION ETHERNET///////////////////////////////////////////////////////////////////////

  EthernetClient client = server.available();

  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //Lee caracter por caracter HTTP
        if (readString.length() < 100) {
          //Almacena los caracteres a un String
          readString += c;
          
         }

         // si el requerimiento HTTP fue finalizado
         if (c == '\n') {          
           Serial.println(readString); //Imprime en el monitor serial

////////////////////////////////////////////////////////////////////////////////HTML/////////////////////////////////////////////////////////////////////////////
     
           client.println("HTTP/1.1 200 OK");           //envia una nueva pagina en codigo HTML
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<TITLE>SALAZAR SIEMPRE TIENE LA RAZON</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<hr />");
           client.println("<H1>SALAZAR SIEMPRE TIENE LA RAZON</H1>");
           client.println("<br />");  
           client.println("<H2>SALAZAR SIEMPRE TIENE LA RAZON</H2>");
           client.println("<br />");  
           
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> SALAZAR</a> ");           // construye en la pagina cada uno de los botones
           client.println(" | | | ");
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> SIEMPRE</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> TIENE</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> LA</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> RAZON</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> SALAZAR</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />");  
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> SIEMPRE</a>");
           client.println(" | | | ");
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> TIENE</a><br />");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> LA</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\"> RAZON</a><br /> ");   
           client.println("<br />");
           
           
           client.println("<br />"); 
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\">SALAZAR</a>");
           client.println(" | | | ");
           client.println("<a href=\"/?SALAZAR/SIEMPRE/TIENE/LA/RAZON\"\">SIEMPRE</a><br />"); 
           client.println("<hr />");
           client.println("<p>by: Su alumno favorito, C.S.</p>");  
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");

/////////////////////////////////////////////////////////////////////////////LECTOR DE APP/////////////////////////////////////////////////////////////////////
     
           delay(1);
           //detiene el cliente servidor
           client.stop();
           
           //control del arduino si un boton es presionado
                   
           if (readString.indexOf("?hola") >0){
               digitalWrite(7, HIGH);
           }
           if (readString.indexOf("?adios") >0){
               digitalWrite(7, LOW);
           }
           
           if (readString.indexOf("?button3on") >0){
               digitalWrite(3, HIGH);
           }
           if (readString.indexOf("?button3off") >0){
               digitalWrite(3, LOW);
           }
           
           
           if (readString.indexOf("?button4on") >0){
               digitalWrite(4, HIGH);
           }
           if (readString.indexOf("?button4off") >0){
               digitalWrite(4, LOW);
           }
           
            if (readString.indexOf("?button5on") >0){
               digitalWrite(5, HIGH);
           }
           if (readString.indexOf("?button5off") >0){
               digitalWrite(5, LOW);
           }
           
           
           if (readString.indexOf("?button6on") >0){
               digitalWrite(6, HIGH);
           }
           if (readString.indexOf("?button6off") >0){
               digitalWrite(6, LOW);
           }
           
           
           
            // Limpia el String(Cadena de Caracteres para una nueva lectura
            readString="";  
           
         }
       }
    }
}


///////////////////////////////////////////////////////////////PROGRAMA ARDUINO///////////////////////////////////////////////////////////////////////////////

  DateTime now = RTC.now();          // Obtiene la fecha y hora del RTC

  Serial.print(now.year(), DEC);  // Ano
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

  segundo=now.second();
  minuto=now.minute();
  hora=now.hour();


//////////////////////////////////////////INICIALIZACION DEL RIEGO AUTOMATICO////////////////////////////////////////////////////
  if((automatico == true) && (manual == false)){
    if ((hora==horaProgramado) && (minuto==minutoProgramado) && (segundo==segundoProgramado)){
      valvula1();
    }
  }
  
}



//////////////////////////////////CICLO AUTOMATICO DE RIEGO DE VALVULA 1 HASTA LA VALVULA FINAL////////////////////////////////////
void valvula1() {

  DateTime now = RTC.now();          // Obtiene la fecha y hora del RTC
  tactual = now.unixtime();
  tanterior = tactual;

  while((tactual - tanterior) < 10){   //Tiempo de encedido de la valvula en segundos
    DateTime now = RTC.now();
    tactual = now.unixtime();
    Serial.print("v1");
    Serial.println(tactual);
  }

  if((tactual - tanterior) >= 10){
    valvula2();
  }

}



void valvula2() {

  DateTime now = RTC.now();          // Obtiene la fecha y hora del RTC
  tactual = now.unixtime();
  tanterior = tactual;

  while((tactual - tanterior) < 10){   //Tiempo de encedido de la valvula en segundos
    DateTime now = RTC.now();
    tactual = now.unixtime();
    Serial.print("v2");
    Serial.println(tactual);
  }

  if((tactual - tanterior) >= 10){
    valvula3();
  }

}



void valvula3() {

  DateTime now = RTC.now();          // Obtiene la fecha y hora del RTC
  tactual = now.unixtime();
  tanterior = tactual;

  while((tactual - tanterior) < 10){   //Tiempo de encedido de la valvula en segundos
    DateTime now = RTC.now();
    tactual = now.unixtime();
    Serial.print("v3");
    Serial.println(tactual);
  }

  if((tactual - tanterior) >= 10){
    valvula4();
  }

}



void valvula4() {

  DateTime now = RTC.now();          // Obtiene la fecha y hora del RTC
  tactual = now.unixtime();
  tanterior = tactual;

  while((tactual - tanterior) < 10){   //Tiempo de encedido de la valvula en segundos
    DateTime now = RTC.now();
    tactual = now.unixtime();
    Serial.print("v4");
    Serial.println(tactual);
  }

  if((tactual - tanterior) >= 10){
    
  }
  
}
