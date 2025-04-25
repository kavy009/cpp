#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    void input() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }


    Point operator+(Point p) {
        Point result;
        result.x = x + p.x;
        result.y = y + p.y;
        return result;
    }


    Point operator-() {
        Point result;
        result.x = -x;
        result.y = -y;
        return result;
    }


    bool operator==(Point p) {
        return (x == p.x && y == p.y);
    }
};

int main() {
    Point p1, p2, sum, negated;

    cout << "Enter first point:\n";
    p1.input();

    cout << "Enter second point:\n";
    p2.input();

    sum = p1 + p2;
    negated = -p1;

    cout << "\nFirst Point: ";
    p1.display();

    cout << "Second Point: ";
    p2.display();

    cout << "Sum of Points: ";
    sum.display();

    cout << "Negated First Point: ";
    negated.display();

    if (p1 == p2)
        cout << "Points are equal.\n";
    else
        cout << "Points are not equal.\n";

    cout << "\n24CE017" << endl;
    return 0;
}

