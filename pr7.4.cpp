#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
    string name;
    int marks;
    string grade;

public:
    Student(const string& n, int m, const string& g)
        : name(n), marks(m), grade(g) {}

    string getName() const { return name; }
    int getMarks() const { return marks; }
    string getGrade() const { return grade; }
};

int main() {
    ifstream file("students.txt");
    vector<Student> students;

    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, grade;
        int marks;

        ss >> name >> marks >> grade;

        if (ss.fail()) {
            cerr << "Error reading line: " << line << endl;
            continue;
        }

        students.emplace_back(name, marks, grade);
    }

    file.close();


    cout << left << setw(20) << "Student Name"
         << setw(10) << "Marks"
         << setw(10) << "Grade" << endl;

    cout << string(40, '-') << endl;


    for (const auto& student : students)
    {
        cout << left << setw(20) << student.getName()
             << setw(10) << student.getMarks()
             << setw(10) << student.getGrade() << endl;
    }

    cout << "\n24CE017" << endl;
    return 0;
}
