#include <iostream>
using namespace std;

// Global Variable (accessible everywhere)
int globalVar = 100;

int main() {

    // 1. Basic Data Types
    int age = 20;                // Integer
    float height = 5.9f;         // Float
    double pi = 3.1415926535;    // Double (more precision)
    char grade = 'A';            // Character
    bool isStudent = true;       // Boolean (true/false)

    cout << "Basic Variables:\n";
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Pi: " << pi << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student: " << isStudent << endl;

    cout << "\n----------------------\n";

    // 2. Variable Declaration & Initialization
    int a;       // Declaration
    a = 10;      // Initialization

    int b = 20;  // Declaration + Initialization

    cout << "a = " << a << ", b = " << b << endl;

    cout << "\n----------------------\n";

    // 3. Constant Variable
    const int DAYS_IN_WEEK = 7;
    cout << "Days in week: " << DAYS_IN_WEEK << endl;

    cout << "\n----------------------\n";

    // 4. Local vs Global Variable
    int globalVar = 50; // Local variable (shadows global)

    cout << "Local globalVar: " << globalVar << endl;
    cout << "Actual Global globalVar: " << ::globalVar << endl;

    cout << "\n----------------------\n";

    // 5. Static Variable
    static int count = 0;
    count++;
    cout << "Static count: " << count << endl;

    cout << "\n----------------------\n";

    // 6. Auto Keyword (default)
    auto x = 5;        // int
    auto y = 3.14;     // double

    cout << "Auto x: " << x << endl;
    cout << "Auto y: " << y << endl;

    cout << "\n----------------------\n";

    // 7. Type Casting
    double num = 10.75;
    int newNum = (int)num; // Explicit casting

    cout << "Original: " << num << endl;
    cout << "After casting to int: " << newNum << endl;

    cout << "\n----------------------\n";

    // 8. Multiple Variables
    int m = 1, n = 2, o = 3;
    cout << "m=" << m << ", n=" << n << ", o=" << o << endl;

    cout << "\n----------------------\n";

    // 9. User Input (Dynamic variable value)
    int userAge;
    cout << "Enter your age: ";
    cin >> userAge;

    cout << "You entered: " << userAge << endl;

    cout << "\n----------------------\n";

    // 10. Reference Variable
    int original = 10;
    int &ref = original;

    ref = 20; // changes original

    cout << "Original after reference change: " << original << endl;

    cout << "\n----------------------\n";

    // 11. Size of Variables
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;

    cout << "\n----------------------\n";

    // 12. Scope Example
    {
        int innerVar = 99;
        cout << "Inner variable: " << innerVar << endl;
    }
    // cout << innerVar; // ❌ Error (out of scope)

    return 0;
}