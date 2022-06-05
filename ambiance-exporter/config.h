#pragma once

// GCC info
#ifdef __VERSION__
#define GCC_VERSION __VERSION__
#else
#define GCC_VERSION "unknown"
#endif

// Project specific info
#define PREFIX "ambiance"
#define ROOM_NAME "livingroom"

// Http Server config
#define WIFI_SSID "ssid"
#define WIFI_PASS "pass"
#define PORT 80

// DHT config
#define DHTPIN D2
#define DHTTYPE DHT22  // DHT 22  (AM2302), AM2321
