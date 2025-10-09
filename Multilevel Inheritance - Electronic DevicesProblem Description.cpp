#include <iostream>
#include <string>
using namespace std;

// Base class: Device
class Device {
protected:
    string brand;

public:
    void setBrand(string b) {
        brand = b;
    }

    void showBrand() {
        cout << "Brand: " << brand << endl;
    }
};

// Derived class: Laptop (inherits from Device)
class Laptop : public Device {
public:
    void showType() {
        cout << "Type: Laptop" << endl;
    }
};

// Derived class: GamingLaptop (inherits from Laptop)
class GamingLaptop : public Laptop {
public:
    void showFeatures() {
        cout << "Features: High-performance CPU, RGB keyboard, Dedicated GPU, Cooling system" << endl;
    }
};

// Main function
int main() {
    // Create object of GamingLaptop
    GamingLaptop myGamingLaptop;

    // Set brand
    myGamingLaptop.setBrand("Asus ROG");

    // Display details
    myGamingLaptop.showBrand();
    myGamingLaptop.showType();
    myGamingLaptop.showFeatures();

    return 0;
}
