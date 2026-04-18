#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    string name;

    // Inline Member Function (defined inside class)
    void setData(string n, int m) {
        name = n;
        marks = m;
    }

    // Inline Member Function (get data)
    void getData() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    // Inline Member Function (simple calculation)
    int add(int a, int b) {
        return a + b;
    }
};

int main() {

    Student s1;

    s1.setData("Ismail", 90);
    s1.getData();

    int result = s1.add(5, 3);
    cout << "Addition: " << result << endl;

    return 0;
}