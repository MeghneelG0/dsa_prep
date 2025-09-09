#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Compare = std::less<T>> 
class Heap {
    vector<T> heap;
    Compare comp; // comparator object

    void heapifyDown(int i) {
        int n = heap.size();
        int best = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && comp(heap[best], heap[left]))
            best = left;
        if (right < n && comp(heap[best], heap[right]))
            best = right;

        if (best != i) {
            swap(heap[i], heap[best]);
            heapifyDown(best);
        }
    }

    void heapifyUp(int i) {
        if (i == 0) return;
        int parent = (i - 1) / 2;
        if (comp(heap[parent], heap[i])) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void push(T val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    T peek() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    void pop() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
    }

    void printHeap() {
        for (T x : heap) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    Heap<int, std::less<int>> maxHeap; // behaves like MaxHeap
    Heap<int, std::greater<int>> minHeap; // behaves like MinHeap

    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    cout << "MaxHeap peek: " << maxHeap.peek() << endl;

    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    cout << "MinHeap peek: " << minHeap.peek() << endl;
}

