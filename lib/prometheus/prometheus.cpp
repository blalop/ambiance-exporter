#include "prometheus.hpp"

#include <cmath>
#include <cstdio>

PrometheusExporter::PrometheusExporter(const char *version, const char *gcc, const char *prefix,
                                       const char *room)
    : version(version), gcc(gcc), prefix(prefix), room(room) {}

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
    int len = sprintf(buffer, "%s_%s{version=\"%s\",gccversion=\"%s\",room=\"%s\"} 1\n",
                      prefix, "build_info", version, gcc, room);

    if (!std::isnan(temperature)) {
        len += sprintf(buffer + len, "%s_%s{room=\"%s\"} %.2f\n", prefix, "temperature",
                       room, temperature);
    }

    if (!std::isnan(humidity)) {
        len += sprintf(buffer + len, "%s_%s{room=\"%s\"} %.2f\n", prefix, "humidity", room,
                       humidity);
    }

    return buffer;
}
