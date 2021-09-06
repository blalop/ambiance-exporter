#include "prometheus.hpp"

String buildRoot() {
    return "<html>"
           "<head><title>Ambiance Exporter</title></head>"
           "<body>"
           "<h1>Ambiance Exporter</h1>"
           "<p><a href=\"/metrics\">Metrics</a></p>"
           "</body>"
           "</html>";
}

String buildMetrics(String prefix, float temperature, float humidity) {
    return prefix + "_temperature " + String(temperature) + "\n" +
           prefix + "_humidity " + String(humidity);
}
