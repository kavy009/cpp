#include<iostream>
#include<vector>
using namespace std;

class Person
{
    string name;
    int age;

public:
    Person(string Name, int Age)
    {
        name = Name;
        age = Age;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person
{
    int Eid;

public:
    Employee(string Name, int Age, int id) : Person(Name, Age)
    {
        Eid = id;
    }

    void display()
    {
        Person::display();
        cout << "Employee ID: " << Eid << endl;
    }
};

class Manager : public Employee
 {
    string Department;

public:
    Manager(string Name, int Age, int id, string dept) : Employee(Name, Age, id)
    {
        Department = dept;
    }

    void display()
    {
        Employee::display();
        cout << "Department: " << Department << endl;
    }
};

int main()

{
     int n;
    cout << "Enter number of managers: ";
    cin >> n;

    vector<Manager> managerList;

    for (int i = 0; i < n; i++)
    {
        string name, dept;
        int age, id;

        cout << "\nEnter details for Manager " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        getline(cin, dept);

        Manager m(name, age, id, dept);
        managerList.push_back(m);
    }


    cout << "\n--- Manager Details ---\n";
    for (size_t i = 0; i < managerList.size(); i++)
    {
        cout << "\nManager " << i + 1 << ":\n";
        managerList[i].display();
    }


    cout<<"\n24CE017";
    return 0;
}
