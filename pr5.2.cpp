#include <iostream>
using namespace std;

class Complex {
public:
    float real;
    float imag;

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator+(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    Complex operator-(Complex c) {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
};

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "Enter second complex number:\n";
    c2.input();

    sum = c1 + c2;
    diff = c1 - c2;

    cout << "\nFirst Number: ";
    c1.display();

    cout << "Second Number: ";
    c2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    cout << "\n24CE017" << endl;
    return 0;
}

