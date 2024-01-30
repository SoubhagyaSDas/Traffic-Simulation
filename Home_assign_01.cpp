
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Vehicle {
protected:
    int currentSpeed;
    string currentDirection;
    pair<int, int> currentLocation;

public:
    Vehicle(int speed, const string& direction, const pair<int, int>& location)
        : currentSpeed(speed), currentDirection(direction), currentLocation(location) {}

    virtual void Accelerate(int toSpeed) = 0;  // Pure virtual function, making Vehicle abstract
    virtual void Decelerate(int toSpeed) = 0;
    virtual void Turn(const string& direction, int degrees) = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(int speed, const string& direction, const pair<int, int>& location)
        : Vehicle(speed, direction, location) {}

    void Accelerate(int toSpeed) {
        
    }

    void Decelerate(int toSpeed) {
        
    }

    void Turn(const string& direction, int degrees) {
        
    }
};

class Truck : public Vehicle {
private:
    int loadWeight;

public:
    Truck(int speed, const string& direction, const pair<int, int>& location, int weight)
        : Vehicle(speed, direction, location), loadWeight(weight) {}

    void Accelerate(int toSpeed) {
        
    }

    void Decelerate(int toSpeed) {
        
    }

    void Turn(const string& direction, int degrees) {
        
    }

    void SetLoadWeight(int weight) {
        
    }
};

int main() {
    return 0;
}
