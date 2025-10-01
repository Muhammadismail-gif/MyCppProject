#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// ================== User Class ==================
class User {
private:
    string username;
    int score;

public:
    User(string name = "") : username(name), score(0) {}

    void setName(string name) { username = name; }
    string getName() const { return username; }

    void addScore() { score++; }
    int getScore() const { return score; }
};

// ================== Abstract Base Class ==================
class Question {
protected:
    string questionText;
public:
    Question(string q = "") : questionText(q) {}
    virtual void display() = 0;          // pure virtual ? Abstraction
    virtual bool checkAnswer(int ans) = 0;
    virtual ~Question() {}              // Virtual destructor
};

// ================== MCQ Question (Derived) ==================
class MCQQuestion : public Question {
private:
    string options[4];
    int correctOption;

public:
    MCQQuestion(string q = "", string opt[4] = {}, int correct = 1)
        : Question(q), correctOption(correct) {
        for (int i = 0; i < 4; i++) options[i] = opt[i];
    }

    void display() override {    // Polymorphism
        cout << "\n" << questionText << "\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(int ans) override {
        return ans == correctOption;
    }
};

// ================== Quiz Class ==================
class Quiz {
private:
    vector<Question*> questions;  // Composition (Quiz HAS-A Question)

public:
    void loadQuestions(string filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Could not open " << filename << endl;
            exit(1);
        }

        string q, o1, o2, o3, o4;
        int correct;
        while (getline(file, q)) {
            getline(file, o1);
            getline(file, o2);
            getline(file, o3);
            getline(file, o4);
            file >> correct;
            file.ignore();

            string options[4] = {o1, o2, o3, o4};
            questions.push_back(new MCQQuestion(q, options, correct));
        }

        file.close();
    }

    void start(User &user) {
        int answer;
        for (size_t i = 0; i < questions.size(); i++) {
            cout << "\nQuestion " << i + 1 << ":\n";
            questions[i]->display();
            cout << "Your answer (1-4): ";
            cin >> answer;

            if (questions[i]->checkAnswer(answer)) {
                cout << "? Correct!\n";
                user.addScore();
            } else {
                cout << "? Wrong!\n";
            }
        }
    }

    ~Quiz() {
        for (auto q : questions) delete q; // free memory
    }
};

// ================== Quiz System ==================
class QuizSystem {
private:
    User currentUser;
    Quiz quiz;

public:
    void run() {
        string name;
        cout << "Enter your name: ";
        getline(cin, name);
        currentUser.setName(name);

        cout << "Welcome " << currentUser.getName() << "! Let's start the quiz.\n";

        quiz.loadQuestions("questions.txt");
        quiz.start(currentUser);

        cout << "\n===== QUIZ OVER =====\n";
        cout << "Player: " << currentUser.getName()
             << " | Score: " << currentUser.getScore() << endl;
    }
};

// ================== Main Function ==================
int main() {
    QuizSystem system;
    system.run();
    return 0;
}
