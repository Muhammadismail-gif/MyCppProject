#include <iostream>
#include <string>
using namespace std;

// Base class: Book
class Book {
protected:
    string title;
    string author;

public:
    void setDetails(string t, string a) {
        title = t;
        author = a;
    }

    virtual void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

// Derived class: LibraryBook
class LibraryBook : public Book {
private:
    int libraryID;

public:
    void setLibraryID(int id) {
        libraryID = id;
    }

    // Override display method
    void display() override {
        // Call base class display
        Book::display();
        cout << "Library ID: " << libraryID << endl;
    }
};

// Main function
int main() {
    LibraryBook myBook;

    // Set details
    myBook.setDetails("C++ Programming", "Bjarne Stroustrup");
    myBook.setLibraryID(101);

    // Display book information
    myBook.display();

    return 0;
}
