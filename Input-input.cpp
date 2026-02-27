#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string name;
    int age;
    double gpa;

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter GPA: ";
    cin >> gpa;

    cout << "\n----- Student Information -----" << endl;
    cout << "Name : " << name << endl;
    cout << "Age  : " << age << endl;
    cout << "GPA  : " << gpa << endl;

    return 0;
}