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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head = NULL, *sum = NULL;
        int c = 0;
        while(l1 || l2) {
            int a = 0, b = 0;
            if(l2) {
                b = l2->val;
                l2 = l2->next;
            }
            if(l1) {
                a = l1->val;
                l1 = l1->next;
            }
            int s = (a+b+c)%10;
            c = (a+b+c)/10;
            if(head == NULL) {
                head = new ListNode(s);
                sum = head;
            } else {
                head->next = new ListNode(s);
                head = head->next;
            }
        }
        if(c)
            head->next = new ListNode(c);

        return sum;
    }
};
