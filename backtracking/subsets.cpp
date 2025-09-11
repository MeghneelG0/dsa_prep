#include <bits/stdc++.h>
using namespace std;
// revision
void printSubsequences(vector<int>& arr, vector<int> curr = {}, int index = 0) {
    if (index == arr.size()) {
        cout << "{ ";
        for (int x : curr) cout << x << " ";
        cout << "}" << endl;
        return;
    }
    // read readme.md for this understanding we always include and exclude in each node to get subsets of each one.
    // include choice
    curr.push_back(arr[index]);
    printSubsequences(arr, curr, index + 1);
    // exclude choice by backtrack after include function
    curr.pop_back();  
    printSubsequences(arr, curr, index + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "All subsequences of the array:\n";
    printSubsequences(arr);
    return 0;
}
