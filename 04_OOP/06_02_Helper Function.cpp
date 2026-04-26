#include <iostream>
using namespace std;

class Calculator {
private:
    // Helper function (only used inside class)
    int add(int a, int b) {
        return a + b;
    }

public:
    // Main function
    void showSum() {
        int result = add(5, 3); // calling helper function
        cout << "Sum is: " << result << endl;
    }
};

int main() {
    Calculator obj;

    obj.showSum(); // Allowed
    // obj.add(5,3); Not allowed (private)

    return 0;
}