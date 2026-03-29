#include <iostream>
using namespace std;
int main() {
 // Integer data type
 int integerVar = 42;
 std::cout << "Integer Variable: " << integerVar << 
std::endl;
 // Floating-point data type
 float floatVar = 3.14f;
 std::cout << "Float Variable: " << floatVar << 
std::endl;
 // Double precision floating-point data type
 double doubleVar = 2.71828;
 std::cout << "Double Variable: " << doubleVar << 
std::endl;
// Character data type
 char charVar = 'A';
 std::cout << "Character Variable: " << charVar << 
std::endl;
 // Boolean data type
 bool boolVar = true;
 std::cout << "Boolean Variable: " << std::boolalpha 
<< boolVar << std::endl;
 // Changing the value of a variable
 integerVar = 50;
 std::cout << "Updated Integer Variable: " << 
integerVar << std::endl;

// Bool Data Type
bool myBool = true;
// Without boolalpha
 std::cout << "Without boolalpha: " << myBool << std::endl;
// With boolalpha
 std::cout << std::boolalpha << "With boolalpha: " << myBool << std::endl;
 // Reset to default behavior
 std::cout << std::noboolalpha << "Back to default: " << myBool << std::endl;

 // character data Type
 char letter;
letter = 'X';
cout << letter << endl;
letter = 'Y';
cout << letter <<endl;

char letter1;
letter = 66; //66 is the ASCII code for the character B
cout << letter1 << endl;
letter1 = 67;//67 is the ASCII code for the character C
cout << letter1 <<endl;

 return 0;}