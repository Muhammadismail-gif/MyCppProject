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

    // Another Private Function (Nested Call)
    void checkPass() {
        if (marks >= 50)
            cout << "Status: Pass\n";
        else
            cout << "Status: Fail\n";
    }

public:
    string name;

    void setData(string n, int m) {
        name = n;
        marks = m;
    }

    // Public Function calling private functions (Nesting)
    void showResult() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;

        // Nesting of Member Functions
        calculateGrade();
        checkPass();
    }
};

int main() {

    Student s1;

    s1.setData("Ismail", 72);

    s1.showResult();

    return 0;
}