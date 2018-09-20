/*
  Simple DHT11 - Webserver
  IOT na prática com o ESP8266
  https://github.com/winlinvip/SimpleDHT
  
*/
#include <ESP8266WiFi.h>
#include <SimpleDHT.h>


int pinDHT11 = D1; // Pino onte está conectado o DHT11
SimpleDHT11 dht11(pinDHT11);

const char *ssid = "DL-CARVALE"; //Nome do AP a ser conectado
const char *password = "le021322"; //Senha do AP

//Configura o WifiServer
WiFiServer servidor(80);

void setup() {
  
  Serial.begin(115200);
  pinMode(D4, OUTPUT); // Incializa o D4  como saída

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
      // Incio das Leituras do DHT11
      Serial.println("=================================");
      Serial.println("Leitura do DHT11...");
      
      digitalWrite(D4, HIGH); //Pisca
      delay(500);
      
      //Variáveis
      byte temperatura = 0;
      byte umidade = 0;
      
      int err = SimpleDHTErrSuccess;
      
      if ((err = dht11.read(&temperatura, &umidade, NULL)) != SimpleDHTErrSuccess) {
        Serial.print("Leitua DHT11 com falha, err="); 
        Serial.println(err);
        delay(1000);
        return;
      }
      
      Serial.print("Leitura OK: ");
      Serial.print((int)temperatura); Serial.print(" *C, "); 
      Serial.print((int)umidade); Serial.println(" %");
      
      digitalWrite(D4, LOW);//Pisca
      delay(500);
     
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("<head></head><body><h1>ESP8266 - Temperatura e Umidade</h1><h3>Temperatura: ");
      client.println(temperatura);
      client.println("*C</h3><h3>Umidade: ");
      client.println(umidade);
      client.println("%</h3><h3>");
      client.println("</body></html>");     
  }
  delay(1);
  client.stop();

}
