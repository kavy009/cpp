#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    string Name;
    int salary, bonus, TotalSalary;
    const int DefaultBonus = 15000;
    string BonusChoice;

public:

 inline void CountSalary()
    {
        TotalSalary = salary + bonus;
    }

    void EmployeeData() {
        cout << "Enter Employee name: ";
        cin>>Name;

        cout << "Enter Salary: ";
        cin >> salary;

        cout << "Employee has a customized BONUS? (yes/no): ";
        cin >> BonusChoice;

        if (BonusChoice == "yes")
        {
            cout << "Enter Bonus: ";
            cin >> bonus;
        } else
        {
            bonus = DefaultBonus;
        }

        CountSalary();
    }

    void ShowEmployeeData() const
    {
        cout << "Name: " << Name
             << ", Basic Salary: " << salary
             << ", Bonus: " << bonus
             << ", Total Salary: " << TotalSalary
             << endl;
    }
};

int main() {
    vector<Employee> emp;
    string EmployeeChoice;

    do {
        Employee e;
        e.EmployeeData();
        emp.push_back(e);

        cout << "Do you want to add another Employee? (yes/no): ";
        cin >> EmployeeChoice;
    } while (EmployeeChoice == "yes");

    cout << "\n-- Displaying Employee Data --\n";
    for (const auto &e : emp)
    {
        e.ShowEmployeeData();
    }

    return 0;
}
