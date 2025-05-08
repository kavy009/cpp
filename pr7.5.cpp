#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


ostream& currency(ostream& os)
{
    return os << "Rs";
}

struct Student
{
    string name;
    int marks;
    double tuitionFee;
};

void displayStudentData(const vector<Student>& students) {

    cout << left << setw(20) << "Student Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;

    for (const auto& student : students)
    {
        cout << left << setw(20) << student.name
             << setw(10) << student.marks
             << setw(15) << currency << fixed << setprecision(2) << student.tuitionFee
             << endl;
    }
}

int main() {
    vector<Student> students;
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;


    for (int i = 0; i < numStudents; ++i) {
        Student student;
        cin.ignore();

        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, student.name);


        cout << "Enter marks for " << student.name << ": ";
        cin >> student.marks;


        cout << "Enter tuition fee for " << student.name << ": Rs";
        cin >> student.tuitionFee;

        students.push_back(student);
    }

    cout << endl << "Formatted Student Data:" << endl;
    displayStudentData(students);

 cout << "\n24CE017" << endl;
    return 0;
}
