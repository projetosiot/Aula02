/*
  Conexão AP - WebServer
  IOT na prática com o ESP8266
*/

#include <ESP8266WiFi.h>

const char *ssid = "MeuSSID"; //Node do SSID a ser transmitido
const char *password = "SENHA"; //Senha

WiFiServer servidor(80);

/* AP Endereço http://192.168.4.1 
*/


void setup() {
  
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
      pagina += "<h1>Parabens!</h1><h2>Voce esta conectado no webserver do ESP8266</h2>";
    
      client.print(pagina);
  }
  
}
