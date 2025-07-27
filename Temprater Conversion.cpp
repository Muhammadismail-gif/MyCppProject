#include <iostream>
using namespace std;

int main() {
    double temp;
    char scale;

    cout << "Enter temperature: ";
    cin >> temp;
    cout << "Enter scale (C for Celsius, F for Fahrenheit): ";
    cin >> scale;

    if (scale == 'C' || scale == 'c') {
        cout << "Temperature in Fahrenheit: " << (temp * 9 / 5) + 32 << endl;
    } else if (scale == 'F' || scale == 'f') {
        cout << "Temperature in Celsius: " << (temp - 32) * 5 / 9 << endl;
    } else {
        cout << "Invalid scale!" << endl;
    }

    return 0;
}