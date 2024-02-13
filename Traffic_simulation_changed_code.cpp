#include <iostream>
#include <vector>

class Vehicle; // Forward declaration of Vehicle class

class ISimOutput {
public:
    virtual double GetSpeed(const Vehicle& v) const = 0;
};

class MetricOutput : public ISimOutput {
public:
    double GetSpeed(const Vehicle& v) const override {
        return v.GetCurrentSpeed() * 1.6; // Convert to km/h
    }
};

class ImperialOutput : public ISimOutput {
public:
    double GetSpeed(const Vehicle& v) const override {
        return v.GetCurrentSpeed();
    }
};

class Constants {
public:
    static constexpr double AccRate = 3.5;           // Acceleration rate for cars in m/s
    static constexpr double AccRateEmpty = 2.5;      // Acceleration rate for light trucks in m/s
    static constexpr double AccRateFull = 1.0;       // Acceleration rate for heavy trucks in m/s
    static constexpr double DecRate = 7.0;           // Braking rate for cars in m/s
    static constexpr double DecRateEmpty = 5.0;      // Braking rate for light trucks in m/s
    static constexpr double DecRateFull = 2.0;       // Braking rate for light trucks in m/s
    static constexpr double MpsToMph = 2.237;
};

class Vehicle {
private:
    double currentSpeed = 0.0;
    double desiredSpeed;

protected:
    virtual void Accelerate(int secondsDelta) = 0;
    virtual void Decelerate(int secondsDelta) = 0;

public:
    double GetCurrentSpeed() const {
        return currentSpeed;
    }

    void SetDesiredSpeed(double mph) {
        desiredSpeed = mph;
    }

    void SetCurrentSpeed(double speed) {
        currentSpeed = (speed < desiredSpeed) ? speed : desiredSpeed;
    }

    void UpdateSpeed(int seconds) {
        if (currentSpeed > desiredSpeed)
            Decelerate(seconds);
        else if (currentSpeed < desiredSpeed)
            Accelerate(seconds);
    }
};

class Car : public Vehicle {
protected:
    void Accelerate(int secondsDelta) override {
        SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRate * secondsDelta * Constants::MpsToMph);
    }

    void Decelerate(int secondsDelta) override {
        SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRate * secondsDelta * Constants::MpsToMph);
    }
};

class Truck : public Vehicle {
private:
    int loadWeight; // in tons

public:
    Truck(int weight) : loadWeight(weight) {}

protected:
    void Accelerate(int secondsDelta) override {
        if (loadWeight <= 5)
            SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateEmpty * secondsDelta * Constants::MpsToMph);
        else
            SetCurrentSpeed(GetCurrentSpeed() + Constants::AccRateFull * secondsDelta * Constants::MpsToMph);
    }

    void Decelerate(int secondsDelta) override {
        if (loadWeight <= 5)
            SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateEmpty * secondsDelta * Constants::MpsToMph);
        else
            SetCurrentSpeed(GetCurrentSpeed() - Constants::DecRateFull * secondsDelta * Constants::MpsToMph);
    }
};

int main() {
    ISimOutput* simOutput = new MetricOutput(); // Change to MetricOutput or ImperialOutput as needed

    Car car;
    car.SetDesiredSpeed(65.0);
    Truck truck1(4);
    truck1.SetDesiredSpeed(55.0);
    Truck truck2(8);
    truck2.SetDesiredSpeed(50.0);

    std::vector<Vehicle*> vehicles;
    vehicles.push_back(&car);
    vehicles.push_back(&truck1);
    vehicles.push_back(&truck2);

    for (int i = 0; i < 11; i++) {
        for (Vehicle* v : vehicles) {
            v->UpdateSpeed(1);
            std::cout << typeid(*v).name() << " speed: " << simOutput->GetSpeed(*v) << std::endl;
        }
    }

    delete simOutput; // Don't forget to delete dynamically allocated memory

    return 0;
}
