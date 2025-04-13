#include<iostream>

using namespace std;

class Account_info
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
    Account_info a1;

     cout<<"Enter your Name ";
     cin>>a1.name;
      cout<<"Enter your Account no. ";
     cin>>a1.account_no;
      cout<<"Enter Amount to deposit ";
     cin>>a1.amount;
     a1.deposit(a1.amount);
      cout<<"Enter Amount to withdraw ";
     cin>>a1.withdrawn_amt;

     a1.withdraw(a1.withdrawn_amt);
a1.display();
cout<<"24CE017"

}
