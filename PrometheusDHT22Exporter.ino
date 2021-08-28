#include "PrometheusDHT22Exporter.hh"

#include <DHT.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

ESP8266WebServer server(PORT);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);

    pinMode(DHTPIN, INPUT);

    dht.begin();

    Serial.println("Connecting to " + SSID);

    WiFi.begin(SSID, PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }

    Serial.println();
    Serial.print("WiFi connected. Got IP: ");
    Serial.println(WiFi.localIP());

    server.on("/", onConnectHandler);
    server.onNotFound(onNotFoundHandler);

    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
}

void onConnectHandler() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    server.send(200, "text/plain", buildMetrics(temperature, humidity));
}

void onNotFoundHandler() {
    server.send(404, "text/plain", "Not found");
}

String buildMetrics(float temperature, float humidity) {
    return METRIC_PREFIX + "_temperature " + String(temperature) + "\r\n" +
           METRIC_PREFIX + "_humidty " + String(humidity);
}
