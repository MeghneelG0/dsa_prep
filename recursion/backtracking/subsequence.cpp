#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int>& arr, vector<int>& ds /*, other params like sum */) {
    // 1. BASE CASE (The Stop Sign)
    // Always the first thing. What happens when we run out of elements?
    if (ind == arr.size()) {
        // Check condition (e.g., sum == target)
        // Print or Store result
        return;
    }

    // 2. PICK (The Action)
    ds.push_back(arr[ind]);       // Take the item
    // currentSum += arr[ind];    // (Optional: Update state)
    
    solve(ind + 1, arr, ds);      // RECURSE (Go deeper with the item)

    // 3. BACKTRACK (The Cleanup)
    // STRICT RULE: Whatever you did in Step 2, you MUST reverse here.
    ds.pop_back();                // Remove the item
    // currentSum -= arr[ind];    // (Optional: Reverse state)

    // 4. NOT PICK (The Skip)
    // We are now "clean". Go down the path where we ignored the item.
    solve(ind + 1, arr, ds);      
}