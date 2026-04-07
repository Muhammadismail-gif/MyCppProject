#include <iostream>
using namespace std;

int main() {

    // 1. Declaration of 3D Array
    int arr[2][2][3];

    // 2. Initialization (separate)
    arr[0][0][0] = 1;
    arr[0][0][1] = 2;
    arr[0][0][2] = 3;

    arr[0][1][0] = 4;
    arr[0][1][1] = 5;
    arr[0][1][2] = 6;

    arr[1][0][0] = 7;
    arr[1][0][1] = 8;
    arr[1][0][2] = 9;

    arr[1][1][0] = 10;
    arr[1][1][1] = 11;
    arr[1][1][2] = 12;

    // 3. Initialization at declaration
    int arr2[2][2][3] = {
        {
            {1,2,3},
            {4,5,6}
        },
        {
            {7,8,9},
            {10,11,12}
        }
    };

    // 4. Initialization using loops
    int arr3[2][2][3];
    int value = 1;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                arr3[i][j][k] = value++;
            }
        }
    }

    // 5. Access elements
    cout << "Access element arr2[1][0][2]: " << arr2[1][0][2] << endl;

    // 6. Change element
    arr2[0][1][1] = 99;
    cout << "After change arr2[0][1][1]: " << arr2[0][1][1] << endl;

    // 7. Loop through 3D array
    cout << "\nAll elements of arr2:\n";
    for(int i = 0; i < 2; i++) {
        cout << "Block " << i << ":\n";
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                cout << arr2[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 8. Size of array
    int totalSize = sizeof(arr2)/sizeof(arr2[0][0][0]);
    cout << "Total elements in arr2: " << totalSize << endl;

    // 9. Arithmetic operation (sum)
    int sum = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                sum += arr2[i][j][k];
            }
        }
    }
    cout << "Sum of elements: " << sum << endl;

    // 10. Searching (Sequential Search)
    int key = 9;
    bool found = false;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(arr2[i][j][k] == key) {
                    cout << "Found " << key << " at [" << i << "][" << j << "][" << k << "]\n";
                    found = true;
                }
            }
        }
    }
    if(!found) cout << "Element not found\n";

    return 0;
}