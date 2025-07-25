#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << "%" << endl;
    }
};

int main() {
    Student s1;
    s1.rollNo = 101;
    s1.name = "Ali";
    s1.marks = 87.5;

    s1.display();
    return 0;
}
