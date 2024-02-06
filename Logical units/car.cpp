#include "car.hpp"

void Car::Accelerate(int secondsDelta) {
    SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRate * secondsDelta * Constants::MpsToMph);
}

void Car::Decelerate(int secondsDelta) {
    SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRate * secondsDelta * Constants::MpsToMph);
}
