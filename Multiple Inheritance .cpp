#include <iostream>
using namespace std;

// Base class: Camera
class Camera {
public:
    void takePhoto() {
        cout << "Photo taken" << endl;
    }
};

// Base class: GPS
class GPS {
public:
    void showLocation() {
        cout << "Location shown" << endl;
    }
};

// Derived class: Smartphone
class Smartphone : public Camera, public GPS {
    // Inherits everything from Camera and GPS
};

// Main function
int main() {
    Smartphone myPhone;

    // Use functionality from both base classes
    myPhone.takePhoto();      // From Camera
    myPhone.showLocation();   // From GPS

    return 0;
}
