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
    void reorderList(ListNode* head) {
        if(!head || head->next == NULL || head->next->next == NULL)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next, *prev = NULL;
        slow->next = NULL;
        while(curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode *a = head, *b = prev;
        while(a && b) {
            ListNode *nb = b->next;
            ListNode *na = a->next;
            b->next = a->next;
            a->next = b;
            a = na; b = nb;
        }

    }
};