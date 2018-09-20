/*
  Conexão AP - WebServer
 IOT na prática com o ESP8266
  https://github.com/esp8266/Arduino/tree/master/doc/esp8266wifi
  http://tomeko.net/online_tools/cpp_text_escape.php?lang=en
*/

#include <ESP8266WiFi.h>

const char *ssid = "DL-CARVALE"; //Node do AP a ser conectado
const char *password = "le021322"; //Senha do AP

//Configura o WifiServer
WiFiServer servidor(80);


void setup() {
  
  Serial.begin(115200);
  Serial.println();

  //Conectando no AP
  WiFi.begin(ssid, password);
  Serial.print("Conectando");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  
  IPAddress MeuIP = WiFi.localIP();
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
 
      pagina += "<!doctype html>\n<html lang=\"pt-BR\">\n    <head>\n        <meta charset=\"utf-8\">\n        <title>Curso ESP8266 na Prática</title>\n    </head>\n\n    <body>\n        <h1>Parabéns</h1>\n\t\t<h2>Você está conectado no webserver do ESP8266 </h2>\n\t\t<h2>ESP8266 no modo Station<h2>\n    </body>\n</html>";

      // Envia a página para o browser
      client.print(pagina);
  }
  
}
