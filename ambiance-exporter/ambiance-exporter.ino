#include <Arduino.h>
#include <ArduinoOTA.h>
#include <DHT.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

#include "config.h"

#define VERSION "0.5"

ESP8266WebServer server(PORT);
DHT dht(DHTPIN, DHTTYPE);

void onRootHandler() {
    server.send(200, "text/html",
                "<html>"
                "<head><title>Ambiance Exporter</title></head>"
                "<body>"
                "<h1>Ambiance Exporter</h1>"
                "<p><a href=\"/metrics\">Metrics</a></p>"
                "</body>"
                "</html>");
}

const char *buildMetrics(char *buffer, float temperature, float humidity) {
    int len = sprintf(buffer, "%s_%s{version=\"%s\",gccversion=\"%s\",room=\"%s\"} 1\n", PREFIX,
                      "build_info", VERSION, GCC_VERSION, ROOM_NAME);

    if (!std::isnan(temperature)) {
        len += sprintf(buffer + len, "%s_%s{room=\"%s\"} %.2f\n", PREFIX, "temperature", ROOM_NAME,
                       temperature);
    }

    if (!std::isnan(humidity)) {
        len += sprintf(buffer + len, "%s_%s{room=\"%s\"} %.2f\n", PREFIX, "humidity", ROOM_NAME,
                       humidity);
    }

    return buffer;
}

void onMetricsPathHandler() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    char buffer[256];

    server.send(200, "text/plain", buildMetrics(buffer, temperature, humidity));
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

void setup() {
    Serial.begin(115200);

    setupDHT();
    setupWiFi();
    setupServer();
}

void loop() {
    ArduinoOTA.handle();
    server.handleClient();
}
