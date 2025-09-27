#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool isAvailable;

public:
    void addBook(string t, string a) {
        title = t;
        author = a;
        isAvailable = true;
    }

          // Display book information
    void displayBookInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
    }

         // Check if book is available
    void checkAvailability() {
        if (isAvailable){
		
            cout << "The book is available." << endl;
       }else {
	   
	   
            cout << "The book is not available." << endl;
}
}
};

int main() {
    Book book1;
    
    // Librarian adds a new book
    book1.addBook("Introduction to C++ Programming", "Bjarne Stroustrup");
    
        // Display book information
    book1.displayBookInfo();
      // Check availability
    book1.checkAvailability();

    return 0;
}
