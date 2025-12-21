/*
 1. Next Greater
Let's start with this example. We are given with the following array and we need to find the next greater elements for each of items of the array.

arr = [13, 8, 1, 5, 2, 5, 9, 7, 6, 12]

Next greater elements (what is the next greater element for the item at this index) -
nextGreaterElements = [null, 9, 5, 9, 5, 9, 12, 12, 12, null]

On the place of writing the element itself, we can also write its index -
nextGreaterIndexes = [-1, 6, 3, 6, 5, 6, 9, 9, 9, -1] (for 13 and 12, because there are no greater elements after themselves, we use -1, an invalid index value of the next greater element. You could use null or arr.length as well.
*/
/*
arr = [4, 5, 2, 25]
🔹 i = 0 → arr[0] = 4
st.empty() → true → skip while loop.
Push index 0.
stack = [0]            // means "index 0 → value 4"
nextGreater = [-1, -1, -1, -1]
🔹 i = 1 → arr[1] = 5
Check while:
st.top() = 0
arr[st.top()] = arr[0] = 4
arr[i] = 5
4 < 5 ✅
Pop 0
nextGreater[0] = 5
stack = []
nextGreater = [5, -1, -1, -1]
Push index 1
stack = [1]   // index 1 → value 5
🔹 i = 2 → arr[2] = 2
Check while:
st.top() = 1
arr[1] = 5
5 < 2 ❌ → stop.
Push index 2
stack = [1, 2]   // (value 5, value 2)
nextGreater = [5, -1, -1, -1]
🔹 i = 3 → arr[3] = 25
Check while:
st.top() = 2 → arr[2] = 2
2 < 25 ✅
Pop 2
nextGreater[2] = 25
stack = [1]
nextGreater = [5, -1, 25, -1]
Check again:
st.top() = 1 → arr[1] = 5
5 < 25 ✅
Pop 1
nextGreater[1] = 25
stack = []
nextGreater = [5, 25, 25, -1]
Stack empty → exit loop.
Push index 3
stack = [3]   // (value 25)
🔚 End of loop
Stack = [3] → means arr[3] = 25 has no next greater, so stays -1.
Final result:
nextGreater = [5, 25, 25, -1] 
*/

#include <bits\stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr) {
    stack<int> st;
    vector<int> nextGreater(arr.size(), -1);
    for (int i=0; i<arr.size(); i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            int index = st.top();
            st.pop();
            nextGreater[index] = arr[i];
        }
    st.push(i);
    }
    return nextGreater;
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

    vector<int> res = nextGreaterElement(arr);

    cout << "next greater element array: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}