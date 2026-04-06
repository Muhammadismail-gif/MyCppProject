#include <iostream>
using namespace std;

int main() {

    // 1. Initializing a 2D Array (separate)
    int arr[2][3];
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;

    // 2. Initializing at the time of Declaration
    int arr2[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    // 3. Initializing a 2D Array with loops
    int arr3[2][3];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            arr3[i][j] = i + j; // example values
        }
    }

    // 4. Access the Elements of a 2D Array
    cout << "Access elements:\n";
    cout << arr2[0][1] << endl; // 20
    cout << arr2[1][2] << endl; // 60

    // 5. Change Elements in a 2D Array
    arr2[0][0] = 99;
    cout << "After change: " << arr2[0][0] << endl;

    // 6. Loop through a 2D Array
    cout << "\n2D Array elements:\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}