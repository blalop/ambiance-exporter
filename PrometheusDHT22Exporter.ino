#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

#include "PrometheusDHT22Exporter.hh"

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321


ESP8266WebServer server(80);

uint8_t DHTPin = D2; 
               
DHT dht(DHTPin, DHTTYPE);                

float Temperature;
float Humidity;
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(DHTPin, INPUT);

  dht.begin();              

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", onConnectHandler);
  server.onNotFound(onNotFoundHandler);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void onConnectHandler() {
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  server.send(200, "text/plain", buildMetrics(Temperature,Humidity)); 
}

void onNotFoundHandler(){
  server.send(404, "text/plain", "Not found");
}

String buildMetrics(float temperature, float humidity) {
  return "esp8266_temperature " + String(temperature) + "\r\n" + "esp8266_humidty " + String(humidity);
}
