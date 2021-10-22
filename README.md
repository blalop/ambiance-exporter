# Prometheus ESP8266 + DHT22 Exporter

A Prometeus Exporter for the DHT22 sensor using ESP8266 hardware. 

Classic ESP8266-DHT22 schematic with pull-up resistor of 4,7k-10k omhs.

## Schematics

Schematics uses [kicad-ESP8266](https://github.com/jdunmire/kicad-ESP8266) library.


## Deployment

```bash
WIFI_SSID='\"ssid\"' WIFI_PASS='\"pass\"' INSTANCE='\"livingroom\"' PLATFORMIO_UPLOAD_PORT=192.168.1.2 pio run -t upload -e ota
```

The output metrics look like this:

```
ambiance_build_info{version="1.0.0",gccversion="10.3.0", instance="bedroom"} 1
ambiance_temperature{instance="bedroom"} 22.00
ambiance_humidity{instance="bedroom"} 59.50
```

## Testing

```bash
WIFI_SSID='\"ssid\"' WIFI_PASS='\"pass\"' INSTANCE='\"livingroom\"' PLATFORMIO_UPLOAD_PORT=192.168.1.2 pio run test
```
