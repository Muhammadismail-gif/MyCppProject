#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    // Constructor
    Box() {
        length = 10;
    }

    // Declare friend function
    friend void showLength(Box b);
};

// Friend function definition
void showLength(Box b) {
    // Accessing private data
    cout << "Length of box: " << b.length << endl;
}

int main() {
    Box obj;

    // Calling friend function
    showLength(obj);

    return 0;
}