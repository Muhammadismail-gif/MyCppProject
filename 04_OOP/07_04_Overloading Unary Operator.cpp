#include <iostream>
using namespace std;
class Distance {
public:
 int feet, inch;
// Constructor to initialize the object's value
 Distance(int f, int i) {
 feet = f;
 inch = i;
 }
// Overloading(-) operator to perform decrement operation of Distance object
 void operator-()
 {
 feet--;
 inch--;
 cout << "\nFeet & Inches(Decrement): " << feet << "'" << inch;
 } };
int main() {
 Distance d1(8, 9);
 // Use (-) unary operator by single operand
 -d1;
 return 0;
}