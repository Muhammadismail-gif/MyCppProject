#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;
    string grade;

    void calculateGrade() {
        if (marks >= 80)
            grade = "A";
        else if (marks >= 70)
            grade = "B";
        else if (marks >= 60)
            grade = "C";
        else if (marks >= 50)
            grade = "D";
        else
            grade = "Fail";
    }

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks (0-100): ";
        cin >> marks;
        calculateGrade();
    }

    void display() {
        cout << roll << "\t" << name << "\t" << marks << "\t" << grade << endl;
    }
};

vector<Student> students;

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Record Added Successfully" << endl;
}

void viewStudents() {
    cout << "\nRoll\tName\tMarks\tGrade" << endl;
    for (auto &s : students)
        s.display();
}

void searchStudent() {
    int r;
    cout << "Enter Roll Number: ";
    cin >> r;

    for (auto &s : students) {
        if (s.roll == r) {
            s.display();
            return;
        }
    }
    cout << "Student Not Found" << endl;
}

void updateStudent() {
    int r;
    cout << "Enter Roll Number to Update: ";
    cin >> r;

    for (auto &s : students) {
        if (s.roll == r) {
            cout << "Update Student Data:" << endl;
            s.input();
            cout << "Updated Successfully" << endl;
            return;
        }
    }
    cout << "Record Not Found" << endl;
}

void deleteStudent() {
    int r;
    cout << "Enter Roll Number to Delete: ";
    cin >> r;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].roll == r) {
            students.erase(students.begin() + i);
            cout << "Record Deleted Successfully" << endl;
            return;
        }
    }
    cout << "Record Not Found" << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Add Student";
        cout << "\n2. View Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateStudent(); break;
        case 5: deleteStudent(); break;
        case 6: return 0;
        default: cout << "Invalid Choice" << endl;
        }
    }
}
