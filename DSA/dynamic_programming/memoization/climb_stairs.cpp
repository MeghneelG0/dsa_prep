#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:;
    int solve(int currentStep, int targetStep, vector<int>& dp) {
        if (currentStep == targetStep) return 1; 
        if (currentStep > targetStep) return 0;  
        if (dp[currentStep] != -1) {
            return dp[currentStep];
        }
        int oneJump = solve(currentStep + 1, targetStep, dp);
        int twoJumps = solve(currentStep + 2, targetStep, dp);
        int result = oneJump + twoJumps;
        dp[currentStep] = result;
        return result;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);  
        return solve(0, n, dp);
    }
};