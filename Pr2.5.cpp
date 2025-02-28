#include<iostream>
using namespace std;

class Loan_details
{
    string customer_name;
    float loan_amt,rate,tenure,EMI;
   
public:

    void add_data()
    {
        

    }

};



int main()
{
    Loan_details L;
    string customer_name;
    float loan_amt,rate,tenure,EMI;
    int choice;
    do{
        cout<<"Enter 1 to add details ,2 to dispaly detalis and 3 to exit";
        cin>>choice;

        switch (choice)
        {
        case 1:
        cout<<"Enter loan applicant name: ";
        cin>>customer_name;
        cout<<"Enter loan amount:";
        cin>>loan_amt;
        cout>>"Enter interest rate:";
        cin>>rate;
        cout<<"Enter the tenure of loan in months: ";
        cin>>tenure;
        

            break;
        
        default:
            break;
        }

    }

}
