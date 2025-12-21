#include <iostream>
#include <vector>
using namespace std;

/* The Problem: Given arr = [1, 2, 3], return all possible orderings.

[1, 2, 3]

[1, 3, 2]

[2, 1, 3]

[2, 3, 1]

[3, 1, 2]

[3, 2, 1]

*/
void recurPermute(int index, vector<int> &nums) {
    if (index == nums.size()) {
        for (auto it: nums) {
            cout << it << endl;
        }
        return; 
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index+1, nums);
        swap(nums[index], nums[i]);
    }
}