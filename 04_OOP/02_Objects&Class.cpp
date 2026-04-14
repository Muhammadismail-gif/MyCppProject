#include <iostream>
#include <vector>
using namespace std;

// Forward declaration
class Department;

class Employee {
    string name;
    Department* dept;  // Association: Employee knows Department
    
public:
    Employee(string n) : name(n), dept(nullptr) {}
    
    void assignTo(Department* d);  // Will define after Department
    
    void show() {
        cout << "Employee: " << name;
        if (dept) cout << " in Department";
        cout << "\n";
    }
};

class Department {
    string name;
    vector<Employee*> employees;  // Aggregation: Department has Employees
    
public:
    Department(string n) : name(n) {}
    
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }
    
    void showEmployees() {
        cout << "Department " << name << " has " 
             << employees.size() << " employees\n";
    }
};

void Employee::assignTo(Department* d) {
    dept = d;
    d->addEmployee(this);
}

// Composition: Car HAS-A Engine (strong ownership)
class Engine {
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {}
    void start() { cout << "Engine (" << horsepower << " HP) started\n"; }
};

class Car {
    Engine engine;  // Composition: Engine is part of Car
    string model;
    
public:
    Car(string m, int hp) : model(m), engine(hp) {}
    
    void start() {
        cout << "Starting " << model << "...\n";
        engine.start();
    }
};

int main() {
    cout << "=== Object Relationships ===\n\n";
    
    // Association & Aggregation
    cout << "--- Association & Aggregation ---\n";
    Employee e1("Alice"), e2("Bob");
    Department sales("Sales");
    
    e1.assignTo(&sales);
    e2.assignTo(&sales);
    
    e1.show();
    e2.show();
    sales.showEmployees();
    
    // Composition
    cout << "\n--- Composition ---\n";
    Car myCar("Tesla Model 3", 450);
    myCar.start();
    // Engine destroyed when Car is destroyed
    
    return 0;
}