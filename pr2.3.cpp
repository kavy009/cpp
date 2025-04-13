#include <iostream>
#include <string>
using namespace std;

class Account_Details {
    int account_number;
    float current_balance = 0;
    float withdraw_balance = 0;
    float deposit_balance = 0;
    string name;

public:

    void create_account() {
        cout << "Enter account number: ";
        cin >> account_number;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        string choice;
        cout << "Do you want to deposit amount in account? (yes/no): ";
        cin >> choice;

        if (choice == "yes" || choice == "Yes" || choice == "YES")
            {
            deposit_money();
        } else {
            cout << "Account created with 0 balance!" << endl;
        }
    }


    void deposit_money() {
        cout << "Enter amount to deposit: ";
        cin >> deposit_balance;

        if (deposit_balance < 0) {
            cout << "Invalid amount! Cannot deposit negative value." << endl;
        } else {
            current_balance += deposit_balance;
            cout << "Amount deposited successfully!" << endl;
        }
    }

    void withdraw_money() {
        cout << "Enter amount to withdraw: ";
        cin >> withdraw_balance;

        if (withdraw_balance < 0) {
            cout << "Invalid amount! Cannot withdraw negative value." << endl;
        } else if (withdraw_balance > current_balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            current_balance -= withdraw_balance;
            cout << "Amount debited successfully!" << endl;
        }
    }


    void display() {
        cout << "\n----- Account Summary -----" << endl;
        cout << "Account number: " << account_number << endl;
        cout << "Name: " << name << endl;
        cout << "Last deposited amount: " << deposit_balance << endl;
        cout << "Last withdrawn amount: " << withdraw_balance << endl;
        cout << "Current balance: " << current_balance << endl;

    }
};

int main() {
    Account_Details a;
    int choice;
    a.create_account();


    do {
        cout << "\nEnter:\n 1 - DEPOSIT\n 2 - WITHDRAW\n 3 - DISPLAY ACCOUNT\n 4 - EXIT\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                a.deposit_money();
                break;
            case 2:
                a.withdraw_money();
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
    cout<<"\n24CE017";
    return 0;
}
