#include<iostream>
#include<math.h>
using namespace std;

class Loan_details {
    string customer_name;
    float loan_amt, rate, tenure, EMI;

public:

    void add_data() {
        cout << "Enter loan applicant name: ";
        getline(cin, customer_name);

        cout << "Enter loan amount: ";
        cin >> loan_amt;

        cout << "Enter annual interest rate (in %): ";
        cin >> rate;

        cout << "Enter the tenure of loan in months: ";
        cin >> tenure;

        calculate(loan_amt, rate, tenure);
    }

    void calculate(float loan_amt, float rate, float tenure) {

        float R = (rate / 100) / 12;
        float T = tenure;

        EMI = (loan_amt * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
    }

    void display() {
        cout << "\n------ Loan Details ------" << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Loan Amount: " << loan_amt<< endl;
        cout << "Annual Interest Rate: " << rate << "%" << endl;
        cout << "Loan Tenure: " << tenure << " months" << endl;
        cout << "Monthly EMI: " << EMI << endl;
    }
};

int main() {
    Loan_details l;
    int choice;

    do {
        cout << "\nEnter:\n 1 - Add Loan Details\n 2 - Display Loan Details\n 0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.add_data();
                break;

            case 2:
                l.display();
                break;

            case 0:
                cout << "Exiting from the system..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

        cout<<"\n24CE017";
    return 0;
}
