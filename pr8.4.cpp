#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student

 {
    string name;
    int score;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students;

    cout << "Enter student name and score:" << endl;
    for (int i = 0; i < n; i++)
    {
        Student s;
        cin >> s.name >> s.score;
        students.push_back(s);
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b)
        {
        return a.score > b.score;
    });

    cout << "Ranked list of students:" << endl;
    int rank = 1;
    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
    {
        cout << rank << ". " << it->name << " - " << it->score << endl;
        rank++;
    }

    cout << "\n24CE017" << endl;
    return 0;
}
