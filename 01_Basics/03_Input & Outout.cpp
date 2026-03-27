#include <iostream>
using namespace std;
int main() {
    // 1. OUTPUT
    cout << "Hello, World!" << endl;
    cout << "Welcome to C++ programming." << endl;

    // 2. INPUT
    string name;
    cout << "Enter your Name:";
    cin >> name;   // taking input from user
    cout << "Your Name is:"<< name << endl;

    int age;
    cout << "Enter your age: ";
    cin >> age;  // taking input from user

    cout << "You are " << age << " years old." << endl;

    return 0;
}