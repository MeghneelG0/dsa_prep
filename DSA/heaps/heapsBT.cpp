#include <bits\stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "enter number of elements in arr: ";
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n;i++) {
        cout << "enter element " << i << ":";
        cin >> arr[i];
    }

    // make_heap(arr.begin(), arr.end(), greater<int>());  min heap
    make_heap(arr.begin(), arr.end()); // max heap
    // arr.front() is the root
    cout << "max element: " << arr.front() << endl;

    // first insert element into list then perform heap operations / functions
    arr.push_back(60);
    // push_heap(arr.begin(), arr.end(), greater<int>());
    push_heap(arr.begin(), arr.end());
    cout << "after insertion, max: " << arr.front() << endl;

    // remove max element
    pop_heap(arr.begin(), arr.end()); // moves max to end
    arr.pop_back();  // remove it
    cout << "after deletion, max: " << arr.front() << endl;

    sort_heap(arr.begin(), arr.end());
    cout << "sorted element: ";
    for (int i: arr) cout << i << " ";
    return 0;
}