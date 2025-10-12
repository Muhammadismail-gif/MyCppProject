#include <iostream>
using namespace std;

// Function templates for calculator operations
void add(int* a, int* b) {
    cout << "Addition (int): " << (*a + *b) << endl;
}

void subtract(float* a, float* b) {
    cout << "Subtraction (float): " << (*a - *b) << endl;
}

void multiply(double* a, double* b) {
    cout << "Multiplication (double): " << (*a * *b) << endl;
}

void divide(double* a, double* b) {
    if (*b != 0)
        cout << "Division (double): " << (*a / *b) << endl;
    else
        cout << "Division by zero is not allowed!" << endl;
}

// Main function
int main() {
    // Step 1: Declare variables
    int a = 10, b = 5;
    float x = 7.5f, y = 2.5f;
    double m = 9.0, n = 3.0;

    // Step 2: Declare pointers
    int* p1 = &a;
    int* p2 = &b;

    float* p3 = &x;
    float* p4 = &y;

    double* p5 = &m;
    double* p6 = &n;

    // Step 3: Perform operations using functions
    cout << "--- Simple Calculator Using Pointers ---" << endl << endl;

    add(p1, p2);             // int addition
    subtract(p3, p4);        // float subtraction
    multiply(p5, p6);        // double multiplication
    divide(p5, p6);          // double division

    return 0;
}
