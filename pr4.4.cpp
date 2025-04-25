#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
protected:
    int accNumber;
    float balance;

public:
    BankAccount(int num, float bal) {
        accNumber = num;
        balance = bal;
    }

    virtual void deposit(float amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Not enough balance!" << endl;
        }
    }

    virtual void showDetails() {
        cout << "Account Number: " << accNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccNumber() {
        return accNumber;
    }

    virtual ~BankAccount() {}
};


class SavingsAccount : public BankAccount {
    float interestRate;

public:
    SavingsAccount(int num, float bal, float rate)
        : BankAccount(num, bal), interestRate(rate) {}

    void applyInterest() {
        float interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Added: " << interest << endl;
    }

    void showDetails() override {
        BankAccount::showDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};


class CurrentAccount : public BankAccount {
    float overdraftLimit;

public:
    CurrentAccount(int num, float bal, float limit)
        : BankAccount(num, bal), overdraftLimit(limit) {}

    void withdraw(float amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void showDetails() override {
        BankAccount::showDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class TransactionHistory {
    vector<string> transactions;
    int activeCount = 0;

public:
    void add(string record) {
        transactions.push_back(record);
        activeCount++;
    }

    void undo() {
        if (activeCount > 0) {
            cout << "Undo: " << transactions[activeCount - 1] << endl;
            activeCount--;
        } else {
            cout << "No transaction to undo." << endl;
        }
    }

    void showHistory() {
        if (activeCount == 0) {
            cout << "No transaction history.\n";
            return;
        }
        cout << "Transaction History:\n";
        for (int i = activeCount - 1; i >= 0; --i) {
            cout << transactions[i] << endl;
        }
    }
};


BankAccount* findAccount(vector<BankAccount*>& accounts, int num) {
    for (BankAccount* acc : accounts) {
        if (acc->getAccNumber() == num) return acc;
    }
    return nullptr;
}

int main() {
    vector<BankAccount*> accounts;
    TransactionHistory history;
    int choice;

    do {
        cout << "\n--- BANK MENU ---\n";
        cout << "1. Add Savings Account\n";
        cout << "2. Add Current Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Apply Interest\n";
        cout << "6. Undo Last Transaction\n";
        cout << "7. Show Account Details\n";
        cout << "8. Show Transaction History\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int num;
        float amt, rate, limit;

        switch (choice) {
            case 1:
                cout << "Account Number: ";
                cin >> num;
                cout << "Initial Balance: ";
                cin >> amt;
                cout << "Interest Rate (%): ";
                cin >> rate;
                accounts.push_back(new SavingsAccount(num, amt, rate));
                break;

            case 2:
                cout << "Account Number: ";
                cin >> num;
                cout << "Initial Balance: ";
                cin >> amt;
                cout << "Overdraft Limit: ";
                cin >> limit;
                accounts.push_back(new CurrentAccount(num, amt, limit));
                break;

            case 3:
                cout << "Account Number: ";
                cin >> num;
                cout << "Amount to Deposit: ";
                cin >> amt;
                if (BankAccount* acc = findAccount(accounts, num)) {
                    acc->deposit(amt);
                    history.add("Deposited " + to_string(amt) + " to " + to_string(num));
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 4:
                cout << "Account Number: ";
                cin >> num;
                cout << "Amount to Withdraw: ";
                cin >> amt;
                if (BankAccount* acc = findAccount(accounts, num)) {
                    acc->withdraw(amt);
                    history.add("Withdrew " + to_string(amt) + " from " + to_string(num));
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 5:
                cout << "Account Number: ";
                cin >> num;
                if (BankAccount* acc = findAccount(accounts, num)) {
                    if (SavingsAccount* sa = dynamic_cast<SavingsAccount*>(acc)) {
                        sa->applyInterest();
                        history.add("Applied interest to " + to_string(num));
                    } else {
                        cout << "Not a Savings Account!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 6:
                history.undo();
                break;

            case 7:
                cout << "Account Number: ";
                cin >> num;
                if (BankAccount* acc = findAccount(accounts, num)) {
                    acc->showDetails();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 8:
                history.showHistory();
                break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    for (BankAccount* acc : accounts) {
        delete acc;
    }

    cout << "\n24CE017" << endl;
    return 0;
}
