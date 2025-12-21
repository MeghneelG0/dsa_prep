#include <bits/stdc++.h>
using namespace std;

string reverseString(string s) {
    for (char c: s) {
        if (isdigit(c)) {
            return "error: string contains digit";
        }
        }
        reverse(s.begin(), s.end());
        return s;
    }

int main() {
    string s1;
    cout << "enter string you want to reverse" << endl; 
    cin >> s1;
    string result = reverseString(s1);
    cout << "reversed string is =" << result << endl; 
    return 0; 
}