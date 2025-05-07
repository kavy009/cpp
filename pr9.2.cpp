#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount
 {

    string accountHolder;
    float balance;
    vector<string> transactionHistory;

public:

    BankAccount(const string& holderName, float initialBalance) {
        accountHolder = holderName;
        balance = initialBalance;
        logTransaction("Account created with initial balance.");
    }


    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            logTransaction("Deposited: " + to_string(amount));
            cout << "Deposited: " << amount << endl;
        } else {
            logTransaction("Error: Invalid deposit amount.");
            cout << "Error: Invalid deposit amount." << endl;
        }
    }

    void withdraw(float amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            logTransaction("Withdrew: " + to_string(amount));
            cout << "Withdrew: " << amount << endl;
        } else {
            logTransaction("Error: Insufficient funds or invalid withdrawal amount.");
            cout << "Error: Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void logTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

    void displayTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (const string& transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }
};

int main() {
    string name;
    float initialDeposit;

    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter initial deposit amount: ";
    cin >> initialDeposit;

    BankAccount account(name, initialDeposit);


    int choice;
    do {
        cout << "\nBanking System Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                cout << "Current Balance: " << account.getBalance() << endl;
                break;
            case 4:
                account.displayTransactionHistory();
                break;
            case 5:
                cout << "Exiting the banking system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

     cout << "\n24CE017" << endl;
    return 0;
}

