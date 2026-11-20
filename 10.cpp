
#include <iostream>
#include <exception>
#include <string>
using namespace std;


class InvalidAmount : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid amount! Amount must be greater than zero.";
    }
};


class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance! Withdrawal cannot be completed.";
    }
};

class BankAccount {
private:
    int accountNumber;
    double balance;

public:

    
    BankAccount(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    
    void withdraw(double amount) {

        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;

        cout << "Withdrawal successful!" << endl;
        cout << "Withdrawn Amount: Rs. " << amount << endl;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};


int main() {

    BankAccount account(101, 10000);

    cout << "===== BANKING TRANSACTION SYSTEM ====="
         << endl;

    cout << "\nInitial Account Details:" << endl;
    account.display();

    cout << "\nTransaction 1: Successful Withdrawal"
         << endl;

    try {
        account.withdraw(2000);
    }
    catch (const InvalidAmount& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }

    account.display();
    cout << "\nTransaction 2: Insufficient Funds"
         << endl;

    try {
        account.withdraw(15000);
    }
    catch (const InvalidAmount& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }

    account.display();

    cout << "\nTransaction 3: Invalid Amount"
         << endl;

    try {
        account.withdraw(-500);
    }
    catch (const InvalidAmount& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }

    account.display();

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
