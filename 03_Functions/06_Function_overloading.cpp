#include <iostream>
using namespace std;

 
// GLOBAL VARIABLES (accessible everywhere)
 
int globalVar = 100;  // Global variable

void showGlobal() {
    cout << "Global inside function: " << globalVar << endl;
}

 
// 1. FUNCTION OVERLOADING
 

// Same function name, different parameters
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {  // Different parameter types
    return a + b;
}

int add(int a, int b, int c) {    // Different number of parameters
    return a + b + c;
}

 
// 2. OPERATOR OVERLOADING
 

class Complex {
public:
    int real, imag;
    
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    
    // Overload + operator
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

 
// 3. RECURSION
 

int factorial(int n) {
    if (n <= 1)           // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

 
// MAIN FUNCTION
 

// main() CANNOT be overloaded in C++ - only one main allowed
int main() {
    cout << "=== C++ FUNCTIONS ===" << endl << endl;

    // --- Function Overloading ---
    cout << "1. FUNCTION OVERLOADING" << endl;
    cout << "add(2, 3) = " << add(2, 3) << endl;
    cout << "add(2.5, 3.5) = " << add(2.5, 3.5) << endl;
    cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;
    cout << "Advantage: Same name for similar operations" << endl;
    cout << "Disadvantage: Can be confusing if overused" << endl << endl;

    // --- Operator Overloading ---
    cout << "2. OPERATOR OVERLOADING" << endl;
    Complex c1(3, 2), c2(1, 7);
    Complex c3 = c1 + c2;  // Using overloaded +
    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << "c1 + c2 = "; c3.display();
    cout << endl;

    // --- Recursion ---
    cout << "3. RECURSION" << endl;
    cout << "Factorial of 5 = " << factorial(5) << endl;
    cout << "5! = 5 × 4 × 3 × 2 × 1 = 120" << endl << endl;

    // --- Main Function ---
    cout << "4. MAIN FUNCTION" << endl;
    cout << "- Entry point of program" << endl;
    cout << "- Can only have ONE main()" << endl;
    cout << "- CANNOT be overloaded" << endl << endl;

    // --- Global vs Local Variables ---
    cout << "5. GLOBAL vs LOCAL VARIABLES" << endl;
    
    cout << "Global: " << globalVar << endl;
    showGlobal();
    
    int localVar = 50;  // Local variable
    cout << "Local in main: " << localVar << endl;
    
    // Local variable scope demo
    {
        int blockVar = 25;  // Local to this block
        cout << "Block local: " << blockVar << endl;
    }
    // blockVar not accessible here
    
    cout << endl << "--- COMPARISON ---" << endl;
    cout << "LOCAL VARIABLES:" << endl;
    cout << "+ Memory efficient (created/destroyed as needed)" << endl;
    cout << "+ No naming conflicts" << endl;
    cout << "+ Easier to debug" << endl;
    cout << "- Limited scope" << endl;
    cout << "- Data not shared between functions" << endl << endl;
    
    cout << "GLOBAL VARIABLES:" << endl;
    cout << "+ Shared across all functions" << endl;
    cout << "+ Data persists throughout program" << endl;
    cout << "- Risk of accidental modification" << endl;
    cout << "- Harder to debug" << endl;
    cout << "- Memory occupied for entire program" << endl;

    return 0;
}