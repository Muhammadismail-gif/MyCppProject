#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string make;
    int year;

public:
    void setDetails(string m, int y) {
        make = m;
        year = y;
    }

    void showDetails() {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class: Car (using virtual inheritance)
class Car : virtual public Vehicle {
public:
    void carType() {
        cout << "Type: Car" << endl;
    }
};

// Derived class: Truck (using virtual inheritance)
class Truck : virtual public Vehicle {
public:
    void truckType() {
        cout << "Type: Truck" << endl;
    }
};

// Derived class: ElectricTruck (inherits from both Car and Truck)
class ElectricTruck : public Car, public Truck {
public:
    void showElectricTruckDetails() {
        cout << "Electric Truck Features: Battery Powered, Zero Emissions, High Torque" << endl;
    }
};

// Main function
int main() {
    // Create object of ElectricTruck
    ElectricTruck et;

    // Set and show base class details
    et.setDetails("Tesla", 2024);
    et.showDetails();

    // Show types
    et.carType();
    et.truckType();

    // Show electric truck specific details
    et.showElectricTruckDetails();

    return 0;
}
