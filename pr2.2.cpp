#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks[3];
    float average;

public:
    Student(int r, string n, float m1, float m2, float m3)
    {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateAverage();
    }

    void calculateAverage()
    {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void displayDetails()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average Marks: " << average << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {

    Student s[3] =
    {
        Student(14,"Jayraj",80,85,90),
        Student(17, "Kavya", 85, 90, 88),
        Student(18, "Jay", 90, 75, 85)
    };

    cout << "Student Records:\n";
    for (int i = 0; i < 3; i++)
    {
        s[i].displayDetails();
    }
    cout<<"\n24CE017";
    return 0;
}

