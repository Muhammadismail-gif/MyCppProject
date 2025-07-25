#include <iostream>
using namespace std;

class StepCounter {
private:
    int steps;

public:
    StepCounter() {
        steps = 0;
    }

    // Prefix ++
    StepCounter& operator++() {
        steps += 100;
        return *this;
    }

    // Postfix ++
    StepCounter operator++(int) {
        StepCounter temp = *this;
        steps += 100;
        return temp;
    }

    void display() {
        cout << "Current Steps: " << steps << endl;
    }
};

int main() {
    StepCounter s1;
    s1.display();

    ++s1;
    s1.display();

    s1++;
    s1.display();

    StepCounter s2;
    ++s2;
    s2++;
    s2.display();

    return 0;
}
