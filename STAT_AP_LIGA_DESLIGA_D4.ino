/*
  Conexão Station - WebServer
 IOT na prática com o ESP8266
  https://github.com/esp8266/Arduino/tree/master/doc/esp8266wifi
  http://tomeko.net/online_tools/cpp_text_escape.php?lang=en
*/

#include <ESP8266WiFi.h>

// Seu AP da Rede
const char *ssid = "DL-CARVALE"; //Nome do AP a ser conectado
const char *password = "le021322"; //Senha do AP

// AP do ESP
const char *ssid_ap = "pelicano"; //Nome do SSID do ESP8266
const char *password_ap = "pelicano1"; //Senha



//Configura o WifiServer
WiFiServer servidor(80);


void setup() {

  pinMode(D4, OUTPUT); // Incializa o D4  como saída
  
  Serial.begin(115200);
  Serial.println();

//------------ Conectando no AP (STAT) ---------------------
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
//---------------------------------------------------------

  Serial.println();
  
//-----------Modo AP--------------------------------------- 
  Serial.println("Configurando o AP ...");
  
  /* Start do AP*/
  WiFi.softAP(ssid_ap, password_ap);
  IPAddress MeuIP_ap = WiFi.softAPIP();
  Serial.print("Endereço AP : ");
  Serial.println(MeuIP_ap);
//---------------------------------------------------------

  /*Start WebServer*/
  servidor.begin();

}

void loop() {

  WiFiClient client = servidor.available();
  
  if (client){
    
      Serial.println("Novo Cliente");
     
      String pagina = "";
    
      /* Página HTML */
 
      pagina += "<!doctype html>\n<html lang=\"pt-BR\">\n    <head>\n        <meta charset=\"utf-8\">\n        <title>Curso ESP8266 na Prática</title>\n    </head>\n\n    <body>\n        <h1>Comando Liga/Desliga LED</h1>\n\t\t<p>LED D4\n\t\t\t<a href=?function=d4_on><button>LIGA</button></a>\n\t\t\t<a href=?function=d4_off><button>DESLIGA</button></a>\n\t\t</p>\n\t\t\t\n    </body>\n</html>";

      String req = client.readStringUntil('\r');
      if (req.indexOf("d4_on") != -1) digitalWrite(D4, LOW);
      if (req.indexOf("d4_off") != -1) digitalWrite(D4, HIGH);
 
      // Envia a página para o browser
      client.print(pagina);
  }
  
}
