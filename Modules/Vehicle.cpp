#include "Vehicle.h"
#include "Constants.h"

double Vehicle::GetCurrentSpeed() const {
    return currentSpeed;
}

void Vehicle::SetDesiredSpeed(double mph) {
    desiredSpeed = mph;
}

void Vehicle::SetCurrentSpeed(double speed) {
    currentSpeed = (speed < desiredSpeed) ? speed : desiredSpeed;
}

void Vehicle::UpdateSpeed(int seconds) {
    if (currentSpeed > desiredSpeed)
        Decelerate(seconds);
    else if (currentSpeed < desiredSpeed)
        Accelerate(seconds);
}

void Vehicle::Accelerate(int secondsDelta) {
    // Implementation depends on the specific vehicle type
}

void Vehicle::Decelerate(int secondsDelta) {
    // Implementation depends on the specific vehicle type
}
