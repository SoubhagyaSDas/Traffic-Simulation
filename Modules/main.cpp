#include <iostream>
#include <vector>
#include <typeinfo>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "MetricOutput.h"
#include "ImperialOutput.h"

int main() {
    Car car;
    car.SetDesiredSpeed(65.0);
    Truck truck1(4);
    truck1.SetDesiredSpeed(55.0);
    Truck truck2(8);
    truck2.SetDesiredSpeed(50.0);

    MetricOutput metricOutput;
    ImperialOutput imperialOutput;
    ISimOutput* simOutput = &metricOutput; // Start with MetricOutput

    std::cout << "Running simulation with MetricOutput:" << std::endl;

    std::vector<Vehicle*> vehicles;
    vehicles.push_back(&car);
    vehicles.push_back(&truck1);
    vehicles.push_back(&truck2);

    for (size_t i = 0; i < vehicles.size(); ++i) {
        Vehicle* v = vehicles[i];
        for (int j = 0; j < 11; j++) {
            v->UpdateSpeed(1);
            std::cout << typeid(*v).name() << " speed: " << simOutput->GetSpeed(*v) << std::endl;
        }
    }

    // Switch to ImperialOutput
    simOutput = &imperialOutput;

    std::cout << "\nRunning simulation with ImperialOutput:" << std::endl;

    for (size_t i = 0; i < vehicles.size(); ++i) {
        Vehicle* v = vehicles[i];
        for (int j = 0; j < 11; j++) {
            v->UpdateSpeed(1);
            std::cout << typeid(*v).name() << " speed: " << simOutput->GetSpeed(*v) << std::endl;
        }
    }

    return 0;
}
