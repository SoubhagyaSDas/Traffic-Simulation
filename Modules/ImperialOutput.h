#pragma once
#include "ISimOutput.h"

class ImperialOutput : public ISimOutput {
public:
    double GetSpeed(const Vehicle& v) const override;
};
