#include <bits/stdc++.h>
using namespace std; 

bool isArraySorted(vector<int>& arr, int idx) {
    if (idx >= arr.size()) {
        return true;
    }
    if (arr[idx] < arr[idx-1]) {
        return false; 
    }
    return isArraySorted(arr,idx+1);
}

int main() { 
    vector<int> arr = {1,2,3,4};
    cout << isArraySorted(arr, 1);
    return 0;
}