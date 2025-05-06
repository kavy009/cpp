#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int n;


    cout << "Enter the number of integers: ";
    cin >> n;

    vector<int> sequence;
    int num;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        sequence.push_back(num);
    }


    cout << "Original sequence:\n";
    for (int val : sequence)
    {
        cout << val << " ";
    }
    cout << endl;

    reverse(sequence.begin(), sequence.end());

    cout << "Reversed sequence:\n";
    for (int val : sequence)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "\n24CE017" << endl;

    return 0;
}
