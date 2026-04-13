#include <iostream>
using namespace std;

// Real-world analogy: A Car
class Car {
    string brand;
    string model;
    int speed;
    
public:
    Car(string b, string m) : brand(b), model(m), speed(0) {}
    
    void accelerate() { speed += 10; }
    void brake() { speed = 0; }
    void honk() { cout << "Beep! Beep!\n"; }
    
    void showStatus() {
        cout << brand << " " << model << " running at " << speed << " km/h\n";
    }
};

int main() {
    // Objects interacting like real entities
    Car toyota("Toyota", "Corolla");
    Car bmw("BMW", "X5");
    
    toyota.accelerate();
    toyota.honk();
    bmw.accelerate();
    bmw.accelerate();
    
    toyota.showStatus();  // Toyota Corolla running at 10 km/h
    bmw.showStatus();     // BMW X5 running at 20 km/h
    
    return 0;
}