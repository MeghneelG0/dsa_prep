#include <bits/stdc++.h>
using namespace std;


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i=0; i<n;i++) {
        int min_idx = i;
        for (int j=i+1; j < n; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        swap(arr[i], arr[min_idx]);
        }
    }
}

int main() {
    int n;
    cout << "enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "enter array element [" << i << "]: ";
        cin >> arr[i];
    }
    selectionSort(arr);
    cout << "sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
  