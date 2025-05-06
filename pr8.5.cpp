#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    map<string, vector<string>> directory;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory Structure\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string folderName;
            cout << "Enter folder name: ";
            cin >> folderName;
            directory[folderName];
            cout << "Folder '" << folderName << "' added.\n";

        } else if (choice == 2) {
            string folderName, fileName;
            cout << "Enter folder name: ";
            cin >> folderName;
            if (directory.find(folderName) != directory.end()) {
                cout << "Enter file name: ";
                cin >> fileName;
                directory[folderName].push_back(fileName);
                cout << "File '" << fileName << "' added to '" << folderName << "'.\n";
            } else {
                cout << "Folder '" << folderName << "' does not exist.\n";
            }

        } else if (choice == 3) {
            cout << "\nDirectory Structure:\n";
            for (auto it = directory.begin(); it != directory.end(); it++) {
                cout << it->first << ":\n";
                for (const string& file : it->second) {
                    cout << "  - " << file << "\n";
                }
            }

        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
 cout << "\n24CE017" << endl;
    return 0;
}
