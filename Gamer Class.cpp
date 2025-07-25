#include <iostream>
using namespace std;

class Gamer {
private:
    string username;
    int level;
    float accuracy;

public:
    void setData(string u, int l, float a) {
        username = u;
        level = l;
        accuracy = a;
    }

    void display() {
        cout << "Player: " << username 
             << " | Level: " << level 
             << " | Accuracy: " << accuracy << "%" << endl;
    }
};

int main() {
    Gamer g1;
    g1.setData("ShadowHunter", 12, 87.5);
    g1.display();

    return 0;
}
