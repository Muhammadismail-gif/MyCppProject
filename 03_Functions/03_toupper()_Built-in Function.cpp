#include <cctype> 
#include <iostream> 
using namespace std; 
int main() { 
 char x = 'e';
 char y = toupper(x);
 cout << "Lowercase character: " << x << endl;
 cout << "Uppercase conversion: " << y << endl;
return 0; 
}