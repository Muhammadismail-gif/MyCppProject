#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    // Default Constructor
    Counter() {
        count = 0;
        cout << "Counter initialized with 0 (Default Constructor)." << endl;
    }

    // Parameterized Constructor
    Counter(int initialValue) {
        count = initialValue;
        cout << "Counter initialized with value: " << count << " (Parameterized Constructor)." << endl;
    }

    // Destructor
    ~Counter() {
        cout << "Destructor called. Final count value was: " << count << endl;
    }

    // Increment Method
    void increment() {
        count++;
    }

    // Display Method
    void display() {
        cout << "Current count: " << count << endl;
    }
};

int main() {
    // Creating first object using default constructor
    Counter c1;

    // Creating second object using parameterized constructor
    Counter c2(5);

    // Increment both counters
    c1.increment();
    c2.increment();

    // Display current values
    cout << "\nDisplaying Counter Values:\n";
    cout << "Counter 1: ";
    c1.display();

    cout << "Counter 2: ";
    c2.display();

    // Objects go out of scope here, so destructor will be automatically called
    return 0;
}
