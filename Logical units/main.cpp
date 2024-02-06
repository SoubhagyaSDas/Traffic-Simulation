#include <iostream>
#include <vector>
#include "car.hpp"
#include "truck.hpp"

int main() {
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
            std::string s = typeid(*v).name();
            std::cout << s << " speed: " << v->GetCurrentSpeed() << " mph" << std::endl;
        }
    }

    return 0;
}
