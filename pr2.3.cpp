#include <iostream>
#include <string>
using namespace std;

class AccountDetails {
    int accountNumber;
    float currentBalance = 0;
    float withdrawBalance = 0;
    float depositBalance = 0;
    string name;

public:

    void createAccount() {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        string choice;
        cout << "Do you want to deposit amount in account? (yes/no): ";
        cin >> choice;

        if (choice == "yes" || choice == "Yes" || choice == "YES") {
            depositMoney();
        } else {
            cout << "Account created with 0 balance!" << endl;
        }
    }

    void depositMoney() {
        cout << "Enter amount to deposit: ";
        cin >> depositBalance;

        if (depositBalance < 0) {
            cout << "Invalid amount! Cannot deposit negative value." << endl;
        } else {
            currentBalance += depositBalance;
            cout << "Amount deposited successfully!" << endl;
        }
    }

    void withdrawMoney() {
        cout << "Enter amount to withdraw: ";
        cin >> withdrawBalance;

        if (withdrawBalance < 0) {
            cout << "Invalid amount! Cannot withdraw negative value." << endl;
        } else if (withdrawBalance > currentBalance) {
            cout << "Insufficient balance!" << endl;
        } else {
            currentBalance -= withdrawBalance;
            cout << "Amount debited successfully!" << endl;
        }
    }

    void display() {
        cout << "\n----- Account Summary -----" << endl;
        cout << "Account number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Last deposited amount: " << depositBalance << endl;
        cout << "Last withdrawn amount: " << withdrawBalance << endl;
        cout << "Current balance: " << currentBalance << endl;
    }
};

int main() {
    AccountDetails a;
    int choice;
    a.createAccount();

    do {
        cout << "\nEnter:\n 1 - DEPOSIT\n 2 - WITHDRAW\n 3 - DISPLAY ACCOUNT\n 4 - EXIT\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                a.depositMoney();
                break;
            case 2:
                a.withdrawMoney();
                break;
            case 3:
                a.display();
                break;
            case 4:
                cout << "Exiting. Thank you!" << endl;
                break;
            default:
                cout << "Invalid input! Try again." << endl;
        }

    } while (choice != 4);
    cout << "\n24CE017";
    return 0;
}
