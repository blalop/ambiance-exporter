#include "config.hpp"
#include "prometheus.hpp"

#include <Arduino.h>
#include <DHT.h>
#include <unity.h>

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
    String actual = buildMetrics("test", 1.0, 1.0);
    String expected = "test_temperature 1.00\ntest_humidity 1.00";
    TEST_ASSERT_EQUAL_STRING(expected.c_str(), actual.c_str());
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