#include <iostream>
using namespace std;

// Helper function
int add(int a, int b) {
    return a + b;
}

// Main function using helper
void showResult() {
    int result = add(5, 3); // calling helper function
    cout << "Sum is: " << result << endl;
}

int main() {
    showResult();
    return 0;
}