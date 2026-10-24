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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || head->next == NULL || left==right)
            return head;
        int c = 1;
        ListNode *prev = NULL, *curr = head;
        while(c != left) {
            prev = curr;
            curr = curr->next;
            c++;
        }
        ListNode *a = curr->next;
        while(c != right) {
            ListNode *tmp = a->next;
            a->next = curr;
            curr = a;
            a = tmp;
            c++;
        }
        if(prev == NULL) {
            head->next = a;
            head = curr;
        } else {
            prev->next->next = a;
            prev->next = curr;
        }
        return head;
    }
};