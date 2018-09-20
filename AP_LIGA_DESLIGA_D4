/*
  Conexão AP - Liga/Desliga Led D4
  IOT na prática com o ESP8266
 
*/

#include <ESP8266WiFi.h>

const char *ssid = "pelicano"; //Node do SSID a ser transmitido
const char *password = "pelicano1"; //Senha

WiFiServer servidor(80);

/* AP Endereço http://192.168.4.1 
*/


void setup() {

  pinMode(D4, OUTPUT); // Incializa o ledPin  como saída
  
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configurando o AP ...");
  
  /* Start do AP*/
  WiFi.softAP(ssid, password);
  IPAddress MeuIP = WiFi.softAPIP();
  Serial.print("Endereço AP : ");
  Serial.println(MeuIP);

  /*Start WebServer*/
  servidor.begin();

}

void loop() {

  WiFiClient client = servidor.available();
  
  if (client){
    
      Serial.println("Novo Cliente");
     
      String pagina = "";
    
      /* Página HTML */
    
      pagina += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n";
      pagina += "<h1>Comando ESP8266</h1><h2>Liga/Desliga</h2>";
      pagina += "<p>LED D4<a href=\"?function=d4_on\"><button>LIGA</button></a> <a href=\"?function=d4_off\"><button>DESLIGA</button></a></p>";

      String req = client.readStringUntil('\r');
      if (req.indexOf("d4_on") != -1) digitalWrite(D4, LOW);
      if (req.indexOf("d4_off") != -1) digitalWrite(D4, HIGH);
    
      client.print(pagina);
  }
  
  client.stop();
}
