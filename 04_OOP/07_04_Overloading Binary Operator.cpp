#include <iostream>
using namespace std;
class Distance { //represents distances in feet and inches
public:
 int feet, inch;
// Default constructor initializes the object’s variables (feet and inch) to 0
 Distance() : feet(0), inch(0)
 {}
 // Parametrized constructor initializes the object’s variables to provided 
value
 Distance(int f, int i) : feet(f), inch(i)
 {}
// Overloading (+) operator to perform addition of two distance objects 
i.e. d1 (current object, this) and d2 (as a reference)
 Distance operator+(Distance& d2) {
 // Create an object to return
 Distance d3;
 d3.feet = feet + d2.feet;
 d3.inch =inch + d2.inch;
 return d3; // Return the resulting object
 } }

 int main() {
 Distance d1(8, 9); //using the parameterized constructor
 Distance d2(10, 2); //using the parameterized constructor
 Distance d3; //using the default constructor
 // call or use overloaded “+” operator function
 d3 = d1 + d2;
 cout << "Total Feet & Inches: " << d3.feet << " ‘ " << d3.inch;
 return 0;
}