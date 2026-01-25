/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* dummy = new Node(0);
        Node* tail = dummy;
        Node* curr = head;
        unordered_map<Node*, Node*> mp;
        while (curr) {
            tail->next = new Node(curr->val);
            tail = tail->next;
            mp[curr] = tail;
            curr = curr->next;
        }
        curr = head;
        tail = dummy->next;
        while (curr) {
            if (curr->random) {
                tail->random = mp[curr->random];
            } else {
                tail->random = NULL;
            }
            curr = curr->next;
            tail = tail->next;
        }
        return dummy->next;
    }
};