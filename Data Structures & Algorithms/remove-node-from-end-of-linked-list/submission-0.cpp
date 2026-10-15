/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = n;
        ListNode *s = head, *p = head, *prev = NULL;
        while(--m) {
            s = s->next;
        }
        while(s->next) {
            prev = p;
            p = p->next;
            s = s->next;
        }

        if(p == head) {
            head = head->next;
        } else {
            prev->next = p->next;
        }
        return head;
    }
};
