/*
  Simple DHT11
  IOT na prática com o ESP8266
  https://github.com/winlinvip/SimpleDHT
  
*/

#include <SimpleDHT.h>

int pinDHT11 = D1; // Pino onte está conectado o DHT11
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200);
  pinMode(D4, OUTPUT); // Incializa o D4  como saída
}

void loop() {
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
}
