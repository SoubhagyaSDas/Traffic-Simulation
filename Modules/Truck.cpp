#include "Truck.h"
#include "Constants.h"

Truck::Truck(int weight) : loadWeight(weight) {}

void Truck::Accelerate(int secondsDelta) {
    if (loadWeight <= 5)
        SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateEmpty * secondsDelta * Constants::MpsToMph);
    else
        SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateFull * secondsDelta * Constants::MpsToMph);
}

void Truck::Decelerate(int secondsDelta) {
    if (loadWeight <= 5)
        SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateEmpty * secondsDelta * Constants::MpsToMph);
    else
        SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateFull * secondsDelta * Constants::MpsToMph);
}
