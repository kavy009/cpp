#include<iostream>
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

};

class Employee: public Person
{
    int Eid;

public:

    Employee(string Name, int Age, int id) :Person(Name,Age)
    {
        Eid=id;
    }
};

class Manager: public Employee
{
    string Department;
public:

    Manager(string Name, int Age, int id,string dept): Employee(Name,Age,id)
    {
        Department=dept;
    }
};

int main()
{
    string Name,dept;
    int Age, id;

    cout<<"Enter name of manager: ";
    cin>>Name;
    cout<<"Enter age of manager: ";
    cin>>Age;
    cout<<"Enter employee ID:";
    cin>>id;
    cout<<"Enter employee department";
    cin>>dept;

     Manager M;

     M(Name,Age,id,dept);
}
