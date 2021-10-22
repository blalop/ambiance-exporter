#pragma once

class PrometheusExporter {
  public:
    PrometheusExporter(const char *version, const char *gcc, const char *prefix, const char *room);
    const char *buildRoot();
    const char *buildMetrics(char *buffer, float temperature, float humidity);

  private:
    const char *version;
    const char *gcc;
    const char *prefix;
    const char *room;
};
