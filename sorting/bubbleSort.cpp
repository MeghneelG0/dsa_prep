#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr) {
    // [1,3,5,6,2,9]
    /*    
    int n = arr.size();
    for (int i=0; i<n-1;i++) {
        for (int j=i+1; j<n;j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }*/

    int n = arr.size();
    for (int i=0; i<n; i++) {
        bool swapped = false;
        for (int j=0; j<n-i-1;j++) {
            if (arr[j+1] < arr[j]) {
                swap(arr[j+1], arr[j]);
            }
        }
    }
}


int main() { 
    int n;
    cout << "enter no. of array elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter elements: ";
    for (int i=0; i<n;i++) cin >> arr[i];
    bubbleSort(arr);
    cout << "sorted array: ";
    for (int x: arr) cout << x << "";
    return 0;
}

