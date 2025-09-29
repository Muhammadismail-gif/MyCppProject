#include <iostream>
using namespace std;

class Book {
private:
    string ISBN;
    string title;
    string author;
    string genre;

public:
    // Default Constructor
    Book() {
        ISBN = "N/A";
        title = "N/A";
        author = "N/A";
        genre = "N/A";
    }
    // Parameterized Constructor
    Book(string isbn, string t, string a, string g) {
        ISBN = isbn;
        title = t;
        author = a;
        genre = g;
    }
    // Display Function
    void display() {
        cout << "\nBook Information:\n";
        cout << "ISBN   : " << ISBN << endl;
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Genre  : " << genre << endl;
    }

    // Update Function
    void update() {
        cout << "\nUpdate Book Information:\n";
        cout << "Enter new ISBN: ";
        cin.ignore(); // Clear previous newline
        getline(cin, ISBN);
        cout << "Enter new Title: ";
        getline(cin, title);
        cout << "Enter new Author: ";
        getline(cin, author);
        cout << "Enter new Genre: ";
        getline(cin, genre);
        cout << "Book updated successfully!\n";
    }
};

int main() {
    int n;
    cout << "Enter number of books to add: ";
    cin >> n;

    Book books[n];  // Array of Book objects

    // Input book data using parameterized constructor
    for (int i = 0; i < n; i++) {
        string isbn, title, author, genre;

        cout << "\nEnter details for Book " << i + 1 << ":\n";
        cin.ignore(); // Clear buffer before getline
        cout << "ISBN: ";
        getline(cin, isbn);
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Genre: ";
        getline(cin, genre);

        books[i] = Book(isbn, title, author, genre);  // Using parameterized constructor
    }

    // Display all books
    cout << "\n--- Library Book List ---";
    for (int i = 0; i < n; i++) {
        books[i].display();
    }

    // Optionally update a book
    char choice;
    cout << "\nDo you want to update any book? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int index;
        cout << "Enter book number to update (1 to " << n << "): ";
        cin >> index;

        if (index >= 1 && index <= n) {
            books[index - 1].update();
            books[index - 1].display();
        } else {
            cout << "Invalid book number!\n";
        }
    }

    return 0;
}
