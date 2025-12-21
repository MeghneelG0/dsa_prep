#include <bits\stdc++.h>
using namespace std;

int numberOfSubStr(string s, int k) {
    int count = 0;
    for (int i=0; i<s.size(); i++) {
        unordered_map<char, int> countMap;
        for (int j=i; j<s.size(); j++) {
            countMap[s[j]]++;
            if (countMap.size() == k) {
                count++;
            }
            else if (countMap.size() > k) {
                break;
            }
        }
    }
    return count;
}

int main() {
    string s1 = "pqpqs";
    int k1 = 2;
    cout << "Example 1 result: " << numberOfSubStr(s1, k1) << endl;

    string s2 = "abcbaa";
    int k2 = 3;
    cout << "Example 2 result: " << numberOfSubStr(s2, k2) << endl;

    return 0;
}