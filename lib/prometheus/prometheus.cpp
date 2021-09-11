#include "prometheus.hpp"

#include <cstdio>

PrometheusExporter::PrometheusExporter(const char *version, const char *prefix)
    : version(version), prefix(prefix) {}

const char *PrometheusExporter::buildRoot() {
    return "<html>"
           "<head><title>Ambiance Exporter</title></head>"
           "<body>"
           "<h1>Ambiance Exporter</h1>"
           "<p><a href=\"/metrics\">Metrics</a></p>"
           "</body>"
           "</html>";
}

const char *PrometheusExporter::buildMetrics(char *buffer, float temperature, float humidity) {
#ifdef __VERSION__
    int len = sprintf(buffer, "%s_%s{version=\"%s\",gccversion=\"%s\"} 1\n", prefix,
                      "build_info", version, __VERSION__);
#else
    int len = sprintf(buffer, "%s_%s{version=\"%s\"} 1\n", prefix, "build_info", version);
#endif
    len += sprintf(buffer + len, "%s_%s %.2f\n", prefix, "temperature", temperature);
    len += sprintf(buffer + len, "%s_%s %.2f\n", prefix, "humidity", humidity);
    return buffer;
}
