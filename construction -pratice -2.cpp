#include <iostream>
#include <iomanip>  // For setprecision
using namespace std;

class Product {
private:
    string name;
    string id;
    double price;
    int quantity;
    string category;

public:
    // Default Constructor
    Product() {
        name = "Unknown";
        id = "0000";
        price = 0.0;
        quantity = 0;
        category = "Unknown";
    }

    // Constructor 1: All parameters
    Product(string n, string i, double p, int q, string c) {
        name = n;
        id = i;
        price = p;
        quantity = q;
        category = c;
    }

    // Constructor 2: name, id, price, category (quantity = 0)
    Product(string n, string i, double p, string c) {
        name = n;
        id = i;
        price = p;
        quantity = 0;
        category = c;
    }

    // Constructor 3: name, id, price, quantity (category = "Unknown")
    Product(string n, string i, double p, int q) {
        name = n;
        id = i;
        price = p;
        quantity = q;
        category = "Unknown";
    }

    // Constructor 4: name, price, quantity, category (id = "0000")
    Product(string n, double p, int q, string c) {
        name = n;
        id = "0000";
        price = p;
        quantity = q;
        category = c;
    }

    // Constructor 5: id, price, quantity, category (name = "Unknown")
    Product(string i, double p, int q, string c, bool byId) {
        name = "Unknown";
        id = i;
        price = p;
        quantity = q;
        category = c;
    }

    // Display function
    void display() {
        cout << fixed << setprecision(2); // Format price to 2 decimal places
        cout << "Name     : " << name << endl;
        cout << "ID       : " << id << endl;
        cout << "Price    : $" << price << endl;
        cout << "Quantity : " << quantity << endl;
        cout << "Category : " << category << endl;
        cout << "-------------------------\n";
    }
};

int main() {
    // Creating objects using different constructors
    Product p1;  // Default
    Product p2("Laptop", "LAP123", 799.99, 10, "Electronics");  // All values
    Product p3("iPhone", "IPH456", 999.99, "Electronics");  // Quantity = 0
    Product p4("Notebook", "PRO987", 19.99, 30);  // Category = Unknown
    Product p5("PRO567", 5.99, 50, "Stationery", true);  // Name = Unknown

    // Displaying all products
    cout << "Product 1:\n"; p1.display();
    cout << "Product 2:\n"; p2.display();
    cout << "Product 3:\n"; p3.display();
    cout << "Product 4:\n"; p4.display();
    cout << "Product 5:\n"; p5.display();

    return 0;
}
