#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;

public:
    void setDetails(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class: Teacher
class Teacher : public Person {
private:
    string subject;

public:
    void setSubject(string s) {
        subject = s;
    }

    void role() {
        cout << "Role: Teacher" << endl;
        cout << "Subject: " << subject << endl;
    }
};

// Derived class: Student
class Student : public Person {
private:
    string grade;

public:
    void setGrade(string g) {
        grade = g;
    }

    void role() {
        cout << "Role: Student" << endl;
        cout << "Grade: " << grade << endl;
    }
};

// Main function
int main() {
    // Create and set details for Teacher
    Teacher t;
    t.setDetails("Mr. Ahmed", 35);
    t.setSubject("Mathematics");
    t.display();
    t.role();

    cout << endl;

    // Create and set details for Student
    Student s;
    s.setDetails("Ali", 17);
    s.setGrade("A+");
    s.display();
    s.role();

    return 0;
}
