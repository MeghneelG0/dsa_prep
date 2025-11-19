understand what pass by value and pass by reference is and its difference : 
http://tutorialspoint.com/differences-between-pass-by-value-and-pass-by-reference-in-cplusplus

1. The "Filter" Pattern (Subsequences / Subsets)
The Vibe: Packing a bag. For every item, you have a simple Yes/No choice. The Tree: Binary (2 branches per node). Input: [1, 2, 3] -> Output: [1, 2], [1], []...

The Template:

C++

void solve(int ind, vector<int>& arr, vector<int>& ds) {
    // Base Case
    if (ind == arr.size()) { print(ds); return; }

    // 1. PICK (Take it, move to NEXT index)
    ds.push_back(arr[ind]);
    solve(ind + 1, arr, ds); 
    
    // 2. BACKTRACK
    ds.pop_back();

    // 3. DON'T PICK (Leave it, move to NEXT index)
    solve(ind + 1, arr, ds);
}

2. The "Unlimited Supply" Pattern (Combinations)
The Vibe: Ordering scoops of ice cream. If you pick Chocolate, you can pick Chocolate again immediately. The Tree: Binary (but the Left branch loops on itself). Input: [2, 3], Target 6 -> Output: [2, 2, 2], [3, 3]...

The Template:

C++

`void solve(int ind, vector<int>& arr, int target, vector<int>& ds) {
    // Base Case
    if (ind == arr.size()) { ... return; }

    // 1. PICK (Take it, STAY at SAME index)
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        solve(ind, arr, target - arr[ind], ds); // <--- THE KEY DIFFERENCE
        ds.pop_back();
    }

    // 2. DON'T PICK (Leave it, move to NEXT index)
    solve(ind + 1, arr, target, ds);
} ` 
3. The "Shuffle" Pattern (Permutations)
The Vibe: Musical Chairs. Who sits in Chair 0? Who sits in Chair 1? The Tree: N-ary (The tree is very wide). Input: [1, 2, 3] -> Output: [2, 1, 3], [3, 2, 1]...

The Template:

C++

void solve(int ind, vector<int>& nums) {
    // Base Case
    if (ind == nums.size()) { print(nums); return; }

    // Loop through all candidates for the current chair ('ind')
    for (int i = ind; i < nums.size(); i++) {
        
        swap(nums[ind], nums[i]); // Put candidate 'i' in chair 'ind'
        
        solve(ind + 1, nums);     // Move to the next chair
        
        swap(nums[ind], nums[i]); // Backtrack (Reset the chair)
    }
}