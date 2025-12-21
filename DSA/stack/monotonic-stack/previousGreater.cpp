/* 
2. Previous Greater
This time we want to find the previous greater elements. One option is to iterate from arr.length - 1 to 0 and use the same logic as above in the opposite direction. In order to keep things simple, I rather like another flavour of the template above where we add three more lines after the while loop to get the previous greater element. Let's see how to do that.

arr = [13, 8, 1, 5, 2, 5, 9, 7, 6, 12]

Previous greater elements -
previousGreaterElements = [null, 13, 8, 8, 5, 8, 13, 9, 7, 13]
nextGreaterIndexes = [-1, 0, 1, 1, 3, 1, 0, 6, 7, 0]
*/
#include<bits\stdc++.h>
using namespace std;

vector<int> previousGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> prevGreater(n, -1);  // default -1 (if none found)
    stack<int> st; // will store indices

    for (int i = 0; i < n; i++) {
        // we remove any greater element from previous from the stack
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        // after the while loop, only the elements which are greater than the current element are left in stack
        // this means we can confidentally decide the previous greater element of the current element i, that's stack top
        if (!st.empty()) {
            prevGreater[i] = arr[st.top()];
        }

        // Push current index
        st.push(i);
    }

    return prevGreater;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter array element [" << i << "]: ";
        cin >> arr[i];
    }

    vector<int> res = previousGreaterElement(arr);

    cout << "next greater element array: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}