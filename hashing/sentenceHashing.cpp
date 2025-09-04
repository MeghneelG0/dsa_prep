#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; 
    cout << "enter string: ";
    getline(cin,s);
    unordered_map<string, int> freq;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        freq[word]++;
    }
    for (auto &it : freq) {
        cout << "word = " << it.first << ", freq = " << it.second << endl;
    }
    return 0;
}