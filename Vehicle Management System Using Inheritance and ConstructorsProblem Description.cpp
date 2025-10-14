#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string brand;
    int year;

public:
    // Constructor
    Vehicle(string b, int y) : brand(b), year(y) {
        cout << "Vehicle constructor called for: " << brand << endl;
    }

    // Destructor
    virtual ~Vehicle() {
        cout << "Destroying Vehicle: " << brand << endl;
    }

    // Virtual function for polymorphism
    virtual void display() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor
    Car(string b, int y, int doors) : Vehicle(b, y), numDoors(doors) {
        cout << "Car constructor called for: " << brand << endl;
    }

    // Destructor
    ~Car() {
        cout << "Destroying Car: " << brand << endl;
    }

    // Override display function
    void display() const override {
        cout << "Car - Brand: " << brand << ", Year: " << year
             << ", Doors: " << numDoors << endl;
    }
};

// Derived class: Bicycle
class Bicycle : public Vehicle {
private:
    int numGears;

public:
    // Constructor
    Bicycle(string b, int y, int gears) : Vehicle(b, y), numGears(gears) {
        cout << "Bicycle constructor called for: " << brand << endl;
    }

    // Destructor
    ~Bicycle() {
        cout << "Destroying Bicycle: " << brand << endl;
    }

    // Override display function
    void display() const override {
        cout << "Bicycle - Brand: " << brand << ", Year: " << year
             << ", Gears: " << numGears << endl;
    }
};

// Main Function
int main() {
    // Creating a Car object
    Car myCar("Toyota", 2022, 4);
    cout << endl;

    // Creating a Bicycle object
    Bicycle myBike("Trek", 2021, 18);
    cout << endl;

    // Using polymorphism
    Vehicle* v1 = &myCar;
    Vehicle* v2 = &myBike;

    v1->display();  // Calls Car's display
    v2->display();  // Calls Bicycle's display

    cout << endl;

    return 0;
}
