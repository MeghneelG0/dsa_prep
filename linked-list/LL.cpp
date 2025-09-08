#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    // constructor
    ListNode(int x): val(x), next(nullptr) {}

    // destructor (called when delete is used)
    ~ListNode() {
        cout << "Deleting node with value: " << val << endl;
    }
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

// Free memory (delete linked list)
void deleteList(ListNode*& head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;  // calls ~ListNode()
    }
    head = nullptr; // avoid dangling pointer
}
void deleteNode(ListNode*& head, int target) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    // find the target 
    while (curr != nullptr && curr->val != target) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) return; // no target found
    if (prev == nullptr) { // head is target
        head = head->next;
    }
    else { 
        prev->next = curr->next; // previous node from to be deleted node next is now pointing to the next node from the to be deleted. 
    }
    delete curr; 
}


int main() {
    ListNode* head = nullptr; // we initialize an empty list first

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
    int d;
    cout << "enter node value to be deleted: ";
    cin >> d;
    deleteNode(head, d);

    return 0;
}
