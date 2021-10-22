#include "config.hpp"

#include "prometheus.hpp"

#include <Arduino.h>
#include <ArduinoOTA.h>
#include <DHT.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

ESP8266WebServer server(PORT);
DHT dht(DHTPIN, DHTTYPE);
PrometheusExporter prometheus(VERSION, GCC_VERSION, METRICS_PREFIX, ROOM);

void onRootHandler() { server.send(200, "text/html", prometheus.buildRoot()); }

void onMetricsPathHandler() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    char body [256];

    server.send(200, "text/plain", prometheus.buildMetrics(body, temperature, humidity));
}

void onNotFoundHandler() { server.send(404, "text/plain", "Not found"); }

void setupDHT() {
    pinMode(DHTPIN, INPUT);
    dht.begin();
    Serial.printf("DHT started with Pin %d\n", DHTPIN);
}

void setupWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    Serial.printf("Connecting to %s\n", WIFI_SSID);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }

    Serial.println();
    Serial.println("WiFi connected. Got IP: " + WiFi.localIP().toString());
}

void setupServer() {
    server.on("/", onRootHandler);
    server.on("/metrics", onMetricsPathHandler);
    server.onNotFound(onNotFoundHandler);

    server.begin();
    Serial.println("HTTP server started");
}

void setupOTA() {
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });

    ArduinoOTA.onEnd([]() { Serial.println("\nEnd"); });

    ArduinoOTA.onError([](ota_error_t error) { Serial.printf("OTA error: %u\n", error); });

    ArduinoOTA.begin();
    Serial.println("OTA started");
}

void setup() {
    Serial.begin(115200);

    setupDHT();
    setupWiFi();
    setupServer();
    setupOTA();
}

void loop() {
    ArduinoOTA.handle();
    server.handleClient();
}
