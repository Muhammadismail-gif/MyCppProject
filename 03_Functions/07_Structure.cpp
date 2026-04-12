#include <iostream>
using namespace std;

 
// 1. CREATE/DEFINE A STRUCTURE
// Basic structure definition
struct Student {
    string name;
    int age;
    float marks;
};

 
// 2. NAMED STRUCTURE (TAG)
 

// Using typedef for cleaner syntax
typedef struct {
    string brand;
    int year;
    double price;
} Car;  // 'Car' is now the type name

 
// 3. C++ UNION
 
// Union shares same memory for all members
union Data {
    int i;
    float f;
    char str[20];
};

 
// 4. C++ ENUMERATION
 

// Basic enum declaration
enum Color {
    RED,    // 0
    GREEN,  // 1
    BLUE    // 2
};

// Enum with custom values
enum Status {
    PENDING = 100,
    APPROVED = 200,
    REJECTED = 300
};

// C++11 enum class (type-safe)
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};
 
// MAIN FUNCTION

int main() {
    cout << "=== C++ STRUCTURES ===" << endl << endl;

    // --- Create Structure Variable ---
    cout << "1. CREATE & ACCESS STRUCTURE" << endl;
    Student s1;  // Create variable
    s1.name = "Alice";
    s1.age = 20;
    s1.marks = 85.5;
    
    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Marks: " << s1.marks << endl << endl;

    // --- Multiple Variables ---
    cout << "2. ONE STRUCTURE, MULTIPLE VARIABLES" << endl;
    Student s2, s3;  // Multiple variables of same structure
    s2.name = "Bob"; s2.age = 21; s2.marks = 90.0;
    s3.name = "Carol"; s3.age = 19; s3.marks = 78.5;
    
    cout << "Student 2: " << s2.name << ", " << s2.age << endl;
    cout << "Student 3: " << s3.name << ", " << s3.age << endl << endl;

    // --- Named Structure (typedef) ---
    cout << "3. NAMED STRUCTURE (TAG)" << endl;
    Car c1;  // No need to write 'struct'
    c1.brand = "Toyota";
    c1.year = 2023;
    c1.price = 25000.50;
    
    cout << "Car: " << c1.brand << " " << c1.year << " $" << c1.price << endl << endl;

    // --- Union ---
    cout << "4. C++ UNION" << endl;
    Data data;
    
    data.i = 10;
    cout << "Integer: " << data.i << endl;
    
    data.f = 220.5;
    cout << "Float: " << data.f << endl;
    cout << "Integer (corrupted): " << data.i << endl;  // Value corrupted!
    
    cout << "Size of union: " << sizeof(data) << " bytes" << endl;
    cout << "(Union size = size of largest member)" << endl << endl;

    // --- Enumeration ---
    cout << "5. C++ ENUMERATION" << endl;
    
    Color myColor = RED;
    cout << "Color RED value: " << myColor << endl;
    
    myColor = GREEN;
    cout << "Color GREEN value: " << myColor << endl;
    
    Status myStatus = APPROVED;
    cout << "Status APPROVED value: " << myStatus << endl << endl;

    // Enum class (type-safe)
    Direction dir = Direction::NORTH;
    cout << "Direction NORTH (enum class)" << endl << endl;

    // --- Why Use Enum? ---
    cout << "6. WHY USE ENUM?" << endl;
    cout << "Without enum:" << endl;
    const int SUNDAY = 0;
    const int MONDAY = 1;
    // Easy to make mistakes, not type-safe
    
    cout << "With enum:" << endl;
    enum Weekday { DAY_SUNDAY, DAY_MONDAY, DAY_TUESDAY };
    Weekday today = DAY_MONDAY;
    cout << "Today is: " << today << endl;
    
    cout << "\nBenefits of Enum:" << endl;
    cout << "+ Readable code (names instead of numbers)" << endl;
    cout << "+ Type safety (compiler checks valid values)" << endl;
    cout << "+ Easy maintenance (change values in one place)" << endl;
    cout << "+ Auto-incrementing values" << endl;

    return 0;
}