#include <iostream>
#include <vector>
using namespace std;

void solve(int ind, vector<int>& arr, vector<int>& ds, int currentSum, int target) {
    // 1. Base Case
    if (ind == arr.size()) {
        if (currentSum == target) {
            // Manual loop to print vector
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
        }
        return; // <--- CRITICAL: Stop the recursion here!
    }

    // 2. PICK (Include the element)
    ds.push_back(arr[ind]);
    currentSum += arr[ind];
    
    solve(ind + 1, arr, ds, currentSum, target); // Recurse with updated state

    // 3. BACKTRACK (Undo the changes)
    ds.pop_back();            // Remove the last element (No arguments!)
    currentSum -= arr[ind];   // Subtract the value we added

    // 4. NOT PICK (Skip the element)
    // Since we backtracked, 'ds' and 'currentSum' are clean.
    solve(ind + 1, arr, ds, currentSum, target);
}


int solve(int ind, vector<int>& arr, int currentSum, int target) {
    // 1. Base Case
    if (ind == arr.size()) {
        if (currentSum == target) return 1; // Found a way! Count 1.
        else return 0;                      // Failed. Count 0.
    }

    // 2. PICK
    // We pass (currentSum + arr[ind]) to the next level.
    // We do NOT modify 'currentSum' here.
    int left = solve(ind + 1, arr, currentSum + arr[ind], target);

    // 3. DON'T PICK
    // We pass 'currentSum' as is (because we didn't add anything).
    // Since we never changed 'currentSum' in step 2, we don't need to undo anything.
    int right = solve(ind + 1, arr, currentSum, target);

    // 4. TOTAL
    return left + right;
}

int main() {
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    int target = 2;
    solve(0, arr, ds, 0, target);
    return 0;
}