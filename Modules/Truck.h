#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
private:
    int loadWeight; // in tons

public:
    Truck(int weight);
    
protected:
    void Accelerate(int secondsDelta) override;
    void Decelerate(int secondsDelta) override;
};
