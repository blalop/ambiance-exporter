#pragma once

class PrometheusExporter {
  public:
    PrometheusExporter(const char *version, const char *prefix);
    const char *buildRoot();
    const char *buildMetrics(char *buffer, float temperature, float humidity);

  private:
    const char *version;
    const char *prefix;
};
