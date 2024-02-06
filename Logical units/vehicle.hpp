#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle {
protected:
    double currentSpeed = 0.0;
    double desiredSpeed;

    virtual void Accelerate(int secondsDelta) = 0;
    virtual void Decelerate(int secondsDelta) = 0;

public:
    double GetCurrentSpeed();
    void SetDesiredSpeed(double mph);
    void SetCurrentSpeed(double speed);
    void UpdateSpeed(int seconds);
};

#endif /* VEHICLE_HPP */
