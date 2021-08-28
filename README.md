# Prometheus ESP8266 + DHT22 Exporter

A Prometeus Exporter for the DHT22 sensor using ESP8266 hardware. 

Classic ESP8266-DHT22 schematic with pull-up resistor of 4,7k-10k omhs.

## IDE configuration

This project uses Arduino IDE. In order to make it work with ESP8266, some libs and config are needed.

### ESP8266 Arduino IDE configuration

Under preferences, add the following link to the Additional Manager URLS section: 

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

Then click Tools>Board Manager and install esp8266 by ESP8266 Community. Select `Node MCU 1.0 (ESP-12 Module)`

### Required libs

* DHT sensor by Adafruit
* Adafruit Unified Sensor