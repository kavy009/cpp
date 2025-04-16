#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
    int itemId;
    string itemName;
    float price;
    int quantity;

public:

    void InitializeItem() {
        cout << "Enter item ID: ";
        cin >> itemId;
        cin.ignore();
        cout << "Enter item name: ";
        getline(cin, itemName);
        cout << "Enter item price: ";
        cin >> price;
        cout << "Enter initial quantity: ";
        cin >> quantity;
    }

    void AddStock() {
        int addQty;
        cout << "Enter quantity to add: ";
        cin >> addQty;

        quantity += addQty;
        cout << "Stock updated successfully!" << endl;
    }

    void SellItem() {
        int sellQty;
        cout << "Enter quantity to sell: ";
        cin >> sellQty;
        if (sellQty <= 0) {
            cout << "Invalid quantity. Enter a positive number." << endl;
        } else if (sellQty > quantity) {
            cout << "Insufficient stock available!" << endl;
        } else {
            quantity -= sellQty;
            cout << "Sale successful!" << endl;
        }
    }

    void DisplayItem() {
        cout << "\nItem ID: " << itemId << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity in Stock: " << quantity << endl;
    }
};

int main() {
     int Size = 30;
    InventoryItem items[SIZE];
    int n = 0;
    int choice, index;

    do {
        cout << "\n----- Inventory Management System -----\n";
        cout << "1. Add New Item\n2. Add Stock to Item\n3. Sell Item\n4. Display Item\n5. Display All Items\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (n < Size) {
                    cout << "\nEnter details for item " << (n + 1) << ":\n";
                    items[n].InitializeItem();
                    n++;
                } else {
                    cout << "Inventory full! Cannot add more items.\n";
                }
                break;

            case 2:
                cout << "Enter item index (0 to " << n - 1 << ") to add stock: ";
                cin >> index;
                if (index >= 0 && index < n) {
                    items[index].AddStock();
                } else {
                    cout << "Invalid item index.\n";
                }
                break;

            case 3:
                cout << "Enter item index (0 to " << n - 1 << ") to sell: ";
                cin >> index;
                if (index >= 0 && index < n) {
                    items[index].SellItem();
                } else {
                    cout << "Invalid item index.\n";
                }
                break;

            case 4:
                cout << "Enter item index (0 to " << n - 1 << ") to display: ";
                cin >> index;
                if (index >= 0 && index < n) {
                    items[index].DisplayItem();
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
                        items[i].DisplayItem();
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

    cout << "\n24CE017";
    return 0;
}
