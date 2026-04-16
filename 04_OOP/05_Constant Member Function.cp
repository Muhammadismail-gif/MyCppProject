#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    string name;

    // Setter function (normal member function)
    void setData(string n, int m) {
        name = n;
        marks = m;
    }

    // Constant Member Function
    void getData() const {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;

        // marks = 90; ❌ Not allowed (cannot modify in const function)
    }
};

int main() {

    Student s1;

    s1.setData("Ismail", 85);

    // Calling constant member function
    s1.getData();

    return 0;
}