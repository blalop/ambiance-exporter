#pragma once

#include <DHT.h>

// Http Server config
const String SSID = "yourssid";
const String PASS = "yourpass";
const uint16_t PORT = 80;

// DHT config
const uint8_t DHTPIN = D2;
const uint8_t DHTTYPE = DHT22;  // DHT 22  (AM2302), AM2321

// Project specific config
const String METRICS_PREFIX = "esp8266";
const String METRICS_PATH = "/metrics"
