#include <iostream>
using namespace std;

class CalculatorSystem
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    double add(int a, double b)
    {
        return a + b;
    }

    double add(double a, int b)
    {
        return a + b;
    }
};

int main()
 {
    CalculatorSystem c;

    int intResult = c.add(5, 10);
    double doubleResult = c.add(5.5, 10.5);
    double mixedResult1 = c.add(5, 10.5);
    double mixedResult2 = c.add(5.5, 10);

    cout << "Integer Addition Result: " << intResult << endl;
    cout << "Double Addition Result: " << doubleResult << endl;
    cout << "Mixed Addition Result (int + double): " << mixedResult1 << endl;
    cout << "Mixed Addition Result (double + int): " << mixedResult2 << endl;

    return 0;
}
