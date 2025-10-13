#include <iostream>
using namespace std;

// Step 3: Swap function using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main function
int main() {
    // Step 1: Declare and initialize two integers
    int x = 10;
    int y = 20;

    // Step 2: Declare pointers to the variables
    int* ptr1 = &x;
    int* ptr2 = &y;

    // Display before swapping
    cout << "--- Before Swapping ---" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Step 4: Call swap function
    swap(ptr1, ptr2);

    // Display after swapping
    cout << "--- After Swapping ---" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
