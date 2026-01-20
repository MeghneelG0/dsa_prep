// 1st naive solution O(2n)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the LL
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        // remove nth node from the reversed LL
        ListNode* revhead = prev;
        // delete the first node 
        if (n==1) {
            ListNode* delptr = revhead;
            revhead = revhead->next;
            delete delptr;
        } else {
            ListNode* c = revhead;
            for (int i=1; i<n-1 && c ; i++) {
                c = c->next;
            }
            if ( c && c->next) {
                ListNode* del = c->next;
                c->next = del->next;
                delete del;
            }
        }
        curr = revhead;
        prev = NULL;
        while (curr != NULL) {
            ListNode* nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }
};

// correct approach slow fast pointers

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head; 
        for (int i=0; i < n; i++) {
            fast = fast->next;
        }
        if (!fast) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delptr = slow->next;
        slow->next = delptr->next;
        delete delptr;
        return head;
    }
};