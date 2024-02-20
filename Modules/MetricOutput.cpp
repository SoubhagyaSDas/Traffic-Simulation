#include "MetricOutput.h"

double MetricOutput::GetSpeed(const Vehicle& v) const {
    return v.GetCurrentSpeed() * 1.6; // Convert to km/h
}
