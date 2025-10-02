#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the class with private data members
class Book {
private:
    string title;
    string author;
    float price;

public:
    // Step 2: Setter methods
    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setPrice(float p) {
        price = p;
    }

    // Step 3: Getter methods
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    float getPrice() {
        return price;
    }
};

// Step 4: Main function to demonstrate usage
int main() {
    // Create object of Book
    Book myBook;

    // Set values using setters
    myBook.setTitle("C++ Programming");
    myBook.setAuthor("Bjarne Stroustrup");
    myBook.setPrice(1499.99);

    // Get and display values using getters
    cout << "--- Book Details ---" << endl;
    cout << "Title: " << myBook.getTitle() << endl;
    cout << "Author: " << myBook.getAuthor() << endl;
    cout << "Price: $" << myBook.getPrice() << endl;

    return 0;
}
