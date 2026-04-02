#include <iostream>
using namespace std;

int main() {
    int age, choice;

    cout << "Enter your age: ";
    cin >> age;

    // 1. if statement
    if (age >= 18) {
        cout << "You are eligible to vote.\n";
    }

    // 2. if-else statement
    if (age % 2 == 0) {
        cout << "Your age is even.\n";
    } else {
        cout << "Your age is odd.\n";
    }

    // 3. else-if statement
    if (age < 13) {
        cout << "You are a child.\n";
    } else if (age < 20) {
        cout << "You are a teenager.\n";
    } else if (age < 60) {
        cout << "You are an adult.\n";
    } else {
        cout << "You are a senior citizen.\n";
    }

    // 4. shorthand if-else (ternary operator)
    string result = (age >= 18) ? "Adult" : "Minor";
    cout << "Category: " << result << endl;

    // 5. switch statement
    cout << "\nChoose a room (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "This is Bedroom 1.\n";
            break; // break keyword

        case 2:
            cout << "This is Bedroom 2.\n";
            break;

        case 3:
            cout << "This is Bedroom 3.\n";
            break;

        default: // default keyword
            cout << "Invalid room choice.\n";
    }

    return 0;
}