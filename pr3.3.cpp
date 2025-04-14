#include <iostream>
#include <vector>
using namespace std;

class Account {
    int accNo;
    string name;
    float balance;

public:
    Account(int acc, string accHolder, float bal) {
        accNo = acc;
        name = accHolder;
        balance = bal;
    }

    int getAccNo() const {
        return accNo;
    }

    float getBalance() const {
        return balance;
    }

    void deposit(float amount) {
        balance += amount;
    }

    bool withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    void display() const {
        cout << "Account No: " << accNo
             << ", Name: " << name
             << ", Balance: " << balance << endl;
    }

    bool transfer(Account &receiver, float amount) {
        if (withdraw(amount)) {
            receiver.deposit(amount);
            return true;
        }
        return false;
    }
};

class Bank {
    vector<Account> accounts;
    int nextAccNo = 1001;

public:
    void createAccount() {
        string name;
        float depositAmount;

        cout << "Enter account holder's name: ";
        cin >> name;
        cout << "Enter initial deposit amount: ";
        cin >> depositAmount;

        Account newAcc(nextAccNo, name, depositAmount);
        accounts.push_back(newAcc);

        cout << "Account created successfully!" << endl;
        cout << "Your Account Number is: " << nextAccNo << endl;

        nextAccNo++;
    }

    Account* findAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.getAccNo() == accNo)
                return &acc;
        }
        return nullptr;
    }

    void depositMoney() {
        int accNo;
        float amount;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);

        if (acc) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc->deposit(amount);
            cout << "Amount deposited successfully!" << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdrawMoney() {
        int accNo;
        float amount;
        cout << "Enter account number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);

        if (acc) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (acc->withdraw(amount)) {
                cout << "Withdrawal successful!" << endl;
            }
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void transferMoney() {
        int fromAccNo, toAccNo;
        float amount;

        cout << "Enter sender's account number: ";
        cin >> fromAccNo;
        cout << "Enter receiver's account number: ";
        cin >> toAccNo;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        Account* sender = findAccount(fromAccNo);
        Account* receiver = findAccount(toAccNo);

        if (sender && receiver) {
            if (sender->transfer(*receiver, amount)) {
                cout << "Transfer successful!" << endl;
            }
        } else {
            cout << "One or both account numbers are invalid!" << endl;
        }
    }

    void displayAllAccounts() {
        cout << "\n--- All Accounts ---" << endl;
        for (const auto &acc : accounts) {
            acc.display();
        }
        cout << "Total accounts: " << accounts.size() << endl;
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Show All Accounts" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.depositMoney();
            break;
        case 3:
            bank.withdrawMoney();
            break;
        case 4:
            bank.transferMoney();
            break;
        case 5:
            bank.displayAllAccounts();
            break;
        case 0:
            cout << "Exiting system. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    cout<<"\n24CE017";
    return 0;
}
