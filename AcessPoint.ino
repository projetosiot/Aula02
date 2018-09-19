/*
  Conexão AP
  IOT na prática com o ESP8266
 
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


const char *ssid = "MEU_SSID"; //Node do SSID a ser transmitido
const char *password = "MINHA_SENHA"; //Senha

ESP8266WebServer server(80);

/* AP Endereço http://192.168.4.1 
*/
void pagina_html() {
  server.send(200, "text/html", "<h1>Parabens!</h1><h1>Voce esta conectado no webserver do ESP8266</h1>");
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configurando o AP ...");
  
  /* Start do AP*/
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Endereço AP : ");
  Serial.println(myIP);

   /* Start do Servidor Web*/
  server.on("/", pagina_html);
  server.begin();
  Serial.println("HTTP Servidor Iniciado");
}

void loop() {
  server.handleClient();
}
