#include <iostream>
using namespace std;

// Class with Member Functions
class Student {

private:
    int marks; // private member

protected:
    int rollNo; // protected member

public:
    string name;

    // 1. Member Function Declaration
    void setData(string n, int m, int r);
    void getData();

    // 2. Member Function Overloading
    void display() {
        cout << "Simple Display Function\n";
    }

    void display(string msg) {
        cout << "Message: " << msg << endl;
    }

    // 3. Member Function with Default Argument
    void show(int x = 100) {
        cout << "Value: " << x << endl;
    }
};

// 4. Member Function Definition (outside class)
void Student::setData(string n, int m, int r) {
    name = n;
    marks = m;
    rollNo = r;
}

void Student::getData() {
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks << endl;
    cout << "Roll No: " << rollNo << endl;
}

int main() {

    Student s1;

    // Accessing public member functions
    s1.setData("Ismail", 85, 101);
    s1.getData();

    // Function Overloading
    s1.display();
    s1.display("Hello Overloading");

    // Default Argument
    s1.show();
    s1.show(500);

    return 0;
}