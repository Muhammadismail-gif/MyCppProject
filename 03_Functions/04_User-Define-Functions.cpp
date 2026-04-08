#include <iostream>
#include <cmath>  // For built-in functions
using namespace std;

// ============================================================
// 1. FUNCTION DECLARATION / PROTOTYPE
// ============================================================
// A function prototype declares the function's interface before it's defined
// It tells the compiler: return type, function name, and parameters

// Syntax: return_type function_name(parameter_list);
int add(int a, int b);           // Prototype for add function
double calculateArea(double radius);  // Prototype for area function
void printMessage(string msg);   // Prototype for void function (no return)
bool isPositive(int num);        // Prototype returning bool

// ============================================================
// 2. USER DEFINED FUNCTIONS - Complete Examples
// ============================================================

// ------------------- EXAMPLE 1: Function with Return Value -------------------
// RETURN TYPE: int
// FUNCTION NAME: add
// PARAMETERS: (int a, int b) - two integer parameters

int add(int a, int b) {          // FUNCTION HEADER starts here
    // FUNCTION BODY starts here (inside braces)
    int sum = a + b;             // Local variable declaration
    return sum;                  // RETURN KEYWORD: sends value back to caller
}                                // FUNCTION BODY ends here

// ------------------- EXAMPLE 2: Function with double return -------------------
// Shows different return types and parameter types

double calculateArea(double radius) {
    const double PI = 3.14159;
    double area = PI * radius * radius;
    return area;                 // Returns a double value
}

// ------------------- EXAMPLE 3: Void Function (No Return Value) -------------------
// VOID return type means function doesn't return anything

void printMessage(string msg) {  // FUNCTION HEADER
    // FUNCTION BODY
    cout << "Message: " << msg << endl;
    // No return statement needed (but can use 'return;' to exit early)
}

// ------------------- EXAMPLE 4: Function with Multiple Parameters -------------------
// Demonstrates various parameter types and default values

double calculatePower(double base, int exponent = 2) {
    // Default parameter: if exponent not provided, uses 2
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// ------------------- EXAMPLE 5: Function returning bool -------------------
bool isPositive(int num) {
    if (num > 0) {
        return true;             // Returns boolean value
    } else {
        return false;            // Returns boolean value
    }
    // Alternative single line: return (num > 0);
}

// ------------------- EXAMPLE 6: Function with Reference Parameters -------------------
// Modifies original variable (pass by reference)

void swapValues(int &x, int &y) {  // & indicates reference (alias to original)
    int temp = x;
    x = y;
    y = temp;
    // No return needed - changes are made directly to original variables
}

// ------------------- EXAMPLE 7: Function with Multiple Return Paths -------------------
int findMax(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;                // First return path
    } else if (b >= a && b >= c) {
        return b;                // Second return path
    } else {
        return c;                // Third return path
    }
}

// ============================================================
// 3. BUILT-IN vs USER DEFINED FUNCTIONS DEMONSTRATION
// ============================================================

void demonstrateBuiltInVsUserDefined() {
    cout << "\n=== BUILT-IN vs USER DEFINED FUNCTIONS ===" << endl;
    
    // BUILT-IN FUNCTIONS: Pre-defined in C++ standard libraries
    // Examples from <cmath> library:
    double number = 16.0;
    
    cout << "Built-in sqrt(16): " << sqrt(number) << endl;      // Square root
    cout << "Built-in pow(2, 3): " << pow(2, 3) << endl;         // Power
    cout << "Built-in abs(-10): " << abs(-10) << endl;           // Absolute value
    cout << "Built-in ceil(4.2): " << ceil(4.2) << endl;         // Ceiling
    cout << "Built-in floor(4.8): " << floor(4.8) << endl;       // Floor
    
    // USER DEFINED FUNCTIONS: Created by programmer (like our 'add' function)
    cout << "User-defined add(5, 3): " << add(5, 3) << endl;
    cout << "User-defined calculateArea(5): " << calculateArea(5) << endl;
}

// ============================================================
// 4. RETURNING VALUES FROM FUNCTIONS - Various Examples
// ============================================================

// Returning basic types
char getGrade(int score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';                  // Multiple return statements
}

// Returning from void function (early exit)
void checkEligibility(int age) {
    if (age < 18) {
        cout << "Not eligible - too young" << endl;
        return;                  // Exit function early (no value returned)
    }
    cout << "Eligible for voting" << endl;
}

// Returning string
string getDayName(int dayNum) {
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", 
                     "Thursday", "Friday", "Saturday"};
    if (dayNum >= 0 && dayNum <= 6) {
        return days[dayNum];
    }
    return "Invalid day";        // Return string
}

// ============================================================
// MAIN FUNCTION - Where program execution begins
// ============================================================

int main() {
    cout << "========================================" << endl;
    cout << "   C++ FUNCTIONS - COMPLETE GUIDE" << endl;
    cout << "========================================" << endl;

    // --------------------------------------------------------
    // CALLING FUNCTIONS (Function Invocation)
    // --------------------------------------------------------
    cout << "\n=== CALLING FUNCTIONS ===" << endl;
    
    // Call 1: Simple function call with literals
    int result1 = add(10, 20);           // Function call: add(10, 20)
    cout << "add(10, 20) = " << result1 << endl;
    
    // Call 2: Function call with variables
    int x = 5, y = 8;
    int result2 = add(x, y);             // Passing variables as arguments
    cout << "add(x, y) where x=5, y=8: " << result2 << endl;
    
    // Call 3: Function call in expression
    int result3 = add(2, 3) + add(4, 5); // Functions in expression
    cout << "add(2,3) + add(4,5) = " << result3 << endl;
    
    // Call 4: Void function call (no assignment, no return value)
    printMessage("Hello from C++ Functions!");
    
    // Call 5: Function with default parameter
    cout << "calculatePower(3) [default exp=2]: " << calculatePower(3) << endl;
    cout << "calculatePower(2, 4) [exp=4]: " << calculatePower(2, 4) << endl;
    
    // Call 6: Function call with return value used directly
    cout << "Area of circle (radius 7): " << calculateArea(7) << endl;
    
    // Call 7: Function with reference parameters
    int num1 = 10, num2 = 20;
    cout << "\nBefore swap: num1=" << num1 << ", num2=" << num2 << endl;
    swapValues(num1, num2);              // Call by reference - modifies originals
    cout << "After swap: num1=" << num1 << ", num2=" << num2 << endl;
    
    // Call 8: Function returning bool used in condition
    int testNum = 25;
    if (isPositive(testNum)) {
        cout << testNum << " is positive" << endl;
    }
    
    // Call 9: Multiple return paths function
    cout << "Max of (10, 25, 15): " << findMax(10, 25, 15) << endl;
    
    // --------------------------------------------------------
    // BUILT-IN vs USER DEFINED DEMONSTRATION
    // --------------------------------------------------------
    demonstrateBuiltInVsUserDefined();
    
    // --------------------------------------------------------
    // RETURNING VALUES DEMONSTRATION
    // --------------------------------------------------------
    cout << "\n=== RETURNING VALUES FROM FUNCTIONS ===" << endl;
    
    // Return char
    cout << "Grade for score 85: " << getGrade(85) << endl;
    
    // Return string
    cout << "Day 3 is: " << getDayName(3) << endl;
    
    // Void with early return
    checkEligibility(16);
    checkEligibility(21);
    
    // --------------------------------------------------------
    // PARTS OF FUNCTION DEFINITION SUMMARY
    // --------------------------------------------------------
    cout << "\n=== PARTS OF FUNCTION DEFINITION ===" << endl;
    cout << "1. FUNCTION HEADER: int add(int a, int b)" << endl;
    cout << "   - Return type: int" << endl;
    cout << "   - Function name: add" << endl;
    cout << "   - Parameter list: (int a, int b)" << endl;
    cout << "\n2. FUNCTION BODY: { ... }" << endl;
    cout << "   - Contains statements inside braces" << endl;
    cout << "   - May contain: declarations, operations, return statement" << endl;
    cout << "\n3. RETURN KEYWORD: return value;" << endl;
    cout << "   - Exits function and sends value back to caller" << endl;
    cout << "   - For void functions: return; (or omit)" << endl;

    return 0;  // Main function also returns a value (0 = success)
}