#include <iostream>
#include <string>
using namespace std;

class Inventory_Item {
    int item_id;
    string item_name;
    float price;
    int quantity;

public:

    void initialize_item() {
        cout << "Enter item ID: ";
        cin >> item_id;
          cin.ignore();
        cout << "Enter item name: ";
        getline(cin, item_name);
        cout << "Enter item price: ";
        cin >> price;
        cout << "Enter initial quantity: ";
        cin >> quantity;
    }

    void add_stock() {
        int add_qty;
        cout << "Enter quantity to add: ";
        cin >> add_qty;

            quantity += add_qty;
            cout << "Stock updated successfully!" << endl;

    }

    void sell_item() {
        int sell_qty;
        cout << "Enter quantity to sell: ";
        cin >> sell_qty;
        if (sell_qty <= 0) {
            cout << "Invalid quantity. Enter a positive number." << endl;
        } else if (sell_qty > quantity) {
            cout << "Insufficient stock available!" << endl;
        } else {
            quantity -= sell_qty;
            cout << "Sale successful!" << endl;
        }
    }

    void display_item() {
        cout << "\nItem ID: " << item_id << endl;
        cout << "Item Name: " << item_name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity in Stock: " << quantity << endl;
    }
};

int main() {
    const int SIZE = 100;
    Inventory_Item items[SIZE];
    int n = 0;
    int choice, index;

    do {
        cout << "\n----- Inventory Management System -----\n";
        cout << "1. Add New Item\n2. Add Stock to Item\n3. Sell Item\n4. Display Item\n5. Display All Items\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (n < SIZE) {
                    cout << "\nEnter details for item " << (n + 1) << ":\n";
                    items[n].initialize_item();
                    n++;
                } else {
                    cout << "Inventory full! Cannot add more items.\n";
                }
                break;

            case 2:
                cout << "Enter item index (0 to " << n - 1 << ") to add stock: ";
                cin >> index;
                if (index >= 0 && index < n) {
                    items[index].add_stock();
                } else {
                    cout << "Invalid item index.\n";
                }
                break;

            case 3:
                cout << "Enter item index (0 to " << n - 1 << ") to sell: ";
                cin >> index;
                if (index >= 0 && index < n) {
                    items[index].sell_item();
                } else {
                    cout << "Invalid item index.\n";
                }
                break;

            case 4:
                cout << "Enter item index (0 to " << n - 1 << ") to display: ";
                cin >> index;
                if (index >= 0 && index < n) {
                    items[index].display_item();
                } else {
                    cout << "Invalid item index.\n";
                }
                break;

            case 5:
                if (n == 0) {
                    cout << "No items to display.\n";
                } else {
                    for (int i = 0; i < n; i++) {
                        cout << "\nItem " << i << ":" << endl;
                        items[i].display_item();
                    }
                }
                break;

            case 0:
                cout << "Exiting system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
