#include <iostream>
using namespace std;

int main() {
    cout << "C++ REFERENCE & POINTERS" << endl << endl;

    // 1. C++ REFERENCE
 
    cout << "1. C++ REFERENCE" << endl;
    
    int num = 10;
    int &ref = num;  // Reference declaration - ref is alias for num
    
    cout << "num = " << num << endl;
    cout << "ref = " << ref << endl;
    
    ref = 20;  // Changing ref changes num
    cout << "After ref = 20:" << endl;
    cout << "num = " << num << endl;  // num is also 20!
    cout << endl;

 
    // 2. MEMORY ADDRESS
 
    cout << "2. MEMORY ADDRESS" << endl;
    
    int var = 100;
    cout << "Value: " << var << endl;
    cout << "Address: " << &var << endl;  // & gets memory address
    
    cout << "Reference ref address: " << &ref << endl;
    cout << "(Same as num address!)" << endl << endl;

 
    // 3. C++ POINTERS
 
    cout << "3. C++ POINTERS" << endl;
    
    // Pointer declaration
    int *ptr;           // ptr can store address of int
    ptr = &var;         // & gets address, ptr stores it
    
    cout << "var value: " << var << endl;
    cout << "var address: " << &var << endl;
    cout << "ptr stores: " << ptr << endl;    // Same address
    cout << endl;

 
    // 4. DEREFERENCE (USING POINTER VALUES)
 
    cout << "4. DEREFERENCE (*)" << endl;
    
    cout << "ptr (address): " << ptr << endl;
    cout << "*ptr (value at address): " << *ptr << endl;  // Dereference
    
    *ptr = 500;  // Change value through pointer
    cout << "After *ptr = 500:" << endl;
    cout << "var = " << var << endl;  // var changed!
    cout << endl;

 
    // 5. USING POINTERS IN C++
 
    cout << "5. USING POINTERS" << endl;
    
    int a = 5, b = 10;
    int *p1 = &a, *p2 = &b;
    
    // Swap using pointers
    cout << "Before: a=" << a << ", b=" << b << endl;
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << "After swap: a=" << a << ", b=" << b << endl;
    cout << endl;

 
    // 6. REFERENCE vs POINTER COMPARISON
 
    cout << "6. REFERENCE vs POINTER" << endl;
    
    int x = 50;
    
    // Reference
    int &refX = x;      // Must initialize when declared
    // int &refY;       // ERROR: must initialize
    
    // Pointer
    int *ptrX;          // Can declare without initializing
    ptrX = &x;          // Assign address later
    ptrX = nullptr;     // Can point to nothing
    
    cout << "Reference: always valid, cannot rebind" << endl;
    cout << "Pointer: can be null, can change what it points to" << endl;

    return 0;
}