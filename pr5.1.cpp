#include <iostream>
using namespace std;

class CalculatorSystem
{
public:

    int add(int a, int b)
    {
        return a + b;
    }


    float add(float a, float b)
    {
        return a + b;
    }

    float add(int a, float b)
    {
        return a + b;
    }


    float add(float a, int b)
    {
        return a + b;
    }

    void displayResult(float result)
    {
        cout << "Result: " << result << endl;
    }
};

int main() {
    CalculatorSystem calc;

    int i1, i2;
    float f1, f2;
    float result;
    int choice;
    do{

    cout << "Calculator - Choose input type:\n";
    cout << "1. int + int\n";
    cout << "2. float + float\n";
    cout << "3. int + float\n";
    cout << "4. float + int\n";
    cout<<"0 To Exit \n";
    cout << "Enter your choice: ";

    cin >> choice;



    switch (choice)
    {
        case 1:
            cout << "Enter two integers: ";
            cin >> i1 >> i2;
            result = calc.add(i1, i2);
            calc.displayResult(result);
            break;

        case 2:
            cout << "Enter two floats: ";
            cin >> f1 >> f2;
            result = calc.add(f1, f2);

            calc.displayResult(result);
            break;

        case 3:
            cout << "Enter an integer and a float: ";
            cin >> i1 >> f1;
            result = calc.add(i1, f1);

            calc.displayResult(result);
            break;

        case 4:
            cout << "Enter a float and an integer: ";
            cin >> f1 >> i1;
            result = calc.add(f1, i1);

            calc.displayResult(result);
            break;

        case 0:
            cout<<"Exitting...";
            break;

        default:
            cout << "Invalid choice!" << endl;
            return 1;


    }
    }while(choice!=0);


    cout<<"\n24CE017";
    return 0;
}
