#include <iostream>
using namespace std;

int main() {

    // 1. Array Declaration
    int arr[5];

    // 2. Declaration of Multiple Arrays
    int marks[5], ages[5];

    // 3. Array Initialization
    int numbers[5] = {10, 20, 30, 40, 50};

    // 4. Access the Elements of an Array
    cout << "First element: " << numbers[0] << endl;
    cout << "Third element: " << numbers[2] << endl;

    // 5. Change an Array Element
    numbers[1] = 25;

    cout << "After change: " << numbers[1] << endl;

    // 6. Accessing Array Elements using loops
    cout << "\nArray elements using loop:\n";
    for(int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }

    // 7. Input and Output values of an Array
    cout << "\n\nEnter 5 values:\n";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "You entered:\n";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}