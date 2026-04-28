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

    // Operator Overloading
    Number operator + (Number obj) {
        Number temp(0);
        temp.value = value + obj.value;
        return temp;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n1(5), n2(3);

    Number n3 = n1 + n2; // calling overloaded operator

    n3.display();

    return 0;
}