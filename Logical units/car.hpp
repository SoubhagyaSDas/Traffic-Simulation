#ifndef CAR_HPP
#define CAR_HPP

#include "vehicle.hpp"
#include "constants.hpp"

class Car : public Vehicle {
protected:
    void Accelerate(int secondsDelta) override;
    void Decelerate(int secondsDelta) override;
};

#endif /* CAR_HPP */
