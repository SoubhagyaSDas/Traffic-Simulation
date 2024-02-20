#pragma once
#include "ISimOutput.h"

class MetricOutput : public ISimOutput {
public:
    double GetSpeed(const Vehicle& v) const override;
};
