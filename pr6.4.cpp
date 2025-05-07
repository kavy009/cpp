#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor\n";
    }

    virtual ~Base() {
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[30];
        cout << "Derived constructor: Allocated memory\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived destructor: Released memory\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;

    cout << "\n24CE017" << endl;
    return 0;
}

