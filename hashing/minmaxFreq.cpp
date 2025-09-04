#include <bits/stdc++.h>
using namespace std;

void minmaxCount(vector<int>& arr, const vector<int>& query) {
    map<int,int> freq;
    for (int num : arr) {
        freq[num]++;
    }

    int maxFreq = 0, minFreq = INT_MAX;
    int maxElement = 0, minElement = 0;

    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxElement = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minElement = it.first;
        }
    }

    cout << "Element with max frequency: " << maxElement << " = " << maxFreq << endl;
    cout << "Element with min frequency: " << minElement << " = " << minFreq << endl;
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
    minmaxCount(arr, query);
    return 0;
}