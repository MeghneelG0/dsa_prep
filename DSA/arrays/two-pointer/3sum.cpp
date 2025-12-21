/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter. */


#include<bits\stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Step 1: sort

    for (int i = 0; i < n; i++) {
    /*Case 3: i = 2 → nums[i] = -1 again
        Problem: this is the same as previous nums[i] = nums[1].
        If we don’t skip, we will find:
        [-1, -1, 2] again
        [-1, 0, 1] again
        So we check:
        if (i > 0 && nums[i] == nums[i-1]) continue;
        This avoids duplicate work.*/
        if (i > 0 && nums[i] == nums[i-1]) continue; 

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                /* Why skip duplicates inside the while loop?
                Imagine after finding [-1, -1, 2], we increment left.
                But if nums[left] is still -1 (duplicate), we’d repeat the same triplet.*/
                while (left < right && nums[left] == nums[left-1]) left++;
                // skip duplicates for right
                while (left < right && nums[right] == nums[right+1]) right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    return ans;
}


int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    for (auto triplet : result) {
        cout << "[";
        for (int j = 0; j < triplet.size(); j++) {
            cout << triplet[j] << (j+1 < triplet.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}