#include <bits/stdc++.h>
using namespace std;

bool binarySearch(const vector<int>& arr, int start, int end, int target) {
    if (start > end) {
        return false;
    }
    int mid = start + (end-start)/2;
    if (arr[mid] == target) {
        return true;
    }
    if (arr[mid] < target) {
        return binarySearch(arr,mid+1,end,target);
    }
    if (arr[mid] > target) {
        return binarySearch(arr,start,mid-1,target); 
    }
    return false;
}

int main() { 
    cout << binarySearch({1,2,3,4,5}, 0, 4,5);
    return 0;
}   
