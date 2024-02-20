#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
protected:
    void Accelerate(int secondsDelta) override;
    void Decelerate(int secondsDelta) override;
};
