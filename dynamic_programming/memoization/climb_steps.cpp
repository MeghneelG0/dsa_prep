#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> memo; 
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (memo.count(n)) return memo[n];

        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};

int main() {
    int x;
    cout << "enter number of steps to be climbed: ";
    cin >> x;
    Solution obj;
    cout << obj.climbStairs(x) << endl;
    return 0;
}