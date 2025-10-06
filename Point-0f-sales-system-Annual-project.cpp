#include <iostream>
#include <string>
using namespace std;

// Structure to hold product details
struct Product {
    string name;
    float price;
    int quantity;
};

// Global variables
const int MAX_PRODUCTS = 100;
Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function prototypes
bool adminLogin();
void displayMenu();
void addProduct();
void viewProducts();
void processSale();
void exitSystem();

int main() {
    if (!adminLogin()) {
        cout << "Access Denied! Exiting System...\n";
        return 0;
    }

    while (true) {
        displayMenu();
    }

    return 0;
}

// Admin Login Function
bool adminLogin() {
    string username, password;
    const string correctUsername = "admin";
    const string correctPassword = "12345";
    int attempts = 3;

    while (attempts > 0) {
        cout << "\n=== Admin Login ===\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        if (username == correctUsername && password == correctPassword) {
            cout << "Login Successful!\n";
            return true;
        } else {
            attempts--;
            cout << "Incorrect Credentials! Attempts Remaining: " << attempts << "\n";
        }
    }

    return false;
}

// Display Menu
void displayMenu() {
    int choice;
    cout << "\n=== Point of Sale System ===\n";
    cout << "1. Add Product\n";
    cout << "2. View Products\n";
    cout << "3. Process Sale\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            viewProducts();
            break;
        case 3:
            processSale();
            break;
        case 0:
            exitSystem();
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
    }
}

// Add Product Function
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Inventory Full! Cannot add more products.\n";
        return;
    }

    cout << "\n=== Add Product ===\n";
    cout << "Enter Product Name: ";
    cin >> inventory[productCount].name;
    cout << "Enter Product Price: ";
    cin >> inventory[productCount].price;
    cout << "Enter Product Quantity: ";
    cin >> inventory[productCount].quantity;

    productCount++;
    cout << "Product Added Successfully!\n";
}

// View Products Function
void viewProducts() {
    if (productCount == 0) {
        cout << "No products available in inventory.\n";
        return;
    }

    cout << "\n=== Product List ===\n";
    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << i + 1
             << " | Name: " << inventory[i].name
             << " | Price: $" << inventory[i].price
             << " | Quantity: " << inventory[i].quantity << "\n";
    }
}

// Process Sale Function
void processSale() {
    if (productCount == 0) {
        cout << "No products available for sale.\n";
        return;
    }

    int productID, quantity;
    cout << "\n=== Process Sale ===\n";
    viewProducts();
    cout << "Enter Product ID to Purchase: ";
    cin >> productID;

    if (productID < 1 || productID > productCount) {
        cout << "Invalid Product ID!\n";
        return;
    }

    cout << "Enter Quantity: ";
    cin >> quantity;

    if (quantity > inventory[productID - 1].quantity) {
        cout << "Not enough stock available!\n";
        return;
    }

    float totalCost = inventory[productID - 1].price * quantity;
    inventory[productID - 1].quantity -= quantity;
    cout << "Total Cost: $" << totalCost << "\n";
    cout << "Sale Successful!\n";
}

// Exit System Function
void exitSystem() {
    cout << "Exiting the system. Thank you for using POS System!\n";
    exit(0);
}
