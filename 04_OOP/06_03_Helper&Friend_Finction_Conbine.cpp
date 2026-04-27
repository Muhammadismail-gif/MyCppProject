#include <iostream>
using namespace std;

class Number {
private:
    int value;

    // Helper function (private)
    int square() {
        return value * value;
    }

public:
    // Constructor
    Number(int v) {
        value = v;
    }

    // Public function using helper
    void showSquare() {
        cout << "Square (using helper): " << square() << endl;
    }

    // Friend function declaration
    friend void showDouble(Number obj);
};

// Friend function definition
void showDouble(Number obj) {
    // Accessing private data directly
    cout << "Double (using friend): " << obj.value * 2 << endl;
}

int main() {
    Number n(5);

    n.showSquare();     // uses helper function
    showDouble(n);      // uses friend function

    return 0;
}