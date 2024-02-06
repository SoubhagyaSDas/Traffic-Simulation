#include "vehicle.hpp"

double Vehicle::GetCurrentSpeed() {
    return currentSpeed;
}

void Vehicle::SetDesiredSpeed(double mph) {
    desiredSpeed = mph;
}

void Vehicle::SetCurrentSpeed(double speed) {
    if (currentSpeed <= speed) { // accelerating
        if (speed > desiredSpeed) currentSpeed = desiredSpeed;
        else currentSpeed = speed;
    } else { // braking
        if (speed < desiredSpeed) currentSpeed = desiredSpeed;
        else currentSpeed = speed;
    }
}

void Vehicle::UpdateSpeed(int seconds) {
    if (currentSpeed > desiredSpeed) Decelerate(seconds);
    else if (currentSpeed < desiredSpeed) Accelerate(seconds);
}
