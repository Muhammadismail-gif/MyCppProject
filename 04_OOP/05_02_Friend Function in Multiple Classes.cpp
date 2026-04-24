#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
private:
    int numA;

public:
    A() {
        numA = 5;
    }

    // Declare friend function
    friend void findMax(A, B);
};

class B {
private:
    int numB;

public:
    B() {
        numB = 10;
    }

    // Declare same friend function
    friend void findMax(A, B);
};

// Friend function definition
void findMax(A objA, B objB) {
    if (objA.numA > objB.numB) {
        cout << "A is greater: " << objA.numA << endl;
    } else {
        cout << "B is greater: " << objB.numB << endl;
    }
}

int main() {
    A a;
    B b;

    findMax(a, b);

    return 0;
}