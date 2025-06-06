#include <iostream>
using namespace std;

class Shape
{

protected:
    float radius;

public:
    void getRadius(float r)
     {
        radius = r;
    }
};

class Circle : public Shape
{
public:
        float getArea() {
        return 3.14 * radius * radius;
    }

};

int main() {
     int n;
     cout<<"Enter number of circles: ";
     cin>>n;
    Circle c[n];

    for (int i = 0; i < n; i++)
    {
        float r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;
        c[i].getRadius(r);
    }

    cout << "\nAreas of Circles:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Circle " << i + 1 << ": " << c[i].getArea() << endl;
    }

        cout<<"\n24CE017";
    return 0;
}
