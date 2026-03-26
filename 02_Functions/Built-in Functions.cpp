#include <iostream>
#include <cmath>      // for math functions
#include <algorithm>  // for sort, max, min
#include <string>     // for string functions
using namespace std;

int main() {
    
    // ===== 1. STRING BUILT-IN FUNCTIONS =====
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Length of your name: " << name.length() << endl;
    cout << "First character: " << name.at(0) << endl;

    // ===== 2. MATH BUILT-IN FUNCTIONS =====
    double num;
    cout << "\nEnter a number: ";
    cin >> num;

    cout << "Square root: " << sqrt(num) << endl;
    cout << "Power (num^2): " << pow(num, 2) << endl;
    cout << "Ceil value: " << ceil(num) << endl;
    cout << "Floor value: " << floor(num) << endl;

    // ===== 3. ARRAY + ALGORITHM FUNCTIONS =====
    int arr[5];
    cout << "\nEnter 5 numbers:\n";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // Sorting array
    sort(arr, arr + 5);

    cout << "Sorted array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Finding max and min
    cout << "Maximum: " << *max_element(arr, arr + 5) << endl;
    cout << "Minimum: " << *min_element(arr, arr + 5) << endl;

    // ===== 4. CHARACTER FUNCTIONS =====
    char ch;
    cout << "\nEnter a character: ";
    cin >> ch;

    if(isalpha(ch)) {
        cout << "It is an alphabet." << endl;
    }
    if(isdigit(ch)) {
        cout << "It is a digit." << endl;
    }

    // ===== 5. TYPE CONVERSION FUNCTIONS =====
    int number = 100;
    double converted = static_cast<double>(number);

    cout << "\nConverted int to double: " << converted << endl;

    return 0;
}