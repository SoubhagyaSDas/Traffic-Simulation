#pragma once

class Vehicle {
private:
    double currentSpeed = 0.0;
    double desiredSpeed;

protected:
    virtual void Accelerate(int secondsDelta);
    virtual void Decelerate(int secondsDelta);

public:
    double GetCurrentSpeed() const;
    void SetDesiredSpeed(double mph);
    void SetCurrentSpeed(double speed);
    void UpdateSpeed(int seconds);
};
