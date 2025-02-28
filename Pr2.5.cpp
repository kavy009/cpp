#include<iostream>
#include <math.h>
using namespace std;

class Loan_details
{
    string customer_name;
    float loan_amt,rate,tenure,EMI;

public:

    void add_data()
    {
        cout<<"Enter loan applicant name: ";
        cin>>customer_name;
        cout<<"Enter loan amount:";
        cin>>loan_amt;
        cout<<"Enter interest rate:";
        cin>>rate;
        cout<<"Enter the tenure of loan in months: ";
        cin>>tenure;

        calculate(loan_amt,rate,tenure);

  }

    void calculate(float loan_amt, float rate, float tenure)
    {
        EMI= (loan_amt*rate*pow(1+rate,tenure))/(pow(1+rate,tenure)-1);

    }

    void display()
    {
        cout<<"";
    }


};



int main()
{
    Loan_details l;

    int choice;
    do{
        cout<<"Enter 1 to add details ,2 to dispaly detalis and 0 to exit";
        cin>>choice;

        switch (choice)
        {
        case 1:
             l.add_data();
             break;

        case 2:
             l.display();
              break ;

        case 3:
        cout<<"Exiting from the system...";

        default:
            break;
        }

    }
    while(choice!=0);

    return 0;


}
