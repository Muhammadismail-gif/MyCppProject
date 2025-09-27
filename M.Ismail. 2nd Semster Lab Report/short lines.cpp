#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
public:
    string name, ID, address, phone;
    Customer(string n, string i, string a, string p) : name(n), ID(i), address(a), phone(p) {}
    void show() { cout << "Customer: " << name << " (" << ID << ")\n"; }
};

class Account {
protected:
    string accNum, type;
    double balance;
    Customer* customer;
public:
    Account(string num, double bal, string t, Customer* c) : accNum(num), balance(bal), type(t), customer(c) {}
    virtual void deposit(double amt) { balance += amt; cout << "Deposited $" << amt << "\n"; }
    virtual void withdraw(double amt) { 
        if (amt <= balance) { balance -= amt; cout << "Withdrew $" << amt << "\n"; }
        else cout << "Insufficient funds\n";
    }
    void show() { customer->show(); cout << type << " Account " << accNum << ": $" << balance << "\n"; }
};

class SavingsAccount : public Account {
    double minBal, intRate;
public:
    SavingsAccount(string num, double bal, Customer* c, double mb, double ir) : 
        Account(num, bal, "Savings", c), minBal(mb), intRate(ir) {}
    void withdraw(double amt) override {
        if (balance - amt >= minBal) { balance -= amt; cout << "Withdrew $" << amt << "\n"; }
        else cout << "Below min balance\n";
    }
};

class CurrentAccount : public Account {
    double odLimit, fee;
public:
    CurrentAccount(string num, double bal, Customer* c, double od, double f) : 
        Account(num, bal, "Current", c), odLimit(od), fee(f) {}
    void withdraw(double amt) override {
        if (balance - amt >= -odLimit) { balance -= amt; cout << "Withdrew $" << amt << "\n"; }
        else cout << "Overdraft limit\n";
    }
};

class Bank {
    vector<Account*> accounts;
public:
    void createAccount() {
        string type, num, name, id, addr, phone;
        double bal, mb, ir, od, f;
        
        cout << "Account number: "; cin >> num;
        cout << "Initial balance: "; cin >> bal;
        cout << "Type (1-Savings, 2-Current): "; cin >> type;
        cout << "Customer name: "; cin.ignore(); getline(cin, name);
        cout << "Customer ID: "; getline(cin, id);
        cout << "Address: "; getline(cin, addr);
        cout << "Phone: "; getline(cin, phone);
        
        Customer* c = new Customer(name, id, addr, phone);
        
        if (type == "1") {
            cout << "Min balance: "; cin >> mb;
            cout << "Interest rate: "; cin >> ir;
            accounts.push_back(new SavingsAccount(num, bal, c, mb, ir));
        } else {
            cout << "Overdraft limit: "; cin >> od;
            cout << "Transaction fee: "; cin >> f;
            accounts.push_back(new CurrentAccount(num, bal, c, od, f));
        }
        cout << "Account created!\n";
    }
    
    Account* findAccount(string num) {
        for (Account* acc : accounts) if (acc->accNum == num) return acc;
        return nullptr;
    }
    
    void menu() {
        while (true) {
            cout << "\n1. Create\n2. Deposit\n3. Withdraw\n4. Show\n0. Exit\nChoice: ";
            int choice; cin >> choice;
            string num; double amt;
            
            if (choice == 0) break;
            if (choice == 1) { createAccount(); continue; }
            
            cout << "Account number: "; cin >> num;
            Account* acc = findAccount(num);
            if (!acc) { cout << "Not found\n"; continue; }
            
            switch (choice) {
                case 2: cout << "Amount: "; cin >> amt; acc->deposit(amt); break;
                case 3: cout << "Amount: "; cin >> amt; acc->withdraw(amt); break;
                case 4: acc->show(); break;
            }
        }
    }
};

int main() {
    Bank bank;
    bank.menu();
    return 0;
}