#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base Class
class Person {
protected: // Accessible by derived classes
    string name;
    int id;
    string address;

public:
    // Constructor
    Person(const string& n, int i, const string& addr) : name(n), id(i), address(addr) {}

    // Virtual function (for Polymorphism)
    virtual void displayDetails() const {
        cout << "  Name: " << name << endl;
        cout << "  ID: " << id << endl;
        cout << "  Address: " << address << endl;
    }

    // Pure Virtual function (makes Person an Abstract Class)
    virtual string getRole() const = 0;

    // Getters (Encapsulation)
    string getName() const { return name; }
    int getId() const { return id; }
};

//Student and Staff Derived Classes (Inheritance)

// Derived Class 1
class Student : public Person {
private:
    string major;
    double gpa;

public:
    // Constructor calls base class constructor
    Student(const string& n, int i, const string& addr, const string& m, double g)
        : Person(n, i, addr), major(m), gpa(g) {}

    // Override base class function (Polymorphism)
    void displayDetails() const override {
        cout << "\n--- Student Details ---" << endl;
        Person::displayDetails(); // Call base class method
        cout << "  Major: " << major << endl;
        cout << "  GPA: " << gpa << endl;
    }

    string getRole() const override {
        return "Student";
    }
};

// Derived Class 2
class Staff : public Person {
private:
    string department;
    string designation;

public:
    // Constructor calls base class constructor
    Staff(const string& n, int i, const string& addr, const string& dept, const string& desig)
        : Person(n, i, addr), department(dept), designation(desig) {}

    // Override base class function (Polymorphism)
    void displayDetails() const override {
        cout << "\n--- Staff Details ---" << endl;
        Person::displayDetails(); // Call base class method
        cout << "  Department: " << department << endl;
        cout << "  Designation: " << designation << endl;
    }

    string getRole() const override {
        return "Staff";
    }
};

   //Course Class (Encapsulation)
   
   // Helper Class
class Course {
private:
    string courseCode;
    string title;
    int credits;

public:
    // Constructor
    Course(const string& code, const string& t, int c)
        : courseCode(code), title(t), credits(c) {}

    void displayCourseInfo() const {
        cout << "Code: " << courseCode << ", Title: " << title << ", Credits: " << credits << endl;
    }

    string getCode() const { return courseCode; }
};

   //main Function (Demonstration)
   
   
   // Main function to demonstrate OOPS principles
int main() {
    cout << "Welcome to the Simple University Management System!" << endl;

    // 1. Create Objects
    Student s1("Alice Smith", 1001, "456 Main St", "Computer Science", 3.8);
    Staff st1("Dr. Bob Johnson", 501, "789 College Ave", "Engineering", "Professor");

    Course c1("CS101", "Intro to Programming", 3);
    Course c2("MATH201", "Calculus II", 4);

    // 2. Demonstration of Inheritance & Encapsulation
    s1.displayDetails();
    st1.displayDetails();
    cout << "\n--- Course Info ---" << endl;
    c1.displayCourseInfo();
    c2.displayCourseInfo();
    
    // 3. Demonstration of Polymorphism (using a vector of base class pointers)
    cout << "\n--- Polymorphism Demonstration ---" << endl;
    vector<Person*> universityMembers;

    // Assign derived class objects to base class pointers
    universityMembers.push_back(&s1);
    universityMembers.push_back(&st1);

    for (const auto& member : universityMembers) {
        // The correct displayDetails() (Student or Staff) is called at runtime
        // because displayDetails() is virtual.
        cout << "Role: " << member->getRole() << endl;
        member->displayDetails();
    }

    cout << "\nSystem Demonstration Complete." << endl;

    return 0;
}
   