#include<iostream>
using namespace std;

class Account_info
{
    int acc_no;
    string acc_name;
    float curr_balance,withdraw_balance,deposit_balance;


public :

    void deposit()
    {

            cout<<"Enter the amount to deposit:";
            cin>>deposit_balance;
            curr_balance+=deposit_balance;
            cout<<"Your amount is successfully deposited"<< endl;
          //  cout<<"No such account found!" <<endl;
        }


    void withdraw()
    {

            cout<<"Enter the amount to withdraw:"<<withdraw_balance;
            if(withdraw_balance<curr_balance)
            {
                cin>>withdraw_balance;
                cout<<withdraw_balance
            }
            else{
                cout<<"There is not enough balance to withdraw";
            }

    }

    void new_account()
    {
        int choice;
        cout<<"Enter account number:" <<acc_no <<endl;
        cout<<"Enter account holder's name:" <<acc_name << endl;

        cout<<"Do you want to create account with initial balance?";
        cin>>choice;
        if(choice=='yes'|| choice=='Yes')
        {

            deposit();
        }
        else{
            cout<<"Your account is successfully created. ";
        }

    }



};

 int main()
 {
     Account_info a;

     int acc_number,choice;
     string account_name;


     cout<<"Enter account number:";
     cin>>acc_number;
     cout<<"Enter account holder's name:"<< endl;
     cin>>account_name;

     do{
        cout<<"Enter 1 to Deposit, 2 to Withdraw , 3 to Create a new account, 0 to exit.";
        cin>>choice;

        switch(choice)
        {
            case 1:
                a.deposit();
            break;

            case 2:
                a.withdraw();
            break;
            case 3:
                a.new_account();
            break;

            default:
                cout<<"Please enter valid choice.";
        }
        }
        while(choice!=0);

        return 0;

 }











