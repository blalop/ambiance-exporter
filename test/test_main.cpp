#include "config.hpp"
#include "prometheus.hpp"

#include <Arduino.h>
#include <DHT.h>
#include <unity.h>

#include <string>

DHT dht(DHTPIN, DHTTYPE);


void testReadDHTTemperature() {
    float temperature = dht.readTemperature();
    TEST_ASSERT_FLOAT_IS_NOT_NAN(temperature);
}

void testReadDHTHumidity() {
    float humidity = dht.readHumidity();
    TEST_ASSERT_FLOAT_IS_NOT_NAN(humidity);
}

void testBuildMetrics() {
    PrometheusExporter exporter("1.0.0", "10.2.1", "ambiance", "livingroom");
    char buffer [1024];
    const char *actual = exporter.buildMetrics(buffer, 1.0, 1.0);

    const char *expectedTemperature = "ambiance_temperature{room=\"livingroom\"} 1.00";
    const char *expectedHumidity = "ambiance_humidity{room=\"livingroom\"} 1.00";
    TEST_ASSERT_EQUAL_STRING(buffer, actual);
    TEST_ASSERT_NOT_NULL(strstr(actual, expectedTemperature));
    TEST_ASSERT_NOT_NULL(strstr(actual, expectedHumidity));
}

void setup() {
    delay(2000);

    UNITY_BEGIN();

    pinMode(DHTPIN, INPUT);
    dht.begin();

    RUN_TEST(testReadDHTTemperature);
    delay(500);
    RUN_TEST(testReadDHTHumidity);
    delay(500);
    RUN_TEST(testBuildMetrics);
    delay(500);

    UNITY_END();
}

void loop() {

}
