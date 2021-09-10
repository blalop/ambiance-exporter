#include "prometheus.hpp"

#include <cstdio>

const char *buildRoot() {
    return "<html>"
           "<head><title>Ambiance Exporter</title></head>"
           "<body>"
           "<h1>Ambiance Exporter</h1>"
           "<p><a href=\"/metrics\">Metrics</a></p>"
           "</body>"
           "</html>";
}

const char *buildMetrics(char* buffer, PrometheusData data) {
#ifdef __VERSION__
    int len = sprintf(buffer, "%s_%s{version=\"%s\",gccversion=\"%s\"} 1\n", data.prefix, "build_info", data.version, __VERSION__);
#else
    int len = sprintf(buffer, "%s_%s{version=\"%s\"} 1\n", data.prefix, "build_info", data.version);
#endif
    len += sprintf(buffer + len, "%s_%s %.2f\n", data.prefix, "temperature", data.temperature);
    len += sprintf(buffer + len, "%s_%s %.2f\n", data.prefix, "humidity", data.humidity);
    return buffer;
}
