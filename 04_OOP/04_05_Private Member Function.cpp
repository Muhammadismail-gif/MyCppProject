#include <iostream>
using namespace std;

class Student {
private:
    int marks;

    // Private Member Function
    void calculateGrade() {
        if (marks >= 80)
            cout << "Grade: A\n";
        else if (marks >= 60)
            cout << "Grade: B\n";
        else
            cout << "Grade: C\n";
    }

public:
    string name;

    void setData(string n, int m) {
        name = n;
        marks = m;
    }

    // Public function to access private function
    void showResult() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;

        // Calling private member function inside class
        calculateGrade();
    }
};

int main() {

    Student s1;

    s1.setData("Ismail", 75);

    // s1.calculateGrade(); ❌ Not allowed (private)

    s1.showResult();

    return 0;
}