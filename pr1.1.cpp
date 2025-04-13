#include<iostream>

using namespace std;

class BankAccount
{
public:

    string name;
    int account_no,amount,withdrawn_amt;
    float balance;


    void deposit(int amount)
    {
        cout<<"Deposited amount is "<<amount<<endl;
    }

    void withdraw(int withdrawn_amt)
    {

        if (withdrawn_amt>amount)
        {
            cout<<"You have not sufficient Balance"<<endl;
        }

else {
        cout<<"Withdrawn amount is "<<withdrawn_amt<<endl;


}
    }
    void display()
    { if (withdrawn_amt<=amount)
    {
        balance=amount-withdrawn_amt;
    }
    else {
        balance= amount;
    }
    cout<<"Remaining Balance is "<<balance<<endl;

    }

};

int main()
{
    BankAccount b;

     cout<<"Enter your Name ";
     cin>>b.name;
      cout<<"Enter your Account no. ";
     cin>>b.account_no;
      cout<<"Enter Amount to deposit ";
     cin>>b.amount;
     b.deposit(b.amount);
      cout<<"Enter Amount to withdraw ";
     cin>>b.withdrawn_amt;

     b.withdraw(b.withdrawn_amt);
b.display();

    cout<<"\n24CE017";

}
