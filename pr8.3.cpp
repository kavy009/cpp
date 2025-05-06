#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> transactionIDs;
    int id;

    cout << "Enter the transaction IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        transactionIDs.insert(id);
    }

    cout << "\nUnique Transaction IDs (sorted):\n";
    for (set<int>::iterator it = transactionIDs.begin(); it != transactionIDs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n24CE017" << endl;
    return 0;
}
