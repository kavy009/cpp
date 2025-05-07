#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void addProduct() {
    ofstream file("inventory.txt", ios::app);
    string name;
    int qty;
    float price;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    file << name << " " << qty << " " << price << endl;
    file.close();
}

void viewInventory() {
    ifstream file("inventory.txt");
    string name;
    int qty;
    float price;

    while (file >> name >> qty >> price) {
        cout << "Product: " << name << ", Quantity: " << qty << ", Price: Rs" << price << endl;
    }
    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Product\n2. View Inventory\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            addProduct();
        }
        else if (choice == 2) {
            viewInventory();
        }

    } while (choice != 3);

      cout << "\n24CE017" << endl;
    return 0;
}
