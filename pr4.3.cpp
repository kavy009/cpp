#include <iostream>
using namespace std;


class Fuel
{
protected:

    string fuelType;

public:

    Fuel(string ft)
    {
        fuelType = ft;
    }

    void displayFuel()
    {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand
{
protected:

    string brandName;

public:
    Brand(string bn)
     {
        brandName = bn;
    }

    void displayBrand()
    {
        cout << "Brand: "<< brandName << endl;
    }
};

class Car : public Fuel, public Brand
{
public:
    Car(string ft, string bn) : Fuel(ft), Brand(bn) {}

    void displayCarDetails()
    {
        displayFuel();
        displayBrand();
    }
};

int main() {

   int TotalCars=3;
    Car c[3] = {
        Car("Petrol", "Toyota"),
        Car("Diesel", "Tata"),
        Car("Electric", "Tesla")
    };

 cout<<"---Car List---\n";

    for (int i = 0; i < TotalCars; i++) {
        cout << "Car " << i + 1 << " Details:" << endl;
       c[i].displayCarDetails();
        cout << endl;
    }

    return 0;
}
