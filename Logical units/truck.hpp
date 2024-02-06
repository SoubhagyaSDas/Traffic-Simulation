#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "vehicle.hpp"
#include "constants.hpp"

class Truck : public Vehicle {
private:
    int loadWeight;      // in tons

public:
    Truck(int weight);
protected:
    void Accelerate(int secondsDelta) override;
    void Decelerate(int secondsDelta) override;
};

#endif /* TRUCK_HPP */
