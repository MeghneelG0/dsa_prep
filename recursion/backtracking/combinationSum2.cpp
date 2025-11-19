#include <iostream>
#include <vector>
#include <algorithm> // Required for sort
using namespace std;

void solve(int ind, vector<int>& arr, int target, vector<int>& ds) {
    // 1. SUCCESS BASE CASE
    // If target is 0, we found a combination! Print it.
    if (target == 0) {
        cout << "[ ";
        for (auto it : ds) cout << it << " ";
        cout << "]" << endl;
        return;
    }

    // 2. LOOP (The Search)
    for (int i = ind; i < arr.size(); i++) {
        
        // A. DUPLICATE CHECK
        // i > ind: Ensures we always allow the FIRST instance (e.g., the first '1'),
        // but skip the second '1' if it's at the same level.
        if (i > ind && arr[i] == arr[i-1]) continue;

        // B. OPTIMIZATION
        // If current number exceeds target, nothing else in the sorted array will work.
        if (arr[i] > target) break;

        // C. PICK & RECURSE
        ds.push_back(arr[i]);
        // Note: 'i + 1' because we cannot reuse elements
        solve(i + 1, arr, target - arr[i], ds); 
        ds.pop_back(); // Backtrack
    }
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2};
    int target = 4;
    vector<int> ds;
    
    // SORT ONCE HERE
    sort(arr.begin(), arr.end());
    
    solve(0, arr, target, ds);
    return 0;
}