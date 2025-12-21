#include <bits/stdc++.h>
using namespace std;

// create an hashmap and count occurennces on [1,2,1,3,2] given query is [1,3,4,2,10].

void HashMapCount(vector<int>& arr,const vector<int>& query) {
    map<int,int> freq;
    for (int num: arr) {
        freq[num]++;
    }
    for (int q: query) {
        cout << "count of " << q << "=" << freq[q]<< endl;
    }
    for (auto it: freq) {
        cout << "element=" << it.first << ", frequency = " << it.second << endl;
    }
}


int main() {
    int n;
    cout << "enter no. of elements";
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i< arr.size(); i++) {
        cout << "enter element" << i << ":";
        cin >> arr[i];
    }
    vector<int> query = {1,3,4,2,10};
    HashMapCount(arr, query);
    return 0;
}