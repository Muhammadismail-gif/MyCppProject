#include <iostream>
using namespace std;

class Movie {
private:
    string title;
    string director;
    float duration;

public:
    // Constructor with title only
    Movie(string t) {
        title = t;
        director = "Unknown";
        duration = 0;
    }

    // Constructor with title and director
    Movie(string t, string d) {
        title = t;
        director = d;
        duration = 0;
    }

    // Constructor with title, director, and duration
    Movie(string t, string d, float dur) {
        title = t;
        director = d;
        duration = dur;
    }

    void display() {
        cout << "Title: " << title 
             << " | Director: " << director 
             << " | Duration: " << duration << " hrs" << endl;
    }
};

int main() {
    Movie m1("Inception", "Christopher Nolan", 2.5);
    Movie m2("Titanic", "James Cameron");
    Movie m3("Interstellar");

    m1.display();
    m2.display();
    m3.display();

    return 0;
}
