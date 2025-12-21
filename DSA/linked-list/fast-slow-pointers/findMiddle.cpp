#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x): val(x), next(nullptr) {};
};

// Insert at tail
void insertAtTail(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

double findMiddle(ListNode* head) {
    if (!head) return -1; // empty list

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Even number of nodes → take mean of prev & slow
    if (!fast && prev) {
        return (prev->val + slow->val) / 2.0;
    }

    // Odd number of nodes → slow is middle
    return slow->val;
}

int main() {
    ListNode* head = nullptr;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        int x;
        cin >> x;
        insertAtTail(head, x);
    }

    cout << "Created linked list: ";
    printList(head);

    double middle = findMiddle(head);
    if (middle != -1)
        cout << "Middle node value (mean if even length): " << middle << endl;
    else
        cout << "List is empty." << endl;

    return 0;
}
