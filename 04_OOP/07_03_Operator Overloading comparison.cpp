#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v) {
        value = v;
    }

    // Friend operator functions
    friend bool operator == (Number n1, Number n2);
    friend bool operator <  (Number n1, Number n2);
    friend bool operator >  (Number n1, Number n2);
};

// Equality
bool operator == (Number n1, Number n2) {
    return (n1.value == n2.value);
}

// Less than
bool operator < (Number n1, Number n2) {
    return (n1.value < n2.value);
}

// Greater than
bool operator > (Number n1, Number n2) {
    return (n1.value > n2.value);
}

int main() {
    Number a(5), b(10);

    if (a == b)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    if (a < b)
        cout << "A is smaller" << endl;

    if (a > b)
        cout << "A is greater" << endl;

    return 0;
}