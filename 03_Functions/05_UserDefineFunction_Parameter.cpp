#include <iostream>
using namespace std;


// 1. FORMAL vs ACTUAL PARAMETERS
// ============================================

// Formal parameters: a and b (declared in function definition)
void add(int a, int b) {
    cout << "Sum = " << (a + b) << endl;
}

// ============================================
// 2. DEFAULT PARAMETER
// ============================================

void greet(string name, string msg = "Hello") {
    cout << msg << " " << name << endl;
}

// ============================================
// 3. MULTIPLE PARAMETERS
// ============================================

void showInfo(string name, int age, float marks) {
    cout << "Name: " << name << ", Age: " << age << ", Marks: " << marks << endl;
}

// ============================================
// 4. CONST PARAMETER
// ============================================

void printNumber(const int num) {
    // num = 10;  // ERROR: cannot modify const
    cout << "Number: " << num << endl;
}

// ============================================
// 5. PASS BY VALUE
// ============================================

void changeValue(int x) {
    x = 100;  // Changes only the copy
    cout << "Inside function: x = " << x << endl;
}

// ============================================
// 6. PASS BY REFERENCE
// ============================================

void changeReference(int &x) {
    x = 100;  // Changes original
    cout << "Inside function: x = " << x << endl;
}

// ============================================
// 7. PASS BY POINTER
// ============================================

void changePointer(int *x) {
    *x = 100;  // Changes original through pointer
    cout << "Inside function: *x = " << *x << endl;
}

// ============================================
// 8. PASS ARRAY
// ============================================

void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ============================================
// MAIN FUNCTION
// ============================================

int main() {
    cout << "=== C++ FUNCTION PARAMETERS ===" << endl << endl;

    // 1. Formal vs Actual
    cout << "1. FORMAL vs ACTUAL PARAMETERS" << endl;
    int m = 5, n = 3;
    add(m, n);           // m, n are actual parameters
    add(10, 20);         // literals as actual parameters
    cout << endl;

    // 2. Default Parameter
    cout << "2. DEFAULT PARAMETER" << endl;
    greet("Alice");              // uses default "Hello"
    greet("Bob", "Hi");          // overrides default
    cout << endl;

    // 3. Multiple Parameters
    cout << "3. MULTIPLE PARAMETERS" << endl;
    showInfo("John", 20, 85.5);
    cout << endl;

    // 4. Const Parameter
    cout << "4. CONST PARAMETER" << endl;
    printNumber(50);
    cout << endl;

    // 5. Pass by Value
    cout << "5. PASS BY VALUE" << endl;
    int a = 10;
    cout << "Before: a = " << a << endl;
    changeValue(a);
    cout << "After: a = " << a << " (unchanged!)" << endl;
    cout << endl;

    // 6. Pass by Reference
    cout << "6. PASS BY REFERENCE" << endl;
    int b = 10;
    cout << "Before: b = " << b << endl;
    changeReference(b);
    cout << "After: b = " << b << " (changed!)" << endl;
    cout << endl;

    // 7. Pass by Pointer
    cout << "7. PASS BY POINTER" << endl;
    int c = 10;
    cout << "Before: c = " << c << endl;
    changePointer(&c);
    cout << "After: c = " << c << " (changed!)" << endl;
    cout << endl;

    // 8. Pass Array
    cout << "8. PASS ARRAY" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    cout << "Note: Arrays always pass by reference (pointer)" << endl;

    return 0;
}