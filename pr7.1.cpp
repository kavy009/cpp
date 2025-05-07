#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void toLowerCase(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

int main()
{

    char paragraph[100];

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, 100);

    toLowerCase(paragraph);

    int capacity = 10;
    char** words = new char*[capacity];
    int* counts = new int[capacity];
    int wordCount = 0;

    char* token = strtok(paragraph, " ,.!?\n");
    while (token) {
        bool found = false;

        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                counts[i]++;
                found = true;
                break;
            }
        }

        if (!found) {
            if (wordCount == capacity) {

                int newCapacity = capacity * 2;

                char** newWords = new char*[newCapacity];
                int* newCounts = new int[newCapacity];

                for (int i = 0; i < wordCount; i++) {
                    newWords[i] = words[i];
                    newCounts[i] = counts[i];
                }

                delete[] words;
                delete[] counts;

                words = newWords;
                counts = newCounts;
                capacity = newCapacity;
            }

            words[wordCount] = new char[strlen(token) + 1];
            strcpy(words[wordCount], token);
            counts[wordCount] = 1;
            wordCount++;
        }

        token = strtok(nullptr, " ,.!?\n");
    }


    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << ": " << counts[i] << endl;
        delete[] words[i];
    }


    delete[] words;
    delete[] counts;


  cout << "\n24CE017" << endl;
    return 0;
}
