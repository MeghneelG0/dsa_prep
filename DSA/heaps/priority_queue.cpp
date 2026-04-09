#include <queue>
#include <bits\stdc++.h>

using namespace std;

int main() {
    std::priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(50);
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}