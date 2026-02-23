#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class BrowserStack {
private:
    string stack[MAX];
    int top;

public:
    BrowserStack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void visitPage() {
        if (isFull()) {
            cout << "History is full. Cannot visit more pages.\n";
            return;
        }

        string url;
        cout << "Enter Page URL: ";
        cin >> url;

        stack[++top] = url;
        cout << "Page visited successfully.\n";
    }

    void goBack() {
        if (isEmpty()) {
            cout << "No pages to go back.\n";
            return;
        }

        cout << "Going back from: " << stack[top--] << endl;
    }

    void searchPage() {
        if (isEmpty()) {
            cout << "History is empty.\n";
            return;
        }

        string url;
        cout << "Enter URL to search: ";
        cin >> url;

        for (int i = 0; i <= top; i++) {
            if (stack[i] == url) {
                cout << "Page found in history.\n";
                return;
            }
        }

        cout << "Page not found.\n";
    }

    void displayHistory() {
        if (isEmpty()) {
            cout << "No browsing history available.\n";
            return;
        }

        cout << "Browsing History (Latest First):\n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
};

int main() {
    BrowserStack bs;
    int choice;

    do {
        cout << "\n===== Browser Navigation System =====\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Search Page\n";
        cout << "4. Display History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bs.visitPage();
            break;
        case 2:
            bs.goBack();
            break;
        case 3:
            bs.searchPage();
            break;
        case 4:
            bs.displayHistory();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}