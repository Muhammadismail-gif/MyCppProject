#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Car {
public:
    int id;
    string brand;
    string model;
    double price;
    string status; // e.g., "Available" or "Sold"

    void input() {
        cout << "Enter Car ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Brand: ";
        getline(cin, brand);
        cout << "Enter Model: ";
        getline(cin, model);
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
        cout << "Enter Status (Available/Sold): ";
        getline(cin, status);
    }

    void display() const {
        cout << "----------------------------------\n";
        cout << "Car ID: " << id << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: $" << price << endl;
        cout << "Status: " << status << endl;
    }
};

void saveToFile(const vector<Car>& cars) {
    ofstream file("cars.txt");
    for (const auto& car : cars) {
        file << car.id << "," << car.brand << "," << car.model << ","
             << car.price << "," << car.status << "\n";
    }
    file.close();
}

vector<Car> loadFromFile() {
    vector<Car> cars;
    ifstream file("cars.txt");
    string line;
    while (getline(file, line)) {
        Car c;
        sscanf(line.c_str(), "%d,%[^,],%[^,],%lf,%[^,]", &c.id, &c.brand[0], &c.model[0], &c.price, &c.status[0]);
        cars.push_back(c);
    }
    return cars;
}

int main() {
    vector<Car> cars;
    int choice;

    do {
        cout << "\n=== Car Management System ===\n";
        cout << "1. Add Car\n";
        cout << "2. View Cars\n";
        cout << "3. Search Car\n";
        cout << "4. Delete Car\n";
        cout << "5. Save & Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Car c;
            c.input();
            cars.push_back(c);
            cout << "Car added successfully!\n";
        } 
        else if (choice == 2) {
            if (cars.empty()) cout << "No cars available.\n";
            else for (const auto& c : cars) c.display();
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter Car ID to search: ";
            cin >> id;
            bool found = false;
            for (const auto& c : cars) {
                if (c.id == id) {
                    c.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Car not found.\n";
        } 
        else if (choice == 4) {
            int id;
            cout << "Enter Car ID to delete: ";
            cin >> id;
            bool deleted = false;
            for (auto it = cars.begin(); it != cars.end(); ++it) {
                if (it->id == id) {
                    cars.erase(it);
                    cout << "Car deleted successfully!\n";
                    deleted = true;
                    break;
                }
            }
            if (!deleted) cout << "Car not found.\n";
        } 
        else if (choice == 5) {
            saveToFile(cars);
            cout << "Data saved successfully. Exiting...\n";
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
