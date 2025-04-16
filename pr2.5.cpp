#include <iostream>
#include <math.h>
using namespace std;

class LoanDetails {
    string customerName;
    float loanAmt, rate, tenure, emi;

public:

    void AddData() {
        cin.ignore();
        cout << "Enter loan applicant name: ";
        getline(cin, customerName);

        cout << "Enter loan amount: ";
        cin >> loanAmt;

        cout << "Enter annual interest rate (in %): ";
        cin >> rate;

        cout << "Enter the tenure of loan in months: ";
        cin >> tenure;

        Calculate(loanAmt, rate, tenure);
    }

    void Calculate(float loanAmt, float rate, float tenure) {
        float R = (rate / 100) / 12;
        float T = tenure;

        emi = (loanAmt * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
    }

    void Display() {
        cout << "\n------ Loan Details ------" << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Loan Amount: " << loanAmt << endl;
        cout << "Annual Interest Rate: " << rate << "%" << endl;
        cout << "Loan Tenure: " << tenure << " months" << endl;
        cout << "Monthly EMI: " << emi << endl;
    }
};

int main() {
    LoanDetails l;
    int choice;

    do {
        cout << "\nEnter:\n 1 - Add Loan Details\n 2 - Display Loan Details\n 0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.AddData();
                break;

            case 2:
                l.Display();
                break;

            case 0:
                cout << "Exiting from the system..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    cout << "\n24CE017";
    return 0;
}
