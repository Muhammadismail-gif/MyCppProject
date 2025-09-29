#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int ID;
    float GPA;

public:
    // Setter methods
    void setName(string newName) {
        name = newName;
    }
    void setID(int newID) {
        ID = newID;
    }
    void setGPA(float newGPA) {
        GPA = newGPA;
    }
    // Getter methods
    string getName() {
        return name;
    }
    int getID() {
        return ID;
    }
    float getGPA() {
        return GPA;
    }
};

      int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;
    Student students[n];  // Array of Student objects

    // Input student data
    for (int i = 0; i < n; i++) {
        string name;
        int id;
        float gpa;

        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();  // To clear the newline character from previous input
        getline(cin, name);

        cout << "ID: ";
        cin >> id;

        cout << "GPA: ";
        cin >> gpa;

        students[i].setName(name);
        students[i].setID(id);
        students[i].setGPA(gpa);
    }

    // Display student data
    cout << "\n--- Student Information ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: " << students[i].getName() << "\n";
        cout << "ID: " << students[i].getID() << "\n";
        cout << "GPA: " << students[i].getGPA() << "\n\n";
    }

    return 0;
}
