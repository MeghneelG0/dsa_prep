#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// Insert at tail
void insertAtTail(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Merge with dummy node
ListNode* mergeTwoListsDummy(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);   // fake node
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    tail->next = (l1) ? l1 : l2;

    return dummy.next;  // skip fake head
}

int main() {
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    int n, m;
    cout << "Enter number of elements in list 1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertAtTail(l1, x);
    }

    cout << "Enter number of elements in list 2: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        insertAtTail(l2, x);
    }

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    ListNode* merged = mergeTwoListsDummy(l1, l2);
    cout << "Merged list: ";
    printList(merged);
}
