#include <bits/stdc++.h>
using namespace std;

string replaceAlphWithNext(string s) {
    for (char &c: s) {
        if (isdigit(c)) {
            return "error: string contains digit";
        }
        else if (isalpha(c)) {
            if (c=='z') {
                c = 'a';
            }
            else if ( c== 'Z') {
                c = 'A';
            } else {
                c++;
            }
        }
    }
    return s;
}

int main() { 
    string s1; 
    cout << "enter string you want to replace alpabets to next with: " << endl;
    cin >> s1; 
    string result = replaceAlphWithNext(s1);
    cout << "result is : " << result << endl; 
    return 0;
}