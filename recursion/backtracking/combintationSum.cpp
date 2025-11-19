#include <iostream>
#include <vector>
using namespace std;

void solve(int ind, vector<int>& arr, int target, vector<int>& ds) {
    if (ind == arr.size()) {
        if (target == 0) {
            for (auto it: ds) {
                cout << it << "\n";
            }
        }
        return;
    }
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        solve(ind,arr,target-arr[ind], ds);
        ds.pop_back();
    }
    solve(ind + 1, arr, target, ds);
}