#include <iostream>
using namespace std;

class AreaCalculator {
public:
    // Area of a square (s^2)
    float area(float side) {
        return side * side;
    }

    // Area of a rectangle (l × w)
    float area(float length, float width) {
        return length * width;
    }

    // Area of a trapezium ((a + b)/2 × h)
    float area(float base1, float base2, float height) {
        return (base1 + base2) / 2 * height;
    }

    // Function to calculate and display all areas
    void displayAllAreas(float squareSide, float rectLength, float rectWidth, 
                        float trapBase1, float trapBase2, float trapHeight) {
        cout << "Area of square: " << area(squareSide) << endl;
        cout << "Area of rectangle: " << area(rectLength, rectWidth) << endl;
        cout << "Area of trapezium: " << area(trapBase1, trapBase2, trapHeight) << endl;
    }
};

int main() {
    AreaCalculator calculator;
    
    // Example usage
    calculator.displayAllAreas(5.0, 4.0, 6.0, 3.0, 5.0, 4.0);
    
    return 0;
}

