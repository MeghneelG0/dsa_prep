#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    vector<int> dp;
    int solve(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            return 0;
        }
        if (dp[idx] != -1) return dp[idx];
        int pick = nums[idx] + solve(idx+2, nums);
        int notpick = 0 + solve(idx+1, nums);

        return dp[idx] = max(pick,notpick);
    }
public: 
    int rob(vector<int>& nums) {
            int n = nums.size();
            // Initialize DP with -1
            dp.assign(n+1, -1); 
            return solve(0, nums);
        }
};