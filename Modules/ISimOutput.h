#pragma once
#include "Vehicle.h"

class ISimOutput {
public:
    virtual double GetSpeed(const Vehicle& v) const = 0;
    virtual ~ISimOutput() {}
};
