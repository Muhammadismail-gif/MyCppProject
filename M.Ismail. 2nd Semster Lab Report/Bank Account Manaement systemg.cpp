#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Class Customer
class Customer {
private:
    string name;
    string ID;
    string address;
    string phoneNumber;

public:
    // Constructor
    Customer(string n, string id, string addr, string phone) 
        : name(n), ID(id), address(addr), phoneNumber(phone) {}

    // Member functions
    void getDetails() {
        cout << "\nEnter Customer Details:\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "ID: ";
        getline(cin, ID);
        cout << "Address: ";
        getline(cin, address);
        cout << "Phone Number: ";
        getline(cin, phoneNumber);
    }

    void showDetails() const {
        cout << "\nCustomer Details:\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }

    string getName() const { return name; }
    string getID() const { return ID; }
};

// Base Class Account
class Account {
protected:
    string accountNumber;
    double balance;
    string accountType;
    Customer customer;

public:
    // Constructor
    Account(string accNum, double bal, string accType, Customer cust)
        : accountNumber(accNum), balance(bal), accountType(accType), customer(cust) {}

    // Member functions
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void displayBalance() const {
        cout << "Account Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void displayAccountDetails() const {
        cout << "\nAccount Details:\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        customer.showDetails();
        displayBalance();
    }

    virtual void calculateInterest() {} // To be overridden by derived classes
    virtual void applyTransactionFee() {} // To be overridden by derived classes

    string getAccountNumber() const { return accountNumber; }
    string getAccountType() const { return accountType; }
};

// Derived Class SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNum, double bal, Customer cust, double intRate, double minBal)
        : Account(accNum, bal, "Savings", cust), interestRate(intRate), minimumBalance(minBal) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= minimumBalance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or minimum balance requirement not met." << endl;
        }
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest calculated and added: $" << fixed << setprecision(2) << interest << endl;
        cout << "New balance after interest: $" << balance << endl;
    }

    void displayAccountDetails() const {
        Account::displayAccountDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance Requirement: $" << minimumBalance << endl;
    }
};

// Derived Class CurrentAccount
class CurrentAccount : public Account {
private:
    double overdraftLimit;
    double transactionFee;

public:
    CurrentAccount(string accNum, double bal, Customer cust, double odLimit, double transFee)
        : Account(accNum, bal, "Current", cust), overdraftLimit(odLimit), transactionFee(transFee) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or overdraft limit exceeded." << endl;
        }
    }

    void applyTransactionFee() override {
        balance -= transactionFee;
        cout << "Transaction fee applied: $" << fixed << setprecision(2) << transactionFee << endl;
        cout << "New balance after fee: $" << balance << endl;
    }

    void displayAccountDetails() const {
        Account::displayAccountDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
        cout << "Transaction Fee: $" << transactionFee << endl;
    }
};

// Bank Management System Class
class BankManagementSystem {
private:
    vector<Account*> accounts;

public:
    void createAccount() {
        string accNum, accType;
        double initialDeposit;
        
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        cin.ignore(); // Clear input buffer
        
        cout << "Enter Initial Deposit: $";
        cin >> initialDeposit;
        cin.ignore();
        
        cout << "Select Account Type (1-Savings, 2-Current): ";
        int choice;
        cin >> choice;
        cin.ignore();
        
        Customer customer("", "", "", "");
        customer.getDetails();
        
        if (choice == 1) {
            double intRate, minBal;
            cout << "Enter Interest Rate (%): ";
            cin >> intRate;
            cout << "Enter Minimum Balance: $";
            cin >> minBal;
            cin.ignore();
            
            accounts.push_back(new SavingsAccount(accNum, initialDeposit, customer, intRate, minBal));
        } else if (choice == 2) {
            double odLimit, transFee;
            cout << "Enter Overdraft Limit: $";
            cin >> odLimit;
            cout << "Enter Transaction Fee: $";
            cin >> transFee;
            cin.ignore();
            
            accounts.push_back(new CurrentAccount(accNum, initialDeposit, customer, odLimit, transFee));
        } else {
            cout << "Invalid account type selection." << endl;
            return;
        }
        
        cout << "Account created successfully!" << endl;
    }

    Account* findAccount(const string& accNum) {
        for (Account* acc : accounts) {
            if (acc->getAccountNumber() == accNum) {
                return acc;
            }
        }
        return nullptr;
    }

    void deposit() {
        string accNum;
        double amount;
        
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        
        Account* acc = findAccount(accNum);
        if (acc) {
            cout << "Enter Deposit Amount: $";
            cin >> amount;
            acc->deposit(amount);
        } else {
            cout << "Account not found." << endl;
        }
    }

    void withdraw() {
        string accNum;
        double amount;
        
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        
        Account* acc = findAccount(accNum);
        if (acc) {
            cout << "Enter Withdrawal Amount: $";
            cin >> amount;
            acc->withdraw(amount);
        } else {
            cout << "Account not found." << endl;
        }
    }

    void checkBalance() {
        string accNum;
        
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        
        Account* acc = findAccount(accNum);
        if (acc) {
            acc->displayBalance();
        } else {
            cout << "Account not found." << endl;
        }
    }

    void displayAccountDetails() {
        string accNum;
        
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        
        Account* acc = findAccount(accNum);
        if (acc) {
            acc->displayAccountDetails();
        } else {
            cout << "Account not found." << endl;
        }
    }

    void calculateInterest() {
        string accNum;
        
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        
        Account* acc = findAccount(accNum);
        if (acc && acc->getAccountType() == "Savings") {
            static_cast<SavingsAccount*>(acc)->calculateInterest();
        } else {
            cout << "Account not found or not a savings account." << endl;
        }
    }

    void applyTransactionFee() {
        string accNum;
        
        cout << "\nEnter Account Number: ";
        cin >> accNum;
        
        Account* acc = findAccount(accNum);
        if (acc && acc->getAccountType() == "Current") {
            static_cast<CurrentAccount*>(acc)->applyTransactionFee();
        } else {
            cout << "Account not found or not a current account." << endl;
        }
    }

    void displayAllAccounts() {
        cout << "\nAll Accounts in the System:\n";
        for (Account* acc : accounts) {
            acc->displayAccountDetails();
            cout << "------------------------" << endl;
        }
    }

    ~BankManagementSystem() {
        for (Account* acc : accounts) {
            delete acc;
        }
    }
};

// Main function
int main() {
    BankManagementSystem bank;
    int choice;
    
    cout << "=== BANK ACCOUNT MANAGEMENT SYSTEM ===" << endl;
    
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Calculate Interest (Savings Account)\n";
        cout << "7. Apply Transaction Fee (Current Account)\n";
        cout << "8. Display All Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.checkBalance();
                break;
            case 5:
                bank.displayAccountDetails();
                break;
            case 6:
                bank.calculateInterest();
                break;
            case 7:
                bank.applyTransactionFee();
                break;
            case 8:
                bank.displayAllAccounts();
                break;
            case 0:
                cout << "Exiting system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}