
#include <iostream>
#include <string>
using namespace std;

// BankAccount class
class BankAccount {

private:
    // Private members: Cannot be accessed directly outside the class.
    // They protect sensitive account information.
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Public constructor: Initializes account details.
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;

        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
        }
    }

    // Public function to deposit money.
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Rs. " << amount << " deposited successfully." << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Public function to withdraw money.
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Rs. " << amount << " withdrawn successfully." << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Public function to display account details.
    void display() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

// Main function
int main() {

    // Creating first object
    BankAccount account1(101, "Rahul", 5000);

    // Creating second object
    BankAccount account2(102, "Priya", 8000);

    cout << "========== ACCOUNT 1 ==========" << endl;
    account1.display();

    account1.deposit(2000);
    account1.withdraw(1000);

    cout << "\nUpdated Account 1 Details:";
    account1.display();

    cout << "\n========== ACCOUNT 2 ==========" << endl;
    account2.display();

    account2.deposit(3000);
    account2.withdraw(1500);

    cout << "\nUpdated Account 2 Details:";
    account2.display();

    return 0;
}
