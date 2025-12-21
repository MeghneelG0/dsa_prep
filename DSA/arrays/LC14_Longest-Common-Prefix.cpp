#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0]; 
        for (int i=1; i<strs.size(); i++) {
            int j = 0; // resetting this so we get j value minimum for substr while going through each str
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};