#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

string toLowerCase(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

string removePunctuation(const string& str) {
    string clean;
    for (char ch : str) {
        if (!ispunct(ch)) {
            clean += ch;
        }
    }
    return clean;
}

int main() {
    string paragraph;
    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    paragraph = toLowerCase(paragraph);

    paragraph = removePunctuation(paragraph);

    stringstream ss(paragraph);
    string word;

    map<string, int> wordFreq;

    while (ss >> word) {
        wordFreq[word]++;
    }

    cout << "\nWord Frequencies:\n";
    for (const auto& entry : wordFreq) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
