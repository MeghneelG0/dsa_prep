#include <bits/stdc++.h>
using namespace std;

void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
    if (index == nums.size()) {
        ans.push_back(nums); // store one permutation
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        recurPermute(index + 1, nums, ans);
        swap(nums[i], nums[index]); // backtrack
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> nums[i];
    }

    vector<vector<int>> result = permute(nums);

    cout << "\nAll permutations:\n";
    for (auto &vec : result) {
        for (auto &x : vec) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
