#include "config.hpp"

#include "prometheus.hpp"

#include <Arduino.h>
#include <DHT.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

ESP8266WebServer server(PORT);
DHT dht(DHTPIN, DHTTYPE);

void onRoot() {
    server.send(200, "text/html", buildRoot());
}

void onMetricsPathHandler() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    String prefix = String(METRICS_PREFIX);

    Serial.print(temperature);
    server.send(200, "text/plain", buildMetrics(prefix, temperature, humidity));
}

void onNotFoundHandler() {
    server.send(404, "text/plain", "Not found");
}

void setup() {
    Serial.begin(115200);

    pinMode(DHTPIN, INPUT);

    dht.begin();

    WiFi.begin(WIFI_SSID, WIFI_PASS);

    Serial.println("Connecting to " + String(WIFI_SSID));
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }

    Serial.println();
    Serial.print("WiFi connected. Got IP: ");
    Serial.println(WiFi.localIP());

    server.on("/", onRoot);
    server.on("/metrics", onMetricsPathHandler);
    server.onNotFound(onNotFoundHandler);

    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
}
