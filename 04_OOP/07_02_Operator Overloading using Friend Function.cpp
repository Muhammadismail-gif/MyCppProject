#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v) {
        value = v;
    }

    // Declare friend function
    friend Number operator + (Number n1, Number n2);

    void display() {
        cout << "Value: " << value << endl;
    }
};

// Friend function definition
Number operator + (Number n1, Number n2) {
    Number temp(0);
    temp.value = n1.value + n2.value; // accessing private data
    return temp;
}

int main() {
    Number a(5), b(3);

    Number c = a + b; // calls friend operator

    c.display();

    return 0;
}