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
    curr.push_back(arr[index]);
    printSubsequences(arr, curr, index + 1);
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
