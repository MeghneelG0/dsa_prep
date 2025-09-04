#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; 
    cout << "enter string: ";
    cin >> s;
    map<char, int> freq;

    for (char c: s) {
        freq[c]++;
    }
    for (auto &it : freq) {
        cout << "char = " << it.first << ", freq = " << it.second << endl;
    }
    return 0;
}