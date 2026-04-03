#include <iostream>
using namespace std;

int main() {

    // 1. while loop
    cout << "While Loop:\n";
    int i = 1;

    while (i <= 3) {
        cout << "Feeding cow " << i << endl;
        i++; // increment
    }

    // 2. do-while loop
    cout << "\nDo-While Loop:\n";
    int j = 1;

    do {
        cout << "Giving water to cow " << j << endl;
        j++;
    } while (j <= 3);

    // 3. for loop
    cout << "\nFor Loop:\n";

    for (int k = 1; k <= 3; k++) {
        cout << "Cleaning room " << k << endl;
    }

    return 0;
}