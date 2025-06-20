#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of words: ";
    cin >> size;


    map<int, vector<string>> wordGroups;

    cout << "Enter the words:\n";
    for (int i = 0; i < size; ++i) {
        string word;
        cin >> word;
        int length = word.length();
        wordGroups[length].push_back(word);
    }

    for (const auto& pair : wordGroups) {
        cout << "Length " << pair.first << ": ";
        for (const auto& word : pair.second) {
            cout << word << " ";
        }
        cout << endl;
    }

}
