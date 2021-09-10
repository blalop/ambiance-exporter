#pragma once

struct PrometheusData {
    const char *version;
    const char *prefix;
    float temperature;
    float humidity;
};

const char *buildRoot();
const char *buildMetrics(char *buffer, PrometheusData data);
