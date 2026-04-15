#include <iostream>
#include <string>
using namespace std;

// COMPLETE CLASS DEMONSTRATION
class Student {
// 1. ACCESS SPECIFIERS
private:    // Information hiding
    int id;
    float gpa;
    
protected:  // Inheritance access
    string major;
    
public:     // Public interface
    string name;
    static int totalStudents;  // Class variable
    
    // 2. CONSTRUCTOR
    Student(string n, int i, float g, string m) 
        : name(n), id(i), gpa(g), major(m) {
        totalStudents++;
        cout << "Object created: " << name << " (Total: " << totalStudents << ")\n";
    }
    
    // 3. DESTRUCTOR
    ~Student() {
        totalStudents--;
        cout << "Object destroyed: " << name << " (Remaining: " << totalStudents << ")\n";
    }
    
    // 4. MEMBER FUNCTIONS
    void study(int hours) {  // Modifier
        gpa += hours * 0.01;
        if (gpa > 4.0) gpa = 4.0;
    }
    
    float getGPA() const {   // Accessor (const)
        return gpa;
    }
    
    void display() const {   // Const method
        cout << "[" << this << "] " << id << ": " << name 
             << " (" << major << ") GPA: " << gpa << "\n";
    }
    
    // 5. STATIC METHOD
    static void showCount() {
        cout << "Total students: " << totalStudents << "\n";
    }
};

// Initialize static member
int Student::totalStudents = 0;

int main() {
    cout << "╔═══════════════════════════════════════╗\n";
    cout << "║     C++ OBJECT & CLASS COMPLETE       ║\n";
    cout << "╚═══════════════════════════════════════╝\n\n";
    
    // Creating objects
    Student s1("Alice", 1001, 3.5, "Computer Science");
    Student s2("Bob", 1002, 3.2, "Mathematics");
    
    cout << "\n--- Object States ---\n";
    s1.display();
    s2.display();
    
    cout << "\n--- Message Passing (Method Calls) ---\n";
    s1.study(10);  // Sending message to object s1
    s2.study(5);   // Sending message to object s2
    
    cout << s1.name << "'s new GPA: " << s1.getGPA() << "\n";
    cout << s2.name << "'s new GPA: " << s2.getGPA() << "\n";
    
    cout << "\n--- Static Member Access ---\n";
    Student::showCount();
    
    cout << "\n--- Objects Going Out of Scope ---\n";
    return 0;  // Destructors called automatically
}